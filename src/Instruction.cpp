#include "Instruction.h"
#include "BasicBlock.h"
#include <iostream>
#include "Function.h"
#include "Type.h"
extern FILE* yyout;

//向块中放入指令
Instruction::Instruction(unsigned instType, BasicBlock *insert_bb)
{
    prev = next = this;
    opcode = -1;
    this->instType = instType;
    if (insert_bb != nullptr)
    {
        insert_bb->insertBack(this);
        parent = insert_bb;
    }
}

Instruction::~Instruction()
{
    parent->remove(this);
}

BasicBlock *Instruction::getParent()
{
    return parent;
}

void Instruction::setParent(BasicBlock *bb)
{
    parent = bb;
}

void Instruction::setNext(Instruction *inst)
{
    next = inst;
}

void Instruction::setPrev(Instruction *inst)
{
    prev = inst;
}

Instruction *Instruction::getNext()
{
    return next;
}

Instruction *Instruction::getPrev()
{
    return prev;
}

BinaryInstruction::BinaryInstruction(unsigned opcode, Operand *dst, Operand *src1, Operand *src2, BasicBlock *insert_bb) : Instruction(BINARY, insert_bb)
{
    this->opcode = opcode;
    operands.push_back(dst);
    operands.push_back(src1);
    operands.push_back(src2);
    dst->setDef(this);
    src1->addUse(this);
    src2->addUse(this);
}

BinaryInstruction::~BinaryInstruction()
{
    operands[0]->setDef(nullptr);
    if(operands[0]->usersNum() == 0)
        delete operands[0];
    operands[1]->removeUse(this);
    operands[2]->removeUse(this);
}

void BinaryInstruction::output() const
{
    std::string s1, s2, s3, op, type;
    s1 = operands[0]->toStr();
    s2 = operands[1]->toStr();
    s3 = operands[2]->toStr();
    type = operands[0]->getType()->toStr();
    
    if(type=="constant") type="i32";
    if(type=="constant*") type="i32*";
    switch (opcode)
    {
    case ADD:
        op = "add";
        break;
    case SUB:
        op = "sub";
        break;
    case MUL:
        op = "mul";
        break;
    case DIV:
        op = "sdiv";
        break;
    case REM:
        op = "srem";
        break;    
    case XOR:
        op = "xor";
        break;     
        
    default:
        break;
    }
    fprintf(yyout, "  %s = %s %s %s, %s\n", s1.c_str(), op.c_str(), type.c_str(), s2.c_str(), s3.c_str());
}

CmpInstruction::CmpInstruction(unsigned opcode, Operand *dst, Operand *src1, Operand *src2, BasicBlock *insert_bb): Instruction(CMP, insert_bb){
    this->opcode = opcode;
    operands.push_back(dst);
    operands.push_back(src1);
    operands.push_back(src2);
    dst->setDef(this);
    src1->addUse(this);
    src2->addUse(this);
}

CmpInstruction::~CmpInstruction()
{
    operands[0]->setDef(nullptr);
    if(operands[0]->usersNum() == 0)
        delete operands[0];
    operands[1]->removeUse(this);
    operands[2]->removeUse(this);
}

void CmpInstruction::output() const
{
    std::string s1, s2, s3, op, type;
    s1 = operands[0]->toStr();
    s2 = operands[1]->toStr();
    s3 = operands[2]->toStr();
    type = operands[1]->getType()->toStr();
    if(type=="constant") type="i32";
     if(type=="constant*") type="i32*";
    switch (opcode)
    {
    case E:
        op = "eq";
        break;
    case NE:
        op = "ne";
        break;
    case L:
        op = "slt";
        break;
    case LE:
        op = "sle";
        break;
    case G:
        op = "sgt";
        break;
    case GE:
        op = "sge";
        break;
    default:
        op = "";
        break;
    }

    fprintf(yyout, "  %s = icmp %s %s %s, %s\n", s1.c_str(), op.c_str(), type.c_str(), s2.c_str(), s3.c_str());
}

UncondBrInstruction::UncondBrInstruction(BasicBlock *to, BasicBlock *insert_bb) : Instruction(UNCOND, insert_bb)
{
    branch = to;
}

void UncondBrInstruction::output() const
{
    fprintf(yyout, "  br label %%B%d\n", branch->getNo());
}

void UncondBrInstruction::setBranch(BasicBlock *bb)
{
    branch = bb;
}

BasicBlock *UncondBrInstruction::getBranch()
{
    return branch;
}

