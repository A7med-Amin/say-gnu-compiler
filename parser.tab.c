
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "Parser.y"

    #define register

    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>
    #include <cmath>  // Include the cmath header for pow function
    #include <string>
    #include <cstring>  // For strdup
    #include "AssemblyGenerator.hpp"

    /* Header Files */
    #include "semantic_analyzer.hpp"

    /* Function prototypes */
    extern void yyerror(const char *s);
    int yylex(void);
    int yylineno;     /* from lexer represents line numbers */
    extern FILE *yyin;

    AssemblyGenerator assemblyGenerator;

    /* Macros */
    #ifndef TYPE_VALUE_MACROS_HPP
    #define TYPE_VALUE_MACROS_HPP
    #define GET_TYPE_VALUE(compareDataType, value1, value3, lhs, rhs)        \
        switch (compareDataType) {                                         \
        case INT_TYPE:                                                 \
            lhs = convertTypeValToEntry(INT_TYPE, value1.ival);        \
            rhs = convertTypeValToEntry(INT_TYPE, value3.ival);        \
            break;                                                     \
        case FLOAT_TYPE:                                               \
            lhs = convertTypeValToEntry(FLOAT_TYPE, value1.fval);      \
            rhs = convertTypeValToEntry(FLOAT_TYPE, value3.fval);      \
            break;                                                     \
        case STRING_TYPE:                                              \
            lhs = convertTypeValToEntry(STRING_TYPE, value1.sval);     \
            rhs = convertTypeValToEntry(STRING_TYPE, value3.sval);     \
            break;                                                     \
        case BOOL_TYPE:                                                \
            lhs = convertTypeValToEntry(BOOL_TYPE, value1.bval);       \
            rhs = convertTypeValToEntry(BOOL_TYPE, value3.bval);       \
            break;                                                     \
        case CHAR_TYPE:                                                \
            lhs = convertTypeValToEntry(CHAR_TYPE, value1.cval);       \
            rhs = convertTypeValToEntry(CHAR_TYPE, value3.cval);       \
            break;                                                     \
        }
    #endif // TYPE_VALUE_MACROS_HPP

    char* concatenateNames(const char* name1, const char* name2, const char* name3) {
    std::string nameRepStr = std::string(name1) + std::string(name2) + std::string(name3);
    return strdup(nameRepStr.c_str());  // Copy the result back to a char*
    }


/* Line 189 of yacc.c  */
#line 130 "Parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_DATA_TYPE = 258,
     FLOAT_DATA_TYPE = 259,
     CHAR_DATA_TYPE = 260,
     STRING_DATA_TYPE = 261,
     BOOLEAN_DATA_TYPE = 262,
     CONSTANT = 263,
     VOID_TYPE = 264,
     IF = 265,
     ELSE = 266,
     SWITCH = 267,
     CASE = 268,
     DEFAULT = 269,
     WHILE = 270,
     FOR = 271,
     REPEAT = 272,
     UNTIL = 273,
     BREAK = 274,
     RETURN = 275,
     IDENTIFIER = 276,
     BOOLEAN_TRUE = 277,
     BOOLEAN_FALSE = 278,
     INTEGER_VALUE = 279,
     FLOATING = 280,
     CHARACTER = 281,
     STRING_LITERAL = 282,
     ADD = 283,
     SUB = 284,
     MUL = 285,
     DIV = 286,
     MOD = 287,
     INC = 288,
     DEC = 289,
     POW = 290,
     ASSIGN = 291,
     AND = 292,
     OR = 293,
     NOT = 294,
     EQ = 295,
     NEQ = 296,
     GT = 297,
     LT = 298,
     GTE = 299,
     LTE = 300,
     PRINT = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 59 "Parser.y"

    int lexType;
    char * stringVal;
    struct ActualValue{
        int type;
        char* nameRep;
        union{
            int ival;
            float fval;
            char cval;
            char* sval;
            bool bval;
        };
    }actualValue;



