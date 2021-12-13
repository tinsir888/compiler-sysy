#ifndef __BASIC_BLOCK_H__
#define __BASIC_BLOCK_H__
#include <vector>
#include <set>
#include "Instruction.h"

class Function;

class BasicBlock
{
    typedef std::vector<BasicBlock *>::iterator bb_iterator;

private:
    std::vector<BasicBlock *> pred, succ;//pred存放前驱块 succ存放后继块
    Instruction *head;
    Function *parent;
    int no;

public:
    BasicBlock(Function *);
    ~BasicBlock();
    
    void insertFront(Instruction *);//指令插入块的开头
    void insertBack(Instruction *);//指令插入末尾
    void insertBefore(Instruction *, Instruction *);//****需要自己写
    
    void remove(Instruction *);
    bool empty() const { return head->getNext() == head;}//判断是否为空
    void output() const;//  输出当前块的number以及前驱块的no  以及将当前块存放的指令遍历输出
    bool succEmpty() const { return succ.empty(); };
    bool predEmpty() const { return pred.empty(); };
    
    void addSucc(BasicBlock *);
    void removeSucc(BasicBlock *);
    void addPred(BasicBlock *);
    void removePred(BasicBlock *);
    int getNo() { return no; };
    
    
    
    Function *getParent() { return parent; };
    Instruction* begin() { return head->getNext();};
    Instruction* end() { return head;};
    Instruction* rbegin() { return head->getPrev();};
    Instruction* rend() { return head;};
    
    bb_iterator succ_begin() { return succ.begin(); };
    bb_iterator succ_end() { return succ.end(); };
    bb_iterator pred_begin() { return pred.begin(); };
    bb_iterator pred_end() { return pred.end(); };
    int getNumOfPred() const { return pred.size(); };//获得前驱的个数
    int getNumOfSucc() const { return succ.size(); };//获取后继的个数
     void setSucc(BasicBlock *bb){
         succ.clear();
    succ.push_back(bb);
         
     };
    //
};

#endif