%code top{
    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
}
%code requires {
    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"
}
%define parse.error verbose
%union {
    int itype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;
}
%start Program
%token <strtype> ID
%token <strtype> STRING
%token <itype> INTEGER OCT HEX
%token IF ELSE
%token INT VOID
%token LPAREN RPAREN LBRACE RBRACE LBRACK RBRACK SEMICOLON
%token ADD SUB OR AND LESS LARGE ASSIGN XOR MUL DIV MOD LARAND LESAND NOT
%token DECIMIAL WHILE BREAK CONTINUE CONST
%token RETURN EQU NOEQU
%token <strtype> PUTF
%token COMMA
%nterm <stmttype> Stmts Stmt InvalidStmt AssignStmt BlockStmt IfStmt ReturnStmt DeclStmt FuncDef WhileStmt STREAM ContrStmt ConstDecl VarDecl
%nterm <exprtype> Exp AddExp ConstExp MulExp Cond LOrExp LXorExp PrimaryExp FuncUtil EqExp LVal RelExp LAndExp str Arrayidentifier UnaryExp Const_Array Decl_varlva Var_Array constInstructions constInstruction InitVal InitValList FuncArraylist varInstructions varInstruction funcFParams funcFParam Rea_funcParams
%nterm <type> Type
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
        $$ = new SeqNode($1, $2);//seqNode，我们每一个节点块中存在的stmt的数量-1。反复生成stmt
    }
    ;
Stmt
    : AssignStmt {$$=$1;}
    | BlockStmt {$$=$1;}
    | IfStmt {$$=$1;}
    | ReturnStmt {$$=$1;}
    | DeclStmt {$$=$1;}
    | FuncDef {$$=$1;}
    | STREAM {$$=$1;}
    | WhileStmt {$$=$1;}
    | ContrStmt {$$=$1;}
    | InvalidStmt {$$=$1;}
    ;
Arrayidentifier//非定义声明用数组
    : ID LBRACK Exp RBRACK{
        SymbolEntry *sp;
        sp = identifiers->lookup($1);
        if(sp == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(sp != nullptr);
        }
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new Array(se,new Id(sp),$3);
    }
    | Arrayidentifier LBRACK Exp RBRACK{
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new Array(se,$1,$3);
    }
    | ID LBRACK RBRACK {
       SymbolEntry *sp;
        sp = identifiers->lookup($1);
        if(sp == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(sp != nullptr);
        }
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new Array(se,new Id(sp));
    }
    ;
LVal//非定义申明用变量
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
    | Arrayidentifier{$$=$1;}
    ;
STREAM
    :
    PUTF LPAREN str COMMA Rea_funcParams RPAREN SEMICOLON {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "Function \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new STREAM(new Id(se),$3,$5);
    }
    |
    PUTF LPAREN str RPAREN SEMICOLON {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "Function \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new STREAM(new Id(se),$3);
    }
    ;
InvalidStmt:
    SEMICOLON {
        $$ =new InvalidStmt();
    }
    | Exp SEMICOLON {
        $$ = new InvalidStmt($1);
    }
    ;
ContrStmt:
    CONTINUE SEMICOLON {$$ = new Contr(1);}
    |BREAK SEMICOLON {$$ = new Contr(2);}
    ;
str
    :
    STRING
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::voidType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new String(se);
        delete []$1;
    }
    ;
AssignStmt
    :
    LVal ASSIGN Exp SEMICOLON {
        $$ = new AssignStmt($1, $3);
    }
    ;
