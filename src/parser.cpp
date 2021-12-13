/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 1 "src/parser.y"

    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );

#line 76 "src/parser.cpp"




# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_INCLUDE_PARSER_H_INCLUDED
# define YY_YY_INCLUDE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 9 "src/parser.y"

    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"

#line 128 "src/parser.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    STRING = 259,
    INTEGER = 260,
    OCT = 261,
    HEX = 262,
    IF = 263,
    ELSE = 264,
    INT = 265,
    VOID = 266,
    LPAREN = 267,
    RPAREN = 268,
    LBRACE = 269,
    RBRACE = 270,
    LBRACK = 271,
    RBRACK = 272,
    SEMICOLON = 273,
    ADD = 274,
    SUB = 275,
    OR = 276,
    AND = 277,
    LESS = 278,
    LARGE = 279,
    ASSIGN = 280,
    XOR = 281,
    MUL = 282,
    DIV = 283,
    MOD = 284,
    LARAND = 285,
    LESAND = 286,
    NOT = 287,
    DECIMIAL = 288,
    WHILE = 289,
    BREAK = 290,
    CONTINUE = 291,
    CONST = 292,
    RETURN = 293,
    EQU = 294,
    NOEQU = 295,
    PUTF = 296,
    COMMA = 297,
    THEN = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "src/parser.y"

    int itype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;