CondBrInstruction::CondBrInstruction(BasicBlock*true_branch, BasicBlock*false_branch, Operand *cond, BasicBlock *insert_bb) : Instruction(COND, insert_bb){
    this->true_branch = true_branch;
    this->false_branch = false_branch;
    cond->addUse(this);
    operands.push_back(cond);
}

CondBrInstruction::~CondBrInstruction()
{
    operands[0]->removeUse(this);
}

void CondBrInstruction::output() const
{
    std::string cond, type;
    cond = operands[0]->toStr();
    type = operands[0]->getType()->toStr();
    if(type=="constant")
    {   
       // fprintf(stderr, "%s \n",type.c_str());
        type="i32";
    }
     if(type=="constant*"){
        //fprintf(stderr, "%s \n",type.c_str());
         type="i32*";
     }
     
    int true_label = true_branch->getNo();
    int false_label = false_branch->getNo();
    fprintf(yyout, "  br i1 %s, label %%B%d, label %%B%d\n",  cond.c_str(), true_label, false_label);
}

void CondBrInstruction::setFalseBranch(BasicBlock *bb)
{
    false_branch = bb;
}

BasicBlock *CondBrInstruction::getFalseBranch()
{
    return false_branch;
}

void CondBrInstruction::setTrueBranch(BasicBlock *bb)
{
    true_branch = bb;
}

BasicBlock *CondBrInstruction::getTrueBranch()
{
    return true_branch;
}

RetInstruction::RetInstruction(Operand *src, BasicBlock *insert_bb) : Instruction(RET, insert_bb)
{
    if(src != nullptr)
    {
        operands.push_back(src);
        src->addUse(this);
    }
}

RetInstruction::~RetInstruction()
{
    if(!operands.empty())
        operands[0]->removeUse(this);
}

void RetInstruction::output() const
{
    if(operands.empty())
    {
        fprintf(yyout, "  ret void\n");
    }
    else
    {
        std::string ret, type;
        ret = operands[0]->toStr();
        type = operands[0]->getType()->toStr();
         if(type=="constant*") type="i32*";
          if(type=="constant") type="i32";
       // fprintf(yyout, "  ret %s %s\n", type.c_str(), ret.c_str());
       fprintf(yyout, "  ret i32 %s\n",  ret.c_str());
    }
}

AllocaInstruction::AllocaInstruction(Operand *dst, SymbolEntry *se, BasicBlock *insert_bb,int kind) : Instruction(ALLOCA, insert_bb)
{
    operands.push_back(dst);
    dst->setDef(this);
    this->se = se;
    
    this->kind=kind;
}

AllocaInstruction::~AllocaInstruction()
{
    operands[0]->setDef(nullptr);
    if(operands[0]->usersNum() == 0)
        delete operands[0];
}

void AllocaInstruction::output() const
{
    //fprintf(stderr, "  break 1\n");
    std::string dst, type;
    dst = operands[0]->toStr();
    type = se->getType()->toStr();
    if(type=="constant") type="i32";
     if(type=="constant*") type="i32*";
    if(!kind)
         fprintf(yyout, "  %s = alloca %s, align 4\n", dst.c_str(), type.c_str());
    else//确定为i32 即可输出
    {
        fprintf(yyout, "  %s = alloca i32, align 4\n", dst.c_str());
    }
    //fprintf(yyout, "  %s = alloca %s, align 4\n", dst.c_str(), type.c_str());//输出变量名称 和 类型
}

//添加的全局变量分配指令

globalAllocaInstruction::globalAllocaInstruction(Operand *dst, SymbolEntry *se,Operand * value, BasicBlock *insert_bb) : Instruction(ALLOCA, insert_bb)
{
      
    operands.push_back(dst);
  // fprintf(stderr, "定义断点4 \n");
    dst->setDef(this);//问题在这里
   //fprintf(stderr, "定义断点4 \n");
    this->se = se;
   // fprintf(stderr, "定义断点4 \n");
    this->value=value;
    // fprintf(stderr, "定义断点4 \n");
}

globalAllocaInstruction::~globalAllocaInstruction()
{
    operands[0]->setDef(nullptr);
    if(operands[0]->usersNum() == 0)
        delete operands[0];
}

