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
#line 1 "utype.y" /* yacc.c:339  */

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

	#include "typetables.h"
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
	struct tnode *tUse_Iter = NULL;
	struct Gsymbol *gUse = NULL;
	struct Lsymbol *lUse = NULL;
	struct ArgList *argUse = NULL;

	char *currDataType = NULL;
	struct Fieldlist *curr_FieldList = NULL;
	struct Typetable *variable_type;

	int yylex(void);
	extern FILE *yyin;
	extern int line;
	#define YYSTYPE tnode *

#line 109 "y.tab.c" /* yacc.c:339  */

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
    INIT = 258,
    TYPEI = 259,
    ENDTYPEI = 260,
    FREE = 261,
    ALLOC = 262,
    EXIT = 263,
    FIELD = 264,
    NULL_NODE = 265,
    BEGINNING = 266,
    END = 267,
    FUNC = 268,
    RETURN = 269,
    MOD = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    CONST = 274,
    TRUE = 275,
    FALSE = 276,
    INT = 277,
    BOOL = 278,
    DECL = 279,
    ENDDECL = 280,
    ENDOFFILE = 281,
    MAIN = 282,
    READ = 283,
    WRITE = 284,
    IF = 285,
    THEN = 286,
    ELSE = 287,
    ENDIF = 288,
    WHILE = 289,
    DO = 290,
    ENDWHILE = 291,
    NUM = 292,
    ID = 293,
    PLUS = 294,
    MINUS = 295,
    MUL = 296,
    DIV = 297,
    ASSGN = 298,
    LT = 299,
    LE = 300,
    GT = 301,
    GE = 302,
    EQ = 303,
    NEQ = 304
  };
#endif
/* Tokens.  */
#define INIT 258
#define TYPEI 259
#define ENDTYPEI 260
#define FREE 261
#define ALLOC 262
#define EXIT 263
#define FIELD 264
#define NULL_NODE 265
#define BEGINNING 266
#define END 267
#define FUNC 268
#define RETURN 269
#define MOD 270
#define AND 271
#define OR 272
#define NOT 273
#define CONST 274
#define TRUE 275
#define FALSE 276
#define INT 277
#define BOOL 278
#define DECL 279
#define ENDDECL 280
#define ENDOFFILE 281
#define MAIN 282
#define READ 283
#define WRITE 284
#define IF 285
#define THEN 286
#define ELSE 287
#define ENDIF 288
#define WHILE 289
#define DO 290
#define ENDWHILE 291
#define NUM 292
#define ID 293
#define PLUS 294
#define MINUS 295
#define MUL 296
#define DIV 297
#define ASSGN 298
#define LT 299
#define LE 300
#define GT 301
#define GE 302
#define EQ 303
#define NEQ 304

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

