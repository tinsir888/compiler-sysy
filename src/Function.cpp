#include "Function.h"
#include "Unit.h"
#include "Type.h"
#include "Ast.h"
#include <list>
#include <fstream>
#include <stack>
extern Ast ast;
extern FILE* yyout;

Function::Function(Unit *u, SymbolEntry *s)
{
    u->insertFunc(this);
    entry = new BasicBlock(this);
    sym_ptr = s;
    parent = u;
}

Function::Function(Unit *u, SymbolEntry *s,std::vector<Type*> params)
{
    u->insertFunc(this);
    entry = new BasicBlock(this);
    sym_ptr = s;
    parent = u;
    this->params=params;
    
}


Function::~Function()
{/*
    fprintf(stderr, "函数断点1 \n");
    auto delete_list = block_list;
     fprintf(stderr, "函数断点2 \n");
    for (auto &i : delete_list)
        delete i;
    parent->removeFunc(this);
    fprintf(stderr, "函数断点3 \n");*/
}

// remove the basicblock bb from its block_list.
void Function::remove(BasicBlock *bb)
{
    block_list.erase(std::find(block_list.begin(), block_list.end(), bb));
}
//需要修改 否则无法输出中间代码
void Function::output() const
{
    FunctionType* funcType = dynamic_cast<FunctionType*>(sym_ptr->getType());
    Type *retType = funcType->getRetType();
    int para_num=funcType->getnum();
    std::vector<Type *> Params=funcType->get_vector_type();
   // fprintf(stderr, "函数断点1 \n");
    if(para_num==0)
    {
        //fprintf(stderr, "函数断点1 \n");
        
        
        
        fprintf(yyout, "define %s %s() {\n", retType->toStr().c_str(), sym_ptr->toStr().c_str());
    }
    //针对有参数情况 需要把参数也输出
    else{
        
        //fprintf(stderr, "函数断点2 \n");
        
        fprintf(yyout, "define %s %s(", retType->toStr().c_str(), sym_ptr->toStr().c_str());
        
        //std::vector<Type*>::const_iterator it;
        //it=getparam_begin();//获取参数向量的头部迭代器
         std::vector<Type *>::iterator it=Params.begin();
        //按照参数格式输出
        //fprintf(stderr, "%d \n", int(Params.size()));
        //fprintf(stderr, "%s \n ", (*it)->toStr().c_str());
       //  fprintf(stderr, "函数断点3 \n");
        Type *temp=*it;//这个式子有问题
         //fprintf(stderr, "函数断点3 \n");
        int i=0;
        std::stack<int>tmp;
        for(;i<para_num;i++){
            tmp.push(ast.AllFuncParams.front());
            ast.AllFuncParams.pop_front();
            //fprintf(yyout, "%s \%t%d,", temp->toStr.c_str, )
        } 
        for(;tmp.size()>1;){
            fprintf(yyout, "%s %%t%d, ",temp->toStr().c_str(), tmp.top());
            tmp.pop();
        }
        fprintf(yyout, "%s %%t%d){", temp->toStr().c_str(), tmp.top());
        fprintf(yyout,"\n");
      /*
        for(;i<para_num-1;i++)
        {
            
            fprintf(yyout, "%s %%%d,", temp->toStr().c_str(),i);
            it++;
            temp=*it;
        }
       
        fprintf(yyout, "%s %%%d) {\n", temp->toStr().c_str(),i);
        */
    }
   // fprintf(stderr, "函数断点2 \n");
    //从entry当前函数的入口开始遍历输出指令内容
    std::set<BasicBlock *> v;
    std::list<BasicBlock *> q;
    q.push_back(entry);
    v.insert(entry);
    //fprintf(stderr, "函数断点3 \n");
    while (!q.empty())
    {
        auto bb = q.front();
        q.pop_front();
        bb->output();//输出每个块
        //fprintf(stderr, "函数断点1 \n");
        //每个块可能有多个后继块 所以都要遍历
        for (auto succ = bb->succ_begin(); succ != bb->succ_end(); succ++)
        {
            //fprintf(stderr, "函数断点2 \n");
            if (v.find(*succ) == v.end())
            {
                v.insert(*succ);
                q.push_back(*succ);
            }
        }
    }
    fprintf(yyout, "}\n");
    //fprintf(stderr, "函数断点4 \n");
}
