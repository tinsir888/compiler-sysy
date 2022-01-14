%code top{
    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    #include <cstring>
    #include <stack>
    extern Ast ast;

    int yylex();
    int yyerror(char const*);
    ArrayType* arrayType;
    //int idx;
   // int* arrayValue;
    std::stack<InitValueListExpr*> stk;
    std::stack<StmtNode*> whileStk;
    InitValueListExpr* top;
    int leftCnt = 0;
    int paramNo = 0;
    #include <iostream>
}

%code requires {
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
    SymbolEntry* se;
}

%start Program
%token <strtype> ID STRING
%token <itype> INTEGER
%token IF ELSE WHILE
%token INT VOID
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON LBRACKET RBRACKET COMMA  
%token ADD SUB MUL DIV MOD OR AND LESS LESSEQUAL GREATER GREATEREQUAL ASSIGN EQUAL NOTEQUAL NOT
%token CONST
%token RETURN CONTINUE BREAK

%type<stmttype> Stmts Stmt AssignStmt ExprStmt BlockStmt IfStmt WhileStmt BreakStmt ContinueStmt ReturnStmt DeclStmt FuncDef ConstDeclStmt VarDeclStmt ConstDefList VarDef ConstDef VarDefList FuncFParam FuncFParams OptFuncFParams BlankStmt
%type<exprtype> Exp AddExp Cond LOrExp PrimaryExp LVal RelExp LAndExp MulExp ConstExp EqExp UnaryExp InitVal ConstInitVal FuncArrayIndices   FuncRParams ArrayIndices
%type<type> Type

%precedence THEN
%precedence ELSE
%%

Program
    : Stmts {
        ast.setRoot($1);
    }
    ;
Stmts
    : Stmt {$$=$1;}
    | Stmts Stmt{
        $$ = new SeqNode($1, $2);
    }
    ;
Stmt
    : AssignStmt {
        $$=$1;
    }
    | ExprStmt {$$ = $1;}
    | BlockStmt {$$=$1;}
    | BlankStmt {$$ = $1;}
    | IfStmt {$$ = $1;}
    | WhileStmt {$$ = $1;}
    | BreakStmt {
        
        $$=$1;
    }
    | ContinueStmt {
        
        $$=$1;
    }
    | ReturnStmt {$$ = $1;}
    | DeclStmt {$$ = $1;}
    | FuncDef {$$ = $1;}
    ;
LVal
    : ID {
        SymbolEntry* se;
        se = identifiers->lookup($1);
        if(se == nullptr)
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
        $$ = new Id(se);
        delete []$1;
    }
    | ID ArrayIndices{
        SymbolEntry* se;
        se = identifiers->lookup($1);
        if(se == nullptr)
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
        $$ = new Id(se, $2);
        delete []$1;
    }
    ; 
AssignStmt
    : LVal ASSIGN Exp SEMICOLON {
        $$ = new AssignStmt($1, $3);
    }
    ;
ExprStmt
    : Exp SEMICOLON {
        $$ = new ExprStmt($1);
    }
    ;
BlankStmt
    : SEMICOLON {
        $$ = new BlankStmt();
    }
    ;
BlockStmt
    : LBRACE {
    //新作用域
        identifiers = new SymbolTable(identifiers);
    } 
      Stmts RBRACE {
        
        $$ = new CompoundStmt($3);

        SymbolTable* top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
    }
    | LBRACE RBRACE {
        
        $$ = new BlankStmt();
    }
    ;
IfStmt
    : IF LPAREN Cond RPAREN Stmt %prec THEN {
        $$ = new IfStmt($3, $5);
    }
    | IF LPAREN Cond RPAREN Stmt ELSE Stmt {
        $$ = new IfElseStmt($3, $5, $7);
    }
    ;
    
//-----wyx 1.7修改
WhileStmt
    : WHILE LPAREN Cond RPAREN {
        StmtNode *whileNode = new WhileStmt($3);    
        whileStk.push(whileNode);

    
    }
    Stmt {  
        StmtNode *whileNode =whileStk.top();
        ((WhileStmt*)whileNode)->setStmt($6);//设置内部stmt语句
        $$=whileNode;
        whileStk.pop();

    }
    ;
//break和continue要设置匹配的while
BreakStmt
    : BREAK SEMICOLON {
        $$ = new BreakStmt(whileStk.top());
    }
    ;
ContinueStmt
    : CONTINUE SEMICOLON {
        $$ = new ContinueStmt(whileStk.top());
    }
    ;
    
