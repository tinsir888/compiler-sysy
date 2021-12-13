#include "Unit.h"

void Unit::insertFunc(Function *f)
{
    func_list.push_back(f);
}

void Unit::removeFunc(Function *func)
{
    func_list.erase(std::find(func_list.begin(), func_list.end(), func));
}

void Unit::output() const
{
    //fprintf(stderr," output 1 \n");
    for (auto &global_var : globalvar_list)
        global_var->output();
    //fprintf(stderr," output 2 \n");
    for (auto &func : func_list)
        func->output();
    //fprintf(stderr," output 3 \n");
}

Unit::~Unit()
{
    for(auto &func:func_list)
        delete func;
    for (auto &global_var : globalvar_list)
        delete global_var;
}
