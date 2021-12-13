%option noyywrap
%{
    /*
    * You will need to comment this line in lab5.
    */
    #define ONLY_FOR_LEX
    int IDcnt=0;//count ID number
    char **idtable;
    
    #ifdef ONLY_FOR_LEX
    //add for lab4
    
    #else
    #define YYSTYPE void *
    #include "parser.h"
    #endif

    #define YY_NO_UNPUT
    #define YY_NO_INPUT
    #include <string>
    #include<map>
    #ifdef ONLY_FOR_LEX
    #include <ostream>
    #include <fstream>
    
    using namespace std;
    extern FILE *yyin; 
    extern FILE *yyout;
    //下面是为了符号表添加的结构
    

    int IDno=0;//从0开始记录id
    //int isnew=0;//判断作用域是否变化
    
    
  
    struct IDstruct{
    map<string,int> idmap;
    IDstruct* last=NULL;
    
    };
    IDstruct * root=new IDstruct;//作为根结构 存放一些全局变量的id
    IDstruct* cur=root;
    
    void DEBUG_FOR_LAB4(std::string s){
        std::string DEBUG_INFO = "[DEBUG LAB4]: \t" + s + "\n";
        fputs(DEBUG_INFO.c_str(), yyout);
    }
    #endif
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

SCIENCE {DECIMAL}(\.[0-9]+)?([Ee][-+]?[0-9]+)?
DECIMAL ([1-9][0-9]*|0)
HEXADECIMAL 0[xX][a-fA-F0-9]+
BINARY 0[bB][01]+
OCTAL 0[0-7]+
NUMBER ({HEXADECIMAL}|{DECIMAL}|{OCTAL}|{BINARY})

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

ERROR .

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
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"INT\tint\t%d\n",yylineno);
    #else
        return INT;
    #endif
}
"long" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"LONG\tlong\t%d\n",yylineno);
	#else
		return LONG;
	#endif
}
"signed" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"SIGNED\tsigned\t%d\n",yylineno);
	#else
		return SIGNED;
	#endif
}
"throw" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"THROW\tthrow\t%d\n",yylineno);
	#else
		return THROW;
	#endif
}
"union" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"UNION\tunion\t%d\n",yylineno);
	#else
		return UNION;
	#endif
}

"this" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"THIS\tthis\t%d\n",yylineno);
	#else
		return THIS;
	#endif
}

"unsigned" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"UNSIGNED\tunsigned\t%d\n",yylineno);
	#else
		return UNSIGNED;
	#endif
}

"goto" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"GOTO\tgoto\t%d\n",yylineno);
	#else
		return GOTO;
	#endif
}


"virtual" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"VIRTUAL\tvirtual\t%d\n",yylineno);
	#else
		return VIRTUAL;
	#endif
}

"auto" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"AUTO\tauto\t%d\n",yylineno);
	#else
		return AUTO;
	#endif
}

"class" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"CLASS\tclass\t%d\n",yylineno);
	#else
		return CLASS;
	#endif
}

"case" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"CASE\tcase\t%d\n",yylineno);
	#else
		return CASE;
	#endif
}

"new" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"NEW\tnew\t%d\n",yylineno);
	#else
		return NEW;
	#endif
}

"enum" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"ENUM\tenum\t%d\n",yylineno);
	#else
		return ENUM;
	#endif
}

"sizeof" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"SIZEOF\tsizeof\t%d\n",yylineno);
	#else
		return SIZEOF;
	#endif
}

"private" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"PRIVATE\tprivate\t%d\n",yylineno);
	#else
		return PRIVATE;
	#endif
}
"protected" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"PROTECTED\tprotected\t%d\n",yylineno);
	#else
		return PROTECTED;
	#endif
}

"delete" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"DELETE\tdelete\t%d\n",yylineno);
	#else
		return DELETE;
	#endif
}
"public" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"PUBLIC\tpublic\t%d\n",yylineno);
	#else
		return PUBLIC;
	#endif
}

"struct" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"STRUCT\tstruct\t%d\n",yylineno);
	#else
		return STRUCT;
	#endif
}

