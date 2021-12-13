%code top{
    #include <iostream>
    #include <assert.h>
    #include <string>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
   
    
    
    
}

%code requires {
    
    #include "Function.h"
    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"
}

%union {
    int itype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;
}

%start Program//开始符号
//定义终结符
%token <strtype> ID  PUTF STRING

%token <itype> INTEGER
%token IF ELSE
%token INT VOID
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON
//LPAREN RPAREN是小括号  LBRACE RBRACE是大括号
%token ADD SUB OR AND LESS ASSIGN NOT
%token RETURN

//下面是添加的终结符
%token NEW ENUM DELETE CONST  BREAK  CONTINUE WHILE  
%token EQ  GTR  NEQ LEQ GEQ  MUL DIV REM COMMA COLON DQUA SQUA
%token LBRACK  RBRACK 
%token DECIMIAL OCTAL_DECIMIAL HEX_DECIMAL

//LBRACK  RBRACK 是中括号 


//nterm 下面修饰非终结符
%nterm <stmttype> Stmts Stmt AssignStmt BlockStmt IfStmt ReturnStmt DeclStmt FuncDef  putsFunc
%nterm <exprtype> Exp AddExp Cond LOrExp PrimaryExp LVal RelExp LAndExp  Factor constIdlist  constId varIdlist
%nterm <exprtype>varId varlval PutInchars

%nterm <type> Type 
//下面是添加的非终结符 FuncAddExp
%nterm  <stmttype> Whilestmt     ConstDeclstmt   

%nterm  <stmttype>   ADDstmt Emptystmt VarDeclStmt
//单目运算符   
%nterm <exprtype>     Paramlist Params Param   FuncCallExp UnaryExp
%precedence THEN 
%precedence ELSE
%%

//下面开始定义产生式 以及相应的动作
Program
    : Stmts {
        ast.setRoot($1);//设置分析树的root
    }
    ;
    
Stmts
    : Stmt {
     int rt=0;//0表示void  1表示int
     //这里需要默认化为void 因为有可能没有return语句
        if(static_cast<ReturnStmt*>($1)->getrt()==1)
        {
            rt=1;
        }
        if(static_cast<IfStmt*>($1)->getrt()==1)
        {
            rt=1;
        }
        if(static_cast<IfElseStmt*>($1)->getrt()==1)
        {
            rt=1;
        }
    //$$=$1;
    $$ = new SeqNode($1,rt);//构造函数
    
    }
    | Stmts Stmt{
        
        
        int rt=0;//0表示void  1表示int
        if(static_cast<ReturnStmt*>($2)->getrt()==1)
        {
            rt=1;
        }
        if(static_cast<IfStmt*>($2)->getrt()==1)
        {
            rt=1;
        }
        if(static_cast<IfElseStmt*>($2)->getrt()==1)
        {
            rt=1;
        }
        //fprintf(stderr, "当前rt %d\n",rt);
        $$ = new SeqNode($1, $2,rt);//构造函数
        //$$ = new SeqNode($1, $2);//构造函数
    }
    ;
Stmt
    : 
    AssignStmt {$$=$1;}
    | ADDstmt {$$=$1;}
    | BlockStmt {$$=$1;}
    | IfStmt {$$=$1;}
    | ReturnStmt {$$=$1;}
    | DeclStmt {$$=$1;}
    | FuncDef {$$=$1;}
    | putsFunc {$$=$1;}
    | Whilestmt {$$=$1;}
   
   
   
    | Emptystmt   {$$=$1;}
   
    
    
;







    
 //----------------下面是额外添加的stmt



//下面是添加的stmt

Whilestmt:
WHILE LPAREN   Cond    RPAREN  Stmt
{
    $$=new Whilestmt($3,$5);
}
;


Emptystmt:
    SEMICOLON
    {
        $$=new Emptystmt;//加处理语言就会报错
    }

;









