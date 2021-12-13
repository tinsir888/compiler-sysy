#include "SymbolTable.h"
#include <iostream>
#include <sstream>
#include"Type.h"
SymbolEntry::SymbolEntry(Type *type, int kind) 
{
    this->type = type;
    this->kind = kind;
}
SymbolEntry::SymbolEntry( int kind) //定义构造函数
{
    
    this->kind = kind;

}

ConstantSymbolEntry::ConstantSymbolEntry(Type *type, int value) : SymbolEntry(type, SymbolEntry::CONSTANT)
{
    this->flag=0;
    this->value = value;
}
ConstantSymbolEntry::ConstantSymbolEntry(Type *type, std::string name, int scope) : SymbolEntry(type, SymbolEntry::CONSTANT), name(name)
{
    this->flag=1;
    this->scope = scope;
}

std::string ConstantSymbolEntry::toStr()
{
    std::ostringstream buffer;
    buffer << value;
    return buffer.str();
}

IdentifierSymbolEntry::IdentifierSymbolEntry(Type *type, std::string name, int scope) : SymbolEntry(type, SymbolEntry::VARIABLE), name(name)
{
    this->scope = scope;
    addr = nullptr;
   use=-1;
    kput=-1;
}
IdentifierSymbolEntry::IdentifierSymbolEntry(std::string name, int scope) : SymbolEntry(SymbolEntry::VARIABLE), name(name)
{
    this->scope = scope;
     addr = nullptr;
     use=-1;
    kput=-1;
}
//需要修改的
static int var_no=0;
std::string IdentifierSymbolEntry::toStr()
{
    //修改否则返回的名称和变量名称不同
    //观察实例代码可知 只有全局变量才可以直接输出name 否则要输出%+标号的形式
    std::string prefix,tail;
    prefix="%";
    Type* temp=this->getType();
    if(temp->isFunc()||this->getScope()==0)
    {
        return "@"+name;
    }
    else
    {//对于局部变量 类似于中间变量一样进行标号 
    //标号可以初始化定义 也可以根据当前下标进行设置 例如i1  i10等等
       if(use==-1)
       {
           use=var_no;
           var_no++;
       }
       if(this->getScope()==1){
            //SymbolEntry* tmp_se = SymbolTable::lookup(this->get_name());
            //fprintf(stderr, "name: %s, var_no=%d\n",name.c_str(), var_no);
    }
       tail=std::to_string(use);
       return prefix+tail;//+this->get_name();
    }
    
    
    
    
    
    
    
}

TemporarySymbolEntry::TemporarySymbolEntry(Type *type, int label) : SymbolEntry(type, SymbolEntry::TEMPORARY)
{
    this->label = label;
}

std::string TemporarySymbolEntry::toStr()
{
    std::ostringstream buffer;
    buffer << "%t" << label;//<<":scope"<<this->scope;
    //test
    //fprintf(stderr, "%d\n", label);
    return buffer.str();
}

SymbolTable::SymbolTable()
{
    prev = nullptr;
    level = 0;
}

SymbolTable::SymbolTable(SymbolTable *prev)
{
    this->prev = prev;
    this->level = prev->level + 1;
}

/*
    Description: lookup the symbol entry of an identifier in the symbol table
    Parameters: 
        name: identifier name
    Return: pointer to the symbol entry of the identifier

    hint:
    1. The symbol table is a stack. The top of the stack contains symbol entries in the current scope.
    2. Search the entry in the current symbol table at first.
    3. If it's not in the current table, search it in previous ones(along the 'prev' link).
    4. If you find the entry, return it.
    5. If you can't find it in all symbol tables, return nullptr.
*/
SymbolEntry* SymbolTable::lookup(std::string name)
{
    // Todo
    
    
    SymbolTable *cur=this;

    while(cur->prev!=nullptr)
    {
        if(cur->symbolTable.count(name)==0)
        {
            cur=cur->getPrev();
        }
        else{

            //
            //fprintf(stderr, "lookup %s: %s\n",name.c_str(),cur->symbolTable[name]->toStr().c_str());
            //
            return cur->symbolTable[name];
            
        }
    }
    if(cur->symbolTable.count(name)!=0)
     {
            return cur->symbolTable[name];
     }
    return nullptr;
}
SymbolEntry* SymbolTable::search_inthis(std::string name)
{
    // Todo
    SymbolTable *cur=this;

    
       
    if(cur->symbolTable.count(name)!=0)
     {
            //fprintf(stderr, "lookup %s: %s\n",name.c_str(),cur->symbolTable[name]->toStr().c_str());
            return cur->symbolTable[name];
     }
    return nullptr;
}

SymbolEntry* SymbolTable::search_func()
{
    // Todo
    SymbolTable *cur=this;

    while(cur->prev!=nullptr)
    {
        //遍历当前作用域的符号表
        std::map<std::string, SymbolEntry*>::iterator iter;
        iter=cur->symbolTable.begin();
        while(iter !=cur->symbolTable.end())
        {
            SymbolEntry* se=iter->second;//获取当前符号表项
            if(se->getType()->isFunc()==1)
            {
                return se;
            }
            iter++;
        }
      
       cur=cur->getPrev();
        
    }
    //遍历最顶部作用域的符号表
    std::map<std::string, SymbolEntry*>::iterator iter;
    iter=cur->symbolTable.begin();
    while(iter !=cur->symbolTable.end())
    {
        SymbolEntry* se=iter->second;//获取当前符号表项
        if(se->getType()->isFunc()==1)
        {
            return se;
        }
        iter++;
    }
    return nullptr;
}


// install the entry into current symbol table.
void SymbolTable::install(std::string name, SymbolEntry* entry)
{
    symbolTable[name] = entry;
}

int SymbolTable::counter = 0;
static SymbolTable t;
SymbolTable *identifiers = &t;
SymbolTable *globals = &t;