ReturnStmt
    : RETURN SEMICOLON {
        $$ = new ReturnStmt();
    }
    | RETURN Exp SEMICOLON {
        $$ = new ReturnStmt($2);
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
    : LPAREN Exp RPAREN {
        $$ = $2;
    }
    | LVal {
        $$ = $1;
    }
    | INTEGER {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::intType, $1);
        $$ = new Constant(se);
    }
    | ID LPAREN FuncRParams RPAREN {
        SymbolEntry* se;
        se = identifiers->lookup($1);
        
        $$ = new CallExpr(se, $3);
    }
    | ID LPAREN RPAREN {
        SymbolEntry* se;
        se = identifiers->lookup($1);
        
        $$ = new CallExpr(se);
    }
    ;
    
UnaryExp 
    : PrimaryExp {$$ = $1;}
    
    | ADD UnaryExp {$$ = $2;}
    
    | SUB UnaryExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::SUB, $2);
    }
    //注意NOT是Bool类型
    | NOT UnaryExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::NOT, $2);
    }
    ;
MulExp
    : UnaryExp {$$ = $1;}
    
    | 
    MulExp MUL UnaryExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MUL, $1, $3);
    }
    | 
    MulExp DIV UnaryExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::DIV, $1, $3);
    }
    | 
    MulExp MOD UnaryExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MOD, $1, $3);
    }
    ;
AddExp
    : 
    MulExp {$$ = $1;}
    | 
    AddExp ADD MulExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::ADD, $1, $3);
    }
    | 
    AddExp SUB MulExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::SUB, $1, $3);
    }
    ;
RelExp
    : 
    AddExp {
        $$ = $1;
    }
    | 
    RelExp LESS AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESS, $1, $3);
    }
    | 
    RelExp LESSEQUAL AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESSEQUAL, $1, $3);
    }
    | 
    RelExp GREATER AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATER, $1, $3);
    }
    | 
    RelExp GREATEREQUAL AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATEREQUAL, $1, $3);
    }
    ;
EqExp
    : 
    RelExp {$$ = $1;}
    | 
    EqExp EQUAL RelExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::EQUAL, $1, $3);
    }
    | 
    EqExp NOTEQUAL RelExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NOTEQUAL, $1, $3);
    }
    ;
LAndExp
    : 
    EqExp {$$ = $1;}
    | 
    LAndExp AND EqExp 
    {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::AND, $1, $3);
    }
    ;
LOrExp
    : 
    LAndExp {$$ = $1;}
    | 
    LOrExp OR LAndExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::OR, $1, $3);
    }
    ;
ConstExp
    : AddExp {$$ = $1;}
    ;
    
FuncRParams 
    : 
    Exp {$$ = $1;}
    | 
    FuncRParams COMMA Exp {
        $$ = $1;
        $$->setNext($3);//参数从左到右建立 next
    }
    
Type
    : INT {
        $$ = TypeSystem::intType;
    }
    | VOID {
        $$ = TypeSystem::voidType;
    }
    ;

DeclStmt
    : VarDeclStmt {$$ = $1;}
    | ConstDeclStmt {$$ = $1;}
    ;
    
VarDeclStmt
    : Type VarDefList SEMICOLON
    {$$ = $2;}
    ;
ConstDeclStmt
    : CONST Type ConstDefList SEMICOLON {
       
        $$ = $3;
    }
    ;
VarDefList
    : VarDefList COMMA VarDef {
        $$ = $1;
        $1->setNext($3);
    } 
    | VarDef {$$ = $1;}
    ;
ConstDefList
    : ConstDefList COMMA ConstDef {
        $$ = $1;
        $1->setNext($3);
    }
    | ConstDef {$$ = $1;}
    ;
VarDef
    : ID {
        SymbolEntry* se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
            
        $$ = new DeclStmt(new Id(se));
        delete []$1;
    }
    | ID ArrayIndices {
        SymbolEntry* se;
        std::vector<int> vec;//分别存放维度值
        ExprNode* temp = $2;
        //编译每个维度数组 从高位到低维
        while(temp){
            vec.push_back(temp->getValue());
            temp = (ExprNode*)(temp->getNext());
        }
        Type *type = TypeSystem::intType;
        Type* temp1;
        //注意是倒序 即从右向左 [2][3] 2个数组指针 每行3个整型元素
        //初始为整型元素
        while(!vec.empty()){
        //嵌套数组类型
            temp1 = new ArrayType(type, vec.back());
            //考虑多维数组 每个元素是数组指针
            //如果元素是数组 type设置为数组维度
            if(type->isArray())
                ((ArrayType*)type)->setArrayType(temp1);
            type = temp1;
            vec.pop_back();
        }
        //type保存最低维 a[2][4]即保存2对应类型
        arrayType = (ArrayType*)type;
        se = new IdentifierSymbolEntry(type, $1, identifiers->getLevel());
        
        ((IdentifierSymbolEntry*)se)->setAllZero();//zero是干什么的？
        int *p = new int[type->getSize()];//设置整型空间 即长度*大小
        ((IdentifierSymbolEntry*)se)->setArrayValue(p);
        identifiers->install($1, se);
        $$ = new DeclStmt(new Id(se));
        delete []$1;
    }
    //赋予初值的情况
    | ID ASSIGN InitVal {
        SymbolEntry* se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
           
        ((IdentifierSymbolEntry*)se)->setValue($3->getValue());
        $$ = new DeclStmt(new Id(se), $3);
        delete []$1;
    }
  
    ;