#line 191 "src/parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    46,    47,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    64,    76,    80,    94,   106,
     110,   122,   135,   138,   143,   144,   148,   159,   165,   164,
     174,   181,   184,   189,   195,   198,   204,   208,   214,   218,
     221,   225,   229,   236,   239,   243,   247,   251,   254,   260,
     262,   268,   276,   278,   284,   290,   298,   300,   306,   312,
     318,   326,   327,   329,   333,   335,   343,   345,   353,   355,
     362,   365,   377,   387,   394,   403,   407,   416,   421,   431,
     432,   435,   440,   444,   448,   455,   462,   464,   469,   476,
     481,   487,   492,   496,   499,   502,   509,   513,   520,   535,
     535,   557,   558,   565,   573,   582,   587,   594,   600,   609,
     613
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INTEGER", "OCT", "HEX",
  "IF", "ELSE", "INT", "VOID", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACK", "RBRACK", "SEMICOLON", "ADD", "SUB", "OR", "AND", "LESS",
  "LARGE", "ASSIGN", "XOR", "MUL", "DIV", "MOD", "LARAND", "LESAND", "NOT",
  "DECIMIAL", "WHILE", "BREAK", "CONTINUE", "CONST", "RETURN", "EQU",
  "NOEQU", "PUTF", "COMMA", "THEN", "$accept", "Stmts", "Stmt",
  "InvalidStmt", "AssignStmt", "BlockStmt", "IfStmt", "ReturnStmt",
  "DeclStmt", "FuncDef", "WhileStmt", "STREAM", "ContrStmt", "ConstDecl",
  "VarDecl", "Exp", "AddExp", "ConstExp", "MulExp", "Cond", "LOrExp",
  "LXorExp", "PrimaryExp", "FuncUtil", "EqExp", "LVal", "RelExp",
  "LAndExp", "str", "Arrayidentifier", "UnaryExp", "Const_Array",
  "Decl_varlva", "Var_Array", "constInstructions", "constInstruction",
  "InitVal", "InitValList", "FuncArraylist", "varInstructions",
  "varInstruction", "funcFParams", "funcFParam", "Rea_funcParams", "Type",
  "Program", "$@1", "$@2", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,    32,  -133,  -133,  -133,    11,  -133,  -133,   269,    -7,
    -133,   269,   269,   269,    30,    47,    85,    96,   178,   106,
      21,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,    97,   114,   103,  -133,  -133,    -6,
     119,  -133,   137,   142,   196,   214,   269,   134,  -133,  -133,
      21,  -133,  -133,  -133,   269,  -133,  -133,   148,  -133,   141,
     151,  -133,  -133,   269,   269,   269,   269,   269,   269,   269,
      -5,  -133,    67,   -12,  -133,  -133,  -133,  -133,    -4,  -133,
     146,   114,   154,   150,   143,    99,    98,   155,  -133,   138,
     169,    68,    75,    53,  -133,  -133,  -133,     3,   103,   103,
    -133,  -133,  -133,   168,   170,   175,   232,   269,   269,   179,
    -133,   186,  -133,   269,  -133,    21,   269,   269,   269,   269,
     269,   269,   269,   269,   269,  -133,    21,   187,   269,   189,
     181,  -133,   148,   182,   269,  -133,  -133,   190,    96,  -133,
     114,   188,  -133,   194,    82,    88,  -133,  -133,   197,   143,
     155,    98,    98,   114,   114,   114,   114,    99,  -133,   195,
    -133,   201,   251,  -133,  -133,     4,  -133,     5,  -133,   204,
    -133,  -133,   105,  -133,  -133,  -133,     7,    21,  -133,  -133,
      10,   205,   190,    96,   198,  -133,    28,  -133,   251,  -133,
    -133,  -133,  -133,  -133,   207,   206,  -133,  -133,  -133,   269,
     208,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,    44,    45,    46,     0,    70,    71,     0,    28,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,    14,     5,     6,     7,     8,     9,    10,    12,
      11,    13,    79,    80,     0,    36,    49,    39,    48,    43,
      19,    52,     0,     0,     0,     0,     0,     0,    43,    30,
       0,    40,    41,    42,     0,    25,    24,     0,    35,     0,
       0,     4,    23,     0,     0,     0,     0,     0,     0,     0,
      74,    94,    75,     0,    93,     1,   107,   109,     0,    17,
       0,    56,     0,    38,    68,    64,    61,    66,    47,     0,
       0,     0,     0,     0,    83,    34,    26,     0,    50,    51,
      53,    54,    55,     0,     0,    99,     0,     0,     0,     0,
      91,     0,   108,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     0,
       0,    81,     0,     0,     0,    27,    16,     0,     0,    78,
      37,     0,    95,     0,     0,    74,    92,   110,    31,    69,
      67,    62,    63,    57,    58,    59,    60,    65,    33,     0,
      84,     0,     0,    82,    21,     0,    98,     0,   101,     0,
      76,    77,     0,    97,    86,    89,     0,     0,    72,    73,
       0,     0,     0,     0,   103,    87,     0,    96,     0,    32,
      85,    20,   100,   102,     0,   104,    88,    90,   105,     0,
       0,   106
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,   163,   -17,  -133,  -133,  -132,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,    -8,   -42,   -74,   102,   173,
    -133,   113,  -133,  -133,   108,     1,    43,   123,  -133,  -133,
       2,  -133,  -133,  -133,  -133,   104,    42,   -99,  -133,  -133,
     130,  -133,    59,   109,   -15,  -133,  -133,  -133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   141,    36,    82,
      83,    84,    37,    38,    85,    48,    86,    87,    97,    40,
      41,    92,    71,    72,    93,    94,   175,   176,   195,    73,
      74,   167,   168,    78,    42,    43,    50,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    39,    57,    61,    81,   166,   110,   105,    49,   112,
      59,   106,    81,    51,    52,    53,   133,   181,   182,    68,
     107,    39,   187,    46,     1,   190,     2,     3,     4,     5,
     111,     6,     7,     8,   143,     9,    77,    80,   113,    10,
      11,    12,    54,   196,    44,   134,   113,   183,    45,   188,
     192,    39,   188,    13,   160,    14,    15,    16,    17,    18,
     103,   104,    19,   180,   140,    55,   140,   100,   101,   102,
     188,   131,    61,   186,    81,    81,    81,    81,   153,   154,
     155,   156,    81,   108,   127,     1,   140,     2,     3,     4,
      39,   129,   109,   128,     8,   132,   172,   173,   148,   142,
     130,    11,    12,    56,   106,   147,     6,     7,     1,   158,
       2,     3,     4,   107,    13,    62,    39,     8,    60,   172,
     185,   120,   121,   169,    11,    12,    77,    39,   122,   123,
      65,    66,    67,    63,    64,    69,   174,    13,   118,   119,
      70,     1,    75,     2,     3,     4,     5,    88,     6,     7,
       8,    91,     9,   125,   174,    96,    10,    11,    12,    95,
     189,   151,   152,   114,   174,    98,    99,   115,   169,   117,
      13,   116,    14,    15,    16,    17,    18,   124,    39,    19,
     174,     1,   126,     2,     3,     4,   135,   136,   137,   145,
       8,   200,   159,   144,   161,   162,    58,    11,    12,     1,
     164,     2,     3,     4,     9,   170,   177,   184,     8,    76,
      13,   171,   178,    89,   194,    11,    12,     1,   179,     2,
       3,     4,   199,   191,   198,   201,     8,    90,    13,   149,
     197,    79,   157,    11,    12,     1,   163,     2,     3,     4,
     150,   146,   193,   165,     8,     0,    13,     0,     0,   139,
       0,    11,    12,     0,     1,     0,     2,     3,     4,     0,
       0,     0,     0,     8,    13,   172,     0,     0,     0,     0,
      11,    12,     1,     0,     2,     3,     4,     0,     0,     0,
       0,     8,     0,    13,     0,     0,     0,     0,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13
};

