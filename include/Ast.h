#ifndef __AST_H__
#define __AST_H__

//#include <vector>
#include <fstream>
#include "Operand.h"

class SymbolEntry;
class Unit;
class Function;
class BasicBlock;
class Instruction;
class IRBuilder;

class if_iscond
{
   public:
    int is_cond;
    if_iscond(){is_cond=0;};
    int judge(){return is_cond;};
    
};

static if_iscond JUDGE;

class Node
{
private:
    static int counter;
    int seq;
protected:
    std::vector<Instruction*> true_list;
    std::vector<Instruction*> false_list;
    static IRBuilder *builder;
    void backPatch(std::vector<Instruction*> &list, BasicBlock*bb);
    
    void unbackPatch(std::vector<Instruction*> &list, BasicBlock*bb);
    std::vector<Instruction*> merge(std::vector<Instruction*> &list1, std::vector<Instruction*> &list2);

public:
    Node();
    int getSeq() const {return seq;};
    static void setIRBuilder(IRBuilder*ib) {builder = ib;};
    virtual void output(int level) = 0;
    virtual void typeCheck() = 0;
    virtual void genCode() = 0;
    std::vector<Instruction*>& trueList() {return true_list;}
    std::vector<Instruction*>& falseList() {return false_list;}
};

class ExprNode : public Node
{
public:
    SymbolEntry *symbolEntry;
    //注意继承类需要对dst进行初始化
    Operand *dst;   // The result of the subtree is stored into dst.
//public://dyt modify
    ExprNode(SymbolEntry *symbolEntry) : symbolEntry(symbolEntry){
        
        this->dst=new Operand(symbolEntry);
    };
    //ExprNode()  {};
    Operand* getOperand() {return dst;};
    SymbolEntry* getSymPtr() {return symbolEntry;};
};

class BinaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr1, *expr2;
public:
    enum {ADD, MUL,DIV,REM,  SUB, AND, OR, LESS,     NEQ , LEQ , GEQ,  EQ  ,  GTR    };
    BinaryExpr(SymbolEntry *se, int op, ExprNode*expr1, ExprNode*expr2) : ExprNode(se), op(op), expr1(expr1), expr2(expr2){dst = new Operand(se);};
    void output(int level);
    void typeCheck();
    void genCode();
};

//一元运算符
class UnaryExp : public ExprNode
{
private:
    int op;
    ExprNode *expr1;
public:
//这里我额外添加乘除
    enum {ADD, SUB,NOT};
    UnaryExp(SymbolEntry *se, int op, ExprNode*expr1) : ExprNode(se), op(op), expr1(expr1){dst = new Operand(se);};
    void output(int level);
     void typeCheck();
    void genCode();
};


class Constant : public ExprNode
{
public:
    Constant(SymbolEntry *se) : ExprNode(se){dst = new Operand(se);};
    void output(int level);
    void typeCheck();
    void genCode();
};

class Id : public ExprNode
{
public:
    Id(SymbolEntry *se) : ExprNode(se){
        SymbolEntry *temp = new TemporarySymbolEntry(se->getType(), SymbolTable::getLabel());
        dst = new Operand(temp);
        //fprintf(stderr,"in class id: %s\n",this->dst->toStr().c_str());
    };
    void output(int level);
    void typeCheck();
    void genCode();
};

class ConstId : public ExprNode
{
public:
    ConstId(SymbolEntry *se) : ExprNode(se){SymbolEntry *temp = new TemporarySymbolEntry(se->getType(), SymbolTable::getLabel()); dst = new Operand(temp);};
    void output(int level);
    void typeCheck();
    void genCode();
};
class StmtNode : public Node
{
    /*StmtNode(StmtNode *stmt=NULL) : stmt(stmt) {};
    void output(int level);
    void typeCheck();
    void genCode();*/
};

