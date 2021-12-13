#include "BasicBlock.h"
#include "Function.h"
#include <algorithm>
#include"Type.h"
extern FILE* yyout;

// insert the instruction to the front of the basicblock.
void BasicBlock::insertFront(Instruction *inst)
{
    insertBefore(inst, head->getNext());
}

// insert the instruction to the back of the basicblock.
void BasicBlock::insertBack(Instruction *inst) 
{
    insertBefore(inst, head);
}

// insert the instruction dst before src.
void BasicBlock::insertBefore(Instruction *dst, Instruction *src)
{
    // Todo
 if(src->getNext()==src)
    {
        src->setNext(dst);
        dst->setPrev(src);
        dst->setNext(src);
        src->setPrev(dst);
    }
    else{
        dst->setPrev(src->getPrev());
        dst->setNext(src);
        src->getPrev()->setNext(dst);
        src->setPrev(dst);
    }
    
    dst->setParent(this);   
    
    /*
    dst->setParent(this);
    //这里是一个简单的双向列表插入
    src->setNext(dst);
    dst->setPrev(src);
    dst->setNext(src);
    src->setPrev(dst);*/
   
}

// remove the instruction from intruction list.
void BasicBlock::remove(Instruction *inst)
{
    inst->getPrev()->setNext(inst->getNext());
    inst->getNext()->setPrev(inst->getPrev());
}

void BasicBlock::output() const
{
    fprintf(yyout, "B%d:", no);
    //pred存放多个前驱块 如果已经有其他的块 要把前驱块的id输出
    if (!pred.empty())
    {
        fprintf(yyout, "%*c; preds = %%B%d", 32, '\t', pred[0]->getNo());
        auto i = pred.begin() ;
        i++;
        while(i!=pred.end())
        {
            
                fprintf(yyout, ", %%B%d", (*i)->getNo());
                
           
            i++;
        }
       
    }
    fprintf(yyout, "\n");
    //将当前块存放的指令遍历输出
    auto i = head->getNext();
    //针对空语句块情况 即if else内部返回
    if(i==head)
    {
        FunctionType* funcType = dynamic_cast<FunctionType*>(parent->getSymPtr()->getType());
        //Type *retType = funcType->getRetType();
        //std::string ret;
        std::string ret=funcType->toStr();
        if(ret!="void()")
        {
             fprintf(yyout, "  ret i32 1\n");
        }
        else{
            fprintf(yyout, "  ret void\n");
        }
      
     
      return;
    }
    for (auto i = head->getNext(); i != head; i = i->getNext())
    {
        //fprintf(stderr, "指令1 \n");
        //这里判断如果是返回指令 那么就跳出循环
        //fprintf(stderr, "  break %d\n",(i)->isret());
        /*if(static_cast<RetInstruction*>(i)->isret()==1)
        {
            //fprintf(stderr, "  break 1\n");
            i->output();
            break;
        }*/
        i->output();
    }
}

void BasicBlock::addSucc(BasicBlock *bb)
{
    succ.push_back(bb);
}

// remove the successor basicclock bb.
void BasicBlock::removeSucc(BasicBlock *bb)
{
    succ.erase(std::find(succ.begin(), succ.end(), bb));
}

void BasicBlock::addPred(BasicBlock *bb)
{
    pred.push_back(bb);
}

// remove the predecessor basicblock bb.
void BasicBlock::removePred(BasicBlock *bb)
{
    pred.erase(std::find(pred.begin(), pred.end(), bb));
}
//设置当前块对应的函数
BasicBlock::BasicBlock(Function *f)
{
    this->no = SymbolTable::getLabel();
    f->insertBlock(this);
    parent = f;
    head = new DummyInstruction();
    head->setParent(this);
}
//释放时 首先释放当前块的所有指令 然后释放保存的前驱和后继块
BasicBlock::~BasicBlock()
{
    Instruction *inst;
    inst = head->getNext();
    while (inst != head)
    {
        Instruction *t;
        t = inst;
        inst = inst->getNext();
        delete t;
    }
    for(auto &bb:pred)
        bb->removeSucc(this);
    for(auto &bb:succ)
        bb->removePred(this);
    parent->remove(this);
}