static const yytype_int16 yycheck[] =
{
       8,     0,    17,    20,    46,   137,    18,    12,    15,    13,
      18,    16,    54,    11,    12,    13,    13,    13,    13,    25,
      25,    20,    15,    12,     3,    15,     5,     6,     7,     8,
      42,    10,    11,    12,   108,    14,    44,    45,    42,    18,
      19,    20,    12,    15,    12,    42,    42,    42,    16,    42,
     182,    50,    42,    32,   128,    34,    35,    36,    37,    38,
      68,    69,    41,   162,   106,    18,   108,    65,    66,    67,
      42,    18,    89,   172,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    16,    16,     3,   128,     5,     6,     7,
      89,    16,    25,    25,    12,    42,    14,    15,   115,   107,
      25,    19,    20,    18,    16,   113,    10,    11,     3,   126,
       5,     6,     7,    25,    32,    18,   115,    12,    12,    14,
      15,    23,    24,   138,    19,    20,   134,   126,    30,    31,
      27,    28,    29,    19,    20,    16,   144,    32,    39,    40,
       3,     3,     0,     5,     6,     7,     8,    13,    10,    11,
      12,     3,    14,    15,   162,     4,    18,    19,    20,    18,
     177,   118,   119,    17,   172,    63,    64,    13,   183,    26,
      32,    21,    34,    35,    36,    37,    38,    22,   177,    41,
     188,     3,    13,     5,     6,     7,    18,    17,    13,     3,
      12,   199,     5,    14,     5,    14,    18,    19,    20,     3,
      18,     5,     6,     7,    14,    17,     9,     3,    12,    13,
      32,    17,    17,    50,    16,    19,    20,     3,    17,     5,
       6,     7,    16,    18,    17,    17,    12,    54,    32,   116,
     188,    17,   124,    19,    20,     3,   132,     5,     6,     7,
     117,   111,   183,   134,    12,    -1,    32,    -1,    -1,    17,
      -1,    19,    20,    -1,     3,    -1,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    32,    14,    -1,    -1,    -1,    -1,
      19,    20,     3,    -1,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    -1,    32,    -1,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    10,    11,    12,    14,
      18,    19,    20,    32,    34,    35,    36,    37,    38,    41,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    62,    66,    67,    69,
      73,    74,    88,    89,    12,    16,    12,    59,    69,    15,
      90,    74,    74,    74,    12,    18,    18,    88,    18,    59,
      12,    46,    18,    19,    20,    27,    28,    29,    25,    16,
       3,    76,    77,    83,    84,     0,    13,    59,    87,    17,
      59,    60,    63,    64,    65,    68,    70,    71,    13,    45,
      63,     3,    75,    78,    79,    18,     4,    72,    62,    62,
      74,    74,    74,    59,    59,    12,    16,    25,    16,    25,
      18,    42,    13,    42,    17,    13,    21,    26,    39,    40,
      23,    24,    30,    31,    22,    15,    13,    16,    25,    16,
      25,    18,    42,    13,    42,    18,    17,    13,    91,    17,
      60,    61,    59,    61,    14,     3,    84,    59,    46,    65,
      71,    70,    70,    60,    60,    60,    60,    68,    46,     5,
      61,     5,    14,    79,    18,    87,    49,    85,    86,    88,
      17,    17,    14,    15,    59,    80,    81,     9,    17,    17,
      81,    13,    13,    42,     3,    15,    81,    15,    42,    46,
      15,    18,    49,    86,    16,    82,    15,    80,    17,    16,
      59,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    89,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    73,    73,    73,    69,    69,
      55,    55,    47,    47,    56,    56,    72,    48,    90,    49,
      49,    50,    50,    54,    51,    51,    59,    61,    63,    74,
      74,    74,    74,    66,    66,    66,    66,    66,    66,    60,
      60,    60,    62,    62,    62,    62,    70,    70,    70,    70,
      70,    68,    68,    68,    71,    71,    65,    65,    64,    64,
      88,    88,    75,    75,    76,    76,    77,    77,    77,    52,
      52,    57,    78,    78,    79,    79,    80,    80,    80,    81,
      81,    58,    83,    83,    84,    84,    84,    84,    53,    91,
      53,    85,    85,    86,    86,    82,    82,    67,    67,    87,
      87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     1,     1,
       7,     5,     1,     2,     2,     2,     1,     4,     0,     4,
       2,     5,     7,     5,     3,     2,     1,     1,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     3,     1,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     4,     4,     1,     1,     4,     4,     3,     1,
       1,     4,     3,     1,     3,     5,     1,     2,     3,     1,
       3,     3,     3,     1,     1,     3,     5,     4,     5,     0,
       7,     1,     3,     2,     3,     2,     4,     3,     4,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 41 "src/parser.y"
            {
        ast.setRoot((yyvsp[0].stmttype));
    }
#line 1537 "src/parser.cpp"
    break;

  case 3:
#line 46 "src/parser.y"
           {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1543 "src/parser.cpp"
    break;

  case 4:
#line 47 "src/parser.y"
                {
        (yyval.stmttype) = new SeqNode((yyvsp[-1].stmttype), (yyvsp[0].stmttype));//seqNode，我们每一个节点块中存在的stmt的数量-1。反复生成stmt
    }
#line 1551 "src/parser.cpp"
    break;

  case 5:
#line 52 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1557 "src/parser.cpp"
    break;

  case 6:
#line 53 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1563 "src/parser.cpp"
    break;

  case 7:
#line 54 "src/parser.y"
             {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1569 "src/parser.cpp"
    break;

  case 8:
#line 55 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1575 "src/parser.cpp"
    break;

  case 9:
#line 56 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1581 "src/parser.cpp"
    break;

  case 10:
#line 57 "src/parser.y"
              {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1587 "src/parser.cpp"
    break;

  case 11:
#line 58 "src/parser.y"
             {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1593 "src/parser.cpp"
    break;

  case 12:
#line 59 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1599 "src/parser.cpp"
    break;

  case 13:
#line 60 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1605 "src/parser.cpp"
    break;

  case 14:
#line 61 "src/parser.y"
                  {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1611 "src/parser.cpp"
    break;

  case 15:
#line 64 "src/parser.y"
                          {
        SymbolEntry *sp;
        sp = identifiers->lookup((yyvsp[-3].strtype));
        if(sp == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)(yyvsp[-3].strtype));
            delete [](char*)(yyvsp[-3].strtype);
            assert(sp != nullptr);
        }
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new Array(se,new Id(sp),(yyvsp[-1].exprtype));
    }
#line 1628 "src/parser.cpp"
    break;

  case 16:
#line 76 "src/parser.y"
                                       {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new Array(se,(yyvsp[-3].exprtype),(yyvsp[-1].exprtype));
    }
#line 1637 "src/parser.cpp"
    break;

  case 17:
#line 80 "src/parser.y"
                       {
       SymbolEntry *sp;
        sp = identifiers->lookup((yyvsp[-2].strtype));
        if(sp == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)(yyvsp[-2].strtype));
            delete [](char*)(yyvsp[-2].strtype);
            assert(sp != nullptr);
        }
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new Array(se,new Id(sp));
    }
#line 1654 "src/parser.cpp"
    break;

  case 18:
#line 94 "src/parser.y"
         {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[0].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)(yyvsp[0].strtype));
            delete [](char*)(yyvsp[0].strtype);
            assert(se != nullptr);
        }
        (yyval.exprtype) = new Id(se);
        delete [](yyvsp[0].strtype);
    }