/*
class AssignExp : public ExprNode
{
private:
    ExprNode *lval;
    
    ExprNode *expr;
    
public:
    AssignExp(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr) {};
   
    void output(int level);
    void typeCheck();
    void genCode();
};*/
//定义实数列表
class Paramlist : public ExprNode
{
private:
    ExprNode *exp1;
    ExprNode *exp2;//应该是函数体
public:
    //Paramlist(ExprNode *exp1,ExprNode *exp2) : exp1(exp1), exp2(exp2) {};
    Paramlist(SymbolEntry*se,ExprNode *exp1,ExprNode *exp2) :ExprNode(se), exp1(exp1), exp2(exp2) {};
    //Paramlist(ExprNode *exp1): exp1(exp1), exp2(NULL){};
    void output(int level);
    void typeCheck();
    void genCode();
};

class FuncCallExp : public ExprNode
{
private:
    Id *id;
    SymbolEntry *st;
    ExprNode *params;//应该是函数体
    int param_num;//调用时输入的参数
public:
    
    FuncCallExp(SymbolEntry*se,SymbolEntry*st,ExprNode *params=NULL,int param_num=0
    ) :ExprNode(se), st(st),params(params),param_num(param_num){};
    FuncCallExp(SymbolEntry*se,Id *id) : ExprNode(se),id(id),params(NULL){};
    
    
    int getparam_num(){return param_num;};
    void output(int level);
     void typeCheck();
    void genCode();
};





class CompoundStmt : public StmtNode
{
private:
    StmtNode *stmt;
    int rt;
public:
    CompoundStmt(StmtNode *stmt=NULL,int rt=1) : stmt(stmt),rt(rt) {};
    int getrt(){return rt;};
    void output(int level);
    void typeCheck();
    void genCode();
};





class SeqNode : public StmtNode
{
private:
    StmtNode *stmt1, *stmt2;
    int rt;
public:
    //int rt;
    SeqNode(StmtNode *stmt1, StmtNode *stmt2,int rt=1) : stmt1(stmt1), stmt2(stmt2),rt(rt){};
    SeqNode(StmtNode *stmt1, int rt=1) : stmt1(stmt1), stmt2(NULL),rt(rt){};
    int getrt(){return rt;};
    void output(int level);
    void typeCheck();
    void genCode();
};

class ADDstmt : public StmtNode
{
private:
    
    
    ExprNode *expr;
    
public:
    ADDstmt(ExprNode *expr) : expr(expr) {};
   
    void output(int level);
    void typeCheck();
    void genCode();
};


class ConstDecAndAssStmt : public StmtNode
{
private:
    ConstId *id;
    ExprNode *expr;
    
public:
    ConstDecAndAssStmt(ConstId *id, ExprNode *expr) : id(id), expr(expr) {};
    void output(int level);
    void typeCheck();
    void genCode();
};


class ConstDeclstmt : public StmtNode
{
private:
    ExprNode* expr;
public:
    ConstDeclstmt(ExprNode* expr) : expr(expr){};
    
    void output(int level);
    void typeCheck();
    void genCode();
};



class Idlist: public ExprNode
{
private:
    ExprNode* expr1;
    ExprNode* expr2;
public:
    Idlist(SymbolEntry *se,ExprNode* expr1,ExprNode* expr2):ExprNode(se),expr1(expr1),expr2(expr2){};
    void output(int level);
    void typeCheck();
    void genCode();
};



class VarDeclstmt: public StmtNode
{
private:
    ExprNode* expr1;
public:
    VarDeclstmt(ExprNode* expr1):expr1(expr1){};
    void output(int level);
    void typeCheck();
    void genCode();
};

class Decvar : public ExprNode
{
private:
    Id *id;
public:
    Decvar(SymbolEntry *se,Id *id):ExprNode(se),id(id){};
    void output(int level);
    void typeCheck();
    void genCode();
};



class DAssignStmt : public ExprNode
{
private:
    Id *id;
    ExprNode *expr;
    
public:
    DAssignStmt(SymbolEntry *se,Id *id, ExprNode *expr) :ExprNode(se), id(id), expr(expr) {};
    void output(int level);
    void typeCheck();
    void genCode();
};