void globalAllocaInstruction::output() const
{
    //fprintf(yyout, "  break 2\n");
    std::string dst, type;
    dst = operands[0]->toStr();
    type = se->getType()->toStr();
    
    std::string name=static_cast<IdentifierSymbolEntry*>(se)->get_name();//全局变量名称
    if(value==nullptr)
    {
        if(type=="i32")
             fprintf(yyout, "  @%s = dso_local global i32 0, align 4\n", name.c_str());
        else
        {
            if(type=="constant")
            fprintf(yyout, "  @%s = dso_local constant i32 0, align 4\n", name.c_str());
        }
    }
    else
    {
        //获取操作数的表项 从而获得操作数
        int value_=static_cast<ConstantSymbolEntry*>(value->get_symbolentry())->getValue();
        //fprintf(stderr, "变量 %s 值 %d \n",name.c_str(),value_);
        if(type=="i32")
        {
            
            fprintf(yyout, "  @%s = dso_local global i32 %d, align 4\n", name.c_str(),value_);
        }
        else //if(type=="constant")
        {
         //   fprintf(stderr, "定义断点1 \n");
         //fprintf(stderr, "定义断点1 %s\n",type.c_str());
            fprintf(yyout, "  @%s = dso_local constant i32 %d, align 4\n", name.c_str(),value_);
        }

    }
}




LoadInstruction::LoadInstruction(Operand *dst, Operand *src_addr, BasicBlock *insert_bb) : Instruction(LOAD, insert_bb)
{
    operands.push_back(dst);
    operands.push_back(src_addr);
    dst->setDef(this);
    src_addr->addUse(this);
}

LoadInstruction::~LoadInstruction()
{
    operands[0]->setDef(nullptr);
    if(operands[0]->usersNum() == 0)
        delete operands[0];
    operands[1]->removeUse(this);
}

void LoadInstruction::output() const
{
    std::string dst = operands[0]->toStr();
    std::string src = operands[1]->toStr();
    std::string src_type;
    std::string dst_type;
    dst_type = operands[0]->getType()->toStr();
    src_type = operands[1]->getType()->toStr();
    if(dst=="constant") dst="i32";
    if(dst_type=="constant") dst_type="i32";
    if(src_type=="constant") src_type="i32";
    if(dst=="constant*") dst="i32*";
    if(dst_type=="constant*") dst_type="i32*";
    if(src_type=="constant*") src_type="i32*";
    
    fprintf(yyout, "  %s = load %s, %s %s, align 4\n", dst.c_str(), dst_type.c_str(), src_type.c_str(), src.c_str());
}

StoreInstruction::StoreInstruction(Operand *dst_addr, Operand *src, BasicBlock *insert_bb) : Instruction(STORE, insert_bb)
{
    operands.push_back(dst_addr);
    operands.push_back(src);
    dst_addr->addUse(this);
    src->addUse(this);
}

StoreInstruction::~StoreInstruction()
{
    operands[0]->removeUse(this);
    operands[1]->removeUse(this);
}

void StoreInstruction::output() const
{
    std::string dst = operands[0]->toStr();
    std::string src = operands[1]->toStr();
    std::string dst_type = operands[0]->getType()->toStr();
    std::string src_type = operands[1]->getType()->toStr();
    if(dst=="constant*") dst="i32*";
    if(dst_type=="constant*") dst_type="i32*";
    if(src_type=="constant*") src_type="i32";
     if(dst=="constant") dst="i32*";
    if(dst_type=="constant") dst_type="i32*";
    if(src_type=="constant") src_type="i32";
    if(dst_type=="i32") dst_type="i32*";
    
    fprintf(yyout, "  store %s %s, %s %s, align 4\n", src_type.c_str(), src.c_str(), dst_type.c_str(), dst.c_str());
}


UnaryInstruction::UnaryInstruction(unsigned opcode, Operand *dst, Operand *src,BasicBlock *insert_bb) : Instruction(UNARY, insert_bb)
{
    //设置操作符 和操作数
    this->opcode = opcode;
    operands.push_back(dst);
    operands.push_back(src);
    
    dst->setDef(this);//此指令定义了dst操作数
    src->addUse(this);//此指令使用到了src操作数
}