ConstDef
    : ID ASSIGN ConstInitVal {
        SymbolEntry* se;
        se = new IdentifierSymbolEntry(TypeSystem::constIntType, $1, identifiers->getLevel());
        ((IdentifierSymbolEntry*)se)->setConst();
         identifiers->install($1, se);
     
        
        ((IdentifierSymbolEntry*)se)->setValue($3->getValue());
        $$ = new DeclStmt(new Id(se), $3);
        delete []$1;
    }
   
    ;
//考虑一维和多维的情况 
//
ArrayIndices
    : LBRACKET ConstExp RBRACKET {
        $$ = $2;
    }
    | ArrayIndices LBRACKET ConstExp RBRACKET {
        $$ = $1;
        $1->setNext($3);//多维要把元素大小先后存储
    }
    ;
    
InitVal 
    : Exp {
        
        $$ = $1;
        
    }
;

ConstInitVal
    : ConstExp {
        $$ = $1;
        
    }
;
 

FuncDef
    :
    Type ID {
        identifiers = new SymbolTable(identifiers);
        paramNo = 0;//标记参数的id
    }
    LPAREN OptFuncFParams RPAREN {
        Type* funcType;
        std::vector<Type*> vec;
        std::vector<SymbolEntry*> vec1;
        
        DeclStmt* temp = (DeclStmt*)$5;
        
        while(temp){
            vec.push_back(temp->getId()->getSymbolEntry()->getType());
            vec1.push_back(temp->getId()->getSymbolEntry());
            temp = (DeclStmt*)(temp->getNext());
        }
        //输入参数类型和符号表项
        funcType = new FunctionType($1, vec, vec1);
        SymbolEntry* se = new IdentifierSymbolEntry(funcType, $2, identifiers->getPrev()->getLevel());
        identifiers->getPrev()->install($2, se);
            
        $<se>$ = se; //下面使用
    } 
    BlockStmt {
        $$ = new FunctionDef($<se>7, (DeclStmt*)$5, $8);
        SymbolTable* top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete []$2;
    }
    ;
OptFuncFParams
    : FuncFParams {$$ = $1;}
    | %empty {$$ = nullptr;}
    ;
    
    
FuncFParams
    : FuncFParams COMMA FuncFParam {
        $$ = $1;
        $$->setNext($3);//连接参数
    }
    | FuncFParam {
        $$ = $1;
    }
    ;
    
FuncFParam
    : Type ID {
        SymbolEntry* se;
        //注意这里输入label为参数的标号
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel(), paramNo++);
        identifiers->install($2, se);
        //获取label
        ((IdentifierSymbolEntry*)se)->setLabel();
        ((IdentifierSymbolEntry*)se)->setAddr(new Operand(se));
        
        $$ = new DeclStmt(new Id(se));

    }
    | Type ID FuncArrayIndices {
       
        SymbolEntry* se;
        ExprNode* temp = $3;
        Type* arr = TypeSystem::intType;
        Type* arr1;
        std::stack<ExprNode*> stk;
        //对数组维度进行遍历 放入栈中
        while(temp){
            stk.push(temp);
            temp = (ExprNode*)(temp->getNext());
        }
        //获得最低维度
        while(!stk.empty()){
            arr1 = new ArrayType(arr, stk.top()->getValue());
            if(arr->isArray())
                ((ArrayType*)arr)->setArrayType(arr1);
            arr = arr1;
            stk.pop();
        }
        se = new IdentifierSymbolEntry(arr, $2, identifiers->getLevel(), paramNo++);
        identifiers->install($2, se);
        ((IdentifierSymbolEntry*)se)->setLabel();
        ((IdentifierSymbolEntry*)se)->setAddr(new Operand(se));
        $$ = new DeclStmt(new Id(se));
        delete []$2;
    }
    ;
    
 //输入参数可能是数组 a[][3]
FuncArrayIndices 
    : LBRACKET RBRACKET {
        $$ = new ExprNode(nullptr);
    }
    | FuncArrayIndices LBRACKET Exp RBRACKET {
        $$ = $1;
        $$->setNext($3);
    }
    ;
    
%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