/* Line 214 of yacc.c  */
#line 230 "Parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 242 "Parser.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   581

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  249

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    15,    18,
      19,    26,    27,    36,    37,    38,    48,    50,    51,    58,
      60,    66,    68,    71,    73,    75,    77,    79,    81,    83,
      85,    87,    89,    91,    93,    95,    97,    99,   101,   103,
     105,   107,   109,   111,   115,   119,   123,   127,   131,   135,
     138,   142,   146,   149,   152,   155,   158,   160,   164,   168,
     170,   174,   178,   182,   184,   188,   190,   192,   194,   196,
     198,   202,   205,   209,   213,   215,   221,   228,   233,   234,
     235,   245,   246,   255,   256,   259,   260,   261,   262,   268,
     270,   271,   280,   282,   284,   285,   292,   296,   297,   300,
     302,   304,   307,   310,   312,   313,   314,   320,   321,   322,
     328,   329,   339,   340,   349,   350,   360,   361,   370,   374,
     376,   379,   384,   387,   391,   392,   393,   399,   403,   404,
     410,   414,   418,   420,   424
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    56,    -1,    57,    -1,    56,    57,
      -1,    74,    -1,    76,    -1,    73,    47,    -1,    -1,    15,
      48,    66,    58,    49,    93,    -1,    -1,    17,    93,    18,
      48,    66,    59,    49,    47,    -1,    -1,    -1,    16,    48,
      60,    91,    66,    61,    92,    49,    96,    -1,    77,    -1,
      -1,    12,    48,    21,    62,    49,    83,    -1,    93,    -1,
      46,    48,   112,    49,    47,    -1,    99,    -1,   109,    47,
      -1,   106,    -1,     1,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,     7,    -1,    66,    -1,    27,    -1,    26,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,    22,
      -1,    23,    -1,    68,    -1,    67,    -1,    22,    -1,    23,
      -1,    66,    40,    68,    -1,    66,    41,    68,    -1,    66,
      42,    68,    -1,    66,    43,    68,    -1,    66,    44,    68,
      -1,    66,    45,    68,    -1,    39,    66,    -1,    66,    37,
      66,    -1,    66,    38,    66,    -1,    21,    33,    -1,    21,
      34,    -1,    33,    21,    -1,    34,    21,    -1,    69,    -1,
      69,    28,    70,    -1,    69,    29,    70,    -1,    70,    -1,
      70,    30,    71,    -1,    70,    31,    71,    -1,    70,    32,
      71,    -1,    71,    -1,    71,    35,    72,    -1,    72,    -1,
      24,    -1,    25,    -1,   107,    -1,    21,    -1,    48,    66,
      49,    -1,    29,    66,    -1,    21,    36,    64,    -1,    63,
      21,    47,    -1,    75,    -1,    63,    21,    36,    64,    47,
      -1,     8,    63,    21,    36,    65,    47,    -1,     8,    63,
      21,    47,    -1,    -1,    -1,    10,    48,    66,    78,    49,
      93,    79,    80,    82,    -1,    -1,    80,    11,    10,    48,
      66,    81,    49,    93,    -1,    -1,    11,    93,    -1,    -1,
      -1,    -1,    50,    84,    86,    85,    51,    -1,    89,    -1,
      -1,    13,    88,    52,    56,    87,    19,    47,    86,    -1,
      24,    -1,    26,    -1,    -1,    14,    52,    56,    90,    19,
      47,    -1,    14,    52,    56,    -1,    -1,    73,    47,    -1,
      75,    -1,    47,    -1,    47,    73,    -1,    47,    66,    -1,
      47,    -1,    -1,    -1,    50,    94,    56,    95,    51,    -1,
      -1,    -1,    50,    97,    56,    98,    51,    -1,    -1,    63,
      21,    48,   100,   104,    49,    50,    56,    51,    -1,    -1,
      63,    21,    48,   101,    49,    50,    56,    51,    -1,    -1,
       9,    21,    48,   102,   104,    49,    50,    56,    51,    -1,
      -1,     9,    21,    48,   103,    49,    50,    56,    51,    -1,
     105,    53,   104,    -1,   105,    -1,    63,    21,    -1,    63,
      21,    36,    65,    -1,    20,    47,    -1,    20,    64,    47,
      -1,    -1,    -1,    21,    48,   108,   111,    49,    -1,    21,
      48,    49,    -1,    -1,    21,    48,   110,   111,    49,    -1,
      21,    48,    49,    -1,   111,    53,    64,    -1,    64,    -1,
      64,    53,   112,    -1,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   152,   190,   191,   194,   195,   196,   198,
     197,   210,   207,   219,   220,   219,   230,   232,   231,   249,
     250,   251,   252,   253,   254,   258,   258,   258,   258,   258,
     260,   261,   270,   281,   288,   295,   302,   309,   316,   326,
     326,   328,   335,   341,   371,   410,   443,   476,   509,   542,
     568,   594,   620,   651,   681,   711,   741,   744,   796,   847,
     850,   906,   957,   986,   989,  1039,  1042,  1050,  1057,  1058,
    1116,  1117,  1136,  1180,  1196,  1199,  1251,  1291,  1300,  1307,
    1299,  1313,  1312,  1322,  1325,  1327,  1331,  1334,  1331,  1338,
    1339,  1339,  1342,  1349,  1359,  1359,  1361,  1363,  1367,  1368,
    1369,  1372,  1373,  1374,  1378,  1382,  1377,  1387,  1389,  1387,
    1395,  1394,  1426,  1425,  1459,  1458,  1481,  1480,  1503,  1503,
    1505,  1522,  1566,  1578,  1592,  1606,  1605,  1655,  1697,  1696,
    1721,  1737,  1751,  1768,  1772
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_DATA_TYPE", "FLOAT_DATA_TYPE",
  "CHAR_DATA_TYPE", "STRING_DATA_TYPE", "BOOLEAN_DATA_TYPE", "CONSTANT",
  "VOID_TYPE", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE", "FOR",
  "REPEAT", "UNTIL", "BREAK", "RETURN", "IDENTIFIER", "BOOLEAN_TRUE",
  "BOOLEAN_FALSE", "INTEGER_VALUE", "FLOATING", "CHARACTER",
  "STRING_LITERAL", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC", "POW",
  "ASSIGN", "AND", "OR", "NOT", "EQ", "NEQ", "GT", "LT", "GTE", "LTE",
  "PRINT", "';'", "'('", "')'", "'{'", "'}'", "':'", "','", "$accept",
  "program", "codeBlock", "codeStatement", "$@1", "$@2", "$@3", "$@4",
  "$@5", "dataType", "dataValue", "constantValue", "expression", "boolean",
  "arithmetic", "complexArithmetic", "minorTerm", "majorTerm", "instance",
  "assignment", "variableDeclaration", "variableDeclarationWithAssignment",
  "constantDeclaration", "ifCondition", "$@6", "$@7", "elseIfCondition",
  "$@8", "elseStmnt", "switchBlock", "$@9", "$@10", "caseExpression",
  "$@11", "switchValidValue", "caseDefault", "$@12",
  "forLoopInitialization", "forLoopItter", "scopeBlock", "$@13", "$@14",
  "loopsScopeBlock", "$@15", "$@16", "function", "$@17", "$@18", "$@19",
  "$@20", "ArgList", "Arg", "ReturnCase", "TypedFunctionCall", "$@21",
  "VoidFunctionCall", "$@22", "CallList", "printStatement", 0
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
     295,   296,   297,   298,   299,   300,   301,    59,    40,    41,
     123,   125,    58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    57,    57,    57,    58,
      57,    59,    57,    60,    61,    57,    57,    62,    57,    57,
      57,    57,    57,    57,    57,    63,    63,    63,    63,    63,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    73,    74,    74,    75,    76,    76,    78,    79,
      77,    81,    80,    80,    82,    82,    84,    85,    83,    86,
      87,    86,    88,    88,    90,    89,    89,    89,    91,    91,
      91,    92,    92,    92,    94,    95,    93,    97,    98,    96,
     100,    99,   101,    99,   102,    99,   103,    99,   104,   104,
     105,   105,   106,   106,   106,   108,   107,   107,   110,   109,
     109,   111,   111,   112,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     2,     0,
       6,     0,     8,     0,     0,     9,     1,     0,     6,     1,
       5,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     2,     2,     2,     2,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     1,     5,     6,     4,     0,     0,
       9,     0,     8,     0,     2,     0,     0,     0,     5,     1,
       0,     8,     1,     1,     0,     6,     3,     0,     2,     1,
       1,     2,     2,     1,     0,     0,     5,     0,     0,     5,
       0,     9,     0,     8,     0,     9,     0,     8,     3,     1,
       2,     4,     2,     3,     0,     0,     5,     3,     0,     5,
       3,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,     0,     0,
       4,     0,     0,     6,    74,     7,    16,    19,    21,    23,
       0,     0,     0,     0,     0,     0,    13,     0,    69,    41,
      42,    66,    67,    32,    31,     0,     0,     0,     0,   122,
       0,     0,    30,    40,    39,    56,    59,    63,    65,    68,
       0,   128,     0,     0,     1,     5,     0,     8,    22,     0,
     114,    78,    17,     9,     0,     0,    52,    53,   125,    71,
      54,    55,    49,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
     130,     0,   134,     0,     0,     0,    73,   110,     0,    77,
       0,     0,     0,     0,     0,     0,   100,     0,     0,    99,
       0,     0,   127,     0,    70,    50,    51,    43,    44,    45,
      46,    47,    48,    69,    57,    58,    60,    61,    62,    64,
     132,     0,     0,     0,     0,     0,     0,     0,    37,    38,
      33,    34,    35,    36,     0,     0,     0,   119,     0,     0,
       0,     0,     0,    98,    14,    11,     0,   129,     0,   133,
      20,   106,    75,     0,     0,    76,   120,     0,     0,     0,
      79,    86,    18,    10,     0,     0,   126,   131,     0,     0,
       0,     0,   118,     0,    83,    97,   103,     0,     0,     0,
       0,   121,     0,   117,    85,     0,     0,    87,    89,    69,
     102,   101,     0,    12,     0,   113,   115,     0,    80,    92,
      93,     0,     0,     0,   107,    15,   111,     0,    84,     0,
       0,    88,     0,     0,     0,     0,     0,    81,     0,     0,
       0,     0,     0,    95,   109,     0,    97,    82,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,   114,   185,    74,   184,   113,    21,
     102,   154,    52,    53,    54,    55,    56,    57,    58,    22,
      23,    24,    25,    26,   112,   194,   204,   241,   218,   182,
     195,   223,   207,   238,   221,   208,   235,   120,   197,    27,
      63,   144,   225,   232,   240,    28,   146,   147,   110,   111,
     156,   157,    29,    59,   123,    30,   101,   141,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -135
