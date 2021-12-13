#ifndef __OPERAND_H__
#define __OPERAND_H__

#include "SymbolTable.h"
#include <vector>

class Instruction;
class Function;


// class Operand - The operand of an instruction.
//操作数是指令中使用的一个数据
//操作数的属性有 定义该操作数的指令（只有1个） 使用该操作数的指令(可能有多个)
//每个操作数对应一个符号表项 用于获取type
class Operand
{
typedef std::vector<Instruction *>::iterator use_iterator;

private:
    Instruction *def;                // The instruction where this operand is defined.
    std::vector<Instruction *> uses; // Intructions that use this operand.
    SymbolEntry *se;                 // The symbol entry of this operand.
public:
    Operand(SymbolEntry*se) :se(se){def = nullptr;};
    void setDef(Instruction *inst) {
       // fprintf(stderr, "定义断点5 \n");
        def = inst;//问题在这里
        //fprintf(stderr, "定义断点5 \n");
        };
    void addUse(Instruction *inst) { uses.push_back(inst);};
    void removeUse(Instruction *inst);
    int usersNum() const {return uses.size();};

    use_iterator use_begin() {return uses.begin();};
    use_iterator use_end() {return uses.end();};
    Type* getType() {return se->getType();};
    std::string toStr() const;
    //额外添加
    SymbolEntry* get_symbolentry(){return this->se;};
    
};

#endif