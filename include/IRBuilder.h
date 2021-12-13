#ifndef __IRBUILDER_H__
#define __IRBUILDER_H__

class Unit;
class Function;
class BasicBlock;


//IRBuilder用于处理一个unit 即函数集合 insertBB用于当前位置的插入
class IRBuilder
{
private:
    Unit *unit;
    BasicBlock *insertBB;   // The current basicblock that instructions should be inserted into.

public:
    IRBuilder(Unit*unit) : unit(unit){};
    void setInsertBB(BasicBlock*bb){insertBB = bb;};
    Unit* getUnit(){return unit;};
    BasicBlock* getInsertBB(){return insertBB;};
};

#endif