BlockStmt
    :   LBRACE //作用域开始 定义当前作用域符号表
        {
        //fprintf(stderr, "block断点1\n");
        identifiers = new SymbolTable(identifiers);
        
        } 
        Stmts RBRACE 
        {//这是一个作用域结束 当前符号表删除 指针前移
            //fprintf(stderr, "block断点2\n");
            if(static_cast<SeqNode*>($3)->getrt()==0)
             {
                //fprintf(stderr, "block断点3\n");
                $$ = new CompoundStmt($3,0);
             }
            else
            {
                $$ = new CompoundStmt($3,1);
            }
            
            
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
     |
    LBRACE  RBRACE 
    {
     $$ = new CompoundStmt(0);
     }
    ;
    
    
IfStmt
    : IF LPAREN Cond RPAREN Stmt %prec THEN {
        int st=0;
        if(static_cast<ReturnStmt*>($5)->getrt()==1)
           {
            st=1;
           
           }
    
        $$ = new IfStmt($3, $5,st);
    }
    | IF LPAREN Cond RPAREN Stmt ELSE Stmt {
    
        int st=0;
        
        if(static_cast<ReturnStmt*>($7)->getrt()==1)
           {
           //fprintf(stderr, "断点2\n");
            st=1;
           
           }
    
    
        $$ = new IfElseStmt($3, $5, $7,st);
       // fprintf(stderr, "此时st %d\n",st);
    }
    ;
    
ReturnStmt
    :
    
    
    RETURN AddExp SEMICOLON
    {
        $$ = new ReturnStmt($2,1);
        //fprintf(stderr, "return断点2\n");
    }
   
    |
    RETURN  SEMICOLON
    {
    //fprintf(stderr, "return断点1\n");
        $$ = new ReturnStmt(0);
        //fprintf(stderr, "return断点2\n");
    }
    ;
    
ADDstmt:
    AddExp SEMICOLON
    {
    $$ =new ADDstmt($1);

    }
;


Exp
    :
    AddExp {$$ = $1;}
    
    ;
    
Cond
    :
    LOrExp {$$ = $1;}
    
    ;
  
    
PrimaryExp
    :
    LVal {
        $$ = $1;
    }
    | 
    INTEGER {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::constType, $1);
        $$ = new Constant(se);
    }
    
    |
    LPAREN Exp RPAREN  {
        $$ = $2;
    }
    |
     FuncCallExp   {
        $$ = $1;
    }
   
    ;
    
    
AddExp
    :
    
    AddExp ADD Factor
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::ADD, $1, $3);
    }
    |
    AddExp SUB Factor
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::SUB, $1, $3);
    }
    
    |
  Factor
  {$$ = $1;}
  
    
    ;

    
Factor:

 UnaryExp {$$ = $1;}
 |
  Factor MUL UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MUL, $1, $3);
    }
    |
    Factor DIV UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::DIV, $1, $3);
    }
    |
    Factor REM UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::REM, $1, $3);
    }
   
    ;  
    
    
    
    
    
    
    
    
    
    
    
    
UnaryExp
:
    ADD  UnaryExp
    {
            SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            $$ = new UnaryExp(se, UnaryExp::ADD, $2);
    }
   |
   SUB UnaryExp
   {
            SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            $$ = new UnaryExp(se, UnaryExp::SUB, $2);
   }
   |
   NOT UnaryExp
   {
            SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            $$ = new UnaryExp(se, UnaryExp::NOT, $2);
   }
   |
   PrimaryExp
   {
   
    $$ =$1;
   }
   ;
   

    
    
    
    
    
//这里应该要修改 添加GREAT的情况
RelExp
    :
    AddExp {$$ = $1;}
    
    |
    RelExp LESS AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESS, $1, $3);
    }
    |

    //--------------------------逻辑运算
     RelExp GTR AddExp
    {
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		$$ = new BinaryExpr(se, BinaryExpr::GTR, $1, $3);
	}
	|
	RelExp EQ AddExp
	{
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		$$ = new BinaryExpr(se, BinaryExpr::EQ, $1, $3);
	}
	|
	RelExp NEQ AddExp
	{
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		$$ = new BinaryExpr(se, BinaryExpr::NEQ, $1, $3);
	}
	|
	RelExp GEQ AddExp
	{
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		$$ = new BinaryExpr(se, BinaryExpr::GEQ, $1, $3);
	}
	|
	RelExp LEQ AddExp
	{
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		$$ = new BinaryExpr(se, BinaryExpr::LEQ, $1, $3);
	}
    ;
    
    
    
    
    
    ;
    