#line 1671 "src/parser.cpp"
    break;

  case 19:
#line 106 "src/parser.y"
                     {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1677 "src/parser.cpp"
    break;

  case 20:
#line 110 "src/parser.y"
                                                          {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-6].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "Function \"%s\" is undefined\n", (char*)(yyvsp[-6].strtype));
            delete [](char*)(yyvsp[-6].strtype);
            assert(se != nullptr);
        }
        (yyval.stmttype) = new STREAM(new Id(se),(yyvsp[-4].exprtype),(yyvsp[-2].exprtype));
    }
#line 1693 "src/parser.cpp"
    break;

  case 21:
#line 122 "src/parser.y"
                                     {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-4].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "Function \"%s\" is undefined\n", (char*)(yyvsp[-4].strtype));
            delete [](char*)(yyvsp[-4].strtype);
            assert(se != nullptr);
        }
        (yyval.stmttype) = new STREAM(new Id(se),(yyvsp[-2].exprtype));
    }
#line 1709 "src/parser.cpp"
    break;

  case 22:
#line 135 "src/parser.y"
              {
        (yyval.stmttype) =new InvalidStmt();
    }
#line 1717 "src/parser.cpp"
    break;

  case 23:
#line 138 "src/parser.y"
                    {
        (yyval.stmttype) = new InvalidStmt((yyvsp[-1].exprtype));
    }