"double" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"DOUBLE\tdouble\t%d\n",yylineno);
	#else
		return DOUBLE;
	#endif
}
"float" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"FLOAT\tfloat\t%d\n",yylineno);
	#else
		return FLOAT;
	#endif
}
"char" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"CHAR\tchar\t%d\n",yylineno);
	#else
		return CHAR;
	#endif
}
"for" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"FOR\tfor\t%d\n",yylineno);
	#else
		return FOR;
	#endif
}
"do" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"DO\tdo\t%d\n",yylineno);
	#else
		return DO;
	#endif
}
"default" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"DEFAULT\tdefault\t%d\n",yylineno);
	#else
		return DEFAULT;
	#endif
}
"const" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"CONST\tconst\t%d\n",yylineno);
	#else
		return CONST;
	#endif
}
"void" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"VOID\tvoid\t%d\n",yylineno);
    #else
        return VOID;
    #endif 
}
"short" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"SHORT\tshort\t%d\n",yylineno);
	#else
		return SHORT;
	#endif
}
"break" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"BREAK\tbreak\t%d\n",yylineno);
	#else
		return BREAK;
	#endif
}
"continue" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"CONTINUE\tcontinue\t%d\n",yylineno);
	#else
		return CONTINUE;
	#endif
}
"if" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"IF\tif\t%d\n",yylineno);
    #else
        return IF;
    #endif
}
"else" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"ELSE\telse\t%d\n",yylineno);
    #else
        return ELSE;
    #endif
}
"while" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"WHILE\twhile\t%d\n",yylineno);
	#else
		return WHILE;
	#endif
}
"return" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"RETURN\treturn\t%d\n",yylineno);
    #else
        return RETURN;
    #endif
}
"==" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"EQ\t==\t%d\n",yylineno);
    #else
        return EQ;
    #endif
}


"=" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"ASSIGN\t=\t%d\n",yylineno);
    #else
        return ASSIGN;
    #endif
}
"<" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"LESS\t<\t%d\n",yylineno);
    #else
        return LESS;
    #endif
}
">" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"GTR\t>\t%d\n",yylineno);
	#else
		return GTR;
	#endif
}
"!=" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"NEQ\t!=\t%d\n",yylineno);
	#else
		return NEQ;
	#endif
}
"<=" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"LEQ\t<=\t%d\n",yylineno);
	#else
		return LEQ;
	#endif
}
">=" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"GEQ\t>=\t%d\n",yylineno);
	#else
		return GEQ;
	#endif
}
"+" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"ADD\t+\t%d\n",yylineno);
    #else
        return ADD;
    #endif
}
"-" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"SUB\t-\t%d\n",yylineno);
	#else
		return SUB;
	#endif
}
"*" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"MUL\t*\t%d\n",yylineno);
	#else
		return MUL;
	#endif
}
"/" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"DIV\t/\t%d\n",yylineno);
	#else
		return DIV;
	#endif
}
"%" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"REM\t%%\t%d\n",yylineno);
	#else
		return REM;
	#endif
}
"++" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"INC\t++\t%d\n",yylineno);
	#else
		return INC;
	#endif
}
"--" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"DEC\t--\t%d\n",yylineno);
	#else
		return DEC;
	#endif
}

";" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"SEMICOLON\t;\t%d\n",yylineno);
    #else
        return SEMICOLON;
    #endif
}
"(" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"LPAREN\t(\t%d\n",yylineno);
    #else
        return LPAREN;
    #endif
}
")" {
    #ifdef ONLY_FOR_LEX
        fprintf(yyout,"RPAREN\t)\t%d\n",yylineno);
    #else
    return RPAREN;
    #endif
}