#line 258 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      56,    57,     2,     2,    53,     2,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    55,    57,    61,    62,    65,    66,    69,
      95,   100,   101,   104,   118,   119,   120,   127,   128,   131,
     132,   134,   136,   137,   139,   140,   154,   166,   167,   169,
     172,   173,   175,   274,   314,   316,   317,   319,   320,   322,
     324,   325,   328,   329,   340,   341,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     360,   391,   398,   399,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   457,   458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INIT", "TYPEI", "ENDTYPEI", "FREE",
  "ALLOC", "EXIT", "FIELD", "NULL_NODE", "BEGINNING", "END", "FUNC",
  "RETURN", "MOD", "AND", "OR", "NOT", "CONST", "TRUE", "FALSE", "INT",
  "BOOL", "DECL", "ENDDECL", "ENDOFFILE", "MAIN", "READ", "WRITE", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "NUM", "ID", "PLUS",
  "MINUS", "MUL", "DIV", "ASSGN", "LT", "LE", "GT", "GE", "EQ", "NEQ",
  "'{'", "'}'", "';'", "','", "'['", "']'", "'('", "')'", "'.'", "$accept",
  "program", "Init", "TypeDefBlock", "TypeDefList", "TypeDef",
  "dataTypeName", "FieldDeclList", "FieldDecl", "TypeName", "GDefBlock",
  "GDefList", "GDecl", "GIdList", "GId", "ArgList", "Arg", "funcDefBlock",
  "func", "mainBlock", "retStmt", "LDefBlock", "LDefList", "LDecl",
  "LIdList", "LId", "Slist", "Stmt", "Field", "VAR", "E", "funCallArgs", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     123,   125,    59,    44,    91,    93,    40,    41,    46
};
# endif

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -85,     4,     2,   -85,   -27,     6,   -85,    -4,   -85,   -23,
      95,   127,   -85,   -85,    95,   -85,   -85,   -85,    -5,    20,
     -85,    13,    21,   127,   -85,    25,   -13,   -85,    40,    33,
     101,   -85,   -85,   -85,    28,    34,   -85,    66,   -85,   -85,
     -85,    43,    63,    95,   -85,    -5,    46,    95,   -85,   -85,
      42,    81,   -50,   -85,   -85,    71,   -18,   -85,   -85,    95,
     -85,   103,    82,   -85,    95,   124,   103,   113,   117,   -85,
     298,   135,   152,   108,   -85,   -85,   -85,   115,   171,   172,
     173,   179,   180,    83,   150,   298,     3,   190,   298,   204,
     -85,   113,   213,   195,   220,   110,   110,   110,   110,   227,
     110,   254,   -85,    78,   238,    73,   150,   216,   -85,   105,
     138,   231,   140,   232,   -85,   110,   -85,   -85,   -85,    23,
     110,   226,   -85,   128,   142,   163,   198,   -85,   215,   239,
     235,   233,   -85,   240,   247,   253,   295,   -85,   256,   257,
     -85,   262,   269,   293,   110,   177,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   270,
     292,   289,   -85,   -85,   -85,   268,   -85,   272,   273,   -85,
     280,   -85,   -85,   -85,   -85,   271,    99,   -85,   299,     8,
       8,    60,    60,   299,   299,   293,   293,   293,   293,   293,
     293,   -85,   298,   298,   281,   282,   283,   -85,   110,   -85,
     168,   313,   -85,   -85,   -85,   271,   298,   300,   301,   317,
     -85,   -85,   302,   -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     6,     1,     0,    18,    10,     0,     8,     0,
       0,     0,     5,     7,     0,    14,    15,    16,     0,     0,
      20,    14,     0,     0,    31,     0,     0,    12,     0,    24,
       0,    23,    17,    19,     0,     0,    30,     0,     3,     9,
      11,     0,     0,     0,    21,     0,     0,     0,     2,    13,
       0,     0,     0,    28,    22,     0,     0,    25,    29,     0,
      26,    36,     0,    27,     0,     0,    36,     0,     0,    38,
       0,     0,    42,     0,    41,    35,    37,     0,     0,     0,
       0,     0,     0,    62,     0,    45,     0,     0,     0,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,    84,     0,    80,    81,    79,    62,
       0,    83,    82,     0,     0,     0,     0,    60,     0,     0,
       0,     0,    61,     0,     0,     0,     0,    43,     0,     0,
      46,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    34,    33,     0,    48,     0,     0,    47,
       0,    52,    53,    55,    54,    87,     0,    78,    68,    75,
      76,    64,    66,    65,    67,    69,    71,    70,    72,    73,
      74,    56,     0,     0,     0,     0,     0,    32,     0,    85,
       0,     0,    50,    49,    51,    86,     0,     0,     0,     0,
      58,    59,     0,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   -85,   -85,   -85,   344,   -85,   -85,   329,    18,
     -85,   -85,   337,   -85,   312,   311,   303,   -85,   336,   338,
     258,   294,   -85,   297,   -85,   275,   -80,   -85,   -70,   -68,
     -84,   -85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     7,     8,     9,    26,    27,    51,
      11,    19,    20,    30,    31,    52,    53,    23,    24,    25,
     101,    65,    68,    69,    73,    74,    84,    85,   121,   122,
     123,   176
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,    12,    87,    59,     3,   102,     4,    60,   106,    15,
      16,     6,   124,   125,   126,    86,   128,    87,    86,   131,
      87,   135,   110,   146,   112,    17,   113,    14,    18,    22,
      10,   143,    28,    29,     6,    59,   145,    18,    39,    62,
      34,    22,    15,    16,    28,    32,   103,   149,   150,   151,
     152,    38,   153,   154,   155,   156,   157,   158,    17,    35,
     175,   104,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   146,   133,    98,    41,   144,
     134,    99,    67,   114,    46,   130,    67,    42,   114,    43,
      47,   115,    48,   116,   117,    49,   115,    57,   116,   117,
      50,   151,   152,    55,   153,   154,   155,   156,   157,   158,
     118,   119,   200,   201,   205,   118,   119,    15,    16,    58,
     114,    61,    86,    86,    87,    87,   209,    64,   115,   120,
     116,   117,    66,    17,   120,    70,    86,    98,    87,    15,
      16,    99,    75,   146,   147,   148,    88,   118,   119,    21,
      16,    72,   198,    44,    45,    17,   199,   146,   147,   148,
      90,    91,   138,    99,   100,    17,   120,   149,   150,   151,
     152,    92,   153,   154,   155,   156,   157,   158,   146,   147,
     148,   149,   150,   151,   152,   159,   153,   154,   155,   156,
     157,   158,   146,   147,   148,   139,   104,   141,   104,   160,
     206,   207,   149,   150,   151,   152,    89,   153,   154,   155,
     156,   157,   158,   146,   147,   148,   149,   150,   151,   152,
     161,   153,   154,   155,   156,   157,   158,    93,    94,    95,
     146,   147,   148,   105,   177,    96,    97,   149,   150,   151,
     152,   107,   153,   154,   155,   156,   157,   158,   146,   147,
     148,   109,   111,   162,   149,   150,   151,   152,    83,   153,
     154,   155,   156,   157,   158,   127,   129,   163,   146,   147,
     148,   137,   149,   150,   151,   152,   132,   153,   154,   155,
     156,   157,   158,   140,   104,   166,   146,   147,   148,   142,
     164,   165,   149,   150,   151,   152,   167,   153,   154,   155,
     156,   157,   158,   168,    77,   169,    78,   170,   171,   172,
     149,   150,   151,   152,   173,   153,   154,   155,   156,   157,
     158,   174,   191,   192,   193,   194,    79,    80,    81,   195,
     196,   197,    82,   202,   203,   204,    83,    -1,    -1,    -1,
      -1,    -1,    -1,   153,   154,   155,   156,   157,   158,   208,
     212,    13,   210,   211,   213,    40,    33,    54,    56,    36,
      71,    37,    63,     0,   136,    76,   108
};