#line 1725 "src/parser.cpp"
    break;

  case 24:
#line 143 "src/parser.y"
                       {(yyval.stmttype) = new Contr(1);}
#line 1731 "src/parser.cpp"
    break;

  case 25:
#line 144 "src/parser.y"
                     {(yyval.stmttype) = new Contr(2);}
#line 1737 "src/parser.cpp"
    break;

  case 26:
#line 149 "src/parser.y"
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::voidType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        (yyval.exprtype) = new String(se);
        delete [](yyvsp[0].strtype);
    }
#line 1749 "src/parser.cpp"
    break;

  case 27:
#line 159 "src/parser.y"
                              {
        (yyval.stmttype) = new AssignStmt((yyvsp[-3].exprtype), (yyvsp[-1].exprtype));
    }
#line 1757 "src/parser.cpp"
    break;

  case 28:
#line 165 "src/parser.y"
        {identifiers = new SymbolTable(identifiers);}
#line 1763 "src/parser.cpp"
    break;

  case 29:
#line 167 "src/parser.y"
        {
            (yyval.stmttype) = new CompoundStmt((yyvsp[-1].stmttype));
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
#line 1774 "src/parser.cpp"
    break;

  case 30:
#line 176 "src/parser.y"
        {
            (yyval.stmttype) = new CompoundStmt();
        }
#line 1782 "src/parser.cpp"
    break;

  case 31:
#line 181 "src/parser.y"
                                            {
        (yyval.stmttype) = new IfStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1790 "src/parser.cpp"
    break;

  case 32:
#line 184 "src/parser.y"
                                           {
        (yyval.stmttype) = new IfElseStmt((yyvsp[-4].exprtype), (yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 1798 "src/parser.cpp"
    break;

  case 33:
#line 189 "src/parser.y"
                                    {
        (yyval.stmttype) = new WhileStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1806 "src/parser.cpp"
    break;

  case 34:
#line 195 "src/parser.y"
                         {
        (yyval.stmttype) = new ReturnStmt((yyvsp[-1].exprtype));
    }
#line 1814 "src/parser.cpp"
    break;

  case 35:
#line 198 "src/parser.y"
                       {
        (yyval.stmttype) = new ReturnStmt();
    }
#line 1822 "src/parser.cpp"
    break;

  case 36:
#line 204 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1828 "src/parser.cpp"
    break;

  case 37:
#line 208 "src/parser.y"
           {
        (yyval.exprtype)=(yyvsp[0].exprtype);
    }
#line 1836 "src/parser.cpp"
    break;

  case 38:
#line 214 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1842 "src/parser.cpp"
    break;

  case 39:
#line 218 "src/parser.y"
               {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1850 "src/parser.cpp"
    break;

  case 40:
#line 221 "src/parser.y"
                   {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new HitoExpr(se, HitoExpr::ADD, (yyvsp[0].exprtype));
    }
#line 1859 "src/parser.cpp"
    break;

  case 41:
#line 225 "src/parser.y"
                   {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new HitoExpr(se, HitoExpr::SUB, (yyvsp[0].exprtype));
    }
#line 1868 "src/parser.cpp"
    break;

  case 42:
#line 229 "src/parser.y"
                   {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new HitoExpr(se, HitoExpr::NOT, (yyvsp[0].exprtype));
    }
#line 1877 "src/parser.cpp"
    break;

  case 43:
#line 236 "src/parser.y"
         {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1885 "src/parser.cpp"
    break;

  case 44:
#line 239 "src/parser.y"
              {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[0].itype));
        (yyval.exprtype) = new Constant(se,0);
    }
#line 1894 "src/parser.cpp"
    break;

  case 45:
#line 243 "src/parser.y"
          {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[0].itype));
        (yyval.exprtype) = new Constant(se,2);
    }
#line 1903 "src/parser.cpp"
    break;

  case 46:
#line 247 "src/parser.y"
          {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[0].itype));
        (yyval.exprtype) = new Constant(se,1);
    }
#line 1912 "src/parser.cpp"
    break;

  case 47:
#line 251 "src/parser.y"
                       {
        (yyval.exprtype) = (yyvsp[-1].exprtype);
    }
#line 1920 "src/parser.cpp"
    break;

  case 48:
#line 254 "src/parser.y"
              {
        (yyval.exprtype)=(yyvsp[0].exprtype);
    }
#line 1928 "src/parser.cpp"
    break;

  case 49:
#line 260 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1934 "src/parser.cpp"
    break;

  case 50:
#line 263 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1943 "src/parser.cpp"
    break;

  case 51:
#line 269 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1952 "src/parser.cpp"
    break;

  case 52:
#line 276 "src/parser.y"
             {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1958 "src/parser.cpp"
    break;

  case 53:
#line 279 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1967 "src/parser.cpp"
    break;

  case 54:
#line 285 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1976 "src/parser.cpp"
    break;

  case 55:
#line 291 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MOD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1985 "src/parser.cpp"
    break;

  case 56:
#line 298 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1991 "src/parser.cpp"
    break;

  case 57:
#line 301 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2000 "src/parser.cpp"
    break;

  case 58:
#line 307 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LARGE, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2009 "src/parser.cpp"
    break;

  case 59:
#line 313 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LARAND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2018 "src/parser.cpp"
    break;

  case 60:
#line 319 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESAND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2027 "src/parser.cpp"
    break;

  case 61:
#line 326 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2033 "src/parser.cpp"
    break;

  case 62:
#line 327 "src/parser.y"
                       {SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::EQU, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));}
#line 2040 "src/parser.cpp"
    break;

  case 63:
#line 329 "src/parser.y"
                         {SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NOEQU, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));}
