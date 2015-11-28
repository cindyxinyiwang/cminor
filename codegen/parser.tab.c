/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_ID = 258,
     TOKEN_INTEGER = 259,
     TOKEN_CHAR = 260,
     TOKEN_STRING = 261,
     TOKEN_ADD = 262,
     TOKEN_SUBTRACT = 263,
     TOKEN_MULTIPLY = 264,
     TOKEN_DIVIDE = 265,
     TOKEN_ASSIGN = 266,
     TOKEN_MODULO = 267,
     TOKEN_EXPO = 268,
     TOKEN_POST_INCREASE = 269,
     TOKEN_POST_DECREASE = 270,
     TOKEN_NOT = 271,
     TOKEN_LT = 272,
     TOKEN_GT = 273,
     TOKEN_LE = 274,
     TOKEN_GE = 275,
     TOKEN_EQ = 276,
     TOKEN_NEQ = 277,
     TOKEN_AND = 278,
     TOKEN_OR = 279,
     TOKEN_LPAREN = 280,
     TOKEN_RPAREN = 281,
     TOKEN_LSQBRAC = 282,
     TOKEN_RSQBRAC = 283,
     TOKEN_LBRAC = 284,
     TOKEN_RBRAC = 285,
     TOKEN_COLON = 286,
     TOKEN_COMA = 287,
     TOKEN_SEMI = 288,
     TOKEN_KEYWORD_INTEGER = 289,
     TOKEN_KEYWORD_BOOLEAN = 290,
     TOKEN_KEYWORD_CHAR = 291,
     TOKEN_KEYWORD_STRING = 292,
     TOKEN_KEYWORD_ARRAY = 293,
     TOKEN_KEYWORD_TRUE = 294,
     TOKEN_KEYWORD_FALSE = 295,
     TOKEN_KEYWORD_VOID = 296,
     TOKEN_KEYWORD_FUNCTION = 297,
     TOKEN_KEYWORD_IF = 298,
     TOKEN_KEYWORD_ELSE = 299,
     TOKEN_KEYWORD_FOR = 300,
     TOKEN_KEYWORD_PRINT = 301,
     TOKEN_KEYWORD_RETURN = 302,
     TOKEN_END = 303
   };
#endif
/* Tokens.  */
#define TOKEN_ID 258
#define TOKEN_INTEGER 259
#define TOKEN_CHAR 260
#define TOKEN_STRING 261
#define TOKEN_ADD 262
#define TOKEN_SUBTRACT 263
#define TOKEN_MULTIPLY 264
#define TOKEN_DIVIDE 265
#define TOKEN_ASSIGN 266
#define TOKEN_MODULO 267
#define TOKEN_EXPO 268
#define TOKEN_POST_INCREASE 269
#define TOKEN_POST_DECREASE 270
#define TOKEN_NOT 271
#define TOKEN_LT 272
#define TOKEN_GT 273
#define TOKEN_LE 274
#define TOKEN_GE 275
#define TOKEN_EQ 276
#define TOKEN_NEQ 277
#define TOKEN_AND 278
#define TOKEN_OR 279
#define TOKEN_LPAREN 280
#define TOKEN_RPAREN 281
#define TOKEN_LSQBRAC 282
#define TOKEN_RSQBRAC 283
#define TOKEN_LBRAC 284
#define TOKEN_RBRAC 285
#define TOKEN_COLON 286
#define TOKEN_COMA 287
#define TOKEN_SEMI 288
#define TOKEN_KEYWORD_INTEGER 289
#define TOKEN_KEYWORD_BOOLEAN 290
#define TOKEN_KEYWORD_CHAR 291
#define TOKEN_KEYWORD_STRING 292
#define TOKEN_KEYWORD_ARRAY 293
#define TOKEN_KEYWORD_TRUE 294
#define TOKEN_KEYWORD_FALSE 295
#define TOKEN_KEYWORD_VOID 296
#define TOKEN_KEYWORD_FUNCTION 297
#define TOKEN_KEYWORD_IF 298
#define TOKEN_KEYWORD_ELSE 299
#define TOKEN_KEYWORD_FOR 300
#define TOKEN_KEYWORD_PRINT 301
#define TOKEN_KEYWORD_RETURN 302
#define TOKEN_END 303




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 63 "parser.bison"
{
	struct decl* decl_ptr;
	struct type* type_ptr; 
	struct expr* expr_ptr;
	struct stmt* stmt_ptr;
	struct param_list* param_list_ptr;
	char* char_ptr;
}
/* Line 193 of yacc.c.  */
#line 202 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 82 "parser.bison"


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "decl.h"
#include "stmt.h"
#include "type.h"
#include "symbol.h"
#include "param_list.h"