static const yytype_int16 yycheck[] =
{
      70,     5,    70,    53,     0,    85,     4,    57,    88,    22,
      23,    38,    96,    97,    98,    85,   100,    85,    88,   103,
      88,   105,    92,    15,    94,    38,    94,    50,    10,    11,
      24,   115,    14,    38,    38,    53,   120,    19,    51,    57,
      27,    23,    22,    23,    26,    25,    43,    39,    40,    41,
      42,    26,    44,    45,    46,    47,    48,    49,    38,    38,
     144,    58,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    15,     3,    54,    38,    56,
       7,    58,    64,    10,    56,     7,    68,    54,    10,    56,
      56,    18,    26,    20,    21,    52,    18,    55,    20,    21,
      37,    41,    42,    57,    44,    45,    46,    47,    48,    49,
      37,    38,   192,   193,   198,    37,    38,    22,    23,    38,
      10,    50,   192,   193,   192,   193,   206,    24,    18,    56,
      20,    21,    50,    38,    56,    11,   206,    54,   206,    22,
      23,    58,    25,    15,    16,    17,    11,    37,    38,    22,
      23,    38,    53,    52,    53,    38,    57,    15,    16,    17,
      52,    53,    57,    58,    14,    38,    56,    39,    40,    41,
      42,    56,    44,    45,    46,    47,    48,    49,    15,    16,
      17,    39,    40,    41,    42,    57,    44,    45,    46,    47,
      48,    49,    15,    16,    17,    57,    58,    57,    58,    57,
      32,    33,    39,    40,    41,    42,    54,    44,    45,    46,
      47,    48,    49,    15,    16,    17,    39,    40,    41,    42,
      57,    44,    45,    46,    47,    48,    49,    56,    56,    56,
      15,    16,    17,    43,    57,    56,    56,    39,    40,    41,
      42,    37,    44,    45,    46,    47,    48,    49,    15,    16,
      17,    38,    57,    55,    39,    40,    41,    42,    38,    44,
      45,    46,    47,    48,    49,    38,    12,    52,    15,    16,
      17,    55,    39,    40,    41,    42,    38,    44,    45,    46,
      47,    48,    49,    52,    58,    52,    15,    16,    17,    57,
      51,    56,    39,    40,    41,    42,    56,    44,    45,    46,
      47,    48,    49,    56,     6,    52,     8,    12,    52,    52,
      39,    40,    41,    42,    52,    44,    45,    46,    47,    48,
      49,    52,    52,    31,    35,    57,    28,    29,    30,    57,
      57,    51,    34,    52,    52,    52,    38,    44,    45,    46,
      47,    48,    49,    44,    45,    46,    47,    48,    49,    36,
      33,     7,    52,    52,    52,    26,    19,    45,    47,    23,
      66,    23,    59,    -1,   106,    68,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,    61,     0,     4,    62,    38,    63,    64,    65,
      24,    69,     5,    64,    50,    22,    23,    38,    68,    70,
      71,    22,    68,    76,    77,    78,    66,    67,    68,    38,
      72,    73,    25,    71,    27,    38,    77,    78,    26,    51,
      67,    38,    54,    56,    52,    53,    56,    56,    26,    52,
      37,    68,    74,    75,    73,    57,    74,    55,    38,    53,
      57,    50,    57,    75,    24,    80,    50,    68,    81,    82,
      11,    80,    38,    83,    84,    25,    82,     6,     8,    28,
      29,    30,    34,    38,    85,    86,    87,    88,    11,    54,
      52,    53,    56,    56,    56,    56,    56,    56,    54,    58,
      14,    79,    85,    43,    58,    43,    85,    37,    84,    38,
      87,    57,    87,    88,    10,    18,    20,    21,    37,    38,
      56,    87,    88,    89,    89,    89,    89,    38,    89,    12,
       7,    89,    38,     3,     7,    89,    79,    55,    57,    57,
      52,    57,    57,    89,    56,    89,    15,    16,    17,    39,
      40,    41,    42,    44,    45,    46,    47,    48,    49,    57,
      57,    57,    55,    52,    51,    56,    52,    56,    56,    52,
      12,    52,    52,    52,    52,    89,    90,    57,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    52,    31,    35,    57,    57,    57,    51,    53,    57,
      85,    85,    52,    52,    52,    89,    32,    33,    36,    85,
      52,    52,    33,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    62,    62,    63,    63,    64,
      65,    66,    66,    67,    68,    68,    68,    69,    69,    70,
      70,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      76,    76,    77,    78,    79,    80,    80,    81,    81,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     0,     3,     0,     2,     1,     4,
       1,     2,     1,     3,     1,     1,     1,     3,     0,     2,
       1,     3,     3,     1,     1,     4,     4,     3,     1,     2,
       2,     1,    12,    11,     3,     3,     0,     2,     1,     3,
       3,     1,     1,     4,     2,     1,     4,     4,     4,     6,
       6,     6,     5,     5,     5,     5,     5,    10,     8,     8,
       3,     3,     1,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     1,     1,     1,     4,     3,     1
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
#line 54 "utype.y" /* yacc.c:1646  */
    {}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "utype.y" /* yacc.c:1646  */
    {}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "utype.y" /* yacc.c:1646  */
    {
	TypeTableCreate();	
}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 61 "utype.y" /* yacc.c:1646  */
    { printf("Type Definitions\n"); }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 69 "utype.y" /* yacc.c:1646  */
    { 
												
												//printf("NEW TYPE %s::\n",currDataType);

												Tinstall(currDataType,curr_FieldList);
												struct Fieldlist *temp_FieldIter = temp_current_flist;
												struct Typetable *curr_Tentry = Tlookup(currDataType);

												int fieldIndex = 1;
												while(temp_FieldIter != NULL){
													if(temp_FieldIter ->TYPE == NULL){
														temp_FieldIter ->TYPE = curr_Tentry;
													}
													temp_FieldIter -> fieldIndex = fieldIndex;
													fieldIndex ++;
													//printf("%s - type %s, ",temp_FieldIter->NAME,temp_FieldIter->TYPE->NAME);
													temp_FieldIter = temp_FieldIter->NEXT;
												}
												//printf("\n");
												curr_FieldList = temp_current_flist = NULL;
												free(currDataType);
												currDataType = NULL;

										   }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "utype.y" /* yacc.c:1646  */
    {
		currDataType = malloc(sizeof(char)*20);
		strcpy(currDataType, (yyvsp[0])->NAME);
}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 104 "utype.y" /* yacc.c:1646  */
    {
	
	struct Typetable *t_entry = Tlookup((yyvsp[-2])->NAME);

	if((yyvsp[-2])->TYPE == NULL && strcmp((yyvsp[-2])->NAME, currDataType)!=0){
		printf("Undefined data type\n");
		exit(1);
	}
	curr_FieldList = Finstall((yyvsp[-1])->NAME);
	curr_FieldList -> TYPE = t_entry;

}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 118 "utype.y" /* yacc.c:1646  */
    {(yyval) = treeCreate(VAR_TYPE_INT,0,0,"integer",NULL,NULL,NULL,NULL); variable_type = VAR_TYPE_INT;   }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 119 "utype.y" /* yacc.c:1646  */
    {(yyval) = treeCreate(VAR_TYPE_BOOL,0,0,"boolean",NULL,NULL,NULL,NULL); variable_type = VAR_TYPE_BOOL; }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 120 "utype.y" /* yacc.c:1646  */
    {
							variable_type = Tlookup((yyvsp[0])->NAME);
							(yyval) = treeCreate(variable_type,0,0,(yyvsp[0])->NAME,NULL,NULL,NULL,NULL);
						}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "utype.y" /* yacc.c:1646  */
    {  fp = fopen("intermediate.xsm","w+"); 	write_header(); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "utype.y" /* yacc.c:1646  */
    {  fp = fopen("intermediate.xsm","w+"); 	write_header(); }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 134 "utype.y" /* yacc.c:1646  */
    { printf("%s Global\n",(yyvsp[-2])->TYPE->NAME); updateGentriesTo((yyvsp[-2])->TYPE);  }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 136 "utype.y" /* yacc.c:1646  */
    { 	}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 137 "utype.y" /* yacc.c:1646  */
    { 	}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 139 "utype.y" /* yacc.c:1646  */
    { printf("%s %s\n",variable_type->NAME,(yyvsp[0])->NAME); Ginstall((yyvsp[0])->NAME,variable_type,1);					}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 140 "utype.y" /* yacc.c:1646  */
    { 

													  if(variable_type!=VAR_TYPE_INT && variable_type!=VAR_TYPE_BOOL){
													  	printf("Arrays of User defined types are not allowed\n");
													  	exit(1);
													  }
													  printf("%s %s\n",variable_type->NAME,(yyvsp[-3])->NAME);
													  Ginstall((yyvsp[-3])->NAME,variable_type,(yyvsp[-1])->VALUE);	
													  struct Gsymbol *arrGentry = NULL;
													  arrGentry = Glookup((yyvsp[-3])->NAME);
													  arrGentry->isArray_func = 1;
	
													}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 154 "utype.y" /* yacc.c:1646  */
    {

													  Ginstall((yyvsp[-3])->NAME,NULL,0);
													  struct Gsymbol *funcGentry = NULL;
													  funcGentry = Glookup((yyvsp[-3])->NAME);

													  funcGentry->Args = arg_start;
													  funcGentry->isArray_func = 2;

													  arg_start = arg_end = NULL;	
													}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 169 "utype.y" /* yacc.c:1646  */
    { ArgInstall((yyvsp[0])->NAME, variable_type); }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 175 "utype.y" /* yacc.c:1646  */
    {
																
																printf("Here\n");
																struct Gsymbol* funcGentry = Glookup((yyvsp[-10])->NAME);

																printf("%s for %s\n",funcGentry->TYPE->NAME,(yyvsp[-10])->NAME);

																if(strcmp(funcGentry->TYPE->NAME,(yyvsp[-11])->TYPE->NAME)!=0){
																	printf("FUNCTION Return Type Error\n");
																	exit(1);
																}

																funcGentry->localSymTable = l_start;																	
																funcGentry->Label = label_counter+1;
																
																//printf("%d %d %d\n",$9->Ptr1->TYPE,INT,BOOL);

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
																		printf("Arg Name %s in %s is same as the name of function %s\n",check1->NAME,(yyvsp[-10])->NAME,checkG->NAME);
																		exit(1);
																	}
																	check1 = check1->NEXT;
																	check2 = check2->NEXT;
																}

																if(check1!=NULL || check2!=NULL){
																	printf("check the number of Arguments for %s\n",(yyvsp[-10])->NAME);
																	exit(1);
																}

																printf("args correct\n");

																if((yyvsp[-2])->Ptr1->TYPE != (yyvsp[-11])->TYPE){
																	printf("Return Type Check for %s\n",(yyvsp[-10])->NAME);
																	exit(1);
																}


																funcGentry->Args = arg_start;

																//printf("%d, %d, %d\n",INT,funcGentry->TYPE,$1->TYPE);
																

																
																fprintf(fp,"L%d:\n",label_counter+1);
																label_counter ++;

																fprintf(fp,"PUSH BP\n");
																fprintf(fp,"MOV BP, SP\n");
																fprintf(fp,"ADD SP, %d\n",idx);

																printf("Before Codegen\n");
															 	code_gen((yyvsp[-3])); 
																printf("After Codegen\n");

															 	regs1 = code_gen((yyvsp[-2])->Ptr1);

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

																printf("FUNC Decl done\n");

															}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 274 "utype.y" /* yacc.c:1646  */
    { 
																
																
																Ginstall("main",VAR_TYPE_INT,0);

																arg_start = arg_end = NULL;

																struct Gsymbol* mainGentry = Glookup("main");
																mainGentry->localSymTable = l_start;																	
																mainGentry->Label = 0;
																mainGentry->Args = arg_start;
																
																
																fprintf(fp,"L0:\n");

																fprintf(fp,"PUSH BP\n");
																fprintf(fp,"MOV BP, SP\n");
																fprintf(fp,"ADD SP, %d\n",idx);

															 	code_gen((yyvsp[-3]));

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
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 314 "utype.y" /* yacc.c:1646  */
    {(yyval) = treeCreate(NULL,RETURN,0,'\0',NULL,(yyvsp[-1]),NULL,NULL);}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 316 "utype.y" /* yacc.c:1646  */
    {printf("Local DEcls done\n");}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 317 "utype.y" /* yacc.c:1646  */
    {printf("Local DEcls done\n");}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 328 "utype.y" /* yacc.c:1646  */
    { Linstall((yyvsp[0])->NAME,variable_type,1); 			}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 329 "utype.y" /* yacc.c:1646  */
    { 

													  if(variable_type!=VAR_TYPE_INT && variable_type!=VAR_TYPE_BOOL){
													  	printf("Arrays of User defined types are not allowed\n");
													  	exit(1);
													  }
													  Linstall((yyvsp[-3])->NAME,variable_type,(yyvsp[-1])->VALUE);	

													}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 340 "utype.y" /* yacc.c:1646  */
    { (yyval) = treeCreate(NULL,-1,0,'\0',NULL,(yyvsp[-1]),(yyvsp[0]),NULL); }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 341 "utype.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 344 "utype.y" /* yacc.c:1646  */
    {   (yyval) = treeCreate(NULL,EXIT,0,'\0',NULL,NULL,NULL,NULL);   }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 345 "utype.y" /* yacc.c:1646  */
    {   userDefNodesTypeCheck((yyvsp[-3]),(yyvsp[-1])); (yyval) = treeCreate(NULL,ASSGN,0,'\0',NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);  }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 346 "utype.y" /* yacc.c:1646  */
    {   userDefNodesTypeCheck((yyvsp[-3]),(yyvsp[-1])); (yyval) = treeCreate(NULL,ASSGN,0,'\0',NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);  }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 347 "utype.y" /* yacc.c:1646  */
    {   (yyval) = treeCreate(NULL,ASSGN,0,'\0',NULL,(yyvsp[-5]),(yyvsp[-3]),NULL);  }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 348 "utype.y" /* yacc.c:1646  */
    { 	(yyval) = treeCreate(NULL,ASSGN,0,'\0',NULL,(yyvsp[-5]),(yyvsp[-3]),NULL);  }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 349 "utype.y" /* yacc.c:1646  */
    { 	(yyval) = treeCreate(NULL,ASSGN,0,'\0',NULL,(yyvsp[-5]),(yyvsp[-3]),NULL);  }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 350 "utype.y" /* yacc.c:1646  */
    { 	(yyval) = treeCreate(NULL,FREE,0,'\0',NULL,(yyvsp[-2]),NULL,NULL); }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 351 "utype.y" /* yacc.c:1646  */
    { 	(yyval) = treeCreate(NULL,FREE,0,'\0',NULL,(yyvsp[-2]),NULL,NULL); }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 352 "utype.y" /* yacc.c:1646  */
    { 	(yyval) = treeCreate(NULL,READ,0,'\0',NULL,(yyvsp[-2]),NULL,NULL); }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 353 "utype.y" /* yacc.c:1646  */
    { 	(yyval) = treeCreate(NULL,READ,0,'\0',NULL,(yyvsp[-2]),NULL,NULL); }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 354 "utype.y" /* yacc.c:1646  */
    {   (yyval) = treeCreate(NULL,WRITE,0,'\0',NULL,(yyvsp[-2]),NULL,NULL);}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 355 "utype.y" /* yacc.c:1646  */
    {  	printf("IF\n"); (yyval) = treeCreate(NULL,IF,0,'\0',NULL,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));       }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 356 "utype.y" /* yacc.c:1646  */
    { 	printf("IF\n"); (yyval) = treeCreate(NULL,IF,0,'\0',NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);     }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 357 "utype.y" /* yacc.c:1646  */
    {   (yyval) = treeCreate(NULL,WHILE,0,'\0',NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);  }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 360 "utype.y" /* yacc.c:1646  */
    { 	
							argUse = ArgLookup((yyvsp[-2])->NAME);
							gUse = Glookup((yyvsp[-2])->NAME);
							lUse = Llookup((yyvsp[-2])->NAME);

							if(argUse!=NULL) {
								curr_FieldList = FLookup(argUse->TYPE,(yyvsp[0])->NAME);
								(yyvsp[-2])->TYPE = argUse->TYPE;
							}
							else if(lUse!=NULL) {
								curr_FieldList = FLookup(lUse->TYPE,(yyvsp[0])->NAME);
								(yyvsp[-2])->TYPE = lUse->TYPE;
							}
							else if(gUse!=NULL) {
								curr_FieldList = FLookup(gUse->TYPE,(yyvsp[0])->NAME);
								(yyvsp[-2])->TYPE = gUse->TYPE;
							}
							else{
								printf("Undeclared Variable %s\n",(yyvsp[-2])->NAME);
								exit(1);
							}

							if(curr_FieldList == NULL){
								printf("%s field error\n",(yyvsp[0])->NAME);
								exit(1);
							}

							(yyval) = treeCreate(curr_FieldList->TYPE, FIELD, 0, '\0', NULL, (yyvsp[-2]), (yyvsp[0]), NULL);

						}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 391 "utype.y" /* yacc.c:1646  */
    {
	                        curr_FieldList = FLookup((yyvsp[-2])->TYPE,(yyvsp[0])->NAME);
							(yyval) = treeCreate(curr_FieldList->TYPE, FIELD, 0, '\0', NULL, (yyvsp[-2]), (yyvsp[0]), NULL);
	  					}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 398 "utype.y" /* yacc.c:1646  */
    { updateEntry((yyvsp[0]));  (yyval) = (yyvsp[0]);}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 399 "utype.y" /* yacc.c:1646  */
    { typeCheckNode((yyvsp[-1]),VAR_TYPE_INT); updateEntry((yyvsp[-3])); (yyvsp[-3])->Ptr1 = (yyvsp[-1]); (yyval) = (yyvsp[-3]);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 401 "utype.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),VAR_TYPE_INT);  (yyval) = treeCreate(VAR_TYPE_INT,PLUS,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);    	}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 402 "utype.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),VAR_TYPE_INT);  (yyval) = treeCreate(VAR_TYPE_INT,MUL,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL); 		}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 403 "utype.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),VAR_TYPE_INT);  (yyval) = treeCreate(VAR_TYPE_INT,MINUS,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);   	}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 404 "utype.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),VAR_TYPE_INT);  (yyval) = treeCreate(VAR_TYPE_INT,DIV,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);     	}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 405 "utype.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),VAR_TYPE_INT);  (yyval) = treeCreate(VAR_TYPE_INT,MOD,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);     	}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 406 "utype.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),VAR_TYPE_INT);  (yyval) = treeCreate(VAR_TYPE_BOOL,LT,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);		}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 407 "utype.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),VAR_TYPE_INT);  (yyval) = treeCreate(VAR_TYPE_BOOL,GT,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);		}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 408 "utype.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),VAR_TYPE_INT);  (yyval) = treeCreate(VAR_TYPE_BOOL,LE,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);		}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 409 "utype.y" /* yacc.c:1646  */
    { typeCheckNodes((yyvsp[-2]),(yyvsp[0]),VAR_TYPE_INT);  (yyval) = treeCreate(VAR_TYPE_BOOL,GE,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);		}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 410 "utype.y" /* yacc.c:1646  */
    { /*typeCheckNodesEq($1,$3);*/             (yyval) = treeCreate(VAR_TYPE_BOOL,EQ,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);		}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 411 "utype.y" /* yacc.c:1646  */
    { /*typeCheckNodesEq($1,$3);  */           (yyval) = treeCreate(VAR_TYPE_BOOL,NEQ,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);		}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 412 "utype.y" /* yacc.c:1646  */
    { /*typeCheckNodes($1,$3,VAR_TYPE_BOOL);*/ (yyval) = treeCreate(VAR_TYPE_BOOL,AND,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL); 		}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 413 "utype.y" /* yacc.c:1646  */
    { /*typeCheckNodes($1,$3,VAR_TYPE_BOOL);*/ (yyval) = treeCreate(VAR_TYPE_BOOL,OR,0,'\0',NULL,(yyvsp[-2]),(yyvsp[0]),NULL);  		}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 414 "utype.y" /* yacc.c:1646  */
    { /*typeCheckNode($2,VAR_TYPE_BOOL); */	   (yyval) = treeCreate(VAR_TYPE_BOOL,NOT,0,'\0',NULL,(yyvsp[0]),NULL,NULL);  	}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 415 "utype.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]);}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 416 "utype.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); (yyval)->TYPE = VAR_TYPE_INT;  }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 417 "utype.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); (yyval)->TYPE = VAR_TYPE_BOOL; }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 418 "utype.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); (yyval)->TYPE = VAR_TYPE_BOOL; }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 419 "utype.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 420 "utype.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 421 "utype.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 422 "utype.y" /* yacc.c:1646  */
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
  										if(strcmp(checkT->TYPE->NAME, checkA->TYPE->NAME)!=0){
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

  									printf("Here2\n");
  								}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 457 "utype.y" /* yacc.c:1646  */
    { funcArgAdd((yyvsp[0]));         }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 458 "utype.y" /* yacc.c:1646  */
    { funcArgAdd((yyvsp[0]));   	  }
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2197 "y.tab.c" /* yacc.c:1646  */
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
#line 460 "utype.y" /* yacc.c:1906  */



	#include "decl.c"
	#include "exptest.c"
	#include "label.c"
	#include "codegen.c"
	#include "typetables.c"

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
