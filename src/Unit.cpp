#include "Unit.h"
#include <algorithm>
#include <stack>
#include <string>
#include "Ast.h"
#include "SymbolTable.h"
#include "Type.h"
extern FILE* yyout;

void Unit::insertFunc(Function* f) {
    func_list.push_back(f);
}

void Unit::removeFunc(Function* func) {
    func_list.erase(std::find(func_list.begin(), func_list.end(), func));
}

void Unit::insertGlobal(SymbolEntry* se) {
    global_list.push_back(se);
}

void Unit::insertDeclare(SymbolEntry* se) {
    auto it = std::find(declare_list.begin(), declare_list.end(), se);
    if (it == declare_list.end()) {
        declare_list.push_back(se);
    }
}

void Unit::output() const {
    //输出官方定义库函数
    for (auto se : declare_list) 
    {
        FunctionType* type = (FunctionType*)(se->getType());
        std::string str = type->toStr();
        std::string name = str.substr(0, str.find('('));
        std::string param = str.substr(str.find('('));
        fprintf(yyout, "declare %s %s%s\n", type->getRetType()->toStr().c_str(),
                se->toStr().c_str(), param.c_str());
    }
    for (auto se : global_list) {
        if (se->getType()->isInt())
            fprintf(yyout, "%s = global %s %d, align 4\n", se->toStr().c_str(),
                    se->getType()->toStr().c_str(),
                    ((IdentifierSymbolEntry*)se)->getValue());
         //全局数组的中间代码输出
         //大致思路就是先输出当前高维的情况 例如3*4*i32
         //然后输出低维的情况
        else if (se->getType()->isArray()) {
            ArrayType* type = (ArrayType*)(se->getType());
            int* val = ((IdentifierSymbolEntry*)se)->getArrayValue();
            int i = 0;
            fprintf(yyout, "%s = global ", se->toStr().c_str());
           //初始化全为0 输出[n * i32]
            if (((IdentifierSymbolEntry*)se)->isAllZero()) {
                fprintf(yyout, "%s zeroinitializer", type->toStr().c_str());
            } 
            else 
            {
                std::stack<ArrayType*> stk;//存放类型
                std::stack<int> stk1;//存放长度
                stk.push(type);
                stk1.push(0);//初始时放入0
                ArrayType* temp;
                while (!stk.empty()) {
                    temp = stk.top();//当前维度的类型
                    
                    //对于元素是int的 输出对应数值
                    if (temp->getElementType()->isInt()) {
                        fprintf(yyout, "%s [", temp->toStr().c_str());
                        for (int j = 0; j < temp->getLength(); j++) {
                            if (j != 0)
                                fprintf(yyout, ", ");
                            fprintf(yyout, "i32 %d", val[i++]);
                        }
                        fprintf(yyout, "]");
                        stk1.pop();
                        stk.pop();//弹出低维数组类型
                        if (stk.empty())
                            break;
                        stk1.top()++;
                        continue;
                    }
                    //用于遍历高维数组
                    if (stk1.top() != temp->getLength()) {
                        //fprintf(stderr,"break 1");
                        //每个高维的都要放入一个对应低维的
                        stk.push((ArrayType*)(temp->getElementType()));
                        //如果是第一个高维要输入[
                        if (stk1.top() == 0)
                            fprintf(yyout, "%s [", temp->toStr().c_str());
                        if (stk1.top() != 0)
                            fprintf(yyout, ", ");
                        stk1.push(0);
                    } 
                    //当高维数组遍历完成后 这时候stk1的top值和数组长度相同
                    else {
                       // fprintf(stderr,"break 2");
                        fprintf(yyout, "]");
                        stk.pop();
                        stk1.pop();
                        if (stk.empty())
                            break;
                        stk1.top()++;
                        continue;
                    }
                }
            }
            
            
            //统一对齐
            fprintf(yyout, ", align 4\n");
        }
    }

    for (auto& func : func_list)
        func->output();
    
}

void Unit::genMachineCode(MachineUnit* munit) 
{
    AsmBuilder* builder = new AsmBuilder();
    builder->setUnit(munit);
    for (auto &func : func_list)
        func->genMachineCode(builder);
}

Unit::~Unit()
{
    for(auto &func:func_list)
        delete func;
}


