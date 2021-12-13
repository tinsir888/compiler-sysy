#include "Ast.h"
#include "SymbolTable.h"
#include <string>
#include "Type.h"

extern FILE *yyout;
int Node::counter = 0;

Node::Node()
{
    seq = counter++;
}

void Ast::output()
{
    fprintf(yyout, "program\n");
    if(root != nullptr)
        root->output(4);
}

void BinaryExpr::output(int level)
{
    std::string op_str;
    switch(op)
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case MUL:
            op_str = "mul";
            break;
        case DIV:
            op_str = "div";
            break;
        case MOD:
            op_str = "mod";
            break;
        case AND:
            op_str = "and";
            break;
        case OR:
            op_str = "or";
            break;
        case LESS:
            op_str = "less";
            break;
        case LARGE:
            op_str = "large";
            break;
        case ASSIGN:
            op_str = "assign";
            break;
        case XOR:
            op_str = "xor";
            break;
        case EQU:
            op_str = "equ";
            break;
        case NOEQU:
            op_str = "noequ";
            break;
        case LARAND:
            op_str = "larand";
            break;
        case LESAND:
            op_str = "lesand";
            break;
    }
    fprintf(yyout, "%*cBinaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr1->output(level + 4);
    expr2->output(level + 4);
}

void HitoExpr::output(int level)
{
    std::string op_str;
    switch(op)
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case NOT:
            op_str = "not";
            break;
    }
    fprintf(yyout, "%*cHitoExpr\top: %s\n", level, ' ', op_str.c_str());
    expr->output(level + 4);
}

