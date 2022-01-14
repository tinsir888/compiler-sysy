/**
 * linear scan register allocation
 */

#ifndef _LINEARSCAN_H__
#define _LINEARSCAN_H__
#include <list>
#include <map>
#include <set>
#include <vector>

class MachineUnit;
class MachineOperand;
class MachineFunction;

class LinearScan {
   private:
   //目前还为分配寄存器的活跃区间
    struct Interval {
        int start;//开始位置
        int end;//结束位置
        bool spill;//是否需要溢出
        int disp;//栈偏移
        int rreg;//物理寄存器号（如果虚拟寄存器没有溢出）
        std::set<MachineOperand*> defs;
        std::set<MachineOperand*> uses;
    };
    MachineUnit* unit;//从unit自顶向下
    MachineFunction* func;//遍历函数
    std::vector<int> regs;//保存寄存器号
    std::map<MachineOperand*, std::set<MachineOperand*>> du_chains;
    std::vector<Interval*> intervals;//未分配寄存器的活跃区间
    std::vector<Interval*> active;//-----新增 占用物理寄存器的活跃区间
    static bool compareStart(Interval* a, Interval* b);
    void expireOldIntervals(Interval* interval);
    void spillAtInterval(Interval* interval);
    void makeDuChains();
    void computeLiveIntervals();
    bool linearScanRegisterAllocation();
    void modifyCode();
    void genSpillCode();

   public:
    LinearScan(MachineUnit* unit);
    void allocateRegisters();
};

#endif