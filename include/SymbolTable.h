#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include <string>
#include <map>
//#include"Type.h"
class Type;
class FunctionType;
class Operand;
 
//表项基类  kind用于区分 变量 常量 中间变量
//type保存int或者void类型  
//toStr针对不同类型输出值
class SymbolEntry
{
private:
    int kind;
protected:
    enum {CONSTANT, VARIABLE, TEMPORARY};
    Type *type;

public:
    SymbolEntry(Type *type, int kind);
    //SymbolEntry(FunctionType *type, int kind);
    SymbolEntry(int kind);
    virtual ~SymbolEntry() {};
    bool isConstant() const {return kind == CONSTANT;};
    bool isTemporary() const {return kind == TEMPORARY;};
    bool isVariable() const {return kind == VARIABLE;};
    Type* getType() {return type;};
    
    void setType(Type *type) {this->type = type;};
    virtual std::string toStr() = 0;
    // You can add any function you need here.
};


/*  
    Symbol entry for literal constant. Example:

    int a = 1;

    Compiler should create constant symbol entry for literal constant '1'.
*/
class ConstantSymbolEntry : public SymbolEntry
{
private:
    int value;
    std::string name;
    int flag;
    int scope;
    enum {GLOBAL, PARAM, LOCAL};
public:
    ConstantSymbolEntry(Type *type, int value);
    ConstantSymbolEntry(Type *type, std::string name, int scope);
    virtual ~ConstantSymbolEntry() {};
    int getValue() const {return value;};
    std::string toStr();//将value转换为字符串输出
    int getScope() const {return scope;};
    // You can add any function you need here.
};


/* 
    Symbol entry for identifier. Example:

    int a;
    int b;
    void f(int c)
    {
        int d;
        {
            int e;
        }
    }

    Compiler should create identifier symbol entries for variables a, b, c, d and e:

    | variable | scope    |
    | a        | GLOBAL   |
    | b        | GLOBAL   |
    | c        | PARAM    |
    | d        | LOCAL    |
    | e        | LOCAL +1 |
*/
class IdentifierSymbolEntry : public SymbolEntry
{
private:
    enum {GLOBAL, PARAM, LOCAL};
    std::string name;
    int scope;
    Operand *addr;  // The address of the identifier. 变量地址
    // You can add any field you need here.

public:
    IdentifierSymbolEntry(Type *type, std::string name, int scope);
    IdentifierSymbolEntry(std::string name, int scope);
    virtual ~IdentifierSymbolEntry() {};
    std::string toStr();
    bool isGlobal() const {return scope == GLOBAL;};
    bool isParam() const {return scope == PARAM;};
    bool isLocal() const {return scope == LOCAL;};
    int getScope() const {return scope;};
    void setAddr(Operand *addr) {this->addr = addr;};
    Operand* getAddr() {return addr;};
    
    // You can add any function you need here.
    void increasescope(){scope++;}
    std::string get_name(){return name;};
    int use;
    int kput;
};


/* 
    Symbol entry for temporary variable created by compiler. Example:

    int a;
    a = 1 + 2 + 3;

    The compiler would generate intermediate code like:

    t1 = 1 + 2
    t2 = t1 + 3
    a = t2

    So compiler should create temporary symbol entries for t1 and t2:

    | temporary variable | label |
    | t1                 | 1     |
    | t2                 | 2     |
*/
class TemporarySymbolEntry : public SymbolEntry
{
private:
    int label;
public:
    TemporarySymbolEntry(Type *type, int label);
    virtual ~TemporarySymbolEntry() {};
    std::string toStr();//输出label
    int getLabel() const {return label;};
    // You can add any function you need here.
};

// symbol table managing identifier symbol entries
class SymbolTable
{
private:
    std::map<std::string, SymbolEntry*> symbolTable;
    SymbolTable *prev;
    int level;
    static int counter;
public:
    SymbolTable();
    SymbolTable(SymbolTable *prev);
    void install(std::string name, SymbolEntry* entry);
    SymbolEntry* lookup(std::string name);
    SymbolEntry* search_func();
    SymbolEntry* search_inthis(std::string name);
    SymbolTable* getPrev() {return prev;};
    int getLevel() {return level;};
    static int getLabel() {return counter++;};
    static int getLabelnotInc() {return counter;};//dyt add
};

extern SymbolTable *identifiers;
extern SymbolTable *globals;

#endif
