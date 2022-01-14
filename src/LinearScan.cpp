#include "LinearScan.h"
#include <algorithm>
#include <iostream>
#include "LiveVariableAnalysis.h"
#include "MachineCode.h"

LinearScan::LinearScan(MachineUnit* unit) {
    this->unit = unit;
    //可分配寄存器为4-10
    for (int i = 4; i < 11; i++)
        regs.push_back(i);
}
//遍历每个函数 获得虚拟寄存器对应的物理寄存器
void LinearScan::allocateRegisters() {
    //遍历unit下的每个func
    for (auto& f : unit->getFuncs()) {
        func = f;
        //用success判断何时完成分配
        bool success;
        success = false;
        while (!success)  // repeat until all vregs can be mapped
        {
            //旧区间重构，重分配原来的寄存器
            computeLiveIntervals();
            success = linearScanRegisterAllocation();
            //有溢出情况 生成溢出代码 否则直接调整寄存器
            if (success)  // all vregs can be mapped to real regs
                modifyCode();//没有溢出 修改寄存器映射即可退出
            else  // spill vregs that can't be mapped to real regs
                genSpillCode();//生成溢出代码 然后继续循环
        }
    }
}

void LinearScan::makeDuChains() {
    LiveVariableAnalysis lva;
    lva.pass(func);//遍历函数 添加使用和定义变量，分配寄存器
    du_chains.clear();
    int i = 0;
    std::map<MachineOperand, std::set<MachineOperand*>> liveVar;
    //遍历函数每个MachineBlock
    for (auto& bb : func->getBlocks()) {
        liveVar.clear();
        //放入不活跃的变量
        for (auto& t : bb->getLiveOut())
            liveVar[*t].insert(t);
        int no;
        no = i = bb->getInsts().size() + i;
         //为了对于标号 逆序遍历
        for (auto inst = bb->getInsts().rbegin(); inst != bb->getInsts().rend();
             inst++) {
            (*inst)->setNo(no--);
            //遍历指令定义的操作数
            //将虚拟寄存器的变量
            for (auto& def : (*inst)->getDef()) {
                if (def->isVReg()) {
                    //获取定义变量的活跃寄存器
                    auto& uses = liveVar[*def];//对应变量的集合
                    //集合插入du_chains
                    du_chains[def].insert(uses.begin(), uses.end());
                    auto& kill = lva.getAllUses()[*def];
                    std::set<MachineOperand*> res;
                    set_difference(uses.begin(), uses.end(), kill.begin(),
                                   kill.end(), inserter(res, res.end()));
                    liveVar[*def] = res;
                }
            }
            for (auto& use : (*inst)->getUse()) {
                if (use->isVReg())
                    liveVar[*use].insert(use);
            }
        }
    }
}
//计算活跃区间
void LinearScan::computeLiveIntervals() {
    makeDuChains();
    intervals.clear();
    for (auto& du_chain : du_chains) {
        int t = -1;
        for (auto& use : du_chain.second)
            t = std::max(t, use->getParent()->getNo());
        Interval* interval = new Interval({du_chain.first->getParent()->getNo(),
                                           t,
                                           false,
                                           0,
                                           0,
                                           {du_chain.first},
                                           du_chain.second});
        intervals.push_back(interval);
    }
    bool change;
    change = true;
    while (change) {
        change = false;
        std::vector<Interval*> t(intervals.begin(), intervals.end());
        for (size_t i = 0; i < t.size(); i++)
            for (size_t j = i + 1; j < t.size(); j++) {
                Interval* w1 = t[i];
                Interval* w2 = t[j];
                if (**w1->defs.begin() == **w2->defs.begin()) {
                    std::set<MachineOperand*> temp;
                    set_intersection(w1->uses.begin(), w1->uses.end(),
                                     w2->uses.begin(), w2->uses.end(),
                                     inserter(temp, temp.end()));
                    if (!temp.empty()) {
                        change = true;
                        w1->defs.insert(w2->defs.begin(), w2->defs.end());
                        w1->uses.insert(w2->uses.begin(), w2->uses.end());
                        w1->start = std::min(w1->start, w2->start);
                        w1->end = std::max(w1->end, w2->end);
                        auto it =
                            std::find(intervals.begin(), intervals.end(), w2);
                        if (it != intervals.end())
                            intervals.erase(it);
                    }
                }
            }
    }
    sort(intervals.begin(), intervals.end(), compareStart);
}

bool LinearScan::linearScanRegisterAllocation() {
     bool success = true;//用于判断能否分配成功
    //初始化
    active.clear();
    regs.clear();
    //初始放入可用分配寄存器
    for (int i = 10; i >=4; i--)
        regs.push_back(i);
    //遍历每个unhandled interval没有分配寄存器的活跃区间
    for (auto& i : intervals) {
       
        //遍历 active 列表，看该列表中是否存在结束时间早于 
        //unhandled interval 的 interval
        //主要用于回收可用寄存器
        expireOldIntervals(i);
        
        //没有可分配的寄存器 溢出
        if (regs.empty()) {
            spillAtInterval(i);//溢出操作
            success = false;
        } else {
            //分配寄存器 同时删去已经分配的
            i->rreg = regs.front();
            regs.erase(regs.begin());
            //放入已经分配的向量中
            active.push_back(std::move(i));//右值引用 可以直接用i
            //对活跃区间按照结束时间升序排序
            sort(active.begin(), 
            active.end(),
            [](Interval* a, Interval* b) 
            {return a->end < b->end;});
        }
    }
    return success;
   
}
//没有溢出情况 ---已经实现
void LinearScan::modifyCode() {
       //遍历每个区间
    for (auto& interval : intervals) {
        //添加此函数使用的寄存器
        func->addSavedRegs(interval->rreg);
        //将用到的寄存器放入区间的use和def中
        for (auto def : interval->defs)
            def->setReg(interval->rreg);
        for (auto use : interval->uses)
            use->setReg(interval->rreg);
    }
}

