#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include "Operand.h"
#include <vector>
#include <map>

class BasicBlock;

class Instruction
{
public:
    Instruction(unsigned instType, BasicBlock *insert_bb = nullptr);
    virtual ~Instruction();
    BasicBlock *getParent();
    bool isUncond() const {return instType == UNCOND;};
    bool isCond() const {return instType == COND;};
    void setParent(BasicBlock *);//设置指令1处于的块
    void setNext(Instruction *);
    void setPrev(Instruction *);
    Instruction *getNext();
    Instruction *getPrev();
    virtual void output() const = 0;
    unsigned instType;
   // virtual int isret() const=0;
protected:
    
    unsigned opcode;//指令的操作码
    Instruction *prev;
    Instruction *next;
    BasicBlock *parent;//属于哪个块
    std::vector<Operand*> operands;//操作数
    enum {BINARY, COND, UNCOND, RET, LOAD, STORE, CMP, ALLOCA, UNARY,FUNCALL  };//指令类型  添加指令这里也要添加
};

// meaningless instruction, used as the head node of the instruction list.
class DummyInstruction : public Instruction
{
public:
    DummyInstruction() : Instruction(-1, nullptr) {};
    void output() const {};
     int isret(){return 0;}
};

//分配指令  即给变量分配空间 dst为要分配的操作数 se为变量的表项 针对局部变量
class AllocaInstruction : public Instruction
{
public:
    AllocaInstruction(Operand *dst, SymbolEntry *se, BasicBlock *insert_bb = nullptr,int kind=0);
    ~AllocaInstruction();
    void output() const;
     int isret(){return 0;}
private:
    int kind;
    SymbolEntry *se;//要分配空间的变量的表项
};

//-----------------------------------添加针对全局变量
class globalAllocaInstruction : public Instruction
{
public:
    globalAllocaInstruction(Operand *dst, SymbolEntry *se, Operand * value=nullptr,BasicBlock *insert_bb = nullptr);
    ~globalAllocaInstruction();
    void output() const;
     int isret(){return 0;}
private:
    SymbolEntry *se;
    Operand * value;//全局变量赋予的值
};







//加载指令 dst为加载到的操作数  src为需要加载的操作数
class LoadInstruction : public Instruction
{
public:
    LoadInstruction(Operand *dst, Operand *src_addr, BasicBlock *insert_bb = nullptr);
    ~LoadInstruction();
    void output() const;
     int isret(){return 0;}
};
//存储指令  src为待存储的操作数  dst为存储的地址
class StoreInstruction : public Instruction
{
public:
    StoreInstruction(Operand *dst_addr, Operand *src, BasicBlock *insert_bb = nullptr);
    ~StoreInstruction();
    void output() const;
     int isret(){return 0;}
};
//二元运算指令  opcode 0 1 2 3对应SUB, ADD, AND, OR
//dst为结果操作数 src1 src2为运算的分量 
class BinaryInstruction : public Instruction
{
public:
    BinaryInstruction(unsigned opcode, Operand *dst, Operand *src1, Operand *src2, BasicBlock *insert_bb = nullptr);
    ~BinaryInstruction();
    void output() const;
    enum {SUB, ADD, AND, OR,  MUL,DIV,REM ,XOR  };
     int isret(){return 0;}
};
//比较指令 opcode 0-5对应比较操作  结果写到dst
class CmpInstruction : public Instruction
{
public:
    CmpInstruction(unsigned opcode, Operand *dst, Operand *src1, Operand *src2, BasicBlock *insert_bb = nullptr);
    ~CmpInstruction();
    void output() const;
    enum {E, NE, L, GE, G, LE};
     int isret(){return 0;}
};
//非条件跳转 构造函数的第一个参数为要跳转到的块 即branch
// unconditional branch
class UncondBrInstruction : public Instruction
{
public:
    UncondBrInstruction(BasicBlock*, BasicBlock *insert_bb = nullptr);
    void output() const;//输出跳转指令块的编号
    void setBranch(BasicBlock *);
    BasicBlock *getBranch();
     int isret(){return 0;}
protected:
    BasicBlock *branch;//分支要跳转的操作快
};

// 条件跳转
//根据构造函数的操作数的情况 可以跳转到两个不同的块 true flase各有一个块
class CondBrInstruction : public Instruction
{
public:
    CondBrInstruction(BasicBlock*, BasicBlock*, Operand *, BasicBlock *insert_bb = nullptr);
    ~CondBrInstruction();
    void output() const;
    void setTrueBranch(BasicBlock*);
    BasicBlock* getTrueBranch();
    void setFalseBranch(BasicBlock*);
    BasicBlock* getFalseBranch();
     int isret(){return 0;}
protected:
//条件真或假 跳转的块
    BasicBlock* true_branch;
    BasicBlock* false_branch;
};
//返回指令
//构造时输入的src为返回操作数 可能为空 那么就返回void
class RetInstruction : public Instruction
{
public:
    RetInstruction(Operand *src, BasicBlock *insert_bb = nullptr);
    ~RetInstruction();
    int isret(){return 1;}
    void output() const;
};
//添加的指令类型 

//一元运算指令
//dst为整体表达式的操作数  src为除去运算符的操作数
class UnaryInstruction : public Instruction
{
public:
    UnaryInstruction(unsigned opcode, Operand *dst, Operand *src,BasicBlock *insert_bb = nullptr);
    ~UnaryInstruction();
    void output() const;
    enum {SUB, ADD, NOT};
     int isret(){return 0;}
};

//函数调用指令  src为返回地址操作数  call为包含函数表项的操作数
class FunCcallInstruction : public Instruction
{
    std::vector<Operand *> params;
public:
    FunCcallInstruction(Operand *src, Operand *call,BasicBlock *insert_bb = nullptr,std::vector<Operand *> params={});
    ~FunCcallInstruction();
    void output() const;
    int isret(){return 0;}
};
























#endif