UnaryInstruction::~UnaryInstruction()
{
    operands[0]->setDef(nullptr);//重置dst的定义
    //如果dst操作数 没有指令使用 那么释放
    if(operands[0]->usersNum() == 0)
        delete operands[0];
     //解除此条指令对src操作数的使用
    operands[1]->removeUse(this);
}
//参照二元运算
void UnaryInstruction::output() const
{
    std::string s1, s2, op, type;
    s1 = operands[0]->toStr();
    s2 = operands[1]->toStr();
    type = operands[0]->getType()->toStr();
    if(type=="constant") type="i32";
    if(type=="constant*") type="i32*";
    switch (opcode)
    {
    case ADD:
        op = "add";
        fprintf(yyout, "  %s = %s i32 0, %s\n", s1.c_str(), op.c_str(),  s2.c_str());
        break;
    case SUB:
        op = "sub";
        fprintf(yyout, "  %s = %s i32 0, %s\n", s1.c_str(), op.c_str(), s2.c_str());
        break;
    case NOT://对于取反 要视为控制流
    
        op = "xor";
        fprintf(yyout, "  %s = %s %s %s\n", s1.c_str(), op.c_str(), type.c_str(), s2.c_str());
        break;
    default:
        break;
    }
    
}


FunCcallInstruction::FunCcallInstruction(Operand *src, Operand *call,BasicBlock *insert_bb,std::vector<Operand *> params) : Instruction(FUNCALL, insert_bb)
{

    operands.push_back(src);
    src->addUse(this);
    operands.push_back(call);
    call->addUse(this);
    this->params=params;
}

FunCcallInstruction::~FunCcallInstruction()
{
    if(!operands.empty())
    {
        operands[0]->removeUse(this);
        operands[1]->removeUse(this);
    }
}

void FunCcallInstruction::output() const
{
        std::string retoperand, func_type,calloperand;
        retoperand = operands[0]->toStr();//返回值
        calloperand = operands[1]->toStr();//函数名称
        func_type = operands[1]->getType()->toStr();//函数类型
        
        //接下来分void和int类型的处理
        if(func_type=="void"||func_type=="void()")
        {
            
            if(this->params.size()==0)//没有参数直接输出
            {
                fprintf(yyout, "  call %s %s()\n", func_type.c_str(), calloperand.c_str());
            }
            else
            {
                //fprintf(stderr, "  call %s \n",func_type.c_str() );
                fprintf(yyout, "  call void( ");
                //输出参数格式：
                int num=this->params.size();
                std::vector<Operand *>::const_iterator it=this->params.begin();
                Operand* ope=*it;
                //fprintf(stderr,"func name: %s, params num: %d\n", calloperand.c_str(), num);
                for(int i=0;i<num-1;i++)
                {
                    
                    fprintf(yyout, "%s, ", ope->getType()->toStr().c_str());
                    
                    it++;
                    ope=*it;
                    
                }
                //最后一个参数 
                fprintf(yyout, "%s ", ope->getType()->toStr().c_str());
                
                fprintf(yyout, ") %s(",calloperand.c_str());//函数左端
                
                //下面开始遍历输出参数的信息 为了满足输出格式 最后一个参数要特别处理
                
                std::vector<Operand *>::const_iterator it1=this->params.begin();
                ope=*it1;
                for(int i=0;i<num-1;i++)
                {
                    
                    fprintf(yyout, "%s %s,", ope->getType()->toStr().c_str(), ope->toStr().c_str());
                    
                    it1++;
                    ope=*it1;
                    
                }
                //最后一个参数 输出函数右端
                fprintf(yyout, "%s %s)\n", ope->getType()->toStr().c_str(), ope->toStr().c_str());
                
            }
        }
       else//如果是int() 即有返回值
       {
           fprintf(stderr,"func name: %s, params num: %d\n", calloperand.c_str(), this->params.size());
            if(this->params.size()==0)
            {
                fprintf(yyout, "  %s = call %s %s()\n", retoperand.c_str(), func_type.c_str(), calloperand.c_str());
            }
            else
            {
                //同上 只不过开头不同
                fprintf(yyout, "  %s = call %s %s(", retoperand.c_str(), func_type.c_str(), calloperand.c_str());
                
                int num=this->params.size();
                num = (num+1)>>1;
                std::vector<Operand *>::const_iterator it=this->params.begin();
                Operand* ope=*it;
                for(int i=0;i<num-1;i++)
                {
                    
                    fprintf(yyout, "i32 %s,", /*ope->getType()->toStr().c_str(),*/ ope->toStr().c_str());
                   
                    it++;
                    it++;//dyt add
                    ope=*it;
                }
                //最后一个参数 输出函数右端
                fprintf(yyout, "i32 %s)\n", /*ope->getType()->toStr().c_str(),*/ ope->toStr().c_str());
                
                
               
                
               
            }
       }
}



