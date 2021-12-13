%option noyywrap
%{
    #define YY_NO_UNPUT
    #define YY_NO_INPUT

    #include "parser.h"
    #include <ostream>
    #include <fstream>
    using namespace std;

    extern FILE *yyin; 
    extern FILE *yyout;
    extern bool dump_tokens;

    void DEBUG_FOR_LAB4(std::string s){
        std::string DEBUG_INFO = "[DEBUG LAB4]: \t" + s + "\n";
        fputs(DEBUG_INFO.c_str(), yyout);
    }
%}

INTEGER ([1-9]+[0-9]*)|(0)
OCT (0)([1-7]+[0-7]*)|(0)
HEX (0x)([1-9A-Fa-f]+[0-9A-Fa-f]*)|(0)
digit [0-9]
alpha [A-Za-z]
ID [[:alpha:]_][[:alpha:][:digit:]_]*
STRING ["][^"]*["]
EOL (\r\n|\n|\r)*
WHITE [ \t]*
LINECOMMENT \/\/[^\n]*
CONST "const"
VOID "void"
IF "if"
ELSE "else"
WHILE "while"
BREAK "break"
CONTINUE "continue"
RETURN "return"
INT "int"
PUTF "putf"
COMMA ","
MOD "%"
commentbegin "/*"
commentelement1 .
commentelement2 \n
commentend "*/"
%x COMMENT
%%
{commentbegin} {BEGIN COMMENT;}
<COMMENT>{commentelement1} {}
<COMMENT>{commentelement2} {yylineno++;}
<COMMENT>{commentend} {BEGIN INITIAL;}


"int" {
    /*
    * Questions: 
    *   Q1: Why we need to return INT in further labs?
    *   Q2: What is "INT" actually?
    */
    if(dump_tokens)
        DEBUG_FOR_LAB4("INT\tint");
    return INT;
}
"void" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("VOID\tvoid");
    return VOID;
}
"if" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("IF\tif");
    return IF;
}
"else" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("ELSE\telse");
    return ELSE;
}
"return" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("RETURN\treturn");
    return RETURN;
}

"=" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("ASSIGN\t=");
    return ASSIGN;
}
"<" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("LESS\t<");
    return LESS;
}
">" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("LARGE\t>");
    return LARGE;
}
">=" {return LARAND;}
"<=" {return LESAND;}
"+" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("ADD\t+");
    return ADD;
}
"-" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("SUB\t-");
    return SUB;
}
"*" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("MUL\t*");
    return MUL;
}

"!" {return NOT;}
"||" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("OR\t|");
    return OR;
}
"&&" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("AND\t&");
    return AND;
}
"^" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("XOR\t^");
    return XOR;
}
"/" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("DIV\t/");
    return DIV;
}
";" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("SEMICOLON\t;");
    return SEMICOLON;
}

"%" {return MOD;}

"(" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("LPAREN\t(");
    return LPAREN;
}
")" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("RPAREN\t)");
    return RPAREN;
}
"{" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("LBRACE\t{");
    return LBRACE;
}
"!=" {return NOEQU;}
"==" {return EQU;}
"}" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("RBRACE\t}");
    return RBRACE;
}
"[" {
    return LBRACK;
}
"]" {
    return RBRACK;
}
{WHILE} {
    if(dump_tokens)
        DEBUG_FOR_LAB4("WHILE\tWHILE}");
    return WHILE;
}
"continue" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("CONTINUE\tcontinue}");
    return CONTINUE;
}

{COMMA} {
    return COMMA;
}
"const" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("CONST\tconst}");
    return CONST;
}
"break" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("BREAK\tbreak}");
    return BREAK;
}
"putf" {return PUTF;}
{EOL} {yylineno++;}
{LINECOMMENT} {}
{INTEGER} {
    if(dump_tokens)
        DEBUG_FOR_LAB4(yytext);
    yylval.itype = atoi(yytext);
    return INTEGER;
}


{OCT} {
    if(dump_tokens)
        DEBUG_FOR_LAB4(yytext);
    yylval.itype = strtol(yytext,NULL,8);
    return OCT;
}
{HEX} {
    if(dump_tokens)
        DEBUG_FOR_LAB4(yytext);
    yylval.itype = strtol(yytext,NULL,16);
    return HEX;
}
{ID} {
    if(dump_tokens)
        DEBUG_FOR_LAB4(yytext);
    char *lexeme;
    lexeme = new char[strlen(yytext) + 1];
    strcpy(lexeme, yytext);
    yylval.strtype = lexeme;
    return ID;
}
{STRING} { 
    char *lexeme;
    lexeme = new char[strlen(yytext) + 1];
    strcpy(lexeme, yytext);
    yylval.strtype = lexeme;
    return STRING;
}
%%
