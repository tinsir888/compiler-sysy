/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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
    #include <string>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
   
    
    
    

#line 82 "src/parser.cpp"




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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_PUTF = 4,                       /* PUTF  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_LPAREN = 11,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 12,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 13,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 14,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 15,                 /* SEMICOLON  */
  YYSYMBOL_ADD = 16,                       /* ADD  */
  YYSYMBOL_SUB = 17,                       /* SUB  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_LESS = 20,                      /* LESS  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_NEW = 24,                       /* NEW  */
  YYSYMBOL_ENUM = 25,                      /* ENUM  */
  YYSYMBOL_DELETE = 26,                    /* DELETE  */
  YYSYMBOL_CONST = 27,                     /* CONST  */
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 29,                  /* CONTINUE  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_GTR = 32,                       /* GTR  */
  YYSYMBOL_NEQ = 33,                       /* NEQ  */
  YYSYMBOL_LEQ = 34,                       /* LEQ  */
  YYSYMBOL_GEQ = 35,                       /* GEQ  */
  YYSYMBOL_MUL = 36,                       /* MUL  */
  YYSYMBOL_DIV = 37,                       /* DIV  */
  YYSYMBOL_REM = 38,                       /* REM  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_COLON = 40,                     /* COLON  */
  YYSYMBOL_DQUA = 41,                      /* DQUA  */
  YYSYMBOL_SQUA = 42,                      /* SQUA  */
  YYSYMBOL_LBRACK = 43,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 44,                    /* RBRACK  */
  YYSYMBOL_DECIMIAL = 45,                  /* DECIMIAL  */
  YYSYMBOL_OCTAL_DECIMIAL = 46,            /* OCTAL_DECIMIAL  */
  YYSYMBOL_HEX_DECIMAL = 47,               /* HEX_DECIMAL  */
  YYSYMBOL_THEN = 48,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_Program = 50,                   /* Program  */
  YYSYMBOL_Stmts = 51,                     /* Stmts  */
  YYSYMBOL_Stmt = 52,                      /* Stmt  */
  YYSYMBOL_Whilestmt = 53,                 /* Whilestmt  */
  YYSYMBOL_Emptystmt = 54,                 /* Emptystmt  */
  YYSYMBOL_BlockStmt = 55,                 /* BlockStmt  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_IfStmt = 57,                    /* IfStmt  */
  YYSYMBOL_ReturnStmt = 58,                /* ReturnStmt  */
  YYSYMBOL_ADDstmt = 59,                   /* ADDstmt  */
  YYSYMBOL_Exp = 60,                       /* Exp  */
  YYSYMBOL_Cond = 61,                      /* Cond  */
  YYSYMBOL_PrimaryExp = 62,                /* PrimaryExp  */
  YYSYMBOL_AddExp = 63,                    /* AddExp  */
  YYSYMBOL_Factor = 64,                    /* Factor  */
  YYSYMBOL_UnaryExp = 65,                  /* UnaryExp  */
  YYSYMBOL_RelExp = 66,                    /* RelExp  */
  YYSYMBOL_LAndExp = 67,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 68,                    /* LOrExp  */
  YYSYMBOL_Type = 69,                      /* Type  */
  YYSYMBOL_AssignStmt = 70,                /* AssignStmt  */
  YYSYMBOL_LVal = 71,                      /* LVal  */
  YYSYMBOL_DeclStmt = 72,                  /* DeclStmt  */
  YYSYMBOL_constIdlist = 73,               /* constIdlist  */
  YYSYMBOL_ConstDeclstmt = 74,             /* ConstDeclstmt  */
  YYSYMBOL_constId = 75,                   /* constId  */
  YYSYMBOL_VarDeclStmt = 76,               /* VarDeclStmt  */
  YYSYMBOL_varIdlist = 77,                 /* varIdlist  */
  YYSYMBOL_varId = 78,                     /* varId  */
  YYSYMBOL_varlval = 79,                   /* varlval  */
  YYSYMBOL_Params = 80,                    /* Params  */
  YYSYMBOL_Param = 81,                     /* Param  */
  YYSYMBOL_Paramlist = 82,                 /* Paramlist  */
  YYSYMBOL_FuncDef = 83,                   /* FuncDef  */
  YYSYMBOL_84_2 = 84,                      /* $@2  */
  YYSYMBOL_85_3 = 85,                      /* $@3  */
  YYSYMBOL_86_4 = 86,                      /* $@4  */
  YYSYMBOL_FuncCallExp = 87,               /* FuncCallExp  */
  YYSYMBOL_88_5 = 88,                      /* $@5  */
  YYSYMBOL_PutInchars = 89,                /* PutInchars  */
  YYSYMBOL_putsFunc = 90                   /* putsFunc  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    76,    95,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   130,   150,   158,   175,   174,   199,
     207,   217,   238,   245,   254,   264,   270,   277,   281,   287,
     291,   301,   307,   314,   323,   325,   331,   337,   358,   364,
     370,   376,   392,   395,   403,   409,   415,   421,   427,   442,
     444,   452,   454,   461,   464,   472,   483,   499,   502,   507,
     511,   515,   539,   550,   555,   559,   563,   566,   584,   597,
     615,   634,   662,   672,   689,   687,   768,   776,   768,   845,
     844,   889,   926,   938,   950
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "PUTF", "STRING",
  "INTEGER", "IF", "ELSE", "INT", "VOID", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "SEMICOLON", "ADD", "SUB", "OR", "AND", "LESS", "ASSIGN",
  "NOT", "RETURN", "NEW", "ENUM", "DELETE", "CONST", "BREAK", "CONTINUE",
  "WHILE", "EQ", "GTR", "NEQ", "LEQ", "GEQ", "MUL", "DIV", "REM", "COMMA",
  "COLON", "DQUA", "SQUA", "LBRACK", "RBRACK", "DECIMIAL",
  "OCTAL_DECIMIAL", "HEX_DECIMAL", "THEN", "$accept", "Program", "Stmts",
  "Stmt", "Whilestmt", "Emptystmt", "BlockStmt", "$@1", "IfStmt",
  "ReturnStmt", "ADDstmt", "Exp", "Cond", "PrimaryExp", "AddExp", "Factor",
  "UnaryExp", "RelExp", "LAndExp", "LOrExp", "Type", "AssignStmt", "LVal",
  "DeclStmt", "constIdlist", "ConstDeclstmt", "constId", "VarDeclStmt",
  "varIdlist", "varId", "varlval", "Params", "Param", "Paramlist",
  "FuncDef", "$@2", "$@3", "$@4", "FuncCallExp", "$@5", "PutInchars",
  "putsFunc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     130,    -4,    41,  -125,    51,  -125,  -125,    82,    -2,  -125,
      82,    82,    82,    57,    12,    53,     4,   130,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,    39,    33,  -125,    64,
    -125,    54,  -125,  -125,  -125,  -125,  -125,  -125,    65,    81,
      82,    75,    23,  -125,  -125,   130,  -125,  -125,  -125,  -125,
      67,    87,    82,  -125,  -125,  -125,    82,    82,    82,    82,
      82,    -8,   -10,  -125,  -125,    82,  -125,    82,  -125,    -6,
      79,    23,   131,    73,    77,  -125,    21,  -125,    84,     8,
    -125,    88,    33,    33,  -125,  -125,  -125,    90,    82,  -125,
     100,    91,  -125,     2,   105,    82,   130,    82,    82,    82,
      82,    82,    82,    82,    82,  -125,    82,  -125,    87,   130,
      12,   109,  -125,   101,  -125,  -125,  -125,    82,  -125,     3,
     116,    23,    23,    23,    23,    23,    23,   131,    73,  -125,
    -125,  -125,   122,     7,  -125,  -125,  -125,   111,   130,  -125,
     114,    12,   114,  -125,  -125,  -125,  -125,  -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    56,     0,    28,     0,    53,    54,     0,    17,    16,
       0,     0,     0,     0,     0,     0,     0,     2,     3,    13,
      14,     7,     8,     9,     6,    41,     0,    33,    34,     0,
       5,    27,    10,    58,    57,    11,    30,    12,    79,     0,
       0,     0,    25,    27,    19,     0,    38,    39,    40,    23,
       0,     0,     0,     1,     4,    24,     0,     0,     0,     0,
       0,    68,     0,    65,    66,     0,    81,     0,    82,     0,
       0,    42,    49,    51,    26,    29,     0,    22,     0,     0,
      60,     0,    31,    32,    35,    36,    37,    74,     0,    63,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,    61,     0,     0,
       0,     0,    67,    68,    64,    55,    80,     0,    84,     0,
      20,    43,    45,    44,    46,    48,    47,    50,    52,    62,
      59,    15,     0,     0,    69,    77,    72,     0,     0,    71,
       0,     0,     0,    83,    21,    75,    70,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -125,  -125,    86,   -15,  -125,  -125,  -124,  -125,  -125,  -125,
    -125,     1,    80,  -125,    13,    -7,    -1,    26,    31,  -125,
     -13,  -125,     0,  -125,  -125,  -125,    34,  -125,  -125,    58,
    -125,  -125,     9,    49,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    16,    17,    18,    19,    20,    21,    45,    22,    23,
      24,    92,    70,    25,    26,    27,    28,    72,    73,    74,
      29,    30,    43,    32,    79,    33,    80,    34,    62,    63,
      64,   133,   134,    93,    35,   110,   111,   142,    36,    67,
      69,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    51,    54,    87,    53,    89,    94,    38,    41,    46,
      47,    48,    44,    88,   116,   137,   145,    31,   147,   140,
      42,     5,     6,   107,     1,     2,    50,     3,     4,    90,
       5,     6,     7,    95,     8,   105,     9,    10,    11,    56,
      57,   117,   117,    12,    13,    31,   141,   108,    14,    82,
      83,    15,    39,    71,    55,    56,    57,    84,    85,    86,
       1,    54,    40,     3,    52,    71,    91,    61,     7,    58,
      59,    60,    49,    10,    11,    65,    31,    66,    42,    12,
      42,   120,    77,    56,    57,     1,    68,    75,     3,   112,
      78,    96,   103,     7,   131,   104,    31,   132,    10,    11,
     109,    42,   -76,   113,    12,   106,   115,   129,    42,    31,
     121,   122,   123,   124,   125,   126,    71,    71,   136,    42,
     118,   135,    88,   144,   138,   139,   143,     8,   132,   127,
      42,    76,    81,     1,     2,   128,     3,     4,    31,     5,
       6,     7,   130,     8,   119,     9,    10,    11,   114,     0,
     146,    97,    12,    13,     0,     0,     0,    14,     0,     0,
      15,     0,    98,    99,   100,   101,   102
};

static const yytype_int16 yycheck[] =
{
       0,    14,    17,    11,     0,    15,    12,    11,     7,    10,
      11,    12,    14,    21,    12,    12,   140,    17,   142,    12,
       7,     9,    10,    15,     3,     4,    13,     6,     7,    39,
       9,    10,    11,    39,    13,    14,    15,    16,    17,    16,
      17,    39,    39,    22,    23,    45,    39,    39,    27,    56,
      57,    30,    11,    40,    15,    16,    17,    58,    59,    60,
       3,    76,    11,     6,    11,    52,    65,     3,    11,    36,
      37,    38,    15,    16,    17,    21,    76,    12,    65,    22,
      67,    96,    15,    16,    17,     3,     5,    12,     6,    88,
       3,    12,    19,    11,   109,    18,    96,   110,    16,    17,
      12,    88,    12,     3,    22,    21,    15,   106,    95,   109,
      97,    98,    99,   100,   101,   102,   103,   104,   117,   106,
      15,    12,    21,   138,     8,     3,    15,    13,   141,   103,
     117,    45,    52,     3,     4,   104,     6,     7,   138,     9,
      10,    11,   108,    13,    95,    15,    16,    17,    90,    -1,
     141,    20,    22,    23,    -1,    -1,    -1,    27,    -1,    -1,
      30,    -1,    31,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,     7,     9,    10,    11,    13,    15,
      16,    17,    22,    23,    27,    30,    50,    51,    52,    53,
      54,    55,    57,    58,    59,    62,    63,    64,    65,    69,
      70,    71,    72,    74,    76,    83,    87,    90,    11,    11,
      11,    60,    63,    71,    14,    56,    65,    65,    65,    15,
      63,    69,    11,     0,    52,    15,    16,    17,    36,    37,
      38,     3,    77,    78,    79,    21,    12,    88,     5,    89,
      61,    63,    66,    67,    68,    12,    51,    15,     3,    73,
      75,    61,    64,    64,    65,    65,    65,    11,    21,    15,
      39,    60,    60,    82,    12,    39,    12,    20,    31,    32,
      33,    34,    35,    19,    18,    14,    21,    15,    39,    12,
      84,    85,    60,     3,    78,    15,    12,    39,    15,    82,
      52,    63,    63,    63,    63,    63,    63,    66,    67,    60,
      75,    52,    69,    80,    81,    12,    60,    12,     8,     3,
      12,    39,    86,    15,    52,    55,    81,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    54,    56,    55,    55,
      57,    57,    58,    58,    59,    60,    61,    62,    62,    62,
      62,    63,    63,    63,    64,    64,    64,    64,    65,    65,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    71,    72,    72,    73,
      73,    74,    75,    76,    77,    77,    78,    78,    79,    80,
      80,    81,    82,    82,    84,    83,    85,    86,    83,    88,
      87,    87,    89,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     0,     4,     2,
       5,     7,     3,     2,     2,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     1,     3,     3,     3,     2,     2,
       2,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     1,     4,     1,     1,     1,     3,
       1,     4,     3,     3,     3,     1,     1,     3,     1,     1,
       3,     2,     3,     1,     0,     7,     0,     0,     7,     0,
       5,     3,     1,     7,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: Stmts  */