#line 2047 "src/parser.cpp"
    break;

  case 64:
#line 333 "src/parser.y"
          {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2053 "src/parser.cpp"
    break;

  case 65:
#line 336 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::AND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2062 "src/parser.cpp"
    break;

  case 66:
#line 343 "src/parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2068 "src/parser.cpp"
    break;

  case 67:
#line 346 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::XOR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2077 "src/parser.cpp"
    break;

  case 68:
#line 353 "src/parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2083 "src/parser.cpp"
    break;

  case 69:
#line 356 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::OR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2092 "src/parser.cpp"
    break;

  case 70:
#line 362 "src/parser.y"
          {
        (yyval.type) = TypeSystem::intType;
    }
#line 2100 "src/parser.cpp"
    break;

  case 71:
#line 365 "src/parser.y"
           {
        (yyval.type) = TypeSystem::voidType;
    }
#line 2108 "src/parser.cpp"
    break;

  case 72:
#line 377 "src/parser.y"
                             {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::constType, (yyvsp[-3].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-3].strtype), se);
        SymbolEntry *sp = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[-1].itype));
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        (yyval.exprtype) = new Decl_Array(sg,new Id(se),new Constant(sp));
        delete [](yyvsp[-3].strtype);
    }
#line 2122 "src/parser.cpp"
    break;

  case 73:
#line 387 "src/parser.y"
                                      {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        SymbolEntry *sp = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[-1].itype));
        (yyval.exprtype) = new Decl_Array(se,(yyvsp[-3].exprtype),new Constant(sp));
    }
#line 2132 "src/parser.cpp"
    break;

  case 74:
#line 394 "src/parser.y"
        {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new Decl_id(sg,new Id(se));
        delete [](yyvsp[0].strtype);
    }
#line 2145 "src/parser.cpp"
    break;

  case 75:
#line 403 "src/parser.y"
              {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 2151 "src/parser.cpp"
    break;

  case 76:
#line 407 "src/parser.y"
                              {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-3].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-3].strtype), se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new Decl_Array(sg,new Id(se),(yyvsp[-1].exprtype));
        delete [](yyvsp[-3].strtype);
    }
#line 2164 "src/parser.cpp"
    break;

  case 77:
#line 416 "src/parser.y"
                                     {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new Decl_Array(se,(yyvsp[-3].exprtype),(yyvsp[-1].exprtype));
    }
#line 2173 "src/parser.cpp"
    break;

  case 78:
#line 421 "src/parser.y"
                    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new Decl_Array(sg,new Id(se));
        delete [](yyvsp[-2].strtype);
    }
#line 2186 "src/parser.cpp"
    break;

  case 79:
#line 431 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 2192 "src/parser.cpp"
    break;

  case 80:
#line 432 "src/parser.y"
              {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 2198 "src/parser.cpp"
    break;

  case 81:
#line 435 "src/parser.y"
                                           {
        (yyval.stmttype)=new ConstDecl_stmt((yyvsp[-1].exprtype));
    }
#line 2206 "src/parser.cpp"
    break;

  case 82:
#line 440 "src/parser.y"
                                               {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        constInstructions(sg,(yyvsp[-2].exprtype),(yyvsp[0].exprtype));
    }
#line 2215 "src/parser.cpp"
    break;

  case 83:
#line 444 "src/parser.y"
                       {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 2221 "src/parser.cpp"
    break;

  case 84:
#line 448 "src/parser.y"
                      {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::constType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        (yyval.exprtype)=new Decl_Assign(sg,new Id(se),(yyvsp[0].exprtype));
    }
#line 2233 "src/parser.cpp"
    break;

  case 85:
#line 455 "src/parser.y"
                                                   {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        (yyval.exprtype)=new Array_assign(sg,(yyvsp[-4].exprtype),(yyvsp[-1].exprtype));
    }
#line 2242 "src/parser.cpp"
    break;

  case 86:
#line 462 "src/parser.y"
        {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 2248 "src/parser.cpp"
    break;

  case 87:
#line 464 "src/parser.y"
                  {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new InitVal(se);
        }
#line 2257 "src/parser.cpp"
    break;

  case 88:
#line 469 "src/parser.y"
                              {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new InitVal(se,(yyvsp[-1].exprtype));
    }
#line 2266 "src/parser.cpp"
    break;

  case 89:
#line 476 "src/parser.y"
            {
       SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new InitValList(se,(yyvsp[0].exprtype));
    }
#line 2275 "src/parser.cpp"
    break;

  case 90:
#line 481 "src/parser.y"
                              {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new InitValList(se,(yyvsp[-2].exprtype),(yyvsp[0].exprtype));
    }
#line 2284 "src/parser.cpp"
    break;

  case 91:
#line 487 "src/parser.y"
                                    {
        (yyval.stmttype)=new varDecl_stmt((yyvsp[-1].exprtype));
    }
#line 2292 "src/parser.cpp"
    break;

  case 92:
#line 492 "src/parser.y"
                                           {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new constInstructions(sg,(yyvsp[-2].exprtype),(yyvsp[0].exprtype));
    }
#line 2301 "src/parser.cpp"
    break;

  case 93:
#line 496 "src/parser.y"
                     {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 2307 "src/parser.cpp"
    break;

  case 94:
#line 499 "src/parser.y"
                  {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 2315 "src/parser.cpp"
    break;

  case 95:
#line 502 "src/parser.y"
                   {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new Decl_Assign(sg,new Id(se),(yyvsp[0].exprtype));
    }
#line 2327 "src/parser.cpp"
    break;

  case 96:
#line 509 "src/parser.y"
                                                {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new Array_assign(sg,(yyvsp[-4].exprtype),(yyvsp[-1].exprtype));
    }
#line 2336 "src/parser.cpp"
    break;

  case 97:
#line 513 "src/parser.y"
                                    {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new Array_assign(sg,(yyvsp[-3].exprtype));
    }
#line 2345 "src/parser.cpp"
    break;

  case 98:
#line 520 "src/parser.y"
                                   {
        Type *funcType;
        funcType = new FunctionType((yyvsp[-4].type),{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[-3].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-3].strtype), se);
        identifiers = new SymbolTable(identifiers);
        se = identifiers->lookup((yyvsp[-3].strtype));
        assert(se != nullptr);
        (yyval.stmttype) = new FunctionDef(se, (yyvsp[0].stmttype));
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete [](yyvsp[-3].strtype);
    }
#line 2364 "src/parser.cpp"
    break;

  case 99:
#line 535 "src/parser.y"
                  {
        Type *funcType;
        funcType = new FunctionType((yyvsp[-2].type),{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[-1].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-1].strtype), se);
        identifiers = new SymbolTable(identifiers);
    }
#line 2376 "src/parser.cpp"
    break;

  case 100:
#line 544 "src/parser.y"
    {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-5].strtype));
        assert(se != nullptr);
        (yyval.stmttype) = new FunctionDef(se, (yyvsp[0].stmttype),(yyvsp[-2].exprtype));
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete [](yyvsp[-5].strtype);
    }
