#include <iostream>
#include <string.h>
#include <unistd.h>
#include "Ast.h"
#include "Unit.h"
#include"Type.h"
#include"SymbolTable.h"
using namespace std;

Ast ast;
Unit unit;
extern FILE *yyin;
extern FILE *yyout;

int yyparse();

char outfile[256] = "a.out";
bool dump_tokens;
bool dump_ast;
bool dump_ir;

int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "iato:")) != -1)
    {
        switch (opt)
        {
        case 'o':
            strcpy(outfile, optarg);
            break;
        case 'a':
            dump_ast = true;
            break;
        case 't':
            dump_tokens = true;
            break;
        case 'i':
            dump_ir = true;
            break;
        default:
            fprintf(stderr, "Usage: %s [-o outfile] infile\n", argv[0]);
            exit(EXIT_FAILURE);
            break;
        }
    }
    if (optind >= argc)
    {
        fprintf(stderr, "no input file\n");
        exit(EXIT_FAILURE);
    }
    if (!(yyin = fopen(argv[optind], "r")))
    {
        fprintf(stderr, "%s: No such file or directory\nno input file\n", argv[optind]);
        exit(EXIT_FAILURE);
    }
    if (!(yyout = fopen(outfile, "w")))
    {
        fprintf(stderr, "%s: fail to open output file\n", outfile);
        exit(EXIT_FAILURE);
    }
    //与上次不同 这次要包含函数的类型
    SymbolEntry *se1,*se2,*se3,*se4;
    Type *funcType1,*funcType2,*funcType3,*funcType4;
    
    
    
    //getint没有参数 
    funcType1 = new FunctionType(TypeSystem::intType,{},0);
    se1 = new IdentifierSymbolEntry(funcType1, "getint", identifiers->getLevel());
    
   //getch没有参数 
    funcType2 = new FunctionType(TypeSystem::intType,{},0);
    se2 = new IdentifierSymbolEntry(funcType2, "getch", identifiers->getLevel());
    
    //putint 有一个int参数
    funcType3 = new FunctionType(TypeSystem::voidType,{TypeSystem::intType},1);
    se3 = new IdentifierSymbolEntry(funcType3, "putint", identifiers->getLevel());
    
   //putch 有一个int参数
    funcType4 = new FunctionType(TypeSystem::voidType,{TypeSystem::intType},1);
    se4 = new IdentifierSymbolEntry(funcType4, "putch", identifiers->getLevel());
   
    
     
    //将sysy运行时库函数加入符号表中
    identifiers->install("getint",se1);
    identifiers->install("getch",se2);
    identifiers->install("putint",se3);
     identifiers->install("putch", se4);
     
    
    
    yyparse();//构建语法树
    fprintf(stderr, "语法树构建完成 \n");
   //fprintf(stderr, "break 1 \n");
    if(dump_ast)
        ast.output();//输出语法树
    fprintf(stderr, "语法树输出完成 \n");
    ast.typeCheck();//类型检查
    fprintf(stderr, "类型检查完成 \n");
     //fprintf(stderr, "break 3 \n");
    ast.genCode(&unit);//中间代码生成
    fprintf(stderr, "中间代码生成完成 \n");
    if(dump_ir)
        unit.output();
    fprintf(stderr, "中间代码输出完成 \n");
    return 0;
}