BlockStmt
    :   LBRACE
        {identifiers = new SymbolTable(identifiers);}
        Stmts RBRACE
        {
            $$ = new CompoundStmt($3);
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
        |
        LBRACE
        RBRACE
        {
            $$ = new CompoundStmt();
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
WhileStmt
    : WHILE LPAREN Cond RPAREN Stmt {
        $$ = new WhileStmt($3, $5);
    }
    ;
ReturnStmt
    :
    RETURN Exp SEMICOLON {
        $$ = new ReturnStmt($2);
    }
    | RETURN SEMICOLON {
        $$ = new ReturnStmt();
    }
    ;
Exp
    :
    AddExp {$$ = $1;}
    ;
ConstExp
    :
    AddExp {
        $$=$1;
    }
    ;
Cond
    :
    LOrExp {$$ = $1;}
    ;
UnaryExp
    :
    PrimaryExp {
        $$ = $1;
    }
    | ADD UnaryExp {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new HitoExpr(se, HitoExpr::ADD, $2);
    }
    | SUB UnaryExp {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new HitoExpr(se, HitoExpr::SUB, $2);
    }
    | NOT UnaryExp {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new HitoExpr(se, HitoExpr::NOT, $2);
    }
    ;
PrimaryExp
    :
    LVal {
        $$ = $1;
    }
    | INTEGER {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, $1);
        $$ = new Constant(se,0);
    }
    | OCT {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, $1);
        $$ = new Constant(se,2);
    }
    | HEX {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, $1);
        $$ = new Constant(se,1);
    }
    | LPAREN Exp RPAREN{
        $$ = $2;
    }
    | FuncUtil{
        $$=$1;
    }
    ;
AddExp
    :
    MulExp {$$ = $1;}
    |
    AddExp ADD MulExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::ADD, $1, $3);
    }
    |
    AddExp SUB MulExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::SUB, $1, $3);
    }
    ;
MulExp
    :
    UnaryExp {$$=$1;}
    |
    MulExp MUL UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MUL, $1, $3);
    }
    |
    MulExp DIV UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::DIV, $1, $3);
    }
    |
    MulExp MOD UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MOD, $1, $3);
    }
    ;
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
    RelExp LARGE AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LARGE, $1, $3);
    }
    |
    RelExp LARAND AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LARAND, $1, $3);
    }
    |
    RelExp LESAND AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESAND, $1, $3);
    }
    ;
EqExp
    :
    RelExp {$$ = $1;}
    | EqExp EQU RelExp {SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::EQU, $1, $3);}
    | EqExp NOEQU RelExp {SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NOEQU, $1, $3);}
LAndExp
    :
    EqExp {$$ = $1;}
    |
    LAndExp AND EqExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::AND, $1, $3);
    }
    ;
LXorExp
    :
    LAndExp {$$ = $1;}
    |
    LXorExp XOR LAndExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::XOR, $1, $3);
    }
    ;
LOrExp
    :
    LXorExp {$$ = $1;}
    |
    LOrExp OR LXorExp
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
/*    | CONST INT{
        $$ = TypeSystem::constType;
    }
    | CONST VOID{
        $$ = TypeSystem::constType;
    }*/
    ;
Const_Array
    :
    ID LBRACK INTEGER RBRACK {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::constType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        SymbolEntry *sp = new ConstantSymbolEntry(TypeSystem::intType, $3);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        $$ = new Decl_Array(sg,new Id(se),new Constant(sp));
        delete []$1;
    }
    |
    Const_Array LBRACK INTEGER RBRACK {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        SymbolEntry *sp = new ConstantSymbolEntry(TypeSystem::intType, $3);
        $$ = new Decl_Array(se,$1,new Constant(sp));
    }
    ;
Decl_varlva//用于定义的变量标识符
    :ID {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new Decl_id(sg,new Id(se));
        delete []$1;
    }
    |
    Var_Array {$$=$1;}
    ;
Var_Array
    :
    ID LBRACK ConstExp RBRACK {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new Decl_Array(sg,new Id(se),$3);
        delete []$1;
    }
    |
    Var_Array LBRACK ConstExp RBRACK {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new Decl_Array(se,$1,$3);
    }
    |
    ID LBRACK RBRACK{
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new Decl_Array(sg,new Id(se));
        delete []$1;
    }
    ;