#line 70 "src/parser.y"
            {
        ast.setRoot((yyvsp[0].stmttype));//设置分析树的root
    }
#line 1284 "src/parser.cpp"
    break;

  case 3: /* Stmts: Stmt  */
#line 76 "src/parser.y"
           {
     int rt=0;//0表示void  1表示int
     //这里需要默认化为void 因为有可能没有return语句
        if(static_cast<ReturnStmt*>((yyvsp[0].stmttype))->getrt()==1)
        {
            rt=1;
        }
        if(static_cast<IfStmt*>((yyvsp[0].stmttype))->getrt()==1)
        {
            rt=1;
        }
        if(static_cast<IfElseStmt*>((yyvsp[0].stmttype))->getrt()==1)
        {
            rt=1;
        }
    //$$=$1;
    (yyval.stmttype) = new SeqNode((yyvsp[0].stmttype),rt);//构造函数
    
    }
#line 1308 "src/parser.cpp"
    break;

  case 4: /* Stmts: Stmts Stmt  */
#line 95 "src/parser.y"
                {
        
        
        int rt=0;//0表示void  1表示int
        if(static_cast<ReturnStmt*>((yyvsp[0].stmttype))->getrt()==1)
        {
            rt=1;
        }
        if(static_cast<IfStmt*>((yyvsp[0].stmttype))->getrt()==1)
        {
            rt=1;
        }
        if(static_cast<IfElseStmt*>((yyvsp[0].stmttype))->getrt()==1)
        {
            rt=1;
        }
        //fprintf(stderr, "当前rt %d\n",rt);
        (yyval.stmttype) = new SeqNode((yyvsp[-1].stmttype), (yyvsp[0].stmttype),rt);//构造函数
        //$$ = new SeqNode($1, $2);//构造函数
    }