void LinearScan::genSpillCode() {
    for (auto& interval : intervals) {
        if (!interval->spill)
            continue;
        // TODO
        /* HINT:
         * The vreg should be spilled to memory.
         * 1. insert ldr inst before the use of vreg
         * 2. insert str inst after the def of vreg
         */
         //获取栈内相对偏移
         //注意要是负的 以FP为基准
        interval->disp = -func->AllocSpace(4);
        //获取偏移和FP寄存器的值
        auto off = new MachineOperand(MachineOperand::IMM, interval->disp);
        auto fp = new MachineOperand(MachineOperand::REG, 11);
        for (auto use : interval->uses) {
            //在use之前插入load指令 将其从栈内加载到目的虚拟寄存器中
            auto temp = new MachineOperand(*use);
            MachineOperand* operand = nullptr;
             //首先判断当前数据地址是否超过寻址空间 
            //超出寻址空间 不能直接加载 要分两步
            //首先加载到虚拟寄存器 ldr v1,off
            if (interval->disp > 255 || interval->disp < -255) {
                operand = new MachineOperand(MachineOperand::VREG,
                                             SymbolTable::getLabel());
                auto inst1 = new LoadMInstruction(use->getParent()->getParent(),
                                                  operand, off);
                //USE指令前插入Load指令
                use->getParent()->insertBefore(inst1);
            }
            //超出寻址空间的话 第二步ldr r0,[fp,v1]
            if (operand) {
                auto inst =
                    new LoadMInstruction(use->getParent()->getParent(), temp,
                                         fp, new MachineOperand(*operand));
                use->getParent()->insertBefore(inst);
            } else {
                 //正常情况，直接从fp-off的地方加载
                auto inst = new LoadMInstruction(use->getParent()->getParent(),
                                                 temp, fp, off);
                use->getParent()->insertBefore(inst);
            }
        }
        //遍历其 DEF 指令的列表，
        //在 DEF 指令后插入 StoreMInstruction，将其从目前的虚拟寄存器中
        //存到栈内
        for (auto def : interval->defs) {
             //在def之后插入store指令
            auto temp = new MachineOperand(*def);
            MachineOperand* operand = nullptr;
            MachineInstruction *inst1 = nullptr, *inst = nullptr;
            //同样要考虑寻址空间
            if (interval->disp > 255 || interval->disp < -255) {
                operand = new MachineOperand(MachineOperand::VREG,
                                             SymbolTable::getLabel());
                inst1 = new LoadMInstruction(def->getParent()->getParent(),
                                             operand, off);
                def->getParent()->insertAfter(inst1);
            }
            //StoreMInstruction要插入DEF指令之后
            if (operand)
                inst =
                    new StoreMInstruction(def->getParent()->getParent(), temp,
                                          fp, new MachineOperand(*operand));
            else
                inst = new StoreMInstruction(def->getParent()->getParent(),
                                             temp, fp, off);
            if (inst1)
                inst1->insertAfter(inst);
            else
                def->getParent()->insertAfter(inst);
        }
    }
}

void LinearScan::expireOldIntervals(Interval* interval) {
    auto it = active.begin();
     //查看active中是否有结束时间早于interval起始时间
    //active按照end时间升序排列，所以只用看头部
    //头部如果大于 那么直接返回
    //头部小于 那么active的寄存器可以回收
    while (it != active.end()) {
        if ((*it)->end >= interval->start)
            return;
        regs.push_back((*it)->rreg);
        it = active.erase(find(active.begin(), active.end(), *it));
        sort(regs.begin(), regs.end());
    }
}
//寄存器溢出操作
void LinearScan::spillAtInterval(Interval* interval) {
    //选择active列表末尾与当前unhandled的一个溢出到栈中
    auto spill = active.back();
    //将结束时间更晚的溢出
    if (spill->end > interval->end) {
        spill->spill = true;
        interval->rreg = spill->rreg;
         //额外添加 处理寄存器
        func->addSavedRegs(interval->rreg);
        //再按照 unhandled interval活跃区间结束位置，将其插入到 active 列表中。
        active.push_back(std::move(interval));
        //插入后再次按照结束时间对活跃区间进行排序
        sort(active.begin(), active.end(),
            [](Interval* a, Interval* b) {return a->end < b->end;});
    } else {
        //unhandle溢出更晚只需置位spill标志位
        interval->spill = true;
    }
}

bool LinearScan::compareStart(Interval* a, Interval* b) {
    return a->start < b->start;
}

