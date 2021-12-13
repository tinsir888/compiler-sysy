#ifndef __AST_H__
#define __AST_H__

#include <fstream>

class SymbolEntry;

class Node
{
private:
    static int counter;//静态变量用于标识节点的序号
    int seq;//本节点的序号，我们每构造一个节点就往后+1
public:
    Node();
    int getSeq() const {return seq;};
    virtual void output(int level) = 0;
};

class ExprNode : public Node
{
protected:
    SymbolEntry *symbolEntry;//符号表的表项
public:
    ExprNode(SymbolEntry *symbolEntry) : symbolEntry(symbolEntry){};
};

class BinaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr1, *expr2;
public:
    enum {ADD, SUB, MUL,DIV,AND, OR, XOR,LESS,LARGE,ASSIGN,MOD,EQU,NOEQU,LARAND,LESAND};
    BinaryExpr(SymbolEntry *se, int op, ExprNode*expr1, ExprNode*expr2) : ExprNode(se), op(op), expr1(expr1), expr2(expr2){};
    void output(int level);
};

class HitoExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr;
public:
    enum {ADD, SUB,NOT};
    HitoExpr(SymbolEntry *se, int op, ExprNode*expr) : ExprNode(se), op(op), expr(expr){};
    void output(int level);
};

class Constant : public ExprNode
{
private:
    int lvp;
public:
    Constant(SymbolEntry *se,int lvp=0) : ExprNode(se),lvp(lvp){};
    void output(int level);
};


class Parm : public ExprNode
{

};

class Id : public ExprNode
{
public:
    Id(SymbolEntry *se) : ExprNode(se){};
    void output(int level);
};

class Array :public ExprNode
{
private:
    ExprNode* id;
    ExprNode* expr1;
public:
    Array(SymbolEntry *se,ExprNode*id,ExprNode*expr1=nullptr):ExprNode(se),id(id),expr1(expr1){};
    void output(int level);
};

class String : public ExprNode
{
public:
    String(SymbolEntry *se) : ExprNode(se){};
    void output(int level);
};

class StmtNode : public Node
{


};

class CompoundStmt : public StmtNode
{
private:
    StmtNode *stmt;
public:
    CompoundStmt(StmtNode *stmt=nullptr) : stmt(stmt) {};
    void output(int level);
};

class SeqNode : public StmtNode
{
private:
    StmtNode *stmt1, *stmt2;
public:
    SeqNode(StmtNode *stmt1, StmtNode *stmt2) : stmt1(stmt1), stmt2(stmt2){};
    void output(int level);
};

class Decl_id : public ExprNode
{
private:
    Id *id;
public:
    Decl_id(SymbolEntry *se,Id *id):ExprNode(se),id(id){};
    void output(int level);
};

class Decl_Assign : public ExprNode
{
private:
    Id *id;
    ExprNode *interger;
public:
    Decl_Assign(SymbolEntry *se,Id *id,ExprNode* interger):ExprNode(se),id(id),interger(interger){};
    void output(int level);
};

class Decl_Array: public ExprNode
{
private:
    ExprNode *Array_id;
    ExprNode *interger;
public:
    Decl_Array(SymbolEntry *se,ExprNode* Array_id,ExprNode* interger=nullptr):ExprNode(se),Array_id(Array_id),interger(interger){};
    void output(int level);
};

class Array_assign: public ExprNode
{
private:
    ExprNode* Array_id;
    ExprNode* Initial;
public:
    Array_assign(SymbolEntry *se,ExprNode* Array_id,ExprNode* Initial=nullptr):ExprNode(se),Array_id(Array_id),Initial(Initial){};
    void output(int level);
};

class InitValList: public ExprNode
{
private:
    ExprNode* Array_id;
    ExprNode* Initial;
public:
    InitValList(SymbolEntry *se,ExprNode* Array_id,ExprNode* Initial=nullptr):ExprNode(se),Array_id(Array_id),Initial(Initial){};
    void output(int level);
};

class constInstructions: public ExprNode
{
private:
    ExprNode* preInstruct;
    ExprNode* lastInstruct;
public:
    constInstructions(SymbolEntry *se,ExprNode* pre,ExprNode* last):ExprNode(se),preInstruct(pre),lastInstruct(last){};
    void output(int level);
};

class varInstructions: public ExprNode
{
private:
    ExprNode* preInstruct;
    ExprNode* lastInstruct;
public:
    varInstructions(SymbolEntry *se,ExprNode* pre,ExprNode* last):ExprNode(se),preInstruct(pre),lastInstruct(last){};
    void output(int level);
};

class InitVal: public ExprNode
{
private:
    ExprNode* Initial;
    ExprNode* interger;
public:
    InitVal(SymbolEntry *se,ExprNode* Initial=nullptr,ExprNode* interger=nullptr):ExprNode(se),Initial(Initial),interger(interger){};
    void output(int level);
};

class varDecl_stmt: public StmtNode
{
private:
    ExprNode* varInstruction;
public:
    varDecl_stmt(ExprNode* varInstruction):varInstruction(varInstruction){};
    void output(int level);
};