#line 1333 "src/parser.cpp"
    break;

  case 5: /* Stmt: AssignStmt  */
#line 118 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1339 "src/parser.cpp"
    break;

  case 6: /* Stmt: ADDstmt  */
#line 119 "src/parser.y"
              {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1345 "src/parser.cpp"
    break;

  case 7: /* Stmt: BlockStmt  */
#line 120 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1351 "src/parser.cpp"
    break;

  case 8: /* Stmt: IfStmt  */
#line 121 "src/parser.y"
             {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1357 "src/parser.cpp"
    break;

  case 9: /* Stmt: ReturnStmt  */
#line 122 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1363 "src/parser.cpp"
    break;

  case 10: /* Stmt: DeclStmt  */
#line 123 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1369 "src/parser.cpp"
    break;

  case 11: /* Stmt: FuncDef  */
#line 124 "src/parser.y"
              {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1375 "src/parser.cpp"
    break;

  case 12: /* Stmt: putsFunc  */
#line 125 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1381 "src/parser.cpp"
    break;

  case 13: /* Stmt: Whilestmt  */
#line 126 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1387 "src/parser.cpp"
    break;

  case 14: /* Stmt: Emptystmt  */
#line 130 "src/parser.y"
                  {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1393 "src/parser.cpp"
    break;

  case 15: /* Whilestmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 151 "src/parser.y"
{
    (yyval.stmttype)=new Whilestmt((yyvsp[-2].exprtype),(yyvsp[0].stmttype));
}
#line 1401 "src/parser.cpp"
    break;

  case 16: /* Emptystmt: SEMICOLON  */
#line 159 "src/parser.y"
    {
        (yyval.stmttype)=new Emptystmt;//加处理语言就会报错
    }
#line 1409 "src/parser.cpp"
    break;

  case 17: /* $@1: %empty  */
#line 175 "src/parser.y"
        {
        //fprintf(stderr, "block断点1\n");
        identifiers = new SymbolTable(identifiers);
        
        }
#line 1419 "src/parser.cpp"
    break;

  case 18: /* BlockStmt: LBRACE $@1 Stmts RBRACE  */
#line 181 "src/parser.y"
        {//这是一个作用域结束 当前符号表删除 指针前移
            //fprintf(stderr, "block断点2\n");
            if(static_cast<SeqNode*>((yyvsp[-1].stmttype))->getrt()==0)
             {
                //fprintf(stderr, "block断点3\n");
                (yyval.stmttype) = new CompoundStmt((yyvsp[-1].stmttype),0);
             }
            else
            {
                (yyval.stmttype) = new CompoundStmt((yyvsp[-1].stmttype),1);
            }
            
            
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
#line 1441 "src/parser.cpp"
    break;

  case 19: /* BlockStmt: LBRACE RBRACE  */
#line 200 "src/parser.y"
    {
     (yyval.stmttype) = new CompoundStmt(0);
     }
#line 1449 "src/parser.cpp"
    break;

  case 20: /* IfStmt: IF LPAREN Cond RPAREN Stmt  */
#line 207 "src/parser.y"
                                            {
        int st=0;
        if(static_cast<ReturnStmt*>((yyvsp[0].stmttype))->getrt()==1)
           {
            st=1;
           
           }
    
        (yyval.stmttype) = new IfStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype),st);
    }
#line 1464 "src/parser.cpp"
    break;

  case 21: /* IfStmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 217 "src/parser.y"
                                           {
    
        int st=0;
        
        if(static_cast<ReturnStmt*>((yyvsp[0].stmttype))->getrt()==1)
           {
           //fprintf(stderr, "断点2\n");
            st=1;
           
           }
    
    
        (yyval.stmttype) = new IfElseStmt((yyvsp[-4].exprtype), (yyvsp[-2].stmttype), (yyvsp[0].stmttype),st);
       // fprintf(stderr, "此时st %d\n",st);
    }
#line 1484 "src/parser.cpp"
    break;

  case 22: /* ReturnStmt: RETURN AddExp SEMICOLON  */
#line 239 "src/parser.y"
    {
        (yyval.stmttype) = new ReturnStmt((yyvsp[-1].exprtype),1);
        //fprintf(stderr, "return断点2\n");
    }
#line 1493 "src/parser.cpp"
    break;

  case 23: /* ReturnStmt: RETURN SEMICOLON  */
#line 246 "src/parser.y"
    {
    //fprintf(stderr, "return断点1\n");
        (yyval.stmttype) = new ReturnStmt(0);
        //fprintf(stderr, "return断点2\n");
    }
#line 1503 "src/parser.cpp"
    break;

  case 24: /* ADDstmt: AddExp SEMICOLON  */
#line 255 "src/parser.y"
    {
    (yyval.stmttype) =new ADDstmt((yyvsp[-1].exprtype));

    }
#line 1512 "src/parser.cpp"
    break;

  case 25: /* Exp: AddExp  */
#line 264 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1518 "src/parser.cpp"
    break;

  case 26: /* Cond: LOrExp  */
#line 270 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1524 "src/parser.cpp"
    break;

  case 27: /* PrimaryExp: LVal  */
#line 277 "src/parser.y"
         {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1532 "src/parser.cpp"
    break;

  case 28: /* PrimaryExp: INTEGER  */
#line 281 "src/parser.y"
            {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::constType, (yyvsp[0].itype));
        (yyval.exprtype) = new Constant(se);
    }
#line 1541 "src/parser.cpp"
    break;

  case 29: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 287 "src/parser.y"
                       {
        (yyval.exprtype) = (yyvsp[-1].exprtype);
    }
#line 1549 "src/parser.cpp"
    break;

  case 30: /* PrimaryExp: FuncCallExp  */
#line 291 "src/parser.y"
                   {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1557 "src/parser.cpp"
    break;

  case 31: /* AddExp: AddExp ADD Factor  */
#line 302 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1566 "src/parser.cpp"
    break;

  case 32: /* AddExp: AddExp SUB Factor  */
#line 308 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1575 "src/parser.cpp"
    break;

  case 33: /* AddExp: Factor  */
#line 315 "src/parser.y"
  {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1581 "src/parser.cpp"
    break;

  case 34: /* Factor: UnaryExp  */
#line 323 "src/parser.y"
          {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1587 "src/parser.cpp"
    break;

  case 35: /* Factor: Factor MUL UnaryExp  */
#line 326 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1596 "src/parser.cpp"
    break;

  case 36: /* Factor: Factor DIV UnaryExp  */
#line 332 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1605 "src/parser.cpp"
    break;

  case 37: /* Factor: Factor REM UnaryExp  */
#line 338 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::REM, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1614 "src/parser.cpp"
    break;

  case 38: /* UnaryExp: ADD UnaryExp  */
#line 359 "src/parser.y"
    {
            SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            (yyval.exprtype) = new UnaryExp(se, UnaryExp::ADD, (yyvsp[0].exprtype));
    }
#line 1623 "src/parser.cpp"
    break;

  case 39: /* UnaryExp: SUB UnaryExp  */
#line 365 "src/parser.y"
   {
            SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            (yyval.exprtype) = new UnaryExp(se, UnaryExp::SUB, (yyvsp[0].exprtype));
   }
#line 1632 "src/parser.cpp"
    break;

  case 40: /* UnaryExp: NOT UnaryExp  */
#line 371 "src/parser.y"
   {
            SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            (yyval.exprtype) = new UnaryExp(se, UnaryExp::NOT, (yyvsp[0].exprtype));
   }
#line 1641 "src/parser.cpp"
    break;

  case 41: /* UnaryExp: PrimaryExp  */
#line 377 "src/parser.y"
   {
   
    (yyval.exprtype) =(yyvsp[0].exprtype);
   }
#line 1650 "src/parser.cpp"
    break;

  case 42: /* RelExp: AddExp  */
#line 392 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1656 "src/parser.cpp"
    break;

  case 43: /* RelExp: RelExp LESS AddExp  */
#line 396 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1665 "src/parser.cpp"
    break;

  case 44: /* RelExp: RelExp GTR AddExp  */
#line 404 "src/parser.y"
    {
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		(yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GTR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
	}
#line 1674 "src/parser.cpp"
    break;

  case 45: /* RelExp: RelExp EQ AddExp  */
#line 410 "src/parser.y"
        {
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		(yyval.exprtype) = new BinaryExpr(se, BinaryExpr::EQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
	}
#line 1683 "src/parser.cpp"
    break;

  case 46: /* RelExp: RelExp NEQ AddExp  */
#line 416 "src/parser.y"
        {
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		(yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
	}
#line 1692 "src/parser.cpp"
    break;

  case 47: /* RelExp: RelExp GEQ AddExp  */
#line 422 "src/parser.y"
        {
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		(yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
	}
#line 1701 "src/parser.cpp"
    break;

  case 48: /* RelExp: RelExp LEQ AddExp  */
#line 428 "src/parser.y"
        {
		SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
		(yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
	}
#line 1710 "src/parser.cpp"
    break;

  case 49: /* LAndExp: RelExp  */
#line 442 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1716 "src/parser.cpp"
    break;

  case 50: /* LAndExp: LAndExp AND RelExp  */
#line 445 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::AND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1725 "src/parser.cpp"
    break;

  case 51: /* LOrExp: LAndExp  */
#line 452 "src/parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1731 "src/parser.cpp"
    break;

  case 52: /* LOrExp: LOrExp OR LAndExp  */
#line 455 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::OR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1740 "src/parser.cpp"
    break;

  case 53: /* Type: INT  */
#line 461 "src/parser.y"
          {
        (yyval.type) = TypeSystem::intType;
    }
#line 1748 "src/parser.cpp"
    break;

  case 54: /* Type: VOID  */
#line 464 "src/parser.y"
           {
        (yyval.type) = TypeSystem::voidType;
    }
#line 1756 "src/parser.cpp"
    break;

  case 55: /* AssignStmt: LVal ASSIGN Exp SEMICOLON  */
#line 472 "src/parser.y"
                              {
        (yyval.stmttype) = new AssignStmt((yyvsp[-3].exprtype), (yyvsp[-1].exprtype));
    }
#line 1764 "src/parser.cpp"
    break;

  case 56: /* LVal: ID  */
#line 483 "src/parser.y"
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
#line 1781 "src/parser.cpp"
    break;

  case 57: /* DeclStmt: VarDeclStmt  */
#line 499 "src/parser.y"
                  {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1787 "src/parser.cpp"
    break;

  case 58: /* DeclStmt: ConstDeclstmt  */
#line 502 "src/parser.y"
                  {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1793 "src/parser.cpp"
    break;

  case 59: /* constIdlist: constIdlist COMMA constId  */
#line 507 "src/parser.y"
                            {
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        (yyval.exprtype)=new Idlist(st,(yyvsp[-2].exprtype),(yyvsp[0].exprtype));
    }
#line 1802 "src/parser.cpp"
    break;

  case 60: /* constIdlist: constId  */
#line 511 "src/parser.y"
              {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1808 "src/parser.cpp"
    break;

  case 61: /* ConstDeclstmt: CONST Type constIdlist SEMICOLON  */
#line 517 "src/parser.y"
    {
        (yyval.stmttype)=new ConstDeclstmt((yyvsp[-1].exprtype));
        
        /*SymbolEntry *se=identifiers->search_inthis($3);
        if(se!=NULL)
        {
            fprintf(stderr, "常量 \"%s\" is 重定义\n", (char*)$3);
            delete [](char*)$3;
            assert(se != nullptr);
        }
        SymbolEntry *se1;
        se1 = new IdentifierSymbolEntry(TypeSystem::constType, $3, identifiers->getLevel());
        identifiers->install($3, se1);
        $$ = new ConstDeclstmt(new ConstId(se1));
        delete []$3;*/
    }
#line 1829 "src/parser.cpp"
    break;

  case 62: /* constId: ID ASSIGN Exp  */
#line 539 "src/parser.y"
                 {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::constType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::constType, SymbolTable::getLabel());
        (yyval.exprtype)=new DAssignStmt(st,new Id(se),(yyvsp[0].exprtype));
    }
#line 1841 "src/parser.cpp"
    break;

  case 63: /* VarDeclStmt: Type varIdlist SEMICOLON  */
#line 550 "src/parser.y"
                              {
        (yyval.stmttype)=new VarDeclstmt((yyvsp[-1].exprtype));
    }
#line 1849 "src/parser.cpp"
    break;

  case 64: /* varIdlist: varIdlist COMMA varId  */
#line 555 "src/parser.y"
                            {
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype)=new Idlist(st,(yyvsp[-2].exprtype),(yyvsp[0].exprtype));//可以和常量通用
    }
#line 1858 "src/parser.cpp"
    break;

  case 65: /* varIdlist: varId  */
#line 559 "src/parser.y"
            {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1864 "src/parser.cpp"
    break;

  case 66: /* varId: varlval  */
#line 563 "src/parser.y"
              {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1872 "src/parser.cpp"
    break;

  case 67: /* varId: ID ASSIGN Exp  */
#line 566 "src/parser.y"
                   {
        SymbolEntry *se=identifiers->search_inthis((yyvsp[-2].strtype));
        if(se!=NULL)
        {
            fprintf(stderr, "变量 \"%s\" is 重定义\n", (char*)(yyvsp[-2].strtype));
            delete [](char*)(yyvsp[-2].strtype);
            assert(se != nullptr);
        }
        
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
         (yyval.exprtype)=new DAssignStmt(st,new Id(se),(yyvsp[0].exprtype));
        delete [](yyvsp[-2].strtype);

    }
#line 1893 "src/parser.cpp"
    break;

  case 68: /* varlval: ID  */
#line 584 "src/parser.y"
        {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new Decvar(st,new Id(se));
        delete [](yyvsp[0].strtype);
    }
#line 1906 "src/parser.cpp"
    break;

  case 69: /* Params: Param  */
#line 598 "src/parser.y"
   {
    //para_num+=1;
    //fprintf(stderr,"miaomiaomiao\n");
     def_fun.plus();
     SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
     
     
    Param* tmp=static_cast<Param*>((yyvsp[0].exprtype));
    SymbolEntry *se1=tmp->getSymPtr();
    Type* paratype =se1->getType();
    
    func_para.push(paratype);
    (yyval.exprtype) = new Params(st,(yyvsp[0].exprtype),NULL);
    
   }
#line 1926 "src/parser.cpp"
    break;

  case 70: /* Params: Params COMMA Param  */
#line 616 "src/parser.y"
   {
    SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
    Param* tmp=static_cast<Param*>((yyvsp[-2].exprtype));
    SymbolEntry *se1=tmp->getSymPtr();
    Type* paratype =se1->getType();
    
    //param_Type.push_back(paratype);
    //para_num+=1;
    
     def_fun.plus();
     func_para.push(paratype);
//     fprintf(stderr,"!!!!!!\n");
    (yyval.exprtype) = new Params(se,(yyvsp[0].exprtype),(yyvsp[-2].exprtype));//注意这里先放入param

    }
#line 1946 "src/parser.cpp"
    break;

  case 71: /* Param: Type ID  */
#line 635 "src/parser.y"
    {
    SymbolEntry *se1=identifiers->search_inthis((yyvsp[0].strtype));
    //fprintf(stderr,"ID is: %s\n", (char*)$2);
        if(se1!=NULL)
        {
            fprintf(stderr, "参数 \"%s\" is 重定义\n", (char*)(yyvsp[0].strtype));
            delete [](char*)(yyvsp[0].strtype);
            assert(se1 != nullptr);
        }
    SymbolEntry *se2 = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
    SymbolEntry *se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[0].strtype), identifiers->getLevel());
    
    //fprintf(stderr,"ID: %s getlabel: %d, getlevel: %d\n", (char*)(yyvsp[0].strtype), SymbolTable::getLabelnotInc(), identifiers->getLevel());
    ast.AllFuncParams.push_back(SymbolTable::getLabelnotInc());
    identifiers->install((yyvsp[0].strtype), se);//当前定义的函数是在上一个作用域的se:level=1
    //identifiers->install($2, se2);//testtesttest
    (yyval.exprtype) = new Param(se2,new Id(se));//se2:label=3 se:level=1
    //fprintf(stderr,"push_front: %s\n",se2->toStr().c_str());
    //fprintf(stderr,"param: %s done!\n",(char*)(yyvsp[0].strtype));
    delete [](yyvsp[0].strtype);
}
#line 1972 "src/parser.cpp"
    break;

  case 72: /* Paramlist: Paramlist COMMA Exp  */
#line 663 "src/parser.y"
    {
    SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            
        //use_num+=1;
    call_fun.plus();
        (yyval.exprtype) =new Paramlist(st,(yyvsp[-2].exprtype),(yyvsp[0].exprtype));

    }
#line 1985 "src/parser.cpp"
    break;

  case 73: /* Paramlist: Exp  */
#line 673 "src/parser.y"
    {
    //use_num+=1;
    SymbolEntry *st = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
    call_fun.plus();
    (yyval.exprtype) =new Paramlist(st,(yyvsp[0].exprtype),NULL);
    
    }
#line 1997 "src/parser.cpp"
    break;

  case 74: /* $@2: %empty  */
#line 689 "src/parser.y"
{  

       // para_num=0;//--------------重置参数个数
     //   fprintf(stderr, "断点1\n");
         
         def_fun.reset();
        
        func_para.reset();
        
        //fprintf(stderr,"why!!!1\n");
        //进入左括号 即进入新的作用域
        identifiers = new SymbolTable(identifiers);
        
    }
#line 2016 "src/parser.cpp"
    break;

  case 75: /* FuncDef: Type ID LPAREN $@2 Params RPAREN BlockStmt  */
#line 709 "src/parser.y"
    {
   
   // fprintf(stderr, "断点2\n");
    //还需要把参数作用域释放
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
       
       
        //对函数进行定义
        int num=def_fun.ret_num();
        Type *funcType;
        funcType = new FunctionType((yyvsp[-6].type),func_para.get(),num);//由于有参数 要把参数列表 参数个数输入
        
        
        
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[-5].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-5].strtype), se);//当前定义的函数是在上一个作用域的
        
        
        //在这里判断函数返回类型和定义类型是否相同
       SymbolEntry *se1;
        se1 = identifiers->lookup((yyvsp[-5].strtype));
        
        //fprintf(stderr, "  break 3\n");
       int rt=static_cast<CompoundStmt*>((yyvsp[0].stmttype))->getrt();
        std::string return_t = se1->getType()->toStr();
        if(rt==0)
        {
            if(return_t!="void()")
            {
                fprintf(stderr, "int函数 %s 返回类型错误!\n", (char*)(yyvsp[-5].strtype));
                //fprintf(stderr, "rt %d \n", rt);
                assert(rt!=0);
            }
        }
        else{
         //fprintf(stderr, "当前rt rt %d \n", rt);
            if(return_t=="void()")
            {
                fprintf(stderr, "void函数 %s 返回类型错误!\n", (char*)(yyvsp[-5].strtype));
                assert(rt!=1);
            }
        }
        
        
        assert(se != nullptr);
        (yyval.stmttype) = new FunctionDef(se,(yyvsp[0].stmttype),(yyvsp[-2].exprtype),func_para.get());
       
      
        delete [](yyvsp[-5].strtype);
      //  fprintf(stderr, "函数调用断点2\n");
         //fprintf(stderr, "断点3\n");
          //fprintf(stderr, "  break 1\n"); // 到此没问题
    }
#line 2076 "src/parser.cpp"
    break;

  case 76: /* $@3: %empty  */
#line 768 "src/parser.y"
                  {

        
        
        //进入左括号 即进入新的作用域 即便没有参数
        identifiers = new SymbolTable(identifiers);
        
    }
#line 2089 "src/parser.cpp"
    break;

  case 77: /* $@4: %empty  */
#line 776 "src/parser.y"
           {
  
       
    }
#line 2098 "src/parser.cpp"
    break;

  case 78: /* FuncDef: Type ID LPAREN $@3 RPAREN $@4 BlockStmt  */
#line 782 "src/parser.y"
    {
    //还需要把参数作用域释放
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        
        Type *funcType;
        funcType = new FunctionType((yyvsp[-6].type),{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[-5].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-5].strtype), se);//当前定义的函数是在上一个作用域的
        
        
        
       
        (yyval.stmttype) = new FunctionDef(se,(yyvsp[0].stmttype));
        
        
        int rt=static_cast<CompoundStmt*>((yyvsp[0].stmttype))->getrt();
        std::string return_t = se->getType()->toStr();
 //fprintf(stderr, "断点3\n");
 
 
        if(rt==0)
        {
       // fprintf(stderr, "rt %d \n", rt);
        //fprintf(stderr, "rt %s \n", return_t.c_str());
            if(return_t!="void()")
            {
                fprintf(stderr, "函数 %s 返回类型错误!\n", (char*)(yyvsp[-5].strtype));
                
                assert(rt!=0);
            }
        }
        else{
        //fprintf(stderr, "rt %d \n", rt);
        //fprintf(stderr, "rt %s \n", return_t.c_str());
            if(return_t=="void()")
            {
                fprintf(stderr, "函数 %s 返回类型错误!\n", (char*)(yyvsp[-5].strtype));
                assert(rt!=1);
            }
        }
        
        
        //fprintf(stderr, "断点4\n");
        /*SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;*/

        delete [](yyvsp[-5].strtype);
        //fprintf(stderr, "断点5\n");
        
        // fprintf(stderr, "  break 1\n"); // 到此没问题
    }
#line 2157 "src/parser.cpp"
    break;

  case 79: /* $@5: %empty  */
#line 845 "src/parser.y"
{


//fprintf(stderr, "函数调用 断点1");
 
 call_fun.reset();
}
#line 2169 "src/parser.cpp"
    break;

  case 80: /* FuncCallExp: ID LPAREN $@5 Paramlist RPAREN  */
#line 854 "src/parser.y"
    {
    //fprintf(stderr, "函数调用 断点1");
    //调用函数时不用检查sysy运行时库的函数
    if(((yyvsp[-4].strtype))!=(char*)"putf")
     {  
         SymbolEntry *se;
            se = identifiers->lookup((yyvsp[-4].strtype));
            
            if(se==NULL)
            {
                fprintf(stderr, "函数 %s 没有声明 \n", (char*)(yyvsp[-4].strtype));
                delete [](char*)(yyvsp[-4].strtype);
                assert(se != NULL);
            }
            
            
            Type * tmp=se->getType();
            FunctionType* temp=static_cast<FunctionType*>(tmp);
            int cor_num=temp->getnum();//定义时候的参数个数
            
              int paranum=call_fun.ret_num();//调用时函数个数
            if(cor_num!=paranum)
            {
                fprintf(stderr, "函数调用 %s 输入参数错误\n", (char*)(yyvsp[-4].strtype));
                  assert(cor_num==paranum);
            
            }
            
            SymbolEntry *se1 = new TemporarySymbolEntry(se->getType(), SymbolTable::getLabel());
            (yyval.exprtype) = new FuncCallExp(se1,se,(yyvsp[-1].exprtype),cor_num);
            
            //fprintf(stderr, "函数调用 断点2");
        }
    }
#line 2208 "src/parser.cpp"
    break;

  case 81: /* FuncCallExp: ID LPAREN RPAREN  */
#line 890 "src/parser.y"
    {
        if(((yyvsp[-2].strtype))!=(char*)"putf")
         {  
            SymbolEntry *se;
            se = identifiers->lookup((yyvsp[-2].strtype));
            
            if(se==NULL)
            {
                fprintf(stderr, "函数 %s 没有声明 \n", (char*)(yyvsp[-2].strtype));
                delete [](char*)(yyvsp[-2].strtype);
                assert(se != NULL);
            }
             //fprintf(stderr, "调用断点1 \n");
             
            Type * tmp=se->getType();
            FunctionType* temp=static_cast<FunctionType*>(tmp);
            int cor_num=temp->getnum();//定义时候的参数个数
            
            if(cor_num!=0)
            {
                fprintf(stderr, "函数调用 %s 输入参数错误\n", (char*)(yyvsp[-2].strtype));
                  assert(cor_num==0);
            
            }
        
            
            SymbolEntry *se1 = new TemporarySymbolEntry(se->getType(), SymbolTable::getLabel());
            (yyval.exprtype) = new FuncCallExp(se1,se,NULL,0);
            // fprintf(stderr, "调用断点2 \n");
        }
    }
#line 2244 "src/parser.cpp"
    break;

  case 82: /* PutInchars: STRING  */
#line 927 "src/parser.y"
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::voidType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        (yyval.exprtype) = new PutInchars(se);
        delete [](yyvsp[0].strtype);
    }
#line 2256 "src/parser.cpp"
    break;

  case 83: /* putsFunc: PUTF LPAREN PutInchars COMMA Paramlist RPAREN SEMICOLON  */
#line 938 "src/parser.y"
                                                            {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-6].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "Putint库函数 \"%s\" 未定义\n", (char*)(yyvsp[-6].strtype));
            delete [](char*)(yyvsp[-6].strtype);
            assert(se != nullptr);
        }
        (yyval.stmttype) = new putsFunc(new Id(se),(yyvsp[-4].exprtype),(yyvsp[-2].exprtype));
    }
#line 2272 "src/parser.cpp"
    break;

  case 84: /* putsFunc: PUTF LPAREN PutInchars RPAREN SEMICOLON  */
#line 950 "src/parser.y"
                                            {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-4].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "Putint库函数 \"%s\" 未定义\n", (char*)(yyvsp[-4].strtype));
            delete [](char*)(yyvsp[-4].strtype);
            assert(se != nullptr);
        }
        (yyval.stmttype) = new putsFunc(new Id(se),(yyvsp[-2].exprtype));
    }
#line 2288 "src/parser.cpp"
    break;


#line 2292 "src/parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 964 "src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}




