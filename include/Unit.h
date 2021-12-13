#ifndef __UNIT_H__
#define __UNIT_H__

#include <vector>
#include "Function.h"

//Unit是函数片段的集合
class Unit
{
    typedef std::vector<Function *>::iterator iterator;
    typedef std::vector<Function *>::reverse_iterator reverse_iterator;

private:
    std::vector<Function *> func_list;
    //针对全局变量 在函数以外专门存储分配空间
    std::vector<Instruction *> globalvar_list;
public:
    Unit() = default;
    ~Unit() ;
    void insertFunc(Function *);//把func放到func_list
    void removeFunc(Function *);
    void output() const;//调用func_list中的每个func的output
    //用于遍历
    iterator begin() { return func_list.begin(); };
    iterator end() { return func_list.end(); };
    reverse_iterator rbegin() { return func_list.rbegin(); };
    reverse_iterator rend() { return func_list.rend(); };
    //添加相应的处理函数
    void global_push(Instruction* src)
    {
        
         
            globalvar_list.push_back(src);
        
        // fprintf(stderr, "  break 6\n");
        };
};

#endif