class DeclStmt : public StmtNode
{
private:
    Id *id;
    DAssignStmt *dassignStmt;//没用
public:
    DeclStmt(Id *id) : id(id),dassignStmt(NULL){};
    DeclStmt(Id *id,DAssignStmt *dassignStmt) : id(id),dassignStmt(dassignStmt)  {};
    void output(int level);
    void typeCheck();
    void genCode();
};

class MVA : public StmtNode
{
private:
    Id *id;
    StmtNode *ass;
    
public:
    MVA(Id *id) : id(id),ass(NULL){};
    MVA(StmtNode *ass) : id(NULL),ass(ass){};
    void output(int level);
    void typeCheck();
    void genCode();
};

class VA : public StmtNode
{
private:
    Id *id;
    StmtNode *ass;
    
public:
    VA(Id *id) : id(id),ass(NULL){};
    VA(StmtNode *ass) : id(NULL),ass(ass){};
    void output(int level);
    void typeCheck();
    void genCode();
};


class VAs : public StmtNode
{
private:
    StmtNode *va1;
    StmtNode *va2;
    
public:
    //VAs(StmtNode *vas) : vas(vas),va(NULL){};
    VAs(StmtNode *va) : va1(va),va2(NULL){};
    VAs(StmtNode *va1,StmtNode *va2) : va1(va1),va2(va2)  {};
    void output(int level);
    void typeCheck();
    void genCode();
};
class MVAs : public StmtNode
{
private:
    StmtNode *va1;
    StmtNode *va2;
    
public:
    //VAs(StmtNode *vas) : vas(vas),va(NULL){};
    MVAs(StmtNode *va) : va1(va),va2(NULL){};
    MVAs(StmtNode *va1,StmtNode *va2) : va1(va1),va2(va2)  {};
    void output(int level);
    void typeCheck();
    void genCode();
};





class MULdecstmt : public StmtNode
{
private:
    StmtNode *vas1;
    StmtNode *vas2;
public:
    MULdecstmt(StmtNode *vas1,StmtNode *vas2) : vas1(vas1),vas2(vas2){};
    //DeclStmt(Id *id,DAssignStmt *dassignStmt) : id(id),dassignStmt(dassignStmt)  {};
    void output(int level);
    void typeCheck();
    void genCode();
};


class MULconstdecstmt : public StmtNode
{
private:
    StmtNode *vas1;
    StmtNode *vas2;
public:
    MULconstdecstmt(StmtNode *vas1,StmtNode *vas2) : vas1(vas1),vas2(vas2){};
    //DeclStmt(Id *id,DAssignStmt *dassignStmt) : id(id),dassignStmt(dassignStmt)  {};
    void output(int level);
    void typeCheck();
    void genCode();
};


class IfStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
    int rt;
public:
int getrt(){return rt;};
    IfStmt(ExprNode *cond, StmtNode *thenStmt,int rt) : cond(cond), thenStmt(thenStmt),rt(rt){};
    void output(int level);
    void typeCheck();
    void genCode();
};

class IfElseStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
    StmtNode *elseStmt;
    int rt;
public:
int getrt(){return rt;};
    IfElseStmt(ExprNode *cond, StmtNode *thenStmt, StmtNode *elseStmt,int rt) : 
    cond(cond), thenStmt(thenStmt), elseStmt(elseStmt),rt(rt) {};
    void output(int level);
    void typeCheck();
    void genCode();
};

class ReturnStmt : public StmtNode
{
private:
    //StmtNode *retValue;
    ExprNode *retValue1;
    int rt;
public:
    //int rt;
    ReturnStmt(int rt=1) : retValue1(NULL),rt(rt) {};
    int getrt(){return rt;};
    ReturnStmt(ExprNode*retValue1,int rt=1) : retValue1(retValue1),rt(rt) {};
    void output(int level);
    void typeCheck();
    void genCode();
};


class Whilestmt : public StmtNode
{
private:
    ExprNode *Cond;
    StmtNode *stmt;
public:
    Whilestmt(ExprNode *Cond, StmtNode *stmt) : Cond(Cond), stmt(stmt) {};
    void output(int level);
    void typeCheck();
    void genCode();
};