/*
YYSTYPE is the lexical value returned by each rule in a bison grammar.
By default, it is an integer. In this example, we are returning a pointer to an expression.
*/

//#define YYSTYPE struct expr *


/*
Clunky: Manually declare the interface to the scanner generated by flex. 
*/

extern char *yytext;
extern int yyleng;
extern int yylex();
extern int yyerror( char *str );

/*
Clunky: Keep the final result of the parse in a global variable,
so that it can be retrieved by main().
*/

struct decl * parser_result = 0;




/* Line 216 of yacc.c.  */
#line 254 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    20,    28,    33,
      41,    48,    50,    52,    54,    56,    58,    64,    70,    72,
      73,    75,    79,    81,    85,    88,    90,    92,    94,    96,
      99,   103,   107,   110,   120,   124,   127,   135,   141,   149,
     150,   152,   156,   158,   162,   164,   168,   170,   174,   178,
     182,   186,   190,   194,   196,   200,   204,   206,   210,   214,
     218,   220,   224,   226,   229,   232,   234,   237,   240,   242,
     246,   248,   250,   252,   254,   256,   258,   262,   267,   272,
     274,   275,   279
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    48,    -1,    48,    -1,    51,    52,
      -1,    52,    -1,    54,    31,    53,    11,    63,    33,    -1,
      54,    31,    53,    11,    29,    30,    33,    -1,    54,    31,
      53,    33,    -1,    54,    31,    53,    11,    29,    58,    30,
      -1,    54,    31,    53,    11,    29,    30,    -1,    37,    -1,
      34,    -1,    36,    -1,    35,    -1,    41,    -1,    38,    27,
      62,    28,    53,    -1,    42,    53,    25,    55,    26,    -1,
       3,    -1,    -1,    56,    -1,    56,    32,    57,    -1,    57,
      -1,    54,    31,    53,    -1,    58,    59,    -1,    59,    -1,
      60,    -1,    61,    -1,    52,    -1,    63,    33,    -1,    46,
      73,    33,    -1,    47,    63,    33,    -1,    47,    33,    -1,
      45,    25,    62,    33,    62,    33,    62,    26,    60,    -1,
      29,    58,    30,    -1,    29,    30,    -1,    43,    25,    63,
      26,    60,    44,    60,    -1,    43,    25,    63,    26,    59,
      -1,    43,    25,    63,    26,    60,    44,    61,    -1,    -1,
      63,    -1,    63,    11,    64,    -1,    64,    -1,    64,    24,
      65,    -1,    65,    -1,    65,    23,    66,    -1,    66,    -1,
      66,    21,    67,    -1,    66,    22,    67,    -1,    66,    17,
      67,    -1,    66,    18,    67,    -1,    66,    19,    67,    -1,
      66,    20,    67,    -1,    67,    -1,    67,     7,    68,    -1,
      67,     8,    68,    -1,    68,    -1,    68,     9,    69,    -1,
      68,    10,    69,    -1,    68,    12,    69,    -1,    69,    -1,
      69,    13,    70,    -1,    70,    -1,    16,    70,    -1,     8,
      70,    -1,    71,    -1,    72,    14,    -1,    72,    15,    -1,
      72,    -1,    25,    63,    26,    -1,     4,    -1,    39,    -1,
      40,    -1,    54,    -1,     6,    -1,     5,    -1,    29,    74,
      30,    -1,    54,    25,    73,    26,    -1,    72,    27,    63,
      28,    -1,    74,    -1,    -1,    74,    32,    63,    -1,    63,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   128,   132,   141,   150,   154,   162,   166,
     170,   176,   180,   184,   188,   192,   196,   201,   207,   216,
     219,   225,   234,   240,   246,   255,   261,   263,   267,   276,
     280,   284,   288,   292,   296,   300,   304,   310,   314,   321,
     324,   330,   334,   340,   344,   350,   354,   360,   364,   368,
     372,   376,   380,   384,   390,   394,   398,   404,   408,   412,
     416,   422,   426,   431,   435,   439,   445,   449,   453,   459,
     463,   467,   471,   475,   479,   511,   531,   535,   539,   544,
     549,   554,   563
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_ID", "TOKEN_INTEGER",
  "TOKEN_CHAR", "TOKEN_STRING", "TOKEN_ADD", "TOKEN_SUBTRACT",
  "TOKEN_MULTIPLY", "TOKEN_DIVIDE", "TOKEN_ASSIGN", "TOKEN_MODULO",
  "TOKEN_EXPO", "TOKEN_POST_INCREASE", "TOKEN_POST_DECREASE", "TOKEN_NOT",
  "TOKEN_LT", "TOKEN_GT", "TOKEN_LE", "TOKEN_GE", "TOKEN_EQ", "TOKEN_NEQ",
  "TOKEN_AND", "TOKEN_OR", "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LSQBRAC",
  "TOKEN_RSQBRAC", "TOKEN_LBRAC", "TOKEN_RBRAC", "TOKEN_COLON",
  "TOKEN_COMA", "TOKEN_SEMI", "TOKEN_KEYWORD_INTEGER",
  "TOKEN_KEYWORD_BOOLEAN", "TOKEN_KEYWORD_CHAR", "TOKEN_KEYWORD_STRING",
  "TOKEN_KEYWORD_ARRAY", "TOKEN_KEYWORD_TRUE", "TOKEN_KEYWORD_FALSE",
  "TOKEN_KEYWORD_VOID", "TOKEN_KEYWORD_FUNCTION", "TOKEN_KEYWORD_IF",
  "TOKEN_KEYWORD_ELSE", "TOKEN_KEYWORD_FOR", "TOKEN_KEYWORD_PRINT",
  "TOKEN_KEYWORD_RETURN", "TOKEN_END", "$accept", "program", "decl_list",
  "decl", "type", "ident", "param_list", "not_empty_param_list", "param",
  "stmt_list", "stmt", "stmt_matched", "stmt_unmatched", "expr_opt",
  "expr", "term_nnnn", "term_nnn", "term_nn", "term_n", "term",
  "factor_nn", "factor_n", "factor", "item", "expr_list",
  "expr_list_non_empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    68,    68,    68,
      68,    69,    69,    70,    70,    70,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     6,     7,     4,     7,
       6,     1,     1,     1,     1,     1,     5,     5,     1,     0,
       1,     3,     1,     3,     2,     1,     1,     1,     1,     2,
       3,     3,     2,     9,     3,     2,     7,     5,     7,     0,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     1,     2,     2,     1,     2,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     1,
       0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,     3,     0,     0,     5,     0,     1,     2,     4,
       0,    12,    14,    13,    11,     0,    15,     0,     0,    39,
       0,     0,     8,    70,    75,    74,     0,     0,     0,     0,
      71,    72,    73,     0,    40,    42,    44,    46,    53,    56,
      60,    62,    65,    68,    19,     0,     0,    64,    63,     0,
      82,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,     0,    20,    22,     0,    10,     0,     0,
      80,     0,    28,    73,     0,    25,    26,    27,    82,     6,
      69,    76,     0,     0,    79,    16,    41,    43,    45,    49,
      50,    51,    52,    47,    48,    54,    55,    57,    58,    59,
      61,     0,     0,    17,     0,    35,     0,     7,     0,    39,
       0,    32,     0,     9,    24,     0,    29,    81,    77,    78,
      23,    21,    34,     0,     0,    30,    31,     0,    39,    37,
      26,     0,     0,    39,    36,    38,     0,     0,     0,    33,
       0,     0,     0,     0,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    82,    18,    32,    73,    74,    75,    84,
      85,    86,    87,    33,   125,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    93,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -104
