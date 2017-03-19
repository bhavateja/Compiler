/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "func.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	int idx = 0;
	int regs1 = 0;
	int regs2 = 0;
	FILE *fp = NULL; 

	int reg_num = 0;
	int label_counter = 0;

	FILE *target = NULL;
	#include "decl.h"
	#include "exptest.h"
	#include "label.h"
	#include "codegen.h"

	struct Lsymbol *l_start = NULL;
	struct Lsymbol *l_end = NULL;
	struct ArgList *arg_start = NULL;
	struct ArgList *arg_end = NULL;

	struct tnode *funcArg_start = NULL;
	struct tnode *funcArg_end = NULL;
	struct Gsymbol *gUse = NULL;

	int yylex(void);
	extern FILE *yyin;
	extern int line;
	#define YYSTYPE tnode *

	int variable_type;

#line 102 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNC = 258,
    RETURN = 259,
    MOD = 260,
    AND = 261,
    OR = 262,
    NOT = 263,
    CONST = 264,
    TRUE = 265,
    FALSE = 266,
    INT = 267,
    BOOL = 268,
    DECL = 269,
    ENDDECL = 270,
    ENDOFFILE = 271,
    MAIN = 272,
    READ = 273,
    WRITE = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    ENDIF = 278,
    WHILE = 279,
    DO = 280,
    ENDWHILE = 281,
    END = 282,
    NUM = 283,
    ID = 284,
    PLUS = 285,
    MINUS = 286,
    MUL = 287,
    DIV = 288,
    ASSGN = 289,
    LT = 290,
    LE = 291,
    GT = 292,
    GE = 293,
    EQ = 294,
    NEQ = 295
  };