//定义形参列表
class Params : public ExprNode
{
private:
    ExprNode *exp1;
    ExprNode *exp2;//应该是函数体
public:
    //Params(ExprNode *exp1,ExprNode *exp2) : exp1(exp1), exp2(exp2) {};
   // Params(ExprNode *exp1): exp1(exp1), exp2(NULL){};
    
    Params(SymbolEntry *se1,ExprNode *exp1,ExprNode *exp2=NULL) :ExprNode(se1), exp1(exp1), exp2(exp2) {};
    //Params(): exp1(NULL), exp2(NULL){};
    void output(int level);
    void typeCheck();
    void genCode();
};

class Param : public ExprNode
{
private:
    Id *id;
    ExprNode* expr1;
public:
    Param(SymbolEntry *se1,Id *id,ExprNode* expr1=NULL) : ExprNode(se1),id(id),expr1(expr1) {};
    
    void output(int level);
    void typeCheck();
    void genCode();
};


class FunctionDef : public StmtNode
{
private:
    SymbolEntry *se;
    StmtNode *stmt;//应该是函数体
    ExprNode* params;
    int paranum;//定义时的参数个数
    std::vector<Type*> params_type;
public:
    FunctionDef(SymbolEntry *se, StmtNode *stmt,ExprNode* params=NULL,std::vector<Type*> params_type={}):se(se), stmt(stmt),params(params),params_type(params_type){};
    

    //FunctionDef(SymbolEntry *se, ExprNode* params,StmtNode *stmt) : se(se), stmt(stmt),params(params){};
    //FunctionDef(SymbolEntry *se, StmtNode *stmt) : se(se), stmt(stmt),params(NULL){};
    void output(int level);
    void typeCheck();
    void genCode();
    
     SymbolEntry * getSym(){return se;};
    std::vector<Type*> get_params(){return params_type;};
};

class Funcname : public StmtNode
{
private:
    Id *id;
    
public:
    Funcname(Id *id) : id(id){};
    void output(int level);
    void typeCheck();
    void genCode();
};


class FuncCall : public StmtNode
{
private:
    ExprNode* expr;
    StmtNode *id;
    Paramlist *params;//应该是函数体
public:
    FuncCall(StmtNode *id,Paramlist *params) : id(id),params(params){};
    FuncCall(StmtNode *id) : id(id),params(NULL){};
    FuncCall(ExprNode *expr):expr(expr){};
    void output(int level);
    void typeCheck();
    void genCode();
};


class Emptystmt : public StmtNode
{
private:
    ExprNode* varInstruction;
    
public:
    
    Emptystmt(ExprNode* varInstruction=NULL):varInstruction(varInstruction)  {};
    void output(int level);
    void typeCheck();
    void genCode();
};


class AssignStmt : public StmtNode
{
private:
    ExprNode *lval;
    ExprNode *expr;
public:
    AssignStmt(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr) {};
    AssignStmt(ExprNode *expr) : lval(NULL), expr(expr) {};
    void output(int level);
    void typeCheck();
    void genCode();
};

class putsFunc : public StmtNode
{
private:
    ExprNode* expr1;
    ExprNode *expr2;
    ExprNode* expr3;
public:
    putsFunc(ExprNode* expr1,ExprNode* expr2,ExprNode* expr3=nullptr):expr1(expr1),expr2(expr2),expr3(expr3){};
    void output(int level);
    void genCode();
    void typeCheck();
};
class PutInchars : public ExprNode
{
public:
    PutInchars(SymbolEntry *se) : ExprNode(se){};
    void output(int level);
    void genCode();
    void typeCheck();
};
#include<deque>
class Ast
{
private:
    Node* root;
public:
    Ast() {root = nullptr;}
    void setRoot(Node*n) {root = n;}
    void output();
    void typeCheck();
    void genCode(Unit *unit);
    std::deque<int> AllFuncParams;//dyt add
};

#endif