static const yytype_int16 yypact[] =
{
       2,  -104,  -104,    43,     3,  -104,   -17,  -104,  -104,  -104,
     144,  -104,  -104,  -104,  -104,    25,  -104,   144,    -2,    17,
      36,   288,  -104,  -104,  -104,  -104,    17,    17,    17,    17,
    -104,  -104,    48,    66,    84,    72,    76,   109,    21,    95,
      98,  -104,  -104,    71,   110,    63,     4,  -104,  -104,     6,
      84,    51,    17,   144,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,  -104,
    -104,    17,    81,    89,    85,  -104,   130,    86,    93,    96,
      17,   270,  -104,    -7,   158,  -104,  -104,  -104,     8,  -104,
    -104,  -104,    17,    97,    90,  -104,    72,    76,   109,    21,
      21,    21,    21,    21,    21,    95,    95,    98,    98,    98,
    -104,    19,   144,  -104,   110,  -104,   186,  -104,    17,    17,
      91,  -104,    15,  -104,  -104,     8,  -104,    84,  -104,  -104,
    -104,  -104,  -104,    38,   106,  -104,  -104,   214,    17,  -104,
      99,   107,   214,    17,  -104,  -104,   115,   242,   119,  -104,
      17,    61,   242,   101,   242
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,    55,   -15,     0,  -104,  -104,    34,    73,
     -77,   -72,     9,  -103,   -18,   102,   103,    94,   261,    14,
      24,   -14,  -104,  -104,    77,   -44
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       6,    34,    20,    46,     6,     1,     1,   124,    94,    21,
      49,    50,    47,    48,    10,    54,   134,    54,    52,    54,
       1,    23,    24,    25,    10,    26,    54,    88,    63,    64,
      54,    22,    90,    27,    50,   141,    94,    89,    95,   124,
     146,   126,    28,     7,    72,    83,    29,   129,   136,    54,
       2,     8,    19,   111,   110,     5,    30,    31,    88,     9,
     139,    44,    50,   122,   137,   140,     1,    23,    24,    25,
     144,    26,    54,    52,   127,   149,    83,   105,   106,    27,
     153,    91,   144,    92,    83,    69,    70,   152,    28,   107,
     108,   109,    76,    77,    53,    54,    55,   130,    71,    56,
     133,    34,    30,    31,    65,    66,    78,    67,    79,    80,
      81,    68,   112,     1,    72,   113,    83,   114,   118,   117,
      34,   119,    92,   128,   135,    34,    57,    58,    59,    60,
      61,    62,   151,     1,    23,    24,    25,    83,    26,   138,
     143,   147,    83,   142,   150,   154,    27,    83,   131,   116,
      98,   145,    83,     0,    83,    28,    96,   120,    97,    76,
     115,     1,    23,    24,    25,     0,    26,     0,     0,    30,
      31,     0,     0,    78,    27,    79,    80,    81,    11,    12,
      13,    14,    15,    28,     0,    16,    17,    76,   123,     1,
      23,    24,    25,     0,    26,     0,     0,    30,    31,     0,
       0,    78,    27,    79,    80,    81,     0,     0,     0,     0,
       0,    28,     0,     0,     0,    76,   132,     1,    23,    24,
      25,     0,    26,     0,     0,    30,    31,     0,     0,    78,
      27,    79,    80,    81,     0,     0,     0,     0,     0,    28,
       0,     0,     0,    76,     0,     1,    23,    24,    25,     0,
      26,     0,     0,    30,    31,     0,     0,    78,    27,    79,
      80,    81,     0,     0,     0,     0,     0,    28,     0,     0,
       0,    76,     0,     1,    23,    24,    25,     0,    26,     0,
       0,    30,    31,     0,     0,   148,    27,    79,    80,    81,
       0,     1,    23,    24,    25,    28,    26,     0,     0,    29,
       0,     0,     0,   121,    27,     0,     0,     0,     0,    30,
      31,     0,     0,    28,     0,     0,     0,    45,    99,   100,
     101,   102,   103,   104,     0,     0,     0,    30,    31
};