#endif
/* Tokens.  */
#define FUNC 258
#define RETURN 259
#define MOD 260
#define AND 261
#define OR 262
#define NOT 263
#define CONST 264
#define TRUE 265
#define FALSE 266
#define INT 267
#define BOOL 268
#define DECL 269
#define ENDDECL 270
#define ENDOFFILE 271
#define MAIN 272
#define READ 273
#define WRITE 274
#define IF 275
#define THEN 276
#define ELSE 277
#define ENDIF 278
#define WHILE 279
#define DO 280
#define ENDWHILE 281
#define END 282
#define NUM 283
#define ID 284
#define PLUS 285
#define MINUS 286
#define MUL 287
#define DIV 288
#define ASSGN 289
#define LT 290
#define LE 291
#define GT 292
#define GE 293
#define EQ 294
#define NEQ 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    49,    50,    52,   133,   134,   136,   137,
     139,   141,   142,   144,   145,   153,   164,   165,   167,   169,
     170,   173,   211,   213,   214,   216,   217,   219,   221,   222,
     224,   225,   228,   229,   231,   232,   233,   234,   235,   238,
     239,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   293,   294
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNC", "RETURN", "MOD", "AND", "OR",
  "NOT", "CONST", "TRUE", "FALSE", "INT", "BOOL", "DECL", "ENDDECL",
  "ENDOFFILE", "MAIN", "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "END", "NUM", "ID", "PLUS", "MINUS", "MUL",
  "DIV", "ASSGN", "LT", "LE", "GT", "GE", "EQ", "NEQ", "'('", "')'", "'{'",
  "'}'", "';'", "','", "'['", "']'", "$accept", "program", "funcDefBlock",
  "func", "GDefBlock", "GDefList", "GDecl", "GIdList", "GId", "ArgList",
  "Arg", "Type", "mainBlock", "retStmt", "LDefBlock", "LDefList", "LDecl",
  "LIdList", "LId", "Slist", "Stmt", "VAR", "E", "funCallArgs", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    40,    41,   123,   125,    59,    44,    91,    93
};
# endif

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    14,   108,     5,   -66,   -66,   -66,    38,   -66,   103,
     -66,     5,   -66,   105,   -66,   -66,   -39,    43,   -66,   -66,
      -4,   122,   101,     5,   115,   -66,   103,   104,   -66,     5,
      30,   -66,   117,    96,   -66,   106,    87,   -66,     5,   -66,
     -66,   107,   112,   -66,   133,   133,    62,     4,     4,   -66,
     120,    86,   -66,   127,   139,   140,   141,   128,   158,     4,
     149,   158,   137,    91,   -66,   -66,   -66,   156,   238,   238,
     238,   238,   238,   142,   -66,   238,   143,   160,   -66,   120,
     147,   238,   -66,   -66,   -66,    56,   238,   -66,   121,   134,
     172,    25,    74,   -66,    85,   -66,   145,   -66,   150,    31,
     238,   185,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   151,   173,   174,   -66,   -66,
     -66,   -66,   -66,   223,    89,   -66,    31,   201,   201,   237,
     237,    47,    47,    31,    31,    31,    31,    31,    31,   -66,
       4,     4,   -66,   238,   175,   187,   223,     4,   153,   177,
     -66,   181,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    19,    20,     7,     0,     9,     0,
       1,     0,     4,     0,     6,     8,    13,     0,    12,     3,
       0,     0,     0,     0,     0,    10,     0,     0,     2,     0,
       0,    17,     0,     0,    11,     0,     0,    15,     0,    18,
      14,     0,     0,    16,     0,     0,     0,     0,     0,    24,
       0,     0,    26,     0,     0,     0,     0,    39,     0,    33,
       0,     0,    30,     0,    29,    23,    25,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,    27,     0,
       0,     0,    57,    58,    56,    39,     0,    59,     0,     0,
       0,     0,     0,    21,     0,     5,     0,    28,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    22,
      34,    31,    35,    62,     0,    55,    45,    52,    53,    41,
      43,    42,    44,    46,    48,    47,    49,    50,    51,    36,
       0,     0,    60,     0,     0,     0,    61,     0,     0,     0,
      38,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   190,   -66,   -66,   212,   -66,   209,   214,
     206,     8,   -66,   184,   202,   -66,   199,   -66,   178,   -45,
     -66,   -47,   -65,   -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    11,    12,     3,     7,     8,    17,    18,    30,
      31,    32,    21,    73,    47,    51,    52,    63,    64,    58,
      59,    87,    88,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    60,    23,    61,    89,    90,    91,    92,    24,     9,
      94,    13,    60,    27,    74,     9,    99,     4,     5,    20,
      80,   101,    53,    54,    55,    22,     4,     5,    56,     6,
     102,   103,   104,    57,     1,   123,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       4,     5,   102,    14,    50,   105,   106,   107,   108,    50,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    37,   118,     4,     5,    38,    49,   146,   102,
     103,   104,   109,   110,   111,   112,   113,   114,    25,    26,
     102,   103,   104,    60,    60,   144,   145,   100,     4,     5,
      60,    65,   149,    71,   105,   106,   107,   108,    10,   109,
     110,   111,   112,   113,   114,   105,   106,   107,   108,   119,
     109,   110,   111,   112,   113,   114,   102,   103,   104,    42,
     120,   142,    16,    38,    22,   143,    78,    79,    28,   102,
     103,   104,    29,    33,    40,    35,    39,    46,    41,    62,
      44,   105,   106,   107,   108,    45,   109,   110,   111,   112,
     113,   114,    72,   115,   105,   106,   107,   108,    67,   109,
     110,   111,   112,   113,   114,    71,   116,   102,   103,   104,
      68,    69,    70,    75,    77,    57,    93,    95,    96,    98,
     102,   103,   104,   121,   140,   122,   139,   147,   150,   141,
     151,    19,   105,   106,   107,   108,   102,   109,   110,   111,
     112,   113,   114,   148,   117,   105,   106,   107,   108,    15,
     109,   110,   111,   112,   113,   114,   152,   125,   102,   103,
     104,   105,   106,   107,   108,    34,   109,   110,   111,   112,
     113,   114,   102,    36,    43,    76,    81,    48,    82,    83,
      66,     0,     0,   105,   106,   107,   108,    97,   109,   110,
     111,   112,   113,   114,     0,     0,    84,    85,     0,   107,
     108,     0,   109,   110,   111,   112,   113,   114,     0,    86
};