LAndExp
    :
    RelExp {$$ = $1;}
    |
    LAndExp AND RelExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::AND, $1, $3);
    }
    ;
LOrExp
    :
    LAndExp {$$ = $1;}
    |
    LOrExp OR LAndExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::OR, $1, $3);
    }
    ;
Type
    : INT {
        $$ = TypeSystem::intType;
    }
    | VOID {
        $$ = TypeSystem::voidType;
    }
    ;

 
AssignStmt
    :
    LVal ASSIGN Exp SEMICOLON {
        $$ = new AssignStmt($1, $3);
    }
   
    ;    





LVal//定义变量左值
    : ID {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new Id(se);
        delete []$1;
    }
    ;    
    
    
DeclStmt
    : VarDeclStmt {$$=$1;}
    
    |
    ConstDeclstmt {$$=$1;}
   
    ;
//处理常量部分
constIdlist   
: constIdlist COMMA constId {
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        $$=new Idlist(st,$1,$3);
    }
    | constId {$$=$1;}
    ;
    
ConstDeclstmt:
    CONST 
    Type  constIdlist SEMICOLON
    {
        $$=new ConstDeclstmt($3);
        
        /*SymbolEntry *se=identifiers->search_inthis($3);
        if(se!=NULL)
        {
            fprintf(stderr, "常量 \"%s\" is 重定义\n", (char*)$3);
            delete [](char*)$3;
            assert(se != nullptr);
        }
        SymbolEntry *se1;
        se1 = new IdentifierSymbolEntry(TypeSystem::constType, $3, identifiers->getLevel());
        identifiers->install($3, se1);
        $$ = new ConstDeclstmt(new ConstId(se1));
        delete []$3;*/
    }
    ;
    


constId//常量必须要赋予初值
    : 
    ID ASSIGN Exp{
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::constType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        $$=new DAssignStmt(st,new Id(se),$3);
    }
    ;    
 
//处理变量部分
VarDeclStmt
    : Type varIdlist SEMICOLON{
        $$=new VarDeclstmt($2);
    }
    ;
varIdlist
    : varIdlist COMMA varId {
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new Idlist(st,$1,$3);//可以和常量通用
    }
    | varId {$$=$1;}
    ;
    