"[" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"LBRACK\t[\t%d\n",yylineno);
	#else
		return LBRACK;
	#endif
}
"]" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"RBRACK\t[\t%d\n",yylineno);
	#else
		return RBRACK;
	#endif
}
"," {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"COMMA\t,\t%d\n",yylineno);
	#else
		return COMMA;
	#endif
}
":" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"COLON\t:\t%d\n",yylineno);
	#else
		return COLON;
	#endif
}
"\"" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"DQUA\t\"\t%d\n",yylineno);
		fprintf(yyout,"DQUA\t\"\t%d\n",yylineno);
	#else
		return DQUA;
	#endif
}
"\'" {
	#ifdef ONLY_FOR_LEX
		fprintf(yyout,"SQUA\t\'\t%d\n",yylineno);
	#else
		return SQUA;
	#endif
}
"{" {//左括号意味着新的作用域开始
    #ifdef ONLY_FOR_LEX
        
        //isnew=1;
        IDstruct* newstruct=new IDstruct;
        newstruct->last=cur;
        cur=newstruct;
        fprintf(yyout,"LBRACE\t{\t%d\n",yylineno);
    #else
        return LBRACE;
    #endif
}
"}" {//右大括号意味着上一个作用域结束
    #ifdef ONLY_FOR_LEX
        if(cur->last!=NULL)
        {
            cur=cur->last;
            
            
        }

        fprintf(yyout,"RBRACE\t}\t%d\n",yylineno);
    #else
        return RBRACE;
    #endif
}
{ID} {
    #ifdef ONLY_FOR_LEX
        //
        int ifexist=0;
        /*IDstruct* tmp=cur;
        for(;tmp!=NULL;tmp=tmp->last)
        {
            if(tmp->idmap.count(yytext)!=0)
            {
                ifexist=1;
                break;
            }
        }*/
        if(cur->idmap.count(yytext)!=0)//查看当前作用域是否已经拥有了此id
            ifexist=1;
        //如果当前作用域已经存在此id 且
        if(ifexist==1)
        {
            int id=cur->idmap[yytext];
            
            fprintf(yyout,"ID\t%s\t%d\t%d\n",yytext,yylineno,id);
        }
        else{
            cur->idmap.insert(pair<string,int>(yytext,IDno++));
            //isnew=0;
            fprintf(yyout,"ID\t%s\t%d\t%d\n",yytext,yylineno,cur->idmap[yytext]);
        
        }

	#else
		return ID;
	#endif
}
{NUMBER} {
		#ifdef ONLY_FOR_LEX//only identify binary, octal, decimal, hexdecimal numbers
			int res = 0;
			if(int(strlen(yytext))>1){
				if(yytext[0]=='0'){
					if(yytext[1]=='b'||yytext[1]=='B'){//binary
						int i;
						for(i=2;i<int(strlen(yytext));i++){
							res=(res<<1)+int(yytext[i])-48;
						}
					}
					else if(yytext[1]=='x'||yytext[1]=='X'){//hexdecimal
						int i;
						for(i=2;i<int(strlen(yytext));i++){
							int tmp=0;
							if(yytext[i]<='F'&&yytext[i]>='A'){
								tmp=10+int(yytext[i])-'A';
							} else if(yytext[i]<='f'&&yytext[i]>='a'){
								tmp=10+int(yytext[i])-'a';
							} else tmp=int(yytext[i])-48;
							res=(res<<4)+tmp;
						}
					}
					else{//octal
						int i;
						for(i=1;i<int(strlen(yytext));i++){
							res=(res<<3)+int(yytext[i])-48;
						}
					}
				}
				//else, the number is scientific notation or decimal.
				else{
					int i;
					for(i=0;i<int(strlen(yytext));i++){
						res=res*10+int(yytext[i])-48;
					}
				}
			}
			else{
				int i;
				for(i=0;i<int(strlen(yytext));i++){
					res=res*10+int(yytext[i])-48;
				}
			}
			fprintf(yyout,"NUMBER\t%s\t%d\t%d\n",yytext,res,yylineno);
		#else
			return NUMBER;
		#endif
}

{EOL} yylineno++;
{WHITE} ;
{ERROR} {
        #ifdef ONLY_FOR_LEX
            fprintf(yyout,"ERROR!!!\t%d\n",yylineno);
        #else
            return ERROR;
        #endif
}
%%

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