static const yytype_int16 yycheck[] =
{
      47,    48,    41,    48,    69,    70,    71,    72,    47,     1,
      75,     3,    59,    17,    59,     7,    81,    12,    13,    11,
      67,    86,    18,    19,    20,    29,    12,    13,    24,    15,
       5,     6,     7,    29,    14,   100,     5,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      12,    13,     5,    15,    46,    30,    31,    32,    33,    51,
      35,    36,    37,    38,    39,    40,    35,    36,    37,    38,
      39,    40,    42,    48,    12,    13,    46,    15,   143,     5,
       6,     7,    35,    36,    37,    38,    39,    40,    45,    46,
       5,     6,     7,   140,   141,   140,   141,    41,    12,    13,
     147,    15,   147,    47,    30,    31,    32,    33,     0,    35,
      36,    37,    38,    39,    40,    30,    31,    32,    33,    45,
      35,    36,    37,    38,    39,    40,     5,     6,     7,    42,
      45,    42,    29,    46,    29,    46,    45,    46,    16,     5,
       6,     7,    41,    28,    48,    41,    29,    14,    42,    29,
      43,    30,    31,    32,    33,    43,    35,    36,    37,    38,
      39,    40,     4,    42,    30,    31,    32,    33,    41,    35,
      36,    37,    38,    39,    40,    47,    42,     5,     6,     7,
      41,    41,    41,    34,    47,    29,    44,    44,    28,    42,
       5,     6,     7,    48,    21,    45,    45,    22,    45,    25,
      23,    11,    30,    31,    32,    33,     5,    35,    36,    37,
      38,    39,    40,    26,    42,    30,    31,    32,    33,     7,
      35,    36,    37,    38,    39,    40,    45,    42,     5,     6,
       7,    30,    31,    32,    33,    26,    35,    36,    37,    38,
      39,    40,     5,    29,    38,    61,     8,    45,    10,    11,
      51,    -1,    -1,    30,    31,    32,    33,    79,    35,    36,
      37,    38,    39,    40,    -1,    -1,    28,    29,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    50,    53,    12,    13,    15,    54,    55,    60,
       0,    51,    52,    60,    15,    55,    29,    56,    57,    52,
      60,    61,    29,    41,    47,    45,    46,    17,    16,    41,
      58,    59,    60,    28,    57,    41,    58,    42,    46,    29,
      48,    42,    42,    59,    43,    43,    14,    63,    63,    15,
      60,    64,    65,    18,    19,    20,    24,    29,    68,    69,
      70,    68,    29,    66,    67,    15,    65,    41,    41,    41,
      41,    47,     4,    62,    68,    34,    62,    47,    45,    46,
      70,     8,    10,    11,    28,    29,    41,    70,    71,    71,
      71,    71,    71,    44,    71,    44,    28,    67,    42,    71,
      41,    71,     5,     6,     7,    30,    31,    32,    33,    35,
      36,    37,    38,    39,    40,    42,    42,    42,    48,    45,
      45,    48,    45,    71,    72,    42,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    45,
      21,    25,    42,    46,    68,    68,    71,    22,    26,    68,
      45,    23,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    53,    53,    54,    54,
      55,    56,    56,    57,    57,    57,    58,    58,    59,    60,
      60,    61,    62,    63,    63,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     1,    10,     3,     2,     2,     1,
       3,     3,     1,     1,     4,     4,     3,     1,     2,     1,
       1,     9,     3,     3,     2,     2,     1,     3,     3,     1,
       1,     4,     2,     1,     4,     5,     5,    10,     8,     1,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     1,     1,
       4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 47 "func.y" /* yacc.c:1646  */
    {}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 52 "func.y" /* yacc.c:1646  */
    {
	
																struct Gsymbol* funcGentry = Glookup((yyvsp[-8])->NAME);
																funcGentry->localSymTable = l_start;																	
																funcGentry->Label = label_counter+1;
																
																printf("%d %d %d\n",(yyvsp[-1])->Ptr1->TYPE,INT,BOOL);

																assignIndex(arg_start);
																
																struct Gsymbol *checkG = NULL;
																struct ArgList *check1 = NULL;
																struct ArgList *check2 = NULL;
																check1 = arg_start;
																check2 = funcGentry->Args;

																while(check1!=NULL && check2!=NULL){
																	if(check1->TYPE != check2->TYPE){
																		printf("Check the type of Arguments :: %s\n",funcGentry->NAME);
																		exit(1);
																	}
																	if(strcmp(check1->NAME,check2->NAME)!=0){
																		printf("Change of Argument Names for %s\n",funcGentry->NAME);
																		exit(1);
																	}
																	checkG = Glookup(check1->NAME);
																	if((checkG!=NULL) && (checkG->isArray_func == 2)){
																		printf("Arg Name %s in %s is same as the name of function %s\n",check1->NAME,(yyvsp[-8])->NAME,checkG->NAME);
																		exit(1);
																	}
																	check1 = check1->NEXT;
																	check2 = check2->NEXT;
																}

																if(check1!=NULL || check2!=NULL){
																	printf("check the number of Arguments for %s\n",(yyvsp[-8])->NAME);
																	exit(1);
																}

																if((yyvsp[-1])->Ptr1->TYPE != (yyvsp[-9])->TYPE){
																	printf("Return Type Check for %s\n",(yyvsp[-8])->NAME);
																	exit(1);
																}


																funcGentry->Args = arg_start;

																//printf("%d, %d, %d\n",INT,funcGentry->TYPE,$1->TYPE);

																fprintf(fp,"L%d:\n",label_counter+1);
																label_counter ++;

																fprintf(fp,"PUSH BP\n");
																fprintf(fp,"MOV BP, SP\n");
																fprintf(fp,"ADD SP, %d\n",idx);

															 	code_gen((yyvsp[-2])); 

															 	regs1 = code_gen((yyvsp[-1])->Ptr1);

															 	regs2 = allocate_register();
															    
															    fprintf(fp,"SUB SP, %d\n",idx);

															    fprintf(fp,"MOV R%d, BP\n",regs2);
															    fprintf(fp,"SUB R%d, 2\n",regs2);
															    fprintf(fp,"MOV [R%d], R%d\n",regs2,regs1);
															    register_deallocate();
															    register_deallocate();

															    fprintf(fp,"POP BP\n");
															    fprintf(fp,"RET\n");

															    printf("Intermediate Code Generated\n");

																l_start = l_end = NULL;
																idx = 0;
																arg_start = arg_end = NULL;

															}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 133 "func.y" /* yacc.c:1646  */
    { fp = fopen("intermediate.xsm","w+"); write_header(); }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 134 "func.y" /* yacc.c:1646  */
    { fp = fopen("intermediate.xsm","w+"); write_header(); }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 139 "func.y" /* yacc.c:1646  */
    { updateGentriesTo((yyvsp[-2])->TYPE); }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 141 "func.y" /* yacc.c:1646  */
    { 	}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 142 "func.y" /* yacc.c:1646  */
    { 	}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 144 "func.y" /* yacc.c:1646  */
    { Ginstall((yyvsp[0])->NAME,variable_type,1);					}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 145 "func.y" /* yacc.c:1646  */
    { 
													  Ginstall((yyvsp[-3])->NAME,variable_type,(yyvsp[-1])->VALUE);	
													  struct Gsymbol *arrGentry = NULL;
													  arrGentry = Glookup((yyvsp[-3])->NAME);
													  arrGentry->isArray_func = 1;

													}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 153 "func.y" /* yacc.c:1646  */
    {

													  Ginstall((yyvsp[-3])->NAME,-3,0);
													  struct Gsymbol *funcGentry = NULL;
													  funcGentry = Glookup((yyvsp[-3])->NAME);
													  funcGentry->Args = arg_start;
													  funcGentry->isArray_func = 2;

													  arg_start = arg_end = NULL;		
													}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 167 "func.y" /* yacc.c:1646  */
    { ArgInstall((yyvsp[0])->NAME, variable_type); }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 169 "func.y" /* yacc.c:1646  */
    { (yyval) = treeCreate(INT,0,0,'\0',NULL,NULL,NULL,NULL); variable_type = INT; }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "func.y" /* yacc.c:1646  */
    { (yyval) = treeCreate(BOOL,0,0,'\0',NULL,NULL,NULL,NULL); variable_type = BOOL;}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 173 "func.y" /* yacc.c:1646  */
    { 
																
																Ginstall("main",(yyvsp[-8])->TYPE,0);

																arg_start = arg_end = NULL;

																struct Gsymbol* mainGentry = Glookup("main");
																mainGentry->localSymTable = l_start;																	
																mainGentry->Label = 0;
																mainGentry->Args = arg_start;
																
																fprintf(fp,"L0:\n");

																fprintf(fp,"PUSH BP\n");
																fprintf(fp,"MOV BP, SP\n");
																fprintf(fp,"ADD SP, %d\n",idx);

															 	code_gen((yyvsp[-2]));

															    fprintf(fp,"SUB SP, %d\n",idx);
															    fprintf(fp,"POP BP\n");
															    fprintf(fp,"RET\n");

															    printf("Intermediate Code Generated\n");
															    fclose(fp);
														
															    parse1();
															    printf("Label Table Created\n");
															    parse2();
															    printf("Target Code Generated\n");

																l_start = l_end = NULL;
																idx = 0;
																arg_start = arg_end = NULL;

																exit(1);
															}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 211 "func.y" /* yacc.c:1646  */
    {(yyval) = treeCreate(0,RETURN,0,'\0',NULL,(yyvsp[-1]),NULL,NULL);}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 213 "func.y" /* yacc.c:1646  */
    {}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 214 "func.y" /* yacc.c:1646  */
    {}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 224 "func.y" /* yacc.c:1646  */
    { Linstall((yyvsp[0])->NAME,variable_type,1); 			}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 225 "func.y" /* yacc.c:1646  */
    { Linstall((yyvsp[-3])->NAME,variable_type,(yyvsp[-1])->VALUE);	}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 228 "func.y" /* yacc.c:1646  */
    { (yyval) = treeCreate(-1,-1,0,'\0',NULL,(yyvsp[-1]),(yyvsp[0]),NULL); }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 229 "func.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 231 "func.y" /* yacc.c:1646  */
    { typeCheckNode((yyvsp[-3]),(yyvsp[-1])->TYPE);  (yyval) = treeCreate(0,ASSGN,0,'\0',NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 232 "func.y" /* yacc.c:1646  */
    { 						  	   (yyval) = treeCreate(0,READ,0,'\0',NULL,(yyvsp[-2]),NULL,NULL);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 233 "func.y" /* yacc.c:1646  */
    { /*typeCheckNode($3,INT);*/	   (yyval) = treeCreate(0,WRITE,0,'\0',NULL,(yyvsp[-2]),NULL,NULL);}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 234 "func.y" /* yacc.c:1646  */
    { typeCheckNode((yyvsp[-7]),BOOL); 	   (yyval) = treeCreate(0,IF,0,'\0',NULL,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2])); }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 235 "func.y" /* yacc.c:1646  */
    { typeCheckNode((yyvsp[-5]),BOOL); 	   (yyval) = treeCreate(0,WHILE,0,'\0',NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 238 "func.y" /* yacc.c:1646  */
    {  updateEntry((yyvsp[0]));  (yyval) = (yyvsp[0]);}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 239 "func.y" /* yacc.c:1646  */
    {  typeCheckNode((yyvsp[-1]),INT); updateEntry((yyvsp[-3])); (yyvsp[-3])->Ptr1 = (yyvsp[-1]); (yyval) = (yyvsp[-3]);}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 241 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),INT);  (yyval) = treeCreate(INT,PLUS,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 242 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),INT);  (yyval) = treeCreate(INT,MUL,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL); 	}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 243 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),INT);  (yyval) = treeCreate(INT,MINUS,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);  }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 244 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),INT);  (yyval) = treeCreate(INT,DIV,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);  }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 245 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),INT);  (yyval) = treeCreate(INT,MOD,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);  }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 246 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),INT);  (yyval) = treeCreate(BOOL,LT,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);	}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 247 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),INT);  (yyval) = treeCreate(BOOL,GT,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);	}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 248 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),INT);  (yyval) = treeCreate(BOOL,LE,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);	}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 249 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),INT);  (yyval) = treeCreate(BOOL,GE,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);	}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 250 "func.y" /* yacc.c:1646  */
    { typeCheckNodesEq((yyvsp[-2]),(yyvsp[0]));    (yyval) = treeCreate(BOOL,EQ,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);	}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 251 "func.y" /* yacc.c:1646  */
    { typeCheckNodesEq((yyvsp[-2]),(yyvsp[0]));    (yyval) = treeCreate(BOOL,NEQ,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);	}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 252 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),BOOL); (yyval) = treeCreate(BOOL,AND,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 253 "func.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),BOOL); (yyval) = treeCreate(BOOL,OR,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);  }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 254 "func.y" /* yacc.c:1646  */
    { typeCheckNode((yyvsp[0]),BOOL); 	  (yyval) = treeCreate(BOOL,NOT,0,'\0',NULL,(yyvsp[0]),NULL,NULL);   }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 255 "func.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]);}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 256 "func.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 257 "func.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 258 "func.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 259 "func.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 260 "func.y" /* yacc.c:1646  */
    { 
  									gUse = Glookup((yyvsp[-3])->NAME);
  									if(gUse == NULL){
  										printf("Undeclared Function Call\n");
  										exit(1);
  									}
  									if(gUse->isArray_func != 2){
  										printf("%s is not declared as a function\n",(yyvsp[-3])->NAME);
  										exit(1);
  									}

  									struct tnode *checkT = funcArg_start;
  									struct ArgList *checkA = gUse->Args;

  									while(checkT != NULL && checkA!=NULL){
  										if(checkT->TYPE != checkA->TYPE){
  											printf("Mismatch of Types in function call %s\n",(yyvsp[-3])->NAME);
  											exit(1);
  										}
  										checkT = checkT->NEXT;
  										checkA = checkA->NEXT;
  									}

  									if(checkT!=NULL || checkA!=NULL){
  										printf("Check number of arguments in function call %s\n",(yyvsp[-3])->NAME);
  										exit(1);
  									}

  									(yyval) = treeCreate(gUse->TYPE,FUNC,0,(yyvsp[-3])->NAME,funcArg_start,NULL,NULL,NULL);
  									funcArg_start = funcArg_end = NULL;
  								}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 293 "func.y" /* yacc.c:1646  */
    { funcArgAdd((yyvsp[0]));         }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 294 "func.y" /* yacc.c:1646  */
    { funcArgAdd((yyvsp[0]));   	  }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1892 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 296 "func.y" /* yacc.c:1906  */



	#include "decl.c"
	#include "exptest.c"
	#include "label.c"
	#include "codegen.c"

yyerror(char const *s)
{
    printf("yerror %s",s);
}


int main(int argc, char *argv[]) {
	if(argc>1){
		FILE *fp = fopen(argv[1],"r");
		if(fp) yyin = fp;
	}
	yyparse();
	return 0;
}