varId
    : varlval {
        $$ = $1;
    }
    | ID ASSIGN Exp{
        SymbolEntry *se=identifiers->search_inthis($1);
        if(se!=NULL)
        {
            fprintf(stderr, "变量 \"%s\" is 重定义\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
         $$=new DAssignStmt(st,new Id(se),$3);
        delete []$1;

    }
    ;
varlval
    :ID {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new Decvar(st,new Id(se));
        delete []$1;
    }
//函数部分：--------------------------------------------------------------------

//函数定义的参数列表
Params:

  Param 
   {
    //para_num+=1;
    //fprintf(stderr,"miaomiaomiao\n");
     def_fun.plus();
     SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
     
     
    Param* tmp=static_cast<Param*>($1);
    SymbolEntry *se1=tmp->getSymPtr();
    Type* paratype =se1->getType();
    
    func_para.push(paratype);
    $$ = new Params(st,$1,NULL);
    
   }
    |
    
  Params COMMA Param
   {
    SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
    Param* tmp=static_cast<Param*>($1);
    SymbolEntry *se1=tmp->getSymPtr();
    Type* paratype =se1->getType();
    
    //param_Type.push_back(paratype);
    //para_num+=1;
    
     def_fun.plus();
     func_para.push(paratype);
//     fprintf(stderr,"!!!!!!\n");
    $$ = new Params(se,$3,$1);//注意这里先放入param

    }
    ;

Param:
    Type ID
    {
    SymbolEntry *se1=identifiers->search_inthis($2);
    //fprintf(stderr,"ID is: %s\n", (char*)$2);
        if(se1!=NULL)
        {
            fprintf(stderr, "参数 \"%s\" is 重定义\n", (char*)$2);
            delete [](char*)$2;
            assert(se1 != nullptr);
        }
    SymbolEntry *se2 = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
    SymbolEntry *se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
    
    fprintf(stderr,"ID: %s getlabel: %d, getlevel: %d\n", (char*)$2, SymbolTable::getLabelnotInc(), identifiers->getLevel());
    ast.AllFuncParams.push_back(SymbolTable::getLabelnotInc());
    identifiers->install($2, se);//当前定义的函数是在上一个作用域的se:level=1
    //identifiers->install($2, se2);//testtesttest
    $$ = new Param(se2,new Id(se));//se2:label=3 se:level=1
    //fprintf(stderr,"push_front: %s\n",se2->toStr().c_str());
    fprintf(stderr,"param: %s done!\n",(char*)$2);
    delete []$2;
}
;


//函数调用的参数列表
Paramlist:

    Paramlist  COMMA Exp 
    {
    SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            
        //use_num+=1;
    call_fun.plus();
        $$ =new Paramlist(st,$1,$3);

    }
    | 
        Exp 
    {
    //use_num+=1;
    SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
    call_fun.plus();
    $$ =new Paramlist(st,$1,NULL);
    
    }

;


FuncDef
    :
    
    Type ID LPAREN 
    
{  

       // para_num=0;//--------------重置参数个数
     //   fprintf(stderr, "断点1\n");
         
         def_fun.reset();
        
        func_para.reset();
        
        //fprintf(stderr,"why!!!1\n");
        //进入左括号 即进入新的作用域
        identifiers = new SymbolTable(identifiers);
        
    }



    Params  RPAREN
    
    BlockStmt
    {
   
   // fprintf(stderr, "断点2\n");
    //还需要把参数作用域释放
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
       
       
        //对函数进行定义
        int num=def_fun.ret_num();
        Type *funcType;
        funcType = new FunctionType($1,func_para.get(),num);//由于有参数 要把参数列表 参数个数输入
        
        
        
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, $2, identifiers->getLevel());
        identifiers->install($2, se);//当前定义的函数是在上一个作用域的
        
        
        //在这里判断函数返回类型和定义类型是否相同
       SymbolEntry *se1;
        se1 = identifiers->lookup($2);
        
        //fprintf(stderr, "  break 3\n");
       int rt=static_cast<CompoundStmt*>($7)->getrt();
        std::string return_t = se1->getType()->toStr();
        if(rt==0)
        {
            if(return_t!="void()")
            {
                fprintf(stderr, "int函数 %s 返回类型错误!\n", (char*)$2);
                //fprintf(stderr, "rt %d \n", rt);
                assert(rt!=0);
            }
        }
        else{
         //fprintf(stderr, "当前rt rt %d \n", rt);
            if(return_t=="void()")
            {
                fprintf(stderr, "void函数 %s 返回类型错误!\n", (char*)$2);
                assert(rt!=1);
            }
        }
        
        
        assert(se != nullptr);
        $$ = new FunctionDef(se,$7,$5,func_para.get());
       
      
        delete []$2;
      //  fprintf(stderr, "函数调用断点2\n");
         //fprintf(stderr, "断点3\n");
          //fprintf(stderr, "  break 1\n"); // 到此没问题
    }
    
 |
 
 
  Type ID LPAREN  {

        
        
        //进入左括号 即进入新的作用域 即便没有参数
        identifiers = new SymbolTable(identifiers);
        
    }
    RPAREN {
  
       
    }
    
     BlockStmt
    {
    //还需要把参数作用域释放
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        
        Type *funcType;
        funcType = new FunctionType($1,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, $2, identifiers->getLevel());
        identifiers->install($2, se);//当前定义的函数是在上一个作用域的
        
        
        
       
        $$ = new FunctionDef(se,$7);
        
        
        int rt=static_cast<CompoundStmt*>($7)->getrt();
        std::string return_t = se->getType()->toStr();
 //fprintf(stderr, "断点3\n");
 
 
        if(rt==0)
        {
       // fprintf(stderr, "rt %d \n", rt);
        //fprintf(stderr, "rt %s \n", return_t.c_str());
            if(return_t!="void()")
            {
                fprintf(stderr, "函数 %s 返回类型错误!\n", (char*)$2);
                
                assert(rt!=0);
            }
        }
        else{
        //fprintf(stderr, "rt %d \n", rt);
        //fprintf(stderr, "rt %s \n", return_t.c_str());
            if(return_t=="void()")
            {
                fprintf(stderr, "函数 %s 返回类型错误!\n", (char*)$2);
                assert(rt!=1);
            }
        }
        
        
        //fprintf(stderr, "断点4\n");
        /*SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;*/

        delete []$2;
        //fprintf(stderr, "断点5\n");
        
        // fprintf(stderr, "  break 1\n"); // 到此没问题
    }
 
    ;



FuncCallExp

:
    ID   LPAREN  
{


//fprintf(stderr, "函数调用 断点1");
 
 call_fun.reset();
}
Paramlist    RPAREN  

    {
    //fprintf(stderr, "函数调用 断点1");
    //调用函数时不用检查sysy运行时库的函数
    if(($1)!=(char*)"putf")
     {  
         SymbolEntry *se;
            se = identifiers->lookup($1);
            
            if(se==NULL)
            {
                fprintf(stderr, "函数 %s 没有声明 \n", (char*)$1);
                delete [](char*)$1;
                assert(se != NULL);
            }
            
            
            Type * tmp=se->getType();
            FunctionType* temp=static_cast<FunctionType*>(tmp);
            int cor_num=temp->getnum();//定义时候的参数个数
            
              int paranum=call_fun.ret_num();//调用时函数个数
            if(cor_num!=paranum)
            {
                fprintf(stderr, "函数调用 %s 输入参数错误\n", (char*)$1);
                  assert(cor_num==paranum);
            
            }
            
            SymbolEntry *se1 = new TemporarySymbolEntry(se->getType(), SymbolTable::getLabel());
            $$ = new FuncCallExp(se1,se,$4,cor_num);
            
            //fprintf(stderr, "函数调用 断点2");
        }
    }
    |
    ID   LPAREN   RPAREN  
    {
        if(($1)!=(char*)"putf")
         {  
            SymbolEntry *se;
            se = identifiers->lookup($1);
            
            if(se==NULL)
            {
                fprintf(stderr, "函数 %s 没有声明 \n", (char*)$1);
                delete [](char*)$1;
                assert(se != NULL);
            }
             //fprintf(stderr, "调用断点1 \n");
             
            Type * tmp=se->getType();
            FunctionType* temp=static_cast<FunctionType*>(tmp);
            int cor_num=temp->getnum();//定义时候的参数个数
            
            if(cor_num!=0)
            {
                fprintf(stderr, "函数调用 %s 输入参数错误\n", (char*)$1);
                  assert(cor_num==0);
            
            }
        
            
            SymbolEntry *se1 = new TemporarySymbolEntry(se->getType(), SymbolTable::getLabel());
            $$ = new FuncCallExp(se1,se,NULL,0);
            // fprintf(stderr, "调用断点2 \n");
        }
    }
;

//处理putint等函数
PutInchars
    :
    STRING
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::voidType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new PutInchars(se);
        delete []$1;
    }
    ;    

putsFunc
    :
    PUTF LPAREN PutInchars COMMA Paramlist RPAREN SEMICOLON {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "Putint库函数 \"%s\" 未定义\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new putsFunc(new Id(se),$3,$5);
    }
    |
    PUTF LPAREN PutInchars RPAREN SEMICOLON {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "Putint库函数 \"%s\" 未定义\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new putsFunc(new Id(se),$3);
    }
    ;

    
%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}




