#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include "BasicBlock.h"
#include "SymbolTable.h"

class Unit;

//Function表示当前要处理的程序片段  可能对应多个basic block
//block之间分隔是由于跳转造成的
class Function
{
    typedef std::vector<BasicBlock *>::iterator iterator;
    typedef std::vector<BasicBlock *>::reverse_iterator reverse_iterator;
    //
   typedef std::vector<Type *>::const_iterator const_it;
    
private:
    std::vector<BasicBlock *> block_list;
    SymbolEntry *sym_ptr;//存放当前函数的信息 ，名称 返回类型
    BasicBlock *entry;//block list的头部
    Unit *parent;//函数的集合 即当前函数处于的unit
    //存储函数对应的参数类型
    std::vector<Type *> params;

public:
    std::vector<Operand *> InClassId;//store params' label!!!! dyt added.
    Function(Unit *, SymbolEntry *);
    //有参数的构造
    Function(Unit *, SymbolEntry *,std::vector<Type*>);
    
    ~Function();
    void insertBlock(BasicBlock *bb) { block_list.push_back(bb); };
    BasicBlock *getEntry() { return entry; };
    void remove(BasicBlock *bb);
    void output() const;//输出当前函数的中间代码 需要当前函数的block_list进行output
    std::vector<BasicBlock *> &getBlockList(){return block_list;};
    iterator begin() { return block_list.begin(); };
    iterator end() { return block_list.end(); };
    reverse_iterator rbegin() { return block_list.rbegin(); };
    reverse_iterator rend() { return block_list.rend(); };
    SymbolEntry *getSymPtr() { return sym_ptr; };
    
    
    //int get_blocklist_size(){return block_list.size(););
    const_it getparam_begin() const {return params.begin();};
     
};

#endif