class funcFParam: public ExprNode
{
private:
    Id* Param;
    ExprNode* arry;
public:
    funcFParam(SymbolEntry *se,Id *Param=nullptr,ExprNode* arry=nullptr):ExprNode(se),Param(Param){};
    void output(int level);
};
class funcFParams: public ExprNode
{
private:
    ExprNode* prevParam;
    ExprNode* lastParam;
public:
    funcFParams(SymbolEntry *se,ExprNode *lastParam,ExprNode* prevParam=nullptr):ExprNode(se),prevParam(prevParam),lastParam(lastParam){};
    void output(int level);
};
class FuncArraylist:public ExprNode
{
private:
    ExprNode* empty;
    ExprNode* Expr1;
public:
    FuncArraylist(SymbolEntry *se,ExprNode *empty=nullptr,ExprNode* Expr1=nullptr):ExprNode(se),empty(empty),Expr1(Expr1){};
    void output(int level);
};
class Rea_funcParam: public ExprNode
{
private:
    ExprNode* Param;
public:
    Rea_funcParam(SymbolEntry *se,ExprNode *Param):ExprNode(se),Param(Param){};
    void output(int level);
};

class Rea_funcParams: public ExprNode
{
private:
    ExprNode* prevParam;
    ExprNode* lastParam;
public:
    Rea_funcParams(SymbolEntry *se,ExprNode *lastParam,ExprNode* prevParam=nullptr):ExprNode(se),prevParam(prevParam),lastParam(lastParam){};
    void output(int level);   
};

class ConstDecl_stmt: public StmtNode
{
private:
    ExprNode* constInstruction;
public:
    ConstDecl_stmt(ExprNode* constInstruction):constInstruction(constInstruction){};
    void output(int level);
};

class InvalidStmt :public StmtNode
{
private:
    ExprNode* varInstruction;
public:
    InvalidStmt(ExprNode* varInstruction=nullptr):varInstruction(varInstruction){};
    void output(int level);
};

class Invalidnana : public StmtNode
{
   private:
    int op;
    ExprNode *expr1, *expr2;
public:
    enum {ADD, SUB, MUL,DIV,AND, OR, XOR,LESS,LARGE,ASSIGN,MOD,EQU,NOEQU,LARAND,LESAND};
    Invalidnana( int op, ExprNode*expr1, ExprNode*expr2) : op(op), expr1(expr1), expr2(expr2){};
    void output(int level);

};

class IfStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
public:
    IfStmt(ExprNode *cond, StmtNode *thenStmt) : cond(cond), thenStmt(thenStmt){};
    void output(int level);
};

class WhileStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *stmt;
public:
    WhileStmt(ExprNode *cond, StmtNode *Stmt) : cond(cond), stmt(Stmt){};
    void output(int level);
};

class IfElseStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
    StmtNode *elseStmt;
public:
    IfElseStmt(ExprNode *cond, StmtNode *thenStmt, StmtNode *elseStmt) : cond(cond), thenStmt(thenStmt), elseStmt(elseStmt) {};
    void output(int level);
};

class ReturnStmt : public StmtNode
{
private:
    ExprNode *retValue;
public:
    ReturnStmt(ExprNode*retValue=nullptr) : retValue(retValue) {};
    void output(int level);
};

class AssignStmt : public StmtNode
{
private:
    ExprNode *lval;
    ExprNode *expr;
public:
    AssignStmt(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr) {};
    void output(int level);
};

class FunctionDef : public StmtNode
{
private:
    SymbolEntry *se;
    StmtNode *stmt;
    ExprNode* funcFParams;
public:
    FunctionDef(SymbolEntry *se, StmtNode *stmt,ExprNode* funcFParams=nullptr):se(se), stmt(stmt),funcFParams(funcFParams){};
    void output(int level);
};

class FuncUtilStmt: public StmtNode
{
private: 
    ExprNode* functuil;
public:
    FuncUtilStmt(ExprNode* functuil):functuil(functuil){};
    void output(int level);
};

class FuncUtil : public ExprNode
{
private:
    SymbolEntry *se;
    ExprNode * parms;
public:
    FuncUtil(SymbolEntry *sp,SymbolEntry *se,ExprNode *parms=nullptr):ExprNode(sp),se(se),parms(parms){};
    void output(int level);
};


class STREAM : public StmtNode
{
private:
    ExprNode* putf;
    ExprNode *string;
    ExprNode* funcFParams;
public:
    STREAM(ExprNode* putf,ExprNode* string,ExprNode* funcFParams=nullptr):putf(putf),string(string),funcFParams(funcFParams){};
    void output(int level);
};


class Contr : public StmtNode
{
private:
    int lvp;
    ExprNode *retValue;
public:
    Contr(int lvp,ExprNode *retValue=nullptr) : lvp(lvp){};
    void output(int level);
};

class Ast
{
private:
    Node* root;
public:
    Ast() {root = nullptr;}
    void setRoot(Node*n) {root = n;}
    void output();
};

#endif