#line 2391 "src/parser.cpp"
    break;

  case 101:
#line 557 "src/parser.y"
               {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2397 "src/parser.cpp"
    break;

  case 102:
#line 558 "src/parser.y"
                                   {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        funcFParams(sg,(yyvsp[-2].exprtype),(yyvsp[0].exprtype));
    }
#line 2406 "src/parser.cpp"
    break;

  case 103:
#line 565 "src/parser.y"
           {
        SymbolEntry *se;
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        (yyval.exprtype)=new funcFParam(sg,new Id(se));
    }
#line 2418 "src/parser.cpp"
    break;

  case 104:
#line 573 "src/parser.y"
                         {
        SymbolEntry *se;
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        se = new IdentifierSymbolEntry((yyvsp[-2].type), (yyvsp[-1].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-1].strtype), se);
        (yyval.exprtype)=new funcFParam(sg,new Id(se),(yyvsp[0].exprtype));
    }
#line 2430 "src/parser.cpp"
    break;

  case 105:
#line 582 "src/parser.y"
                 {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new FuncArraylist(sg);
    }
#line 2439 "src/parser.cpp"
    break;

  case 106:
#line 587 "src/parser.y"
                                    {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new FuncArraylist(sg,(yyvsp[-3].exprtype),(yyvsp[-1].exprtype));
    }
#line 2448 "src/parser.cpp"
    break;

  case 107:
#line 594 "src/parser.y"
                      {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-2].strtype));
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new FuncUtil(sg,se);
    }
#line 2459 "src/parser.cpp"
    break;

  case 108:
#line 600 "src/parser.y"
                                      {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-3].strtype));
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new FuncUtil(sg,se,(yyvsp[-1].exprtype));
    }
#line 2470 "src/parser.cpp"
    break;

  case 109:
#line 609 "src/parser.y"
        {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)= new Rea_funcParam(sg,(yyvsp[0].exprtype));
    }
#line 2479 "src/parser.cpp"
    break;

  case 110:
#line 613 "src/parser.y"
                               {
        SymbolEntry *sg = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new Rea_funcParams(sg,(yyvsp[-2].exprtype),(yyvsp[0].exprtype));
    }
#line 2488 "src/parser.cpp"
    break;


#line 2492 "src/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 618 "src/parser.y"

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
