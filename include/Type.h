#ifndef __TYPE_H__
#define __TYPE_H__
#include <vector>
#include <string>
#include <Operand.h>
class Type
{
private:
    int kind;
protected:
    enum {INT, VOID, FUNC,CONST, PTR};
public:
    Type(int kind) : kind(kind) {};
    virtual ~Type() {};
    virtual std::string toStr() = 0;
    bool isInt() const {return kind == INT;};
    bool isVoid() const {return kind == VOID;};
    bool isFunc() const {return kind == FUNC;};
     bool isConst() const {return kind == CONST;};
};

class IntType : public Type
{
private:
    int size;
public:
    IntType(int size) : Type(Type::INT), size(size){};
    std::string toStr();
};

class VoidType : public Type
{
public:
    VoidType() : Type(Type::VOID){};
    std::string toStr();
};

class FunctionType : public Type
{
private:
    
    Type *returnType;
    std::vector<Type*> paramsType;
    int paranum;
public:
    /*FunctionType(Type* returnType, std::vector<Type*> paramsType) : 
    Type(Type::FUNC), returnType(returnType), paramsType(paramsType){};*/
    
    FunctionType(Type* returnType, std::vector<Type*> paramsType,int paranum) : 
    Type(Type::FUNC), returnType(returnType), paramsType(paramsType),paranum(paranum){};
    
    FunctionType(Type* returnType, std::vector<Type*> paramsType) : 
    Type(Type::FUNC), returnType(returnType), paramsType(paramsType){};
    
    Type* getRetType() {return returnType;};
    std::string toStr();
    int getnum(){return paranum;};
    std::vector<Type*> get_vector_type(){return paramsType;};
};

class ConstType : public Type
{
private:
    int size;
public:
    ConstType(int size) : Type(Type::CONST), size(size){};
    std::string toStr();
};


class PointerType : public Type
{
private:
    Type *valueType;
public:
    PointerType(Type* valueType) : Type(Type::PTR) {this->valueType = valueType;};
    std::string toStr();
};

class TypeSystem
{
private:
    static IntType commonInt;
    static IntType commonBool;
    static VoidType commonVoid;
    static ConstType commonConst;
public:
    static Type *intType;
    static Type *voidType;
    static Type *boolType;
    static Type *constType;
};




class Func_def_para//记录定义参数个数
{
private:
    int num;
public:
    Func_def_para(){num=0;};
    void plus(){num++;};
    void reset(){num=0;};
    int ret_num(){return num;};
};
static Func_def_para def_fun;

class Func_paratype//记录定义参数类型
{
private:
    std::vector<Type*> paramsType;
public:
    Func_paratype(){paramsType={};};
    void push(Type * k){paramsType.push_back(k);};
    std::vector<Type*> get(){return paramsType;};
    void reset(){paramsType.clear();};
};
static Func_paratype func_para;


class Func_call_para//记录调用参数个数
{
private:
    int num;
public:
    Func_call_para(){num=0;};
    void plus(){num++;};
    void reset(){num=0;};
    int ret_num(){return num;};
};
static Func_call_para call_fun;

class FuncCall_paratype{//存放调用时 参数类型 只在生成中间代码使用
private:
    std::vector<Operand*> paralist;
public:
    FuncCall_paratype(){paralist={};};
    void push(Operand* k){paralist.push_back(k);};
    std::vector<Operand*> get(){return paralist;};
    void reset(){paralist.clear();};
};
static FuncCall_paratype callparamsType;







/*
static int para_num;//定义参数个数
static int use_num;//调用参数个数
std::vector<Type*> param_Type;
*/
#endif
