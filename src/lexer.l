%option noyywrap
%{
   
    #include "parser.h"
    
    #define YY_NO_UNPUT
    #define YY_NO_INPUT
    
    #include <string>
    
    
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






EQ ==
LSS <
GTR >
NEQ !=
LEQ <=
GEQ >=

ADD \+
SUB \-
MUL \*
DIV \/
REM %
INC \+\+
DEC \-\-


AND &&
OR ||
NOT !


DECIMIAL ([1-9][0-9]*|0)
OCTAL_DECIMIAL (0[1-7][0-7]*|00)
HEX_DECIMAL (0x[1-9,a-f,A-F][0-9,a-f,A-F]*|0X[1-9,a-f,A-F][0-9,a-f,A-F]*|0x0|0X0)


BREAK break
CHAR char
CONST const
CONTINUE continue
DOUBLE double
ELSE else
FLOAT float
FOR for
IF if
INT int
LONG long
RETURN return
DO do
DEFAULT default
SHORT short
VOID void
WHILE while
PUTF "putf"
SIGNED signed
THROW throw
UNION union
THIS this
UNSIGNED unsigned
GOTO goto
VIRTUAL virtual
AUTO auto
CLASS class
OPERATOR operator
CASE case
TYPEDEF typedef
STATIC static
FRIEND friend
TEMPLATE template
NEW new
REGISTER register
EXTERN extern
ENUM enum
INLINE inline
TRY try
SIZEOF sizeof
SWITCH switch
PRIVATE private
PROTECTED protected
ASM asm
CATCH catch
DELETE delete
PUBLIC public
VOLATILE volatile
STRUCT struct




STRING ["][^"]*["]
ID [[:alpha:]_][[:alpha:][:digit:]_]*
COMMENTBEGIN "/*"
COMMENTELEMENT [^\n]
COMMENTNEWLINE [\n]
COMMENTEND "*/"
LINECOMMENT \/\/[^\n]*
EOL (\r\n|\n|\r)
WHITE [\t ]
%x BLOCKCOMMENT
COMMENT {COMMENTBEGIN}{(COMMENTELEMENT|COMMENTNEWLINE)}*{COMMENTEND}

ASSIGN \=

LPAREN \(
LBRACK \[
LBRACE \{
COMMA ,
RPAREN \)
RBRACK \]
RBRACE \}
SEMICOLON ;
COLON :
DQUA \"
SQUA \'



%%
{LINECOMMENT} ;
{COMMENTBEGIN} {
	BEGIN BLOCKCOMMENT;
}
<BLOCKCOMMENT>{COMMENTELEMENT} ;
<BLOCKCOMMENT>{COMMENTNEWLINE} {
	yylineno++;
}
<BLOCKCOMMENT>{COMMENTEND} {
	BEGIN INITIAL;
}


"int" {
    /*
    * Questions: 
    *   Q1: Why we need to return INT in further labs?
    *   Q2: What is "INT" actually?
    */
    //#ifdef ONLY_FOR_LEX
    if(dump_tokens)
        fprintf(yyout,"INT\tint\t%d\n",yylineno);
    
     return INT;
    
}













"new" {
	
    if(dump_tokens)
		fprintf(yyout,"NEW\tnew\t%d\n",yylineno);
	
	return NEW;
	
}

"enum" {
	if(dump_tokens)
		fprintf(yyout,"ENUM\tenum\t%d\n",yylineno);
	
	return ENUM;
	
}



"delete" {
	if(dump_tokens)
		fprintf(yyout,"DELETE\tdelete\t%d\n",yylineno);
	
	return DELETE;
	
}

"const" {
	if(dump_tokens)
		fprintf(yyout,"CONST\tconst\t%d\n",yylineno);
	
	return CONST;
	
}
"void" {
    if(dump_tokens)
        fprintf(yyout,"VOID\tvoid\t%d\n",yylineno);
    
    return VOID;
     
}
"putf" {return PUTF;}
"break" {
	if(dump_tokens)
		fprintf(yyout,"BREAK\tbreak\t%d\n",yylineno);
	
	return BREAK;
	
}
"continue" {
	if(dump_tokens)
		fprintf(yyout,"CONTINUE\tcontinue\t%d\n",yylineno);
	
	return CONTINUE;
	
}
"if" {
    if(dump_tokens)
        fprintf(yyout,"IF\tif\t%d\n",yylineno);
    
    return IF;
    
}
"else" {
    if(dump_tokens)
        fprintf(yyout,"ELSE\telse\t%d\n",yylineno);
    
    return ELSE;
    
}
"while" {
	if(dump_tokens)
		fprintf(yyout,"WHILE\twhile\t%d\n",yylineno);
	
	return WHILE;
	
}
"return" {
    if(dump_tokens)
        fprintf(yyout,"RETURN\treturn\t%d\n",yylineno);
    
    return RETURN;
    
}
"==" {
    if(dump_tokens)
        fprintf(yyout,"EQ\t==\t%d\n",yylineno);
    
    return EQ;
    
}


"=" {
    if(dump_tokens)
        fprintf(yyout,"ASSIGN\t=\t%d\n",yylineno);
    
    return ASSIGN;
    
}
"<" {
    if(dump_tokens)
        fprintf(yyout,"LESS\t<\t%d\n",yylineno);
    
    return LESS;
    
}
">" {
	if(dump_tokens)
		fprintf(yyout,"GTR\t>\t%d\n",yylineno);
	
	return GTR;
	
}
"!=" {
	if(dump_tokens)
		fprintf(yyout,"NEQ\t!=\t%d\n",yylineno);
	
	return NEQ;
	
}
"<=" {
	if(dump_tokens)
		fprintf(yyout,"LEQ\t<=\t%d\n",yylineno);
	
	return LEQ;
	
}
">=" {
	if(dump_tokens)
		fprintf(yyout,"GEQ\t>=\t%d\n",yylineno);
	
	return GEQ;
	
}
"+" {
    if(dump_tokens)
        fprintf(yyout,"ADD\t+\t%d\n",yylineno);
    
    return ADD;
    
}
"-" {
	if(dump_tokens)
		fprintf(yyout,"SUB\t-\t%d\n",yylineno);
	
	return SUB;
	
}
"*" {
	if(dump_tokens)
		fprintf(yyout,"MUL\t*\t%d\n",yylineno);
	
	return MUL;
	
}
"/" {
	if(dump_tokens)
		fprintf(yyout,"DIV\t/\t%d\n",yylineno);
	
	return DIV;
	
}
"%" {
	if(dump_tokens)
		fprintf(yyout,"REM\t%%\t%d\n",yylineno);
	
	return REM;
	
}



";" {
    if(dump_tokens)
        fprintf(yyout,"SEMICOLON\t;\t%d\n",yylineno);
    
    return SEMICOLON;
    
}
"(" {
    if(dump_tokens)
        fprintf(yyout,"LPAREN\t(\t%d\n",yylineno);
    
    return LPAREN;
    
}
")" {
    if(dump_tokens)
        fprintf(yyout,"RPAREN\t)\t%d\n",yylineno);
    
    return RPAREN;
    
}

"[" {
	if(dump_tokens)
		fprintf(yyout,"LBRACK\t[\t%d\n",yylineno);
	
	return LBRACK;
	
}
"]" {
	if(dump_tokens)
		fprintf(yyout,"RBRACK\t[\t%d\n",yylineno);
	
	return RBRACK;
	
}
"," {
	if(dump_tokens)
		fprintf(yyout,"COMMA\t,\t%d\n",yylineno);
	
	return COMMA;
	
}
":" {
	if(dump_tokens)
		fprintf(yyout,"COLON\t:\t%d\n",yylineno);
	
	return COLON;
	
}
"\"" {
	if(dump_tokens)
		{fprintf(yyout,"DQUA\t\"\t%d\n",yylineno);
		fprintf(yyout,"DQUA\t\"\t%d\n",yylineno);}
	
	return DQUA;
	
}
"\'" {
	if(dump_tokens)
		fprintf(yyout,"SQUA\t\'\t%d\n",yylineno);
	
	return SQUA;
	
}


"&&" {
	if(dump_tokens)
		fprintf(yyout,"AND\t&&\t%d\n",yylineno);
	
	return AND;
}

"||" {
	if(dump_tokens)
		fprintf(yyout,"OR\t||\t%d\n",yylineno);
	return OR;
}


"!" {
	if(dump_tokens)
		fprintf(yyout,"NOT\t!\t%d\n",yylineno);
	return NOT;
}





"{" {
    if(dump_tokens)
       {
        fprintf(yyout,"LBRACE\t{\t%d\n",yylineno);
        
        }
    return LBRACE;
    
}
"}" {//右大括号意味着上一个作用域结束
    if(dump_tokens)
     {  
        fprintf(yyout,"RBRACE\t}\t%d\n",yylineno);
      }
        return RBRACE;
    
}
{ID} {
    if(dump_tokens)
 {
     DEBUG_FOR_LAB4(yytext);
    
 }
	 char *lexeme;
    lexeme = new char[strlen(yytext) + 1];
    strcpy(lexeme, yytext);
    yylval.strtype = lexeme;
		return ID;
	
}

{OCTAL_DECIMIAL} {//八进制 
    int num=1,sum=0;
    int l=strlen(yytext);
    for(int i=1;i<=l;++i){
        sum=sum+(yytext[l-i]-'0')*num;
        num*=8;
    } 
    const char *u=std::to_string(sum).c_str();
    char *lexeme;
    lexeme = const_cast<char*>(u);
    if(dump_tokens)
        DEBUG_FOR_LAB4(lexeme);
    yylval.itype = atoi(lexeme);
    return INTEGER;
}

{HEX_DECIMAL} {//16进制 
    int num=1,sum=0;
    int l=strlen(yytext);
    for(int i=1;i<=l-2;++i){
        if(yytext[l-i]>='A'&&yytext[l-i]<='F'){
            sum=sum+(yytext[l-i]-55)*num;
            num*=16;
        }
        else if(yytext[l-i]>='a'&&yytext[l-i]<='f'){
            sum=sum+(yytext[l-i]-87)*num;
            num*=16;
        }
        else{
            sum=sum+(yytext[l-i]-'0')*num;
            num*=16;
        }
    } 
    const char *u=std::to_string(sum).c_str();
    char *lexeme;
    lexeme = const_cast<char*>(u);
    if(dump_tokens)
        DEBUG_FOR_LAB4(lexeme);
    yylval.itype = atoi(lexeme);
    return INTEGER;
}


{DECIMIAL} {
    if(dump_tokens)
        DEBUG_FOR_LAB4(yytext);
    yylval.itype = atoi(yytext);
    return INTEGER;
}

{STRING} {
    char *lexeme= new char[strlen(yytext) + 1]; 
    strcpy(lexeme, yytext);
    yylval.strtype = lexeme;
    return STRING;
}




{EOL} yylineno++;
{WHITE} ;

%%
/*
#ifdef ONLY_FOR_LEX
int main(int argc, char **argv){
    if(argc != 5){
        fprintf(stderr, "Argument Not Enough");
        exit(EXIT_FAILURE);
    }

    if(!(yyin = fopen(argv[1], "r"))){
        fprintf(stderr, "No such file or directory: %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    if(!(yyout = fopen(argv[3], "w"))){
        fprintf(stderr, "No such file or directory: %s", argv[3]);
        exit(EXIT_FAILURE);
    }

    yylex();
    return 0;
}
#endif
*/