static const yytype_int16 yypact[] =
{
     240,  -135,  -135,  -135,  -135,  -135,  -135,   115,   -11,     5,
       8,    14,    18,    25,    78,   -20,    37,  -135,    84,   272,
    -135,    57,    48,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
      51,    66,    49,   166,    87,   166,  -135,    91,    -3,  -135,
    -135,  -135,  -135,  -135,  -135,   166,    89,    92,   166,  -135,
     166,    68,   524,  -135,  -135,    30,    50,    81,  -135,  -135,
     129,    75,   129,   293,  -135,  -135,    -1,  -135,  -135,    13,
      83,   524,  -135,   524,    36,    79,  -135,  -135,    85,   524,
    -135,  -135,  -135,   514,  -135,   166,   166,    40,    40,    40,
      40,    40,    40,   116,   116,   116,   116,   116,   116,  -135,
    -135,   129,    86,    95,   320,   129,  -135,    98,   184,  -135,
     115,   100,   108,   111,   112,   102,  -135,   146,   122,  -135,
     166,   166,  -135,   129,  -135,   530,   530,  -135,  -135,  -135,
    -135,  -135,  -135,    88,    50,    50,    81,    81,    81,  -135,
    -135,   -40,   129,   123,   120,   125,   115,   130,  -135,  -135,
    -135,  -135,  -135,  -135,   131,   159,   132,   133,   135,    25,
     142,    25,   147,  -135,   524,   524,   -38,  -135,   129,  -135,
    -135,  -135,  -135,   144,   148,  -135,   158,   151,   115,   293,
    -135,  -135,  -135,  -135,   150,   154,  -135,  -135,   163,   293,
     184,   293,  -135,   344,  -135,    58,   505,   168,   173,   293,
     371,  -135,   395,  -135,   204,    26,   177,  -135,  -135,    43,
     524,  -135,   181,  -135,   422,  -135,  -135,    -2,  -135,  -135,
    -135,   190,    17,   185,  -135,  -135,  -135,   203,  -135,   474,
     218,  -135,   293,   166,   497,   234,   446,   524,   235,   211,
     208,   213,   216,  -135,  -135,    25,    58,  -135,  -135
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   -56,   -18,  -135,  -135,  -135,  -135,  -135,    -4,
      -9,    76,   -31,  -135,   489,  -135,     0,    34,   167,   -68,
    -135,   193,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,    24,  -135,  -135,  -135,  -135,  -135,  -135,   -13,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -134,  -135,  -135,  -135,  -135,  -135,  -135,   160,   143
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -125
static const yytype_int16 yytable[] =
{
      37,    65,    71,    31,    73,    51,   118,   104,   227,   167,
      32,   186,   173,   168,    79,   168,    60,    82,     1,    83,
       2,     3,     4,     5,     6,     7,     8,     9,    61,    10,
      76,    77,    11,    12,    13,   105,  -124,    14,    15,     2,
       3,     4,     5,     6,   192,    78,   106,   107,    17,   108,
     219,    99,   220,    33,   125,   126,    34,   115,    93,    94,
     109,    38,    35,    16,    41,    42,    36,    17,  -124,    45,
     117,   205,   206,    46,    47,    17,    76,    77,    66,    60,
      95,    96,    97,   116,    64,    62,    65,    69,    50,   164,
     165,    78,   140,   134,   135,    67,   145,    70,    68,    38,
      39,    40,    41,    42,    43,    44,   155,    45,    72,    75,
      80,    46,    47,    81,   140,    84,    98,    48,     2,     3,
       4,     5,     6,   193,   100,    49,    50,   121,   211,   136,
     137,   138,  -116,   200,   122,   202,    78,   133,    60,   142,
      41,    42,   155,   214,   143,    45,   180,  -112,   183,   158,
      38,    39,    40,    41,    42,    43,    44,   159,    45,   187,
     160,   161,    46,    47,    50,   210,   230,   162,    48,   163,
     170,   171,   172,   234,   155,    65,   236,    50,   175,   174,
     176,   177,    65,   105,    65,   179,   178,    38,    39,    40,
      41,    42,   181,   188,   190,    45,    65,   196,   189,    46,
      47,   191,   237,   198,   228,    48,   148,   149,   150,   151,
     152,   153,    65,   199,    50,   217,    65,   212,    65,     1,
     213,     2,     3,     4,     5,     6,     7,     8,     9,   222,
      10,   224,   247,    11,    12,    13,   231,   -94,    14,    15,
      -2,     1,   229,     2,     3,     4,     5,     6,     7,     8,
       9,   233,    10,   239,   242,    11,    12,    13,   243,   244,
      14,    15,   245,   246,    16,   139,   201,   119,    17,   -96,
     248,     0,    -3,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,   166,    10,   169,    16,    11,    12,    13,
      17,     0,    14,    15,     1,     0,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,     0,     0,    11,    12,
      13,     0,     0,    14,    15,     0,     0,     0,    16,     0,
       0,     1,    17,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,     0,     0,    11,    12,    13,     0,    16,
      14,    15,     0,    17,  -124,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,     0,     0,    11,
      12,    13,     0,     0,    14,    15,    16,     0,     0,     0,
      17,  -105,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,     0,     0,    11,    12,    13,     0,
      16,    14,    15,     0,    17,   203,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,     0,     0,
      11,    12,    13,     0,     0,    14,    15,    16,     0,     0,
       0,    17,   215,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,     0,     0,    11,    12,    13,
       0,    16,    14,    15,     0,    17,   216,     1,     0,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,     0,
       0,    11,    12,    13,     0,     0,    14,    15,    16,     0,
       0,     0,    17,   226,     0,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,     0,     0,    11,
      12,    13,    16,  -124,    14,    15,    17,  -108,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
       0,     0,    11,    12,    13,     0,   -90,    14,    15,     0,
      16,     0,     0,     0,    17,     0,   209,    39,    40,    41,
      42,     0,     0,     0,    45,     0,     0,     0,    46,    47,
       0,     0,     0,    16,    48,     0,     0,    17,     0,     0,
       0,    85,    86,    50,    87,    88,    89,    90,    91,    92,
       0,    85,    86,   124,    87,    88,    89,    90,    91,    92,
      87,    88,    89,    90,    91,    92,   127,   128,   129,   130,
     131,   132
};

static const yytype_int16 yycheck[] =
{
      13,    19,    33,     7,    35,    14,    74,    63,    10,    49,
      21,    49,   146,    53,    45,    53,    36,    48,     1,    50,
       3,     4,     5,     6,     7,     8,     9,    10,    48,    12,
      33,    34,    15,    16,    17,    36,    19,    20,    21,     3,
       4,     5,     6,     7,   178,    48,    47,    48,    50,    36,
      24,    60,    26,    48,    85,    86,    48,    21,    28,    29,
      47,    21,    48,    46,    24,    25,    48,    50,    51,    29,
      74,    13,    14,    33,    34,    50,    33,    34,    21,    36,
      30,    31,    32,    47,     0,    48,   104,    21,    48,   120,
     121,    48,   101,    93,    94,    47,   105,    48,    47,    21,
      22,    23,    24,    25,    26,    27,   110,    29,    21,    18,
      21,    33,    34,    21,   123,    47,    35,    39,     3,     4,
       5,     6,     7,   179,    49,    47,    48,    48,   196,    95,
      96,    97,    49,   189,    49,   191,    48,    21,    36,    53,
      24,    25,   146,   199,    49,    29,   159,    49,   161,    49,
      21,    22,    23,    24,    25,    26,    27,    49,    29,   168,
      49,    49,    33,    34,    48,   196,   222,    21,    39,    47,
      47,    51,    47,   229,   178,   193,   232,    48,    47,    49,
      21,    49,   200,    36,   202,    50,    53,    21,    22,    23,
      24,    25,    50,    49,    36,    29,   214,    47,    50,    33,
      34,    50,   233,    49,   217,    39,    22,    23,    24,    25,
      26,    27,   230,    50,    48,    11,   234,    49,   236,     1,
      47,     3,     4,     5,     6,     7,     8,     9,    10,    52,
      12,    50,   245,    15,    16,    17,    51,    19,    20,    21,
       0,     1,    52,     3,     4,     5,     6,     7,     8,     9,
      10,    48,    12,    19,    19,    15,    16,    17,    47,    51,
      20,    21,    49,    47,    46,    98,   190,    74,    50,    51,
     246,    -1,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,   123,    12,   142,    46,    15,    16,    17,
      50,    -1,    20,    21,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    -1,    -1,    15,    16,
      17,    -1,    -1,    20,    21,    -1,    -1,    -1,    46,    -1,
      -1,     1,    50,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    -1,    -1,    15,    16,    17,    -1,    46,
      20,    21,    -1,    50,    51,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    -1,    -1,    15,
      16,    17,    -1,    -1,    20,    21,    46,    -1,    -1,    -1,
      50,    51,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    -1,    -1,    15,    16,    17,    -1,
      46,    20,    21,    -1,    50,    51,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    -1,    -1,
      15,    16,    17,    -1,    -1,    20,    21,    46,    -1,    -1,
      -1,    50,    51,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    -1,    -1,    15,    16,    17,
      -1,    46,    20,    21,    -1,    50,    51,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    15,    16,    17,    -1,    -1,    20,    21,    46,    -1,
      -1,    -1,    50,    51,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    -1,    -1,    15,
      16,    17,    46,    19,    20,    21,    50,    51,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    21,    -1,
      46,    -1,    -1,    -1,    50,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    46,    39,    -1,    -1,    50,    -1,    -1,
      -1,    37,    38,    48,    40,    41,    42,    43,    44,    45,
      -1,    37,    38,    49,    40,    41,    42,    43,    44,    45,
      40,    41,    42,    43,    44,    45,    87,    88,    89,    90,
      91,    92
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      12,    15,    16,    17,    20,    21,    46,    50,    55,    56,
      57,    63,    73,    74,    75,    76,    77,    93,    99,   106,
     109,    63,    21,    48,    48,    48,    48,    93,    21,    22,
      23,    24,    25,    26,    27,    29,    33,    34,    39,    47,
      48,    64,    66,    67,    68,    69,    70,    71,    72,   107,
      36,    48,    48,    94,     0,    57,    21,    47,    47,    21,
      48,    66,    21,    66,    60,    18,    33,    34,    48,    66,
      21,    21,    66,    66,    47,    37,    38,    40,    41,    42,
      43,    44,    45,    28,    29,    30,    31,    32,    35,    64,
      49,   110,    64,   112,    56,    36,    47,    48,    36,    47,
     102,   103,    78,    62,    58,    21,    47,    63,    73,    75,
      91,    48,    49,   108,    49,    66,    66,    68,    68,    68,
      68,    68,    68,    21,    70,    70,    71,    71,    71,    72,
      64,   111,    53,    49,    95,    64,   100,   101,    22,    23,
      24,    25,    26,    27,    65,    63,   104,   105,    49,    49,
      49,    49,    21,    47,    66,    66,   111,    49,    53,   112,
      47,    51,    47,   104,    49,    47,    21,    49,    53,    50,
      93,    50,    83,    93,    61,    59,    49,    64,    49,    50,
      36,    50,   104,    56,    79,    84,    47,    92,    49,    50,
      56,    65,    56,    51,    80,    13,    14,    86,    89,    21,
      66,    73,    49,    47,    56,    51,    51,    11,    82,    24,
      26,    88,    52,    85,    50,    96,    51,    10,    93,    52,
      56,    51,    97,    48,    56,    90,    56,    66,    87,    19,
      98,    81,    19,    47,    51,    49,    47,    93,    86
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 151 "Parser.y"
    {printf("======== EMPTY PROGRAM ***********\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 152 "Parser.y"
    {    
                                                                                                // printf("                 #_   _#\n");
                                                                                                // printf("                 |a` `a|\n");
                                                                                                // printf("                 |  u  |\n");
                                                                                                // printf("                 \\  =  /\n");
                                                                                                // printf("                 |\\___/|\n");
                                                                                                // printf("        ___ ____/:     :\\____ ___\n");
                                                                                                // printf("      .'   `.-===-\\   /-===-.`   '.\n");
                                                                                                // printf("     /      .-\"\"\"\"\"-.-\"\"\"\"\"-.      \\\n");
                                                                                                // printf("    /'             =:=             '\\\n");
                                                                                                // printf("  .'  ' .:    o   -=:=-   o    :. '  `.\n");
                                                                                                // printf("  (.'   /'. '-.....-'-.....-' .\\'   '.)\n");
                                                                                                // printf("  /' ._/   \".     --:--     .\"   \\_. '\\\n");
                                                                                                // printf(" |  .'|      \".  ---:---  .\"      |'.  |\n");
                                                                                                // printf(" |  : |       |  ---:---  |       | :  |\n");
                                                                                                // printf("  \\ : |       |_____._____|       | : /\n");
                                                                                                // printf("  /   (       |----|------|       )   \\\n");
                                                                                                // printf(" /... .|      |    |      |      |. ...\\\n");
                                                                                                // printf("|::::/'' jgs /     |       \\     ''\\::::|\n");
                                                                                                // printf("'\"\"\"\"       /'    .L_      `\\       \"\"\"\"'\n");
                                                                                                // printf("           /'-.,__/` `\\__..-'\\\n");
                                                                                                // printf("          ;      /     \\      ;\n");
                                                                                                // printf("          :     /       \\     |\n");
                                                                                                // printf("          |    /         \\.   |\n");
                                                                                                // printf("          |`../           |  ,/\n");
                                                                                                // printf("          ( _ )           |  _)\n");
                                                                                                // printf("          |   |           |   |\n");
                                                                                                // printf("          |___|           \\___|\n");
                                                                                                // printf("          :===|            |==|\n");
                                                                                                // printf("           \\  /            |__|\n");
                                                                                                // printf("           /\\/\\           /\"\"\"`8.__\n");
                                                                                                // printf("           |oo|           \\__.//___)\n");
                                                                                                // printf("           |==|\n");
                                                                                                // printf("           \\__/\n");
                                                                                                // printf("                       SALAMO ALEEKO! ")
                                                                                            ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 198 "Parser.y"
    {
            if ((yyvsp[(3) - (3)].actualValue).type != BOOL_TYPE)
            {
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 205 "Parser.y"
    { assemblyGenerator.endScope(whileScope);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 210 "Parser.y"
    {
            assemblyGenerator.endScope(repeatScope);
            if ((yyvsp[(5) - (5)].actualValue).type != BOOL_TYPE)
            {
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 219 "Parser.y"
    {createNewSymbolTable();;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 220 "Parser.y"
    {
            if ((yyvsp[(5) - (5)].actualValue).type != BOOL_TYPE)
            {
                writeSemanticError("Condition of FOR must be boolean", yylineno);
                return 0;
            }
            
        ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 228 "Parser.y"
    { printf("for loop itter\n");
            assemblyGenerator.endScope(forScope);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 232 "Parser.y"
    {
            SymbolTableEntry* newEntry = getIdentifierEntry((yyvsp[(3) - (3)].stringVal));
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE && newEntry->getTypeValue()->type != CHAR_TYPE){
                writeSemanticError("Switch identifier must be char type or integer", yylineno);
                return 0;
            }
        ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 248 "Parser.y"
    { assemblyGenerator.endScope(switchScope); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 254 "Parser.y"
    { yyerror("Unexpected statement"); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 262 "Parser.y"
    {
    { 
        string valueStr = (yyvsp[(1) - (1)].actualValue).sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
        } 
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 270 "Parser.y"
    {
    { 
        char charValue = static_cast<char>((yyvsp[(1) - (1)].actualValue).cval);  
        string valueStr(1, charValue);  
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
        } 
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 282 "Parser.y"
    {
    string valueStr = to_string((yyvsp[(1) - (1)].actualValue).ival);
    const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
    assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
    // $$.nameRep = strdup(valueStr.c_str());
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 289 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 296 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).cval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 303 "Parser.y"
    { 
        string valueStr = (yyvsp[(1) - (1)].actualValue).sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 310 "Parser.y"
    { 
        string valueStr = "true";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 317 "Parser.y"
    { 
        string valueStr = "false";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 329 "Parser.y"
    {
            cout << "BOOLEAN_TRUE\n";
            const char* name = assemblyGenerator.addTempVariable("true" , "" , "");
            assemblyGenerator.addQuadruple("ASSIGN", "TRUE", "", name);
            (yyval.actualValue).nameRep = strdup("true");
        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 336 "Parser.y"
    {
        const char* name = assemblyGenerator.addTempVariable("false" , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", "FALSE", "", name);
        (yyval.actualValue).nameRep = strdup("false");
        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 342 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;
            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }
            (yyval.actualValue).type = BOOL_TYPE;
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);
            (yyval.actualValue).bval = checkEqualityEqual(lhs, rhs);
            string valueStr = (yyval.actualValue).bval ? "true" : "false";

           // Print debugging information
            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            // Allocate memory for the final value string and assign it to nameRep
            (yyval.actualValue).nameRep = strdup(valueStr.c_str());

            // Add the quadruple for the EQ operation
            assemblyGenerator.addQuadruple("EQU", name1, name2, name);
        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 372 "Parser.y"
    {
          int lhsType = (yyvsp[(1) - (3)].actualValue).type;
    int rhsType = (yyvsp[(3) - (3)].actualValue).type;

    // Check for type mismatch
    if (typeMismatch(lhsType, rhsType))
    {
        writeSemanticError("Type mismatch", yylineno);
        return 0;
    }

    // Set the result type to BOOL_TYPE
    (yyval.actualValue).type = BOOL_TYPE;

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

    // Check for inequality
    (yyval.actualValue).bval = checkEqualityNot(lhs, rhs);

    // Convert the boolean result to a string
    string valueStr = (yyval.actualValue).bval ? "true" : "false";

    // Print debugging information
    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    // Allocate memory for the final value string and assign it to nameRep
    (yyval.actualValue).nameRep = strdup(valueStr.c_str());

    // Add the quadruple for the NEQ operation
    assemblyGenerator.addQuadruple("NEQ", name1, name2, name);
        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 411 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }

            (yyval.actualValue).type = BOOL_TYPE;

            TypeValue *lhs;
            TypeValue *rhs;

            EntryType compareDataType = static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

            (yyval.actualValue).bval = checkEqualityGT(lhs, rhs);

            string valueStr = (yyval.actualValue).bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            (yyval.actualValue).nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("GT", name1, name2, name);
        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 444 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }

            (yyval.actualValue).type = BOOL_TYPE;

            TypeValue * lhs;
            TypeValue * rhs;

            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

            (yyval.actualValue).bval = checkEqualityLT(lhs, rhs);

            string valueStr = (yyval.actualValue).bval ? "true" : "false";

           printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            (yyval.actualValue).nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("LT", name1, name2, name);
        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 477 "Parser.y"
    {
             int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }

            (yyval.actualValue).type = BOOL_TYPE;

            TypeValue *lhs;
            TypeValue *rhs;

            EntryType compareDataType = static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

            (yyval.actualValue).bval = checkEqualityGTE(lhs, rhs);

            string valueStr = (yyval.actualValue).bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            (yyval.actualValue).nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("GTE", name1, name2, name);
        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 510 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }

            (yyval.actualValue).type = BOOL_TYPE;

            TypeValue * lhs;
            TypeValue * rhs;

            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

            (yyval.actualValue).bval = checkEqualityLTE(lhs, rhs);

            string valueStr = (yyval.actualValue).bval ? "true" : "false";

           printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            (yyval.actualValue).nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("LTE", name1, name2, name);
        ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 543 "Parser.y"
    {
           int varType = (yyvsp[(2) - (2)].actualValue).type;

    if (varType != BOOL_TYPE)
    {
        writeSemanticError("Type mismatch with NOT operation", yylineno);
        return 0;
    }

    (yyval.actualValue).type = BOOL_TYPE;
    (yyval.actualValue).bval = !(yyvsp[(2) - (2)].actualValue).bval;

   string valueStr = (yyval.actualValue).bval ? "true" : "false";

            printf("varStr1NameRep: %s \n", (yyvsp[(2) - (2)].actualValue).nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(2) - (2)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name: %s\n", name1, name);

            (yyval.actualValue).nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("NOT", name1, "", name);

            
        ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 569 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

            if (lhsType != BOOL_TYPE || rhsType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with AND operation, types must be boolean", yylineno);
                return 0;
            }

            (yyval.actualValue).type = BOOL_TYPE;
            (yyval.actualValue).bval = (yyvsp[(1) - (3)].actualValue).bval && (yyvsp[(3) - (3)].actualValue).bval;

            string valueStr = (yyval.actualValue).bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            (yyval.actualValue).nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("AND", name1, name2, name);
        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 595 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;
            if (lhsType != BOOL_TYPE || rhsType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with OR operation, types must be boolean", yylineno);
                return 0;
            }
            (yyval.actualValue).type = BOOL_TYPE;
            (yyval.actualValue).bval = (yyvsp[(1) - (3)].actualValue).bval || (yyvsp[(3) - (3)].actualValue).bval;

            string valueStr = (yyval.actualValue).bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            (yyval.actualValue).nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("OR", name1, name2, name);
        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 621 "Parser.y"
    {
            printf("INC\n");
            SymbolTableEntry* newEntry = getIdentifierEntry((yyvsp[(1) - (2)].stringVal));
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot increment constant variable", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE){
                writeSemanticError("Type mismatch with INC operation, types must be integer", yylineno);
                return 0;
            }
            (yyval.actualValue).type = INT_TYPE;
            (yyval.actualValue).ival = newEntry->getTypeValue()->value.ival + 1;
            newEntry->getTypeValue()->value.ival = (yyval.actualValue).ival;\

            string varStr1NameRep = (yyval.actualValue).nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1, "++" , "");
            (yyval.actualValue).nameRep = concatenateNames(name1, "++" , "");
            assemblyGenerator.addQuadruple("INC", name1, "", name);
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 652 "Parser.y"
    {
            SymbolTableEntry* newEntry = getIdentifierEntry((yyvsp[(1) - (2)].stringVal));
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot decrement constant variable", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE){
                writeSemanticError("Type mismatch with DEC operation, types must be integer", yylineno);
                return 0;
            }
            (yyval.actualValue).type = INT_TYPE;
            (yyval.actualValue).ival = newEntry->getTypeValue()->value.ival - 1;
            newEntry->getTypeValue()->value.ival = (yyval.actualValue).ival;

            string varStr1NameRep = (yyval.actualValue).nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1, "--" , "");
            (yyval.actualValue).nameRep = concatenateNames(name1, "--" , "");
            assemblyGenerator.addQuadruple("DEC", name1, "", name);
        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 682 "Parser.y"
    {
            SymbolTableEntry* newEntry = getIdentifierEntry((yyvsp[(2) - (2)].stringVal));
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot increment constant variable", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE){
                writeSemanticError("Type mismatch with INC operation, types must be integer", yylineno);
                return 0;
            }
            (yyval.actualValue).type = INT_TYPE;
            (yyval.actualValue).ival = newEntry->getTypeValue()->value.ival + 1;
            newEntry->getTypeValue()->value.ival = (yyval.actualValue).ival;

            string varStr1NameRep = (yyval.actualValue).nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable("++", name1 , "");
            (yyval.actualValue).nameRep = concatenateNames("++", name1 , "");
            assemblyGenerator.addQuadruple("INC", name1, "", name);
        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 712 "Parser.y"
    {
            SymbolTableEntry* newEntry = getIdentifierEntry((yyvsp[(2) - (2)].stringVal));
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot decrement constant variable", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE){
                writeSemanticError("Type mismatch with DEC operation, types must be integer", yylineno);
                return 0;
            }
            (yyval.actualValue).type = INT_TYPE;
            (yyval.actualValue).ival = newEntry->getTypeValue()->value.ival - 1;
            newEntry->getTypeValue()->value.ival = (yyval.actualValue).ival;

            string varStr1NameRep = (yyval.actualValue).nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable("--", name1 , "");
            (yyval.actualValue).nameRep = concatenateNames("--", name1 , "");
            assemblyGenerator.addQuadruple("DEC", name1, "", name);
        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 745 "Parser.y"
    {
            cout << " ------------- ADD -------------" << endl;
        int lhsType = (yyvsp[(1) - (3)].actualValue).type;
        int rhsType = (yyvsp[(3) - (3)].actualValue).type;

        if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
        {
            writeSemanticError("Type mismatch with ADD operation, must be integers or float", yylineno);
            return 0;
        }

        TypeValue *lhs;
        TypeValue *rhs;
        EntryType compareDataType = static_cast<EntryType>(lhsType);
        GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

        if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
        {
            (yyval.actualValue).type = FLOAT_TYPE;
            (yyval.actualValue).fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) + 
                    (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
            cout << "value: " << (yyval.actualValue).fval << endl;
        }
        else
        {
            (yyval.actualValue).type = INT_TYPE;
            (yyval.actualValue).ival = lhs->value.ival + rhs->value.ival;
            cout << "value: " << (yyval.actualValue).ival << endl;
        }

        stringstream valueStream;
        if ((yyval.actualValue).type == FLOAT_TYPE)
        {
            valueStream << (yyval.actualValue).fval;
        }
        else
        {
            valueStream << (yyval.actualValue).ival;
        }
        string valueStr = valueStream.str();

        printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
        const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
        const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
        const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
        printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

        (yyval.actualValue).nameRep = strdup(valueStr.c_str());

        assemblyGenerator.addQuadruple("ADD", name1, name2, name);
        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 797 "Parser.y"
    {
        int lhsType = (yyvsp[(1) - (3)].actualValue).type;
        int rhsType = (yyvsp[(3) - (3)].actualValue).type;

        if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
        {
            writeSemanticError("Type mismatch with SUB operation, must be integers or float", yylineno);
            return 0;
        }

        TypeValue *lhs;
        TypeValue *rhs;
        EntryType compareDataType = static_cast<EntryType>(lhsType);
        GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

        if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
        {
            (yyval.actualValue).type = FLOAT_TYPE;
            (yyval.actualValue).fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) - 
                    (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
            cout << "value: " << (yyval.actualValue).fval << endl;
        }
        else
        {
            (yyval.actualValue).type = INT_TYPE;
            (yyval.actualValue).ival = lhs->value.ival - rhs->value.ival;
            cout << "value: " << (yyval.actualValue).ival << endl;
        }

        stringstream valueStream;
        if ((yyval.actualValue).type == FLOAT_TYPE)
        {
            valueStream << (yyval.actualValue).fval;
        }
        else
        {
            valueStream << (yyval.actualValue).ival;
        }
        string valueStr = valueStream.str();

        printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
        const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
        const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
        const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
        printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

        (yyval.actualValue).nameRep = strdup(valueStr.c_str());

        assemblyGenerator.addQuadruple("SUB", name1, name2, name);
        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 851 "Parser.y"
    {
int lhsType = (yyvsp[(1) - (3)].actualValue).type;
    int rhsType = (yyvsp[(3) - (3)].actualValue).type;

    // Ensure types are either INT_TYPE or FLOAT_TYPE
    if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
    {
        writeSemanticError("Type mismatch with MUL operation, must be integers or float", yylineno);
        return 0;
    }

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

    // Calculate the final value based on the types
    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        (yyval.actualValue).type = FLOAT_TYPE;
        (yyval.actualValue).fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) * 
                  (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
        cout << "value: " << (yyval.actualValue).fval << endl;
    }
    else
    {
        (yyval.actualValue).type = INT_TYPE;
        (yyval.actualValue).ival = lhs->value.ival * rhs->value.ival;
        cout << "value: " << (yyval.actualValue).ival << endl;
    }

    // Convert the final value to a string
    stringstream valueStream;
    if ((yyval.actualValue).type == FLOAT_TYPE)
    {
        valueStream << (yyval.actualValue).fval;
    }
    else
    {
        valueStream << (yyval.actualValue).ival;
    }
    string valueStr = valueStream.str();

    // Print debugging information
    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    // Allocate memory for the final value string and assign it to nameRep
    (yyval.actualValue).nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("MUL", name1, name2, name);
        ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 907 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
    int rhsType = (yyvsp[(3) - (3)].actualValue).type;

    if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
    {
        writeSemanticError("Type mismatch with DIV operation, must be integers or float", yylineno);
        return 0;
    }

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        (yyval.actualValue).type = FLOAT_TYPE;
        (yyval.actualValue).fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) / 
                  (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
        cout << "value: " << (yyval.actualValue).fval << endl;
    }
    else
    {
        (yyval.actualValue).type = INT_TYPE;
        (yyval.actualValue).ival = lhs->value.ival / rhs->value.ival;
        cout << "value: " << (yyval.actualValue).ival << endl;
    }

    stringstream valueStream;
    if ((yyval.actualValue).type == FLOAT_TYPE)
    {
        valueStream << (yyval.actualValue).fval;
    }
    else
    {
        valueStream << (yyval.actualValue).ival;
    }
    string valueStr = valueStream.str();

    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    (yyval.actualValue).nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("DIV", name1, name2, name);
        ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 958 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
    int rhsType = (yyvsp[(3) - (3)].actualValue).type;

    if (lhsType != INT_TYPE || rhsType != INT_TYPE)
    {
        writeSemanticError("Type mismatch with MOD operation, must be integers", yylineno);
        return 0;
    }

    (yyval.actualValue).type = INT_TYPE;
    (yyval.actualValue).ival = (yyvsp[(1) - (3)].actualValue).ival % (yyvsp[(3) - (3)].actualValue).ival;
    cout << "value: " << (yyval.actualValue).ival << endl;

    stringstream valueStream;
    valueStream << (yyval.actualValue).ival;
    string valueStr = valueStream.str();

    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    (yyval.actualValue).nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("MOD", name1, name2, name);
        ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 990 "Parser.y"
    {
           int lhsType = (yyvsp[(1) - (3)].actualValue).type;
    int rhsType = (yyvsp[(3) - (3)].actualValue).type;

    if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
    {
        writeSemanticError("Type mismatch with POW operation, must be integers or float", yylineno);
        return 0;
    }

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, (yyvsp[(1) - (3)].actualValue), (yyvsp[(3) - (3)].actualValue), lhs, rhs);

    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        (yyval.actualValue).type = FLOAT_TYPE;
        (yyval.actualValue).fval = (lhsType == INT_TYPE ? pow(lhs->value.ival, rhs->value.fval) : pow(lhs->value.fval, (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval)));
        cout << "value: " << (yyval.actualValue).fval << endl;
    }
    else
    {
        (yyval.actualValue).type = INT_TYPE;
        (yyval.actualValue).ival = pow(lhs->value.ival, rhs->value.ival);
        cout << "value: " << (yyval.actualValue).ival << endl;
    }

    stringstream valueStream;
    if ((yyval.actualValue).type == FLOAT_TYPE)
    {
        valueStream << (yyval.actualValue).fval;
    }
    else
    {
        valueStream << (yyval.actualValue).ival;
    }
    string valueStr = valueStream.str();

    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", (yyvsp[(1) - (3)].actualValue).nameRep, (yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    (yyval.actualValue).nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("POW", name1, name2, name);
        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1043 "Parser.y"
    { 
        // printf("Integer: %d\n", $1.ival);
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).ival);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
        ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1051 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
        ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1059 "Parser.y"
    {
            cout << "Identifier: " << (yyvsp[(1) - (1)].stringVal) << endl;
            SymbolTableEntry* newEntry = getIdentifierEntry((yyvsp[(1) - (1)].stringVal));
            const char* nameeReg = assemblyGenerator.getRegisterAssignment(newEntry);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            newEntry->setused(true);
            (yyval.actualValue).type = (int)newEntry->getTypeValue()->type;
            string valueStr;
            switch((yyval.actualValue).type){
                case INT_TYPE:
                    (yyval.actualValue).ival = newEntry->getTypeValue()->value.ival;
                    valueStr = to_string((yyval.actualValue).ival);
                    cout << "Value string: " << valueStr << endl;
                    (yyval.actualValue).nameRep = strdup(valueStr.c_str());
                    break;
                case FLOAT_TYPE:
                    (yyval.actualValue).fval = newEntry->getTypeValue()->value.fval;
                    valueStr = to_string((yyval.actualValue).fval);
                    (yyval.actualValue).nameRep = strdup(valueStr.c_str());
                    break;
                case STRING_TYPE:
                    (yyval.actualValue).sval = newEntry->getTypeValue()->value.sval;
                    valueStr = (yyval.actualValue).sval;
                    (yyval.actualValue).nameRep = strdup(valueStr.c_str());
                    break;
                case BOOL_TYPE:
                    (yyval.actualValue).bval = newEntry->getTypeValue()->value.bval;
                    valueStr = to_string((yyval.actualValue).bval);
                    if((yyval.actualValue).bval)
                    {
                        valueStr = "true";
                    }
                    else
                    {
                        valueStr = "false";
                    }
                    cout << "Value string: " << valueStr << endl;
                    (yyval.actualValue).nameRep = strdup(valueStr.c_str());
              

                    
                    break;
                case CHAR_TYPE:
                    (yyval.actualValue).cval = newEntry->getTypeValue()->value.cval;
                    valueStr = to_string((yyval.actualValue).cval);
                    (yyval.actualValue).nameRep = strdup(valueStr.c_str());
                    break;
            }
        ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1116 "Parser.y"
    {(yyval.actualValue) = (yyvsp[(2) - (3)].actualValue);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1118 "Parser.y"
    {
            TypeValue * lhs;
            int lhsType = (yyvsp[(2) - (2)].actualValue).type;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, (yyvsp[(2) - (2)].actualValue), (yyvsp[(2) - (2)].actualValue), lhs, lhs);
            switch(lhsType){
                case INT_TYPE:
                    (yyvsp[(2) - (2)].actualValue).ival = -static_cast<int>(lhs->value.ival);
                    break;
                case FLOAT_TYPE:
                    (yyvsp[(2) - (2)].actualValue).fval = -static_cast<float>(lhs->value.fval);
                    break;
            }
            (yyval.actualValue) = (yyvsp[(2) - (2)].actualValue);
        ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1137 "Parser.y"
    {
            SymbolTableEntry* newEntry = getIdentifierEntry((yyvsp[(1) - (3)].stringVal));
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot assign value to constant", yylineno);
                return 0;
            }
            int idType = (int)newEntry->getTypeValue()->type;
            int valType = (yyvsp[(3) - (3)].actualValue).type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Assignment type mismatch", yylineno);
                return 0;
            }
            switch(idType){
                case INT_TYPE:
                    newEntry->getTypeValue()->value.ival = (yyvsp[(3) - (3)].actualValue).ival;
                    break;
                case FLOAT_TYPE:
                    newEntry->getTypeValue()->value.fval = (yyvsp[(3) - (3)].actualValue).fval;
                    break;
                case STRING_TYPE:
                    newEntry->getTypeValue()->value.sval = (yyvsp[(3) - (3)].actualValue).sval;
                    break;
                case BOOL_TYPE:
                    newEntry->getTypeValue()->value.bval = (yyvsp[(3) - (3)].actualValue).bval;
                    break;
                case CHAR_TYPE:
                    newEntry->getTypeValue()->value.cval = (yyvsp[(3) - (3)].actualValue).cval;
                    break;
            }
            newEntry->setinitialization(true);
            newEntry->setused(true);

            const char* name = assemblyGenerator.getRegisterAssignment(newEntry);
            const char* VarName = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            assemblyGenerator.addQuadruple("ASSIGN",VarName,"",name);
        ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1181 "Parser.y"
    {
            SymbolTableEntry* newEntry = identifierScopeCheck((yyvsp[(2) - (3)].stringVal));
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>((yyvsp[(1) - (3)].lexType));
            SymbolTableEntry * entry = addEntryToCurrentTable((yyvsp[(2) - (3)].stringVal), VAR, idTypeValue, false);

            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",(yyvsp[(2) - (3)].stringVal),"",name);


        ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1200 "Parser.y"
    {
            SymbolTableEntry* newEntry = identifierScopeCheck((yyvsp[(2) - (5)].stringVal));

            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            int idType = (yyvsp[(1) - (5)].lexType);
            int valType = (yyvsp[(4) - (5)].actualValue).type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Declaration type mismatch", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>(idType);
            string valueStr;
            switch(idTypeValue->type){
                case INT_TYPE:
                    idTypeValue->value.ival = (yyvsp[(4) - (5)].actualValue).ival;
                    valueStr = to_string((yyvsp[(4) - (5)].actualValue).ival);
                    break;
                case FLOAT_TYPE:
                    idTypeValue->value.fval = (yyvsp[(4) - (5)].actualValue).fval;
                    valueStr = to_string((yyvsp[(4) - (5)].actualValue).fval);
                    break;
                case STRING_TYPE:
                    idTypeValue->value.sval = (yyvsp[(4) - (5)].actualValue).sval;
                    valueStr = (yyvsp[(4) - (5)].actualValue).sval;
                    break;
                case BOOL_TYPE:
                    idTypeValue->value.bval = (yyvsp[(4) - (5)].actualValue).bval;
                    valueStr = to_string((yyvsp[(4) - (5)].actualValue).bval);
                    break;
                case CHAR_TYPE:
                    idTypeValue->value.cval = (yyvsp[(4) - (5)].actualValue).cval;
                    valueStr = to_string((yyvsp[(4) - (5)].actualValue).cval);
                    break;
            }
            SymbolTableEntry * entry = addEntryToCurrentTable((yyvsp[(2) - (5)].stringVal), VAR, idTypeValue, true);


            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",(yyvsp[(2) - (5)].stringVal),"",name);
            const char* VarName = assemblyGenerator.getTempVariable((yyvsp[(4) - (5)].actualValue).nameRep);
            assemblyGenerator.addQuadruple("ASSIGN",VarName,"",name);


        ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1252 "Parser.y"
    {
            SymbolTableEntry* newEntry = identifierScopeCheck((yyvsp[(3) - (6)].stringVal));
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            int idType = (yyvsp[(2) - (6)].lexType);
            int valType = (yyvsp[(5) - (6)].actualValue).type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Declaration type mismatch", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>(idType);
            switch(idTypeValue->type){
                case INT_TYPE:
                    idTypeValue->value.ival = (yyvsp[(5) - (6)].actualValue).ival;
                    break;
                case FLOAT_TYPE:
                    idTypeValue->value.fval = (yyvsp[(5) - (6)].actualValue).fval;
                    break;
                case STRING_TYPE:
                    idTypeValue->value.sval = (yyvsp[(5) - (6)].actualValue).sval;
                    break;
                case BOOL_TYPE:
                    idTypeValue->value.bval = (yyvsp[(5) - (6)].actualValue).bval;
                    break;
                case CHAR_TYPE:
                    idTypeValue->value.cval = (yyvsp[(5) - (6)].actualValue).cval;
                    break;
            }
            SymbolTableEntry * entry = addEntryToCurrentTable((yyvsp[(3) - (6)].stringVal), CONST, idTypeValue, true);

            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",(yyvsp[(3) - (6)].stringVal),"",name);
            const char* VarName = assemblyGenerator.getTempVariable((yyvsp[(5) - (6)].actualValue).nameRep);
            assemblyGenerator.addQuadruple("ASSIGN",VarName,"",name);
        ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1292 "Parser.y"
    {
            writeSemanticError("Constant variable not initialized ", yylineno);
            return 0;
        ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1300 "Parser.y"
    {
            if ((yyvsp[(3) - (3)].actualValue).type != BOOL_TYPE)
            {
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1307 "Parser.y"
    { assemblyGenerator.endScope(ifScope);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1313 "Parser.y"
    {
            if ((yyvsp[(5) - (5)].actualValue).type != BOOL_TYPE)
            {
                writeSemanticError("Condition of ELSE IF must be boolean", yylineno);
                return 0;
            }
        ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1320 "Parser.y"
    { 
            assemblyGenerator.endScope(elseIfScope); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1325 "Parser.y"
    { 
        assemblyGenerator.endScope(elseScope);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1331 "Parser.y"
    {createNewSymbolTable();
    assemblyGenerator.startScope();

;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1334 "Parser.y"
    {scopeEnd();;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1339 "Parser.y"
    {assemblyGenerator.endScope(caseScope);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1343 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).ival);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        // $$.nameRep = strdup(valueStr.c_str());
        ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1350 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).cval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
        ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1359 "Parser.y"
    {
                assemblyGenerator.endScope(defaultScope);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1361 "Parser.y"
    {
                assemblyGenerator.endScope(defaultScope);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1378 "Parser.y"
    {
    printf("**************** Scope Block ****************\n");
    createNewSymbolTable();
    assemblyGenerator.startScope();
;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1382 "Parser.y"
    {
    scopeEnd();
;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1387 "Parser.y"
    {
            assemblyGenerator.startScope();
;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1389 "Parser.y"
    {scopeEnd();;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1395 "Parser.y"
    {
            string functionName = string((yyvsp[(2) - (3)].stringVal)) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            SymbolTableEntry *newEntry = identifierScopeCheck((yyvsp[(2) - (3)].stringVal));
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>((yyvsp[(1) - (3)].lexType));
            EntryType funcOut = static_cast<EntryType>((yyvsp[(1) - (3)].lexType));
            addEntryToCurrentTable((yyvsp[(2) - (3)].stringVal), FUNC, idTypeValue, true, funcOut);
            createNewSymbolTable();
            assemblyGenerator.startScope();

            
        ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1413 "Parser.y"
    {
            printf("**************** Function1 ****************\n");
            if(functionHasReturn == false){
                writeSemanticWarning("Function must return a value", yylineno);
            }
            scopeEnd(); 
            currentFunction = nullptr; 
            functionHasReturn = false;
            assemblyGenerator.endScope(funcScope);
            assemblyGenerator.addQuadruple("RET", "", "", "");

        ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1426 "Parser.y"
    {
            string functionName = string((yyvsp[(2) - (3)].stringVal)) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            printf("**************** Function2 ****************\n");
            SymbolTableEntry *newEntry = identifierScopeCheck((yyvsp[(2) - (3)].stringVal));
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>((yyvsp[(1) - (3)].lexType));
            EntryType funcOut = static_cast<EntryType>((yyvsp[(1) - (3)].lexType));
            addEntryToCurrentTable((yyvsp[(2) - (3)].stringVal), FUNC, idTypeValue, true, funcOut);
            createNewSymbolTable();
            assemblyGenerator.startScope();


        ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1445 "Parser.y"
    {
            if(functionHasReturn == false){
                writeSemanticWarning("Function must return a value", yylineno);
            }

            scopeEnd(); 
            currentFunction = nullptr; 
            functionHasReturn = false;
            assemblyGenerator.endScope(funcScope);
            assemblyGenerator.addQuadruple("RET", "", "", "");


        ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1459 "Parser.y"
    {
            string functionName = string((yyvsp[(2) - (3)].stringVal)) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            SymbolTableEntry *newEntry = identifierScopeCheck((yyvsp[(2) - (3)].stringVal));
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = VOID_DTYPE;
            addEntryToCurrentTable((yyvsp[(2) - (3)].stringVal), FUNC, idTypeValue, true, VOID_DTYPE);
            createNewSymbolTable();
            assemblyGenerator.startScope();

        ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1474 "Parser.y"
    {scopeEnd(); currentFunction = nullptr;
                    assemblyGenerator.endScope(funcScope);
                    assemblyGenerator.addQuadruple("ENDFUNC", "", "", "");


        ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1481 "Parser.y"
    {
            string functionName = string((yyvsp[(2) - (3)].stringVal)) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            SymbolTableEntry *newEntry = identifierScopeCheck((yyvsp[(2) - (3)].stringVal));
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = VOID_DTYPE;
            addEntryToCurrentTable((yyvsp[(2) - (3)].stringVal), FUNC, idTypeValue, true, VOID_DTYPE);
            createNewSymbolTable();
            assemblyGenerator.startScope();

        ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1496 "Parser.y"
    {scopeEnd(); currentFunction = nullptr;
                    assemblyGenerator.endScope(funcScope);
                    assemblyGenerator.addQuadruple("ENDFUNC", "", "", "");

;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1506 "Parser.y"
    {
            SymbolTableEntry *newEntry = identifierScopeCheck((yyvsp[(2) - (2)].stringVal));
            if(newEntry != nullptr){
                writeSemanticError("Already declared variable", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            EntryType paramType = static_cast<EntryType>((yyvsp[(1) - (2)].lexType));
            idTypeValue->type = paramType;
            currentFunction->pushFunctionInput(paramType);
            SymbolTableEntry * entry = addEntryToCurrentTable((yyvsp[(2) - (2)].stringVal), PAR, idTypeValue, true);

             const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",(yyvsp[(2) - (2)].stringVal),"",name);
            
        ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1523 "Parser.y"
    {
            SymbolTableEntry *newEntry = identifierScopeCheck((yyvsp[(2) - (4)].stringVal));
            if(newEntry != nullptr){
                writeSemanticError("Already declared variable", yylineno);
                return 0;
            }
            int idType = (yyvsp[(1) - (4)].lexType);
            int valType = (yyvsp[(4) - (4)].actualValue).type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Function parameter intialization type mismatch", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            EntryType paramType = static_cast<EntryType>(idType);
            idTypeValue->type = paramType;
            currentFunction->pushFunctionInput(paramType);
            switch(idTypeValue->type){
                case INT_TYPE:
                    idTypeValue->value.ival = (yyvsp[(4) - (4)].actualValue).ival;
                    break;
                case FLOAT_TYPE:
                    idTypeValue->value.fval = (yyvsp[(4) - (4)].actualValue).fval;
                    break;
                case STRING_TYPE:
                    idTypeValue->value.sval = (yyvsp[(4) - (4)].actualValue).sval;
                    break;
                case BOOL_TYPE:
                    idTypeValue->value.bval = (yyvsp[(4) - (4)].actualValue).bval;
                    break;
                case CHAR_TYPE:
                    idTypeValue->value.cval = (yyvsp[(4) - (4)].actualValue).cval;
                    break;
            }
            SymbolTableEntry * entry = addEntryToCurrentTable((yyvsp[(2) - (4)].stringVal), PAR, idTypeValue, true);
             const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",(yyvsp[(2) - (4)].stringVal),"",name);
            
        ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1567 "Parser.y"
    {
            if (currentFunction == nullptr)
            {
                writeSemanticError("Return should be inside function block", yylineno);
                return 0;
            }
            if(currentFunction->getFunctionOutput() != VOID_DTYPE){
                writeSemanticError("Function must return a value", yylineno);
                return 0;
            }
        ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1579 "Parser.y"
    {
            if (currentFunction == nullptr)
            {
                writeSemanticError("Return should be inside function block", yylineno);
                return 0;
            }
            if(currentFunction->getFunctionOutput() != (yyvsp[(2) - (3)].actualValue).type){
                writeSemanticError("Return type mismatch", yylineno);
                return 0;
            }
            functionHasReturn = true;
        ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1592 "Parser.y"
    {
            if (currentFunction == nullptr)
            {
                writeSemanticError("Return should be inside function block", yylineno);
                return 0;
            }
            if(currentFunction->getFunctionOutput() != VOID_DTYPE){
                writeSemanticError("Function must return a value", yylineno);
                return 0;
            }
        ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1606 "Parser.y"
    {
            // Enter func args
            SymbolTableEntry *entry = getIdentifierEntry((yyvsp[(1) - (2)].stringVal));
            if(entry == nullptr){
                writeSemanticError("Undeclared function", yylineno);
                return 0;
            }
            if(entry->getKind() != FUNC)
            {
                writeSemanticError("Call must be of a function", yylineno);
                return 0;
            }
            entry->setused(true);
            insertFuncParamsToStack(entry);
        ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1621 "Parser.y"
    {
            // End of func call
            if(functionParameters.size() != 0)
            {
                writeSemanticError("Invalid arguments size", yylineno);
                return 0;
            }
            SymbolTableEntry *entry = getIdentifierEntry((yyvsp[(1) - (5)].stringVal));
            switch((int)entry->getFunctionOutput()){
                case INT_TYPE:
                    (yyval.actualValue).type = INT_TYPE;
                    (yyval.actualValue).ival = entry->getTypeValue()->value.ival;
                    break;
                case FLOAT_TYPE:
                    (yyval.actualValue).type = FLOAT_TYPE;
                    (yyval.actualValue).fval = entry->getTypeValue()->value.fval;
                    break;
                case STRING_TYPE:
                    (yyval.actualValue).type = STRING_TYPE;
                    (yyval.actualValue).sval = entry->getTypeValue()->value.sval;
                    break;
                case BOOL_TYPE:
                    (yyval.actualValue).type = BOOL_TYPE;
                    (yyval.actualValue).bval = entry->getTypeValue()->value.bval;
                    break;
                case CHAR_TYPE:
                    (yyval.actualValue).type = CHAR_TYPE;
                    (yyval.actualValue).cval = entry->getTypeValue()->value.cval;
                    break;
                case VOID_DTYPE:
                    (yyval.actualValue).type = VOID_DTYPE;
                    break;
            }
        ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1656 "Parser.y"
    {
            SymbolTableEntry *entry = getIdentifierEntry((yyvsp[(1) - (3)].stringVal));
            if(entry == nullptr){
                writeSemanticError("Undeclared function", yylineno);
                return 0;
            }
            if(entry->getKind() != FUNC)
            {
                writeSemanticError("Call must be of a function", yylineno);
                return 0;
            }
            entry->setused(true);
            switch((int)entry->getFunctionOutput()){
                case INT_TYPE:
                    (yyval.actualValue).type = INT_TYPE;
                    (yyval.actualValue).ival = entry->getTypeValue()->value.ival;
                    break;
                case FLOAT_TYPE:
                    (yyval.actualValue).type = FLOAT_TYPE;
                    (yyval.actualValue).fval = entry->getTypeValue()->value.fval;
                    break;
                case STRING_TYPE:
                    (yyval.actualValue).type = STRING_TYPE;
                    (yyval.actualValue).sval = entry->getTypeValue()->value.sval;
                    break;
                case BOOL_TYPE:
                    (yyval.actualValue).type = BOOL_TYPE;
                    (yyval.actualValue).bval = entry->getTypeValue()->value.bval;
                    break;
                case CHAR_TYPE:
                    (yyval.actualValue).type = CHAR_TYPE;
                    (yyval.actualValue).cval = entry->getTypeValue()->value.cval;
                    break;
                case VOID_DTYPE:
                    (yyval.actualValue).type = VOID_DTYPE;
                    break;
            }
        ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1697 "Parser.y"
    { 
            // Enter func args
            SymbolTableEntry *entry = getIdentifierEntry((yyvsp[(1) - (2)].stringVal));
            if(entry == nullptr){
                writeSemanticError("Undeclared function", yylineno);
                return 0;
            }
            if(entry->getKind() != FUNC)
            {
                writeSemanticError("Call must be of a function", yylineno);
                return 0;
            }
            entry->setused(true);
            insertFuncParamsToStack(entry);
        ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1713 "Parser.y"
    {
            // End of func call
            if(functionParameters.size() != 0)
            {
                writeSemanticError("Invalid arguments size", yylineno);
                return 0;
            }
        ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1722 "Parser.y"
    {
            SymbolTableEntry *entry = getIdentifierEntry((yyvsp[(1) - (3)].stringVal));
            if(entry == nullptr){
                writeSemanticError("Undeclared function", yylineno);
                return 0;
            }
            if(entry->getKind() != FUNC)
            {
                writeSemanticError("Call must be of a function", yylineno);
                return 0;
            }
            entry->setused(true);
        ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1738 "Parser.y"
    {
            if(functionParameters.size() == 0)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            if((int)functionParameters.top() != (int)(yyvsp[(3) - (3)].actualValue).type)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            functionParameters.pop();
        ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1752 "Parser.y"
    {
            if(functionParameters.size() == 0)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            if((int)functionParameters.top() != (int)(yyvsp[(1) - (1)].actualValue).type)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            functionParameters.pop();
        ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1769 "Parser.y"
    {
            printf("========  PRINT SUCCESSFUL ***********\n");
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 3713 "Parser.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 1777 "Parser.y"


/* Part 3: Subroutines */

int main(int argc, char **argv) {
    // Initialize the symbol table
    initSymbolTable();
    
    FILE *file;
    // Check if a filename was provided
    if (argc > 1) {
        // File name provided, open the file for reading
        file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        // Set Flex to read from it instead of standard input:
        yyin = file;
    } 
    /* else {
        // No filename provided, read from standard input
        yyin = stdin;
    } */
    

    yyparse();
	printGreen("PARSE SUCCESSFUL\n");

    if (argc > 1) {
        fclose(file);
    }

    saveSymbolTables();

    const char* quadPath = "quad.txt";
    const char* assemblyPath = "assembly.txt";

    FILE* quadFile = fopen(quadPath, "w");
    FILE* assemblyFile = fopen(assemblyPath, "w");

    assemblyGenerator.printQuadsToFile();

    return 0;
}

/* Part 3 End */