void Constant::output(int level)
{
    std::string type, value;
    type = symbolEntry->getType()->toStr();
    value = symbolEntry->toStr();
    switch(this->lvp)
    {
        case 0:
            fprintf(yyout, "%*cIntegerLiteral\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
            break;
        case 1:
            fprintf(yyout, "%*cHEX\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
            break;
        case 2:
            fprintf(yyout, "%*cOCT\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
            break;

    }
}

void Id::output(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->toStr();
    type = symbolEntry->getType()->toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    fprintf(yyout, "%*cId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
            name.c_str(), scope, type.c_str());
}

void Array::output(int level){
    fprintf(yyout,"%*cArray\n", level, ' ');
    id->output(level+4);
    if(this->expr1!=nullptr)
    {
    expr1->output(level+4);
    }
}

void funcFParam::output(int level){
    fprintf(yyout,"%*cfuncParam\n", level, ' ');
    Param->output(level+4);
}
void funcFParams::output(int level){
    fprintf(yyout,"%*cfuncParams\n", level, ' ');
    lastParam->output(level+4);
    prevParam->output(level+4);
}
void FuncArraylist::output(int level){
    fprintf(yyout,"%*cFuncArraylist\n", level, ' ');
    if(empty==nullptr)
        fprintf(yyout,"%*cEmpty[ ]\n", level+4, ' ');
    else
        empty->output(level+4);
    Expr1->output(level+4);
}
void Rea_funcParam::output(int level){
    fprintf(yyout,"%*cReal_funcParam\n", level, ' ');
    Param->output(level+4);
}
void Rea_funcParams::output(int level){
    fprintf(yyout,"%*cReal_funcParams\n", level, ' ');
    lastParam->output(level+4);
    prevParam->output(level+4);
}
void CompoundStmt::output(int level)
{
    fprintf(yyout, "%*cCompoundStmt\n", level, ' ');
    if(this->stmt!=nullptr)
    {
    stmt->output(level + 4);//level为我们的输出的时候的相对开始的字符偏移
    }
}

void SeqNode::output(int level)
{
    fprintf(yyout, "%*cSequence\n", level, ' ');
    stmt1->output(level + 4);
    stmt2->output(level + 4);
}

void Decl_id::output(int level)
{
    fprintf(yyout, "%*cDecl_id\n", level, ' ');
    id->output(level);
}

void constInstructions::output(int level)
{
    fprintf(yyout, "%*cconstInstructions\n", level, ' ');
    lastInstruct->output(level+4);
    preInstruct->output(level+4);
}

void varInstructions::output(int level)
{
    fprintf(yyout, "%*cvarInstructions\n", level, ' ');
    lastInstruct->output(level+4);
    preInstruct->output(level+4);
}

void Decl_Assign::output(int level)
{
    fprintf(yyout, "%*cDecl_Assign\n", level, ' ');
    id->output(level + 4);
    interger->output(level+4);
}
void Decl_Array::output(int level)
{
    fprintf(yyout,"%*cDecl_Array\n", level, ' ');
    Array_id->output(level+4);
    if(this->interger!=nullptr)
    {
    interger->output(level+4);
    }
}
void InitValList::output(int level)
{
    fprintf(yyout,"%*cArrayInitVals\n", level, ' ');
    Array_id->output(level+4);
    if(this->Initial!=nullptr)
        Initial->output(level+4);
}
void InitVal::output(int level)
{
    fprintf(yyout,"%*cArray_Initial\n", level, ' ');
    if(this->interger!=nullptr)
        interger->output(level+4);
    if(this->Initial!=nullptr)
        Initial->output(level+4);
}

void Array_assign::output(int level)
{
    fprintf(yyout,"%*cArray_assign\n", level, ' ');
    Array_id->output(level+4);
    if(this->Initial!=nullptr)
        Initial->output(level+4);
}
void ConstDecl_stmt::output(int level){
    fprintf(yyout, "%*cConstDecl_stmt\n", level, ' ');
    constInstruction->output(level+4);
}
void varDecl_stmt::output(int level){
    fprintf(yyout, "%*cvarDecl_stmt\n", level, ' ');
    varInstruction->output(level+4);
}
void InvalidStmt::output(int level){
    fprintf(yyout, "%*cInvalidStmt\n", level, ' ');
    if (varInstruction!=nullptr)
    {
        varInstruction->output(level+4);
    }
    
}
void IfStmt::output(int level)
{
    fprintf(yyout, "%*cIfStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
}

void WhileStmt::output(int level)
{
    fprintf(yyout, "%*cWhileStmt\n", level, ' ');
    cond->output(level + 4);
    stmt->output(level + 4);
}

void IfElseStmt::output(int level)
{
    fprintf(yyout, "%*cIfElseStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
    elseStmt->output(level + 4);
}

void ReturnStmt::output(int level)
{
    fprintf(yyout, "%*cReturnStmt\n", level, ' ');
    if (this->retValue!=nullptr)
    {
        retValue->output(level + 4);
    }
}

void AssignStmt::output(int level)
{
    fprintf(yyout, "%*cAssignStmt\n", level, ' ');
    lval->output(level + 4);
    expr->output(level + 4);
}


void FunctionDef::output(int level)
{
    std::string name, type;
    name = se->toStr();
    type = se->getType()->toStr();
    fprintf(yyout, "%*cFunctionDefine function name: %s, type: %s\n", level, ' ', 
            name.c_str(), type.c_str());
    if(funcFParams!=nullptr)
        funcFParams->output(level+4);
    stmt->output(level + 4);
}

void FuncUtil::output(int level)
{
    std::string name, type;
    name = se->toStr();
    type = se->getType()->toStr();
    fprintf(yyout, "%*cFunctionUtil function name: %s, type: %s\n", level, ' ', 
            name.c_str(), type.c_str());
    if(parms!=nullptr)
        parms->output(level + 4);
}
void FuncUtilStmt::output(int level){
    fprintf(yyout, "%*cFuncUtilStmt\n", level, ' ');
    functuil->output(level+4);
}
void STREAM::output(int level)
{
    fprintf(yyout, "%*cFunctUtilStmt\n", level, ' ');
    putf->output(level + 4);
    string->output(level + 4);
    if (funcFParams!=nullptr)
    {
        funcFParams->output(level+4);
    }
}

void String::output(int level)
{
    std::string strtext;
    strtext = symbolEntry->toStr();
    fprintf(yyout, "%*cString\tstrtext: %s\n", level, ' ',
            strtext.c_str());
}

void Contr::output(int level)
{
    fprintf(yyout, "%*cControl", level, ' ');
    switch(this->lvp)
    {
        case 2:
            fprintf(yyout, "Break\n");
            break;
        case 1:
            fprintf(yyout, "Continue\n");
            break;
    }
}

void Invalidnana::output(int level)
{
    std::string op_str;
    switch(op)
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case MUL:
            op_str = "mul";
            break;
        case DIV:
            op_str = "div";
            break;
        case MOD:
            op_str = "mod";
            break;
        case AND:
            op_str = "and";
            break;
        case OR:
            op_str = "or";
            break;
        case LESS:
            op_str = "less";
            break;
        case LARGE:
            op_str = "large";
            break;
        case ASSIGN:
            op_str = "assign";
            break;
        case XOR:
            op_str = "xor";
            break;
        case EQU:
            op_str = "equ";
            break;
        case NOEQU:
            op_str = "noequ";
            break;
        case LARAND:
            op_str = "larand";
            break;
        case LESAND:
            op_str = "lesand";
            break;
    }
    fprintf(yyout, "%*cInvalidExpr\top: %s\n", level, ' ', op_str.c_str());
    expr1->output(level + 4);
    expr2->output(level + 4);
}