DeclStmt
    : ConstDecl {$$=$1;}
    | VarDecl {$$=$1;}
    ;
ConstDecl
    :CONST Type constInstructions SEMICOLON{
        $$=new ConstDecl_stmt($3);
    }
    ;
constInstructions
    : constInstructions COMMA constInstruction {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        constInstructions(sg,$1,$3);
    }
    | constInstruction {$$=$1;}
    ;
constInstruction
    : 
    ID ASSIGN ConstExp{
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::constType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        $$=new Decl_Assign(sg,new Id(se),$3);
    }
    | Const_Array ASSIGN LBRACE InitValList RBRACE {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        $$=new Array_assign(sg,$1,$4);
    }
    ;
InitVal
    :
    Exp {$$=$1;}
    |
    LBRACE RBRACE {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new InitVal(se);
        }
    |
    LBRACE InitValList RBRACE {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new InitVal(se,$2);
    }
    ;
InitValList
    :
    InitVal {
       SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new InitValList(se,$1);
    }
    |
    InitValList COMMA InitVal {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new InitValList(se,$1,$3);
    }
    ;
VarDecl
    : Type varInstructions SEMICOLON{
        $$=new varDecl_stmt($2);
    }
    ;
varInstructions
    : varInstructions COMMA varInstruction {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new constInstructions(sg,$1,$3);
    }
    | varInstruction {$$=$1;}
    ;
varInstruction
    : Decl_varlva {
        $$ = $1;
    }
    | ID ASSIGN Exp{
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new Decl_Assign(sg,new Id(se),$3);
    }
    | Var_Array ASSIGN LBRACE InitValList RBRACE{
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new Array_assign(sg,$1,$4);
    }
    | Var_Array ASSIGN LBRACE RBRACE{
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new Array_assign(sg,$1);
    }
    ;
FuncDef
    :
    Type ID LPAREN RPAREN BlockStmt{
        Type *funcType;
        funcType = new FunctionType($1,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, $2, identifiers->getLevel());
        identifiers->install($2, se);
        identifiers = new SymbolTable(identifiers);
        se = identifiers->lookup($2);
        assert(se != nullptr);
        $$ = new FunctionDef(se, $5);
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete []$2;
    }
    |
    Type ID LPAREN{
        Type *funcType;
        funcType = new FunctionType($1,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, $2, identifiers->getLevel());
        identifiers->install($2, se);
        identifiers = new SymbolTable(identifiers);
    }
    funcFParams RPAREN
    BlockStmt
    {
        SymbolEntry *se;
        se = identifiers->lookup($2);
        assert(se != nullptr);
        $$ = new FunctionDef(se, $7,$5);
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete []$2;
    }
    ;
funcFParams
    :
    funcFParam {$$ = $1;}
    | funcFParams COMMA funcFParam {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        funcFParams(sg,$1,$3);
    }
    ;
funcFParam
    :
    Type ID{
        SymbolEntry *se;
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$=new funcFParam(sg,new Id(se));
    }
    |
    Type ID FuncArraylist{
        SymbolEntry *se;
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$=new funcFParam(sg,new Id(se),$3);
    }
    ;
FuncArraylist:
    LBRACK RBRACK{
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new FuncArraylist(sg);
    }
    |
    FuncArraylist LBRACK Exp RBRACK {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new FuncArraylist(sg,$1,$3);
    }
    ;
FuncUtil
    :
     ID LPAREN RPAREN {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new FuncUtil(sg,se);
    }
    | ID LPAREN Rea_funcParams RPAREN {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new FuncUtil(sg,se,$3);
    }
    ;
Rea_funcParams//函数实参
    :
    Exp {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$= new Rea_funcParam(sg,$1);
    }
    | Rea_funcParams COMMA Exp {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$=new Rea_funcParams(sg,$1,$3);
    }
    ;
%%
int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