static const yytype_int16 yycheck[] =
{
       0,    19,    17,    21,     4,     3,     3,    84,    52,    11,
      28,    29,    26,    27,    31,    11,   119,    11,    25,    11,
       3,     4,     5,     6,    31,     8,    11,    45,     7,     8,
      11,    33,    26,    16,    52,   138,    80,    33,    53,   116,
     143,    33,    25,     0,    44,    45,    29,    28,    33,    11,
      48,    48,    27,    71,    68,     0,    39,    40,    76,     4,
     137,    25,    80,    81,    26,   137,     3,     4,     5,     6,
     142,     8,    11,    25,    92,   147,    76,    63,    64,    16,
     152,    30,   154,    32,    84,    14,    15,    26,    25,    65,
      66,    67,    29,    30,    28,    11,    24,   112,    27,    23,
     118,   119,    39,    40,     9,    10,    43,    12,    45,    46,
      47,    13,    31,     3,   114,    26,   116,    32,    25,    33,
     138,    25,    32,    26,    33,   143,    17,    18,    19,    20,
      21,    22,   150,     3,     4,     5,     6,   137,     8,    33,
      33,    26,   142,    44,    25,    44,    16,   147,   114,    76,
      56,   142,   152,    -1,   154,    25,    54,    80,    55,    29,
      30,     3,     4,     5,     6,    -1,     8,    -1,    -1,    39,
      40,    -1,    -1,    43,    16,    45,    46,    47,    34,    35,
      36,    37,    38,    25,    -1,    41,    42,    29,    30,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    39,    40,    -1,
      -1,    43,    16,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    39,    40,    -1,    -1,    43,
      16,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    39,    40,    -1,    -1,    43,    16,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    39,    40,    -1,    -1,    43,    16,    45,    46,    47,
      -1,     3,     4,     5,     6,    25,     8,    -1,    -1,    29,
      -1,    -1,    -1,    33,    16,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,    25,    -1,    -1,    -1,    29,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    48,    50,    51,    52,    54,     0,    48,    52,
      31,    34,    35,    36,    37,    38,    41,    42,    53,    27,
      53,    11,    33,     4,     5,     6,     8,    16,    25,    29,
      39,    40,    54,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    25,    29,    63,    70,    70,    63,
      63,    74,    25,    28,    11,    24,    23,    17,    18,    19,
      20,    21,    22,     7,     8,     9,    10,    12,    13,    14,
      15,    27,    54,    55,    56,    57,    29,    30,    43,    45,
      46,    47,    52,    54,    58,    59,    60,    61,    63,    33,
      26,    30,    32,    73,    74,    53,    64,    65,    66,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    69,
      70,    63,    31,    26,    32,    30,    58,    33,    25,    25,
      73,    33,    63,    30,    59,    63,    33,    63,    26,    28,
      53,    57,    30,    63,    62,    33,    33,    26,    33,    59,
      60,    62,    44,    33,    60,    61,    62,    26,    43,    60,
      25,    63,    26,    60,    44
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 127 "parser.bison"
    { return 0; }
    break;

  case 3:
#line 129 "parser.bison"
    { parser_result = 0;  return 0;}
    break;

  case 4:
#line 133 "parser.bison"
    { 
		struct decl *end = (yyvsp[(1) - (2)].decl_ptr);
		while (end -> next) {
			end = end -> next;
		}
		end -> next = (yyvsp[(2) - (2)].decl_ptr);
		(yyval.decl_ptr) = (yyvsp[(1) - (2)].decl_ptr);
	}
    break;

  case 5:
#line 142 "parser.bison"
    {
		(yyval.decl_ptr) = (yyvsp[(1) - (1)].decl_ptr); 
		if (!parser_result) {
			parser_result = (yyvsp[(1) - (1)].decl_ptr);
		}
	}
    break;

  case 6:
#line 151 "parser.bison"
    {
		(yyval.decl_ptr) = decl_create(DECL_VAL_INIT, (yyvsp[(1) - (6)].char_ptr), (yyvsp[(3) - (6)].type_ptr), (yyvsp[(5) - (6)].expr_ptr), 0, 0);
	}
    break;

  case 7:
#line 155 "parser.bison"
    {
		if ((yyvsp[(3) - (7)].type_ptr)->kind == TYPE_FUNCTION) {
			printf("parse error: ';' not allowed after function declaration\n");
			exit(1);
		}
		(yyval.decl_ptr) = decl_create(DECL_VAL_INIT, (yyvsp[(1) - (7)].char_ptr), (yyvsp[(3) - (7)].type_ptr), 0, 0, 0);	// empty array declaration
	}
    break;

  case 8:
#line 163 "parser.bison"
    {
		(yyval.decl_ptr) = decl_create(DECL_NO_INIT, (yyvsp[(1) - (4)].char_ptr), (yyvsp[(3) - (4)].type_ptr), 0, 0, 0);
	}
    break;

  case 9:
#line 167 "parser.bison"
    {
		(yyval.decl_ptr) = decl_create(DECL_CODE_INIT, (yyvsp[(1) - (7)].char_ptr), (yyvsp[(3) - (7)].type_ptr), 0, (yyvsp[(6) - (7)].stmt_ptr), 0);
	}
    break;

  case 10:
#line 171 "parser.bison"
    {
		(yyval.decl_ptr) = decl_create(DECL_CODE_INIT, (yyvsp[(1) - (6)].char_ptr), (yyvsp[(3) - (6)].type_ptr), 0, 0, 0);	// empty statement list
	}
    break;

  case 11:
#line 177 "parser.bison"
    {
		(yyval.type_ptr) = type_create(TYPE_STRING, 0, 0);
	}
    break;

  case 12:
#line 181 "parser.bison"
    {
		(yyval.type_ptr) = type_create(TYPE_INTEGER, 0, 0);
	}
    break;

  case 13:
#line 185 "parser.bison"
    {
		(yyval.type_ptr) = type_create(TYPE_CHARACTER, 0, 0);
	}
    break;

  case 14:
#line 189 "parser.bison"
    {
		(yyval.type_ptr) = type_create(TYPE_BOOLEAN, 0, 0);
	}
    break;

  case 15:
#line 193 "parser.bison"
    {
		(yyval.type_ptr) = type_create(TYPE_VOID, 0, 0);
	}
    break;

  case 16:
#line 197 "parser.bison"
    {
		(yyval.type_ptr) = type_create(TYPE_ARRAY, 0, (yyvsp[(5) - (5)].type_ptr));
		(yyval.type_ptr) -> num_subtype = (yyvsp[(3) - (5)].expr_ptr);
	}
    break;

  case 17:
#line 202 "parser.bison"
    {
		(yyval.type_ptr) = type_create(TYPE_FUNCTION, (yyvsp[(4) - (5)].param_list_ptr), (yyvsp[(2) - (5)].type_ptr));
	}
    break;

  case 18:
#line 208 "parser.bison"
    {
		char *id = malloc(sizeof(char) * strlen(yytext));
		strcpy(id, yytext);
		(yyval.char_ptr) = id;
	}
    break;

  case 19:
#line 216 "parser.bison"
    {
		(yyval.param_list_ptr) = 0;
	}
    break;

  case 20:
#line 220 "parser.bison"
    {
		(yyval.param_list_ptr) = (yyvsp[(1) - (1)].param_list_ptr);
	}
    break;

  case 21:
#line 226 "parser.bison"
    {
		struct param_list *end = (yyvsp[(1) - (3)].param_list_ptr);
		while (end -> next) {
			end = end -> next;
		}
		end -> next = (yyvsp[(3) - (3)].param_list_ptr);
		(yyval.param_list_ptr) = (yyvsp[(1) - (3)].param_list_ptr);
	}
    break;

  case 22:
#line 235 "parser.bison"
    {
		(yyval.param_list_ptr) = (yyvsp[(1) - (1)].param_list_ptr);
	}
    break;

  case 23:
#line 241 "parser.bison"
    {
		(yyval.param_list_ptr) = param_list_create((yyvsp[(1) - (3)].char_ptr), (yyvsp[(3) - (3)].type_ptr), 0);
	}
    break;

  case 24:
#line 247 "parser.bison"
    {
		struct stmt* end = (yyvsp[(1) - (2)].stmt_ptr);
		while (end -> next) {
			end = end ->next;
		}
		end -> next = (yyvsp[(2) - (2)].stmt_ptr);
		(yyval.stmt_ptr) = (yyvsp[(1) - (2)].stmt_ptr);
	}
    break;

  case 25:
#line 256 "parser.bison"
    {
		(yyval.stmt_ptr) = (yyvsp[(1) - (1)].stmt_ptr);
	}
    break;

  case 26:
#line 262 "parser.bison"
    { (yyval.stmt_ptr) = (yyvsp[(1) - (1)].stmt_ptr); }
    break;

  case 27:
#line 264 "parser.bison"
    { (yyval.stmt_ptr) = (yyvsp[(1) - (1)].stmt_ptr); }
    break;

  case 28:
#line 268 "parser.bison"
    {
		// stmt can't be a function declaration
		if ((yyvsp[(1) - (1)].decl_ptr)->kind == DECL_CODE_INIT) {
			printf("parse error: cannot declare function insdie function!\n");
			exit(1);
		}
		(yyval.stmt_ptr) = stmt_create(STMT_DECL, (yyvsp[(1) - (1)].decl_ptr), 0, 0, 0, 0, 0);
	}
    break;

  case 29:
#line 277 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_EXPR, 0, (yyvsp[(1) - (2)].expr_ptr), 0, 0, 0, 0);
	}
    break;

  case 30:
#line 281 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_PRINT, 0, (yyvsp[(2) - (3)].expr_ptr), 0, 0, 0, 0);
	}
    break;

  case 31:
#line 285 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_RETURN, 0, (yyvsp[(2) - (3)].expr_ptr), 0, 0, 0, 0);
	}
    break;

  case 32:
#line 289 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0);
	}
    break;

  case 33:
#line 293 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_FOR, 0, (yyvsp[(3) - (9)].expr_ptr), (yyvsp[(5) - (9)].expr_ptr), (yyvsp[(7) - (9)].expr_ptr), (yyvsp[(9) - (9)].stmt_ptr), 0);
	}
    break;

  case 34:
#line 297 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[(2) - (3)].stmt_ptr), 0);
	}
    break;

  case 35:
#line 301 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, 0, 0);
	}
    break;

  case 36:
#line 305 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_IF_ELSE, 0, (yyvsp[(3) - (7)].expr_ptr), 0, 0, (yyvsp[(5) - (7)].stmt_ptr), (yyvsp[(7) - (7)].stmt_ptr));
	}
    break;

  case 37:
#line 311 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_IF_ELSE, 0, (yyvsp[(3) - (5)].expr_ptr), 0, 0, (yyvsp[(5) - (5)].stmt_ptr), 0);
	}
    break;

  case 38:
#line 315 "parser.bison"
    {
		(yyval.stmt_ptr) = stmt_create(STMT_IF_ELSE, 0, (yyvsp[(3) - (7)].expr_ptr), 0, 0, (yyvsp[(5) - (7)].stmt_ptr), (yyvsp[(7) - (7)].stmt_ptr));
	}
    break;

  case 39:
#line 321 "parser.bison"
    {
		(yyval.expr_ptr) = 0;
	}
    break;

  case 40:
#line 325 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 41:
#line 331 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_ASSIGN, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 42:
#line 335 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 43:
#line 341 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_OR, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 44:
#line 345 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 45:
#line 351 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_AND, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 46:
#line 355 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 47:
#line 361 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_EQ, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 48:
#line 365 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_NEQ, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 49:
#line 369 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_LT, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 50:
#line 373 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_GT, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 51:
#line 377 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_LE, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 52:
#line 381 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_GE, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 53:
#line 385 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 54:
#line 391 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_ADD, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 55:
#line 395 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_SUB, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 56:
#line 399 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 57:
#line 405 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_MUL, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 58:
#line 409 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_DIV, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 59:
#line 413 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_MODULO, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 60:
#line 417 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 61:
#line 423 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_EXPO, (yyvsp[(1) - (3)].expr_ptr), (yyvsp[(3) - (3)].expr_ptr) );
	}
    break;

  case 62:
#line 427 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 63:
#line 432 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_NOT, 0, (yyvsp[(2) - (2)].expr_ptr) );
	}
    break;

  case 64:
#line 436 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_SUB, 0, (yyvsp[(2) - (2)].expr_ptr) );
	}
    break;

  case 65:
#line 440 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 66:
#line 446 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_POST_INCREASE, (yyvsp[(1) - (2)].expr_ptr), 0 );
	}
    break;

  case 67:
#line 450 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create( EXPR_POST_DECREASE, (yyvsp[(1) - (2)].expr_ptr), 0 );
	}
    break;

  case 68:
#line 454 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 69:
#line 460 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(2) - (3)].expr_ptr);
	}
    break;

  case 70:
#line 464 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create_integer_literal( atoi(yytext) );
	}
    break;

  case 71:
#line 468 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create_boolean_literal(1);
	}
    break;

  case 72:
#line 472 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create_boolean_literal(0);
	}
    break;

  case 73:
#line 476 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create_name((yyvsp[(1) - (1)].char_ptr));
	}
    break;

  case 74:
#line 480 "parser.bison"
    {
        char newStr[yyleng];
        int curPos = 0;
        int i = 1;
        for (i = 1; i < yyleng-1; i++) {
            if (yytext[i] == '\\') {
                switch (yytext[i+1]) {
                    case 'n':
                        newStr[curPos] = '\n';
                        break;
                    case '0':
                        newStr[curPos] = '\0';
                        break;
                    default:
                        newStr[curPos] = yytext[i+1];
                        break;
                } 
                i++;
            } else {
                newStr[curPos] = yytext[i];
            }
            curPos++;
        }
        newStr[curPos] = '\0';
        if (strlen(newStr) > 255) {
            // string with more than 256 chars
            fprintf( stderr, "scann error: illegal string(cannot excceed 256 chars): %s\n", yytext );
            exit(1);
        }
		(yyval.expr_ptr) = expr_create_string_literal(yytext);
	}
    break;

  case 75:
#line 512 "parser.bison"
    {
		char c;
        if (yyleng > 3) {
            switch (yytext[2]) {
                    case 'n':
                        c = '\n';
                        break;
                    case '0':
                        c = '\0';
                        break;
                    default:
                        c = yytext[2];
                        break;
                } 
        } else{
            c = yytext[1];
        }
		(yyval.expr_ptr) = expr_create_character_literal(c);
	}
    break;

  case 76:
#line 532 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create_array_val((yyvsp[(2) - (3)].expr_ptr));
	}
    break;

  case 77:
#line 536 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create_function_call((yyvsp[(1) - (4)].char_ptr), (yyvsp[(3) - (4)].expr_ptr));
	}
    break;

  case 78:
#line 540 "parser.bison"
    {
		(yyval.expr_ptr) = expr_create(EXPR_ARRAY_SUB, (yyvsp[(1) - (4)].expr_ptr), (yyvsp[(3) - (4)].expr_ptr));
	}
    break;

  case 79:
#line 545 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;

  case 80:
#line 549 "parser.bison"
    {
		(yyval.expr_ptr)  = 0;
	}
    break;

  case 81:
#line 555 "parser.bison"
    {
		struct expr* end = (yyvsp[(1) - (3)].expr_ptr);
		while (end -> next) {
			end = end -> next;
		}
		end -> next = (yyvsp[(3) - (3)].expr_ptr);		
		(yyval.expr_ptr) = (yyvsp[(1) - (3)].expr_ptr);
	}
    break;

  case 82:
#line 564 "parser.bison"
    {
		(yyval.expr_ptr) = (yyvsp[(1) - (1)].expr_ptr);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2269 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 568 "parser.bison"


/*
This function will be called by bison if the parse should
encounter an error.  In principle, "str" will contain something
useful.  In practice, it often does not.
*/

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
}

