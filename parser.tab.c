
/*  A Bison parser, made from parser.y
 by  GNU Bison version 1.27
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INT_DATA_TYPE	257
#define	FLOAT_DATA_TYPE	258
#define	CHAR_DATA_TYPE	259
#define	STRING_DATA_TYPE	260
#define	BOOLEAN_DATA_TYPE	261
#define	CONSTANT	262
#define	VOID_TYPE	263
#define	IF	264
#define	ELSE	265
#define	SWITCH	266
#define	CASE	267
#define	DEFAULT	268
#define	WHILE	269
#define	FOR	270
#define	REPEAT	271
#define	UNTIL	272
#define	BREAK	273
#define	RETURN	274
#define	IDENTIFIER	275
#define	BOOLEAN_TRUE	276
#define	BOOLEAN_FALSE	277
#define	INTEGER_VALUE	278
#define	FLOATING	279
#define	CHARACTER	280
#define	STRING_LITERAL	281
#define	ADD	282
#define	SUB	283
#define	MUL	284
#define	DIV	285
#define	MOD	286
#define	INC	287
#define	DEC	288
#define	POW	289
#define	ASSIGN	290
#define	AND	291
#define	OR	292
#define	NOT	293
#define	EQ	294
#define	NEQ	295
#define	GT	296
#define	LT	297
#define	GTE	298
#define	LTE	299
#define	PRINT	300

#line 3 "parser.y"

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

#line 59 "parser.y"
typedef union{
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
} YYSTYPE;
#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		249
#define	YYFLAG		-32768
#define	YYNTBASE	54

#define YYTRANSLATE(x) ((unsigned)(x) <= 300 ? yytranslate[x] : 112)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
    49,     2,     2,    53,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    52,    47,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    50,     2,    51,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     3,     5,     8,    10,    12,    15,    16,    23,
    24,    33,    34,    35,    45,    47,    48,    55,    57,    63,
    65,    68,    70,    72,    74,    76,    78,    80,    82,    84,
    86,    88,    90,    92,    94,    96,    98,   100,   102,   104,
   106,   108,   112,   116,   120,   124,   128,   132,   135,   139,
   143,   146,   149,   152,   155,   157,   161,   165,   167,   171,
   175,   179,   181,   185,   187,   189,   191,   193,   195,   199,
   202,   206,   210,   212,   218,   225,   230,   231,   232,   242,
   243,   252,   253,   256,   257,   258,   259,   265,   267,   268,
   277,   279,   281,   282,   289,   293,   294,   297,   299,   301,
   304,   307,   309,   310,   311,   317,   318,   319,   325,   326,
   336,   337,   346,   347,   357,   358,   367,   371,   373,   376,
   381,   384,   388,   389,   390,   396,   400,   401,   407,   411,
   415,   417,   421
};

static const short yyrhs[] = {    -1,
    55,     0,    56,     0,    55,    56,     0,    73,     0,    75,
     0,    72,    47,     0,     0,    15,    48,    65,    57,    49,
    92,     0,     0,    17,    92,    18,    48,    65,    58,    49,
    47,     0,     0,     0,    16,    48,    59,    90,    65,    60,
    91,    49,    95,     0,    76,     0,     0,    12,    48,    21,
    61,    49,    82,     0,    92,     0,    46,    48,   111,    49,
    47,     0,    98,     0,   108,    47,     0,   105,     0,     1,
     0,     3,     0,     4,     0,     5,     0,     6,     0,     7,
     0,    65,     0,    27,     0,    26,     0,    24,     0,    25,
     0,    26,     0,    27,     0,    22,     0,    23,     0,    67,
     0,    66,     0,    22,     0,    23,     0,    65,    40,    67,
     0,    65,    41,    67,     0,    65,    42,    67,     0,    65,
    43,    67,     0,    65,    44,    67,     0,    65,    45,    67,
     0,    39,    65,     0,    65,    37,    65,     0,    65,    38,
    65,     0,    21,    33,     0,    21,    34,     0,    33,    21,
     0,    34,    21,     0,    68,     0,    68,    28,    69,     0,
    68,    29,    69,     0,    69,     0,    69,    30,    70,     0,
    69,    31,    70,     0,    69,    32,    70,     0,    70,     0,
    70,    35,    71,     0,    71,     0,    24,     0,    25,     0,
   106,     0,    21,     0,    48,    65,    49,     0,    29,    65,
     0,    21,    36,    63,     0,    62,    21,    47,     0,    74,
     0,    62,    21,    36,    63,    47,     0,     8,    62,    21,
    36,    64,    47,     0,     8,    62,    21,    47,     0,     0,
     0,    10,    48,    65,    77,    49,    92,    78,    79,    81,
     0,     0,    79,    11,    10,    48,    65,    80,    49,    92,
     0,     0,    11,    92,     0,     0,     0,     0,    50,    83,
    85,    84,    51,     0,    88,     0,     0,    13,    87,    52,
    55,    86,    19,    47,    85,     0,    24,     0,    26,     0,
     0,    14,    52,    55,    89,    19,    47,     0,    14,    52,
    55,     0,     0,    72,    47,     0,    74,     0,    47,     0,
    47,    72,     0,    47,    65,     0,    47,     0,     0,     0,
    50,    93,    55,    94,    51,     0,     0,     0,    50,    96,
    55,    97,    51,     0,     0,    62,    21,    48,    99,   103,
    49,    50,    55,    51,     0,     0,    62,    21,    48,   100,
    49,    50,    55,    51,     0,     0,     9,    21,    48,   101,
   103,    49,    50,    55,    51,     0,     0,     9,    21,    48,
   102,    49,    50,    55,    51,     0,   104,    53,   103,     0,
   104,     0,    62,    21,     0,    62,    21,    36,    64,     0,
    20,    47,     0,    20,    63,    47,     0,     0,     0,    21,
    48,   107,   110,    49,     0,    21,    48,    49,     0,     0,
    21,    48,   109,   110,    49,     0,    21,    48,    49,     0,
   110,    53,    63,     0,    63,     0,    63,    53,   111,     0,
    63,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   151,   152,   190,   191,   194,   195,   196,   197,   205,   206,
   218,   219,   219,   228,   230,   231,   248,   249,   250,   251,
   252,   253,   254,   258,   258,   258,   258,   258,   260,   261,
   270,   281,   288,   295,   302,   309,   316,   326,   326,   328,
   335,   341,   371,   410,   443,   476,   509,   542,   568,   594,
   620,   651,   681,   711,   741,   744,   796,   847,   850,   906,
   957,   986,   989,  1039,  1042,  1050,  1057,  1058,  1116,  1117,
  1136,  1180,  1196,  1199,  1251,  1291,  1299,  1307,  1309,  1312,
  1320,  1322,  1325,  1327,  1331,  1334,  1335,  1337,  1339,  1339,
  1342,  1349,  1358,  1360,  1361,  1363,  1367,  1368,  1369,  1372,
  1373,  1374,  1377,  1382,  1385,  1387,  1389,  1390,  1394,  1412,
  1425,  1444,  1458,  1474,  1480,  1496,  1503,  1503,  1505,  1522,
  1566,  1578,  1591,  1605,  1620,  1655,  1696,  1712,  1721,  1737,
  1751,  1768,  1772
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","INT_DATA_TYPE",
"FLOAT_DATA_TYPE","CHAR_DATA_TYPE","STRING_DATA_TYPE","BOOLEAN_DATA_TYPE","CONSTANT",
"VOID_TYPE","IF","ELSE","SWITCH","CASE","DEFAULT","WHILE","FOR","REPEAT","UNTIL",
"BREAK","RETURN","IDENTIFIER","BOOLEAN_TRUE","BOOLEAN_FALSE","INTEGER_VALUE",
"FLOATING","CHARACTER","STRING_LITERAL","ADD","SUB","MUL","DIV","MOD","INC",
"DEC","POW","ASSIGN","AND","OR","NOT","EQ","NEQ","GT","LT","GTE","LTE","PRINT",
"';'","'('","')'","'{'","'}'","':'","','","program","codeBlock","codeStatement",
"@1","@2","@3","@4","@5","dataType","dataValue","constantValue","expression",
"boolean","arithmetic","complexArithmetic","minorTerm","majorTerm","instance",
"assignment","variableDeclaration","variableDeclarationWithAssignment","constantDeclaration",
"ifCondition","@6","@7","elseIfCondition","@8","elseStmnt","switchBlock","@9",
"@10","caseExpression","@11","switchValidValue","caseDefault","@12","forLoopInitialization",
"forLoopItter","scopeBlock","@13","@14","loopsScopeBlock","@15","@16","function",
"@17","@18","@19","@20","ArgList","Arg","ReturnCase","TypedFunctionCall","@21",
"VoidFunctionCall","@22","CallList","printStatement", NULL
};
#endif

static const short yyr1[] = {     0,
    54,    54,    55,    55,    56,    56,    56,    57,    56,    58,
    56,    59,    60,    56,    56,    61,    56,    56,    56,    56,
    56,    56,    56,    62,    62,    62,    62,    62,    63,    63,
    63,    64,    64,    64,    64,    64,    64,    65,    65,    66,
    66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
    67,    67,    67,    67,    67,    68,    68,    68,    69,    69,
    69,    69,    70,    70,    71,    71,    71,    71,    71,    71,
    72,    73,    73,    74,    75,    75,    77,    78,    76,    80,
    79,    79,    81,    81,    83,    84,    82,    85,    86,    85,
    87,    87,    89,    88,    88,    88,    90,    90,    90,    91,
    91,    91,    93,    94,    92,    96,    97,    95,    99,    98,
   100,    98,   101,    98,   102,    98,   103,   103,   104,   104,
   105,   105,   105,   107,   106,   106,   109,   108,   108,   110,
   110,   111,   111
};

static const short yyr2[] = {     0,
     0,     1,     1,     2,     1,     1,     2,     0,     6,     0,
     8,     0,     0,     9,     1,     0,     6,     1,     5,     1,
     2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     3,     3,     3,     3,     3,     3,     2,     3,     3,
     2,     2,     2,     2,     1,     3,     3,     1,     3,     3,
     3,     1,     3,     1,     1,     1,     1,     1,     3,     2,
     3,     3,     1,     5,     6,     4,     0,     0,     9,     0,
     8,     0,     2,     0,     0,     0,     5,     1,     0,     8,
     1,     1,     0,     6,     3,     0,     2,     1,     1,     2,
     2,     1,     0,     0,     5,     0,     0,     5,     0,     9,
     0,     8,     0,     9,     0,     8,     3,     1,     2,     4,
     2,     3,     0,     0,     5,     3,     0,     5,     3,     3,
     1,     3,     1
};

static const short yydefact[] = {     0,
    23,    24,    25,    26,    27,    28,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   103,     0,     3,     0,
     0,     5,    73,     6,    15,    18,    20,    22,     0,     0,
     0,     0,     0,     0,    12,     0,    68,    40,    41,    65,
    66,    31,    30,     0,     0,     0,     0,   121,     0,     0,
    29,    39,    38,    55,    58,    62,    64,    67,     0,   127,
     0,     0,     4,     0,     7,    21,     0,   113,    77,    16,
     8,     0,     0,    51,    52,   124,    70,    53,    54,    48,
     0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    71,   129,     0,   133,
     0,     0,     0,    72,   109,     0,    76,     0,     0,     0,
     0,     0,     0,    99,     0,     0,    98,     0,     0,   126,
     0,    69,    49,    50,    42,    43,    44,    45,    46,    47,
    68,    56,    57,    59,    60,    61,    63,   131,     0,     0,
     0,     0,     0,     0,     0,    36,    37,    32,    33,    34,
    35,     0,     0,     0,   118,     0,     0,     0,     0,     0,
    97,    13,    10,     0,   128,     0,   132,    19,   105,    74,
     0,     0,    75,   119,     0,     0,     0,    78,    85,    17,
     9,     0,     0,   125,   130,     0,     0,     0,     0,   117,
     0,    82,    96,   102,     0,     0,     0,     0,   120,     0,
   116,    84,     0,     0,    86,    88,    68,   101,   100,     0,
    11,     0,   112,   114,     0,    79,    91,    92,     0,     0,
     0,   106,    14,   110,     0,    83,     0,     0,    87,     0,
     0,     0,     0,     0,    80,     0,     0,     0,     0,     0,
    94,   108,     0,    96,    81,    90,     0,     0,     0
};

static const short yydefgoto[] = {   247,
    18,    19,   112,   183,    72,   182,   111,    20,   100,   152,
    51,    52,    53,    54,    55,    56,    57,    21,    22,    23,
    24,    25,   110,   192,   202,   239,   216,   180,   193,   221,
   205,   236,   219,   206,   233,   118,   195,    26,    62,   142,
   223,   230,   238,    27,   144,   145,   108,   109,   154,   155,
    28,    58,   121,    29,    99,   139,   101
};

static const short yypact[] = {   219,
-32768,-32768,-32768,-32768,-32768,-32768,   558,    -8,    13,    23,
    30,    36,    43,   165,     1,    57,-32768,   241,-32768,    53,
    60,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    74,   103,
    84,    58,   113,    58,-32768,   121,    24,-32768,-32768,-32768,
-32768,-32768,-32768,    58,   117,   124,    58,-32768,    58,    94,
   509,-32768,-32768,    48,   -20,   107,-32768,-32768,   483,    98,
   483,   269,-32768,   -15,-32768,-32768,    26,    99,   509,-32768,
   509,    39,   101,-32768,-32768,   106,   509,-32768,-32768,-32768,
   499,-32768,    58,    58,   490,   490,   490,   490,   490,   490,
    27,    27,    27,    27,    27,    27,-32768,-32768,   483,   112,
   118,   291,   483,-32768,   122,    76,-32768,   558,   126,   130,
   131,   133,   123,-32768,   148,   137,-32768,    58,    58,-32768,
   483,-32768,   515,   515,-32768,-32768,-32768,-32768,-32768,-32768,
   145,   -20,   -20,   107,   107,   107,-32768,-32768,     6,   483,
   138,   119,   149,   558,   151,-32768,-32768,-32768,-32768,-32768,
-32768,   150,   157,   154,   161,   166,    43,   168,    43,   185,
-32768,   509,   509,    14,-32768,   483,-32768,-32768,-32768,-32768,
   183,   187,-32768,   197,   188,   558,   269,-32768,-32768,-32768,
-32768,   196,   203,-32768,-32768,   204,   269,    76,   269,-32768,
   323,-32768,    82,   129,   206,   212,   269,   344,-32768,   376,
-32768,   249,    40,   211,-32768,-32768,   -18,   509,-32768,   214,
-32768,   397,-32768,-32768,    -3,-32768,-32768,-32768,   215,    19,
   217,-32768,-32768,-32768,   218,-32768,   450,   110,-32768,   269,
    58,   482,   252,   429,   509,   261,   235,   232,   239,   246,
-32768,-32768,    43,    82,-32768,-32768,   302,   304,-32768
};

static const short yypgoto[] = {-32768,
   -54,   -17,-32768,-32768,-32768,-32768,-32768,    -4,    -9,   125,
   -30,-32768,   120,-32768,    45,    15,   209,   -66,-32768,   237,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    66,-32768,-32768,-32768,-32768,-32768,-32768,   -13,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -135,-32768,
-32768,-32768,-32768,-32768,-32768,   193,   176
};


#define	YYLAST		565


static const short yytable[] = {    36,
    63,    69,    30,    71,    50,   116,   225,   102,   171,    93,
    94,    95,    31,    77,    74,    75,    80,    59,    81,     1,
   103,     2,     3,     4,     5,     6,     7,     8,     9,    76,
    10,   104,   105,    11,    12,    13,    59,  -123,    14,    15,
   190,     2,     3,     4,     5,     6,    17,   131,    60,    97,
    40,    41,   123,   124,   165,    44,    74,    75,   166,   113,
    32,   106,   184,   217,    16,   218,   166,   115,    17,  -123,
    33,    76,   107,    64,    49,    91,    92,    34,    37,    38,
    39,    40,    41,    35,    63,   114,    44,   162,   163,   138,
    45,    46,    17,   143,   203,   204,    47,   146,   147,   148,
   149,   150,   151,   153,    61,    49,    65,   134,   135,   136,
     1,   138,     2,     3,     4,     5,     6,     7,     8,     9,
    66,    10,   191,    67,    11,    12,    13,   209,   -93,    14,
    15,    68,   198,    70,   200,   132,   133,    78,    73,   153,
    82,    96,   212,   178,    79,   181,    98,  -115,   119,   207,
    38,    39,    40,    41,   120,    16,   185,    44,    59,    17,
   -95,    45,    46,   208,   140,   228,   141,    47,   160,   169,
  -111,   153,   232,    63,   156,   234,    49,   174,   157,   158,
    63,   159,    63,   161,   168,    37,    38,    39,    40,    41,
    42,    43,    76,    44,    63,   170,   173,    45,    46,   172,
   235,   226,   175,    47,   125,   126,   127,   128,   129,   130,
    63,    48,    49,   176,    63,   177,    63,   179,    -1,     1,
   103,     2,     3,     4,     5,     6,     7,     8,     9,   245,
    10,   186,   188,    11,    12,    13,   187,   189,    14,    15,
    -2,     1,   194,     2,     3,     4,     5,     6,     7,     8,
     9,   196,    10,   197,   210,    11,    12,    13,   211,   215,
    14,    15,   220,   222,    16,   231,   227,   229,    17,     1,
   237,     2,     3,     4,     5,     6,     7,     8,     9,   240,
    10,   241,   242,    11,    12,    13,    16,   243,    14,    15,
    17,     1,   244,     2,     3,     4,     5,     6,     7,     8,
     9,   248,    10,   249,   137,    11,    12,    13,   117,   246,
    14,    15,   199,   164,    16,   167,     0,     0,    17,  -123,
     0,     0,     0,     1,     0,     2,     3,     4,     5,     6,
     7,     8,     9,     0,    10,     0,    16,    11,    12,    13,
    17,  -104,    14,    15,     1,     0,     2,     3,     4,     5,
     6,     7,     8,     9,     0,    10,     0,     0,    11,    12,
    13,     0,     0,    14,    15,     0,     0,     0,    16,     0,
     0,     0,    17,   201,     0,     0,     1,     0,     2,     3,
     4,     5,     6,     7,     8,     9,     0,    10,     0,    16,
    11,    12,    13,    17,   213,    14,    15,     1,     0,     2,
     3,     4,     5,     6,     7,     8,     9,     0,    10,     0,
     0,    11,    12,    13,     0,     0,    14,    15,     0,     0,
     0,    16,     0,     0,     0,    17,   214,     0,     0,     1,
     0,     2,     3,     4,     5,     6,     7,     8,     9,     0,
    10,     0,    16,    11,    12,    13,    17,   224,    14,    15,
     1,     0,     2,     3,     4,     5,     6,     7,     8,     9,
     0,    10,     0,     0,    11,    12,    13,     0,  -123,    14,
    15,     0,     0,     0,    16,     0,     0,     0,    17,  -107,
     0,     0,     1,     0,     2,     3,     4,     5,     6,     7,
     8,     9,     0,    10,     0,    16,    11,    12,    13,    17,
   -89,    14,    15,    37,    38,    39,    40,    41,    42,    43,
    37,    44,     0,    40,    41,    45,    46,     0,    44,     0,
     0,    47,    45,    46,     0,     0,     0,    16,     0,     0,
    49,    17,     0,     0,     0,    83,    84,    49,    85,    86,
    87,    88,    89,    90,     0,    83,    84,   122,    85,    86,
    87,    88,    89,    90,    85,    86,    87,    88,    89,    90,
     2,     3,     4,     5,     6
};

static const short yycheck[] = {    13,
    18,    32,     7,    34,    14,    72,    10,    62,   144,    30,
    31,    32,    21,    44,    33,    34,    47,    36,    49,     1,
    36,     3,     4,     5,     6,     7,     8,     9,    10,    48,
    12,    47,    48,    15,    16,    17,    36,    19,    20,    21,
   176,     3,     4,     5,     6,     7,    50,    21,    48,    59,
    24,    25,    83,    84,    49,    29,    33,    34,    53,    21,
    48,    36,    49,    24,    46,    26,    53,    72,    50,    51,
    48,    48,    47,    21,    48,    28,    29,    48,    21,    22,
    23,    24,    25,    48,   102,    47,    29,   118,   119,    99,
    33,    34,    50,   103,    13,    14,    39,    22,    23,    24,
    25,    26,    27,   108,    48,    48,    47,    93,    94,    95,
     1,   121,     3,     4,     5,     6,     7,     8,     9,    10,
    47,    12,   177,    21,    15,    16,    17,   194,    19,    20,
    21,    48,   187,    21,   189,    91,    92,    21,    18,   144,
    47,    35,   197,   157,    21,   159,    49,    49,    48,    21,
    22,    23,    24,    25,    49,    46,   166,    29,    36,    50,
    51,    33,    34,   194,    53,   220,    49,    39,    21,    51,
    49,   176,   227,   191,    49,   230,    48,    21,    49,    49,
   198,    49,   200,    47,    47,    21,    22,    23,    24,    25,
    26,    27,    48,    29,   212,    47,    47,    33,    34,    49,
   231,   215,    49,    39,    85,    86,    87,    88,    89,    90,
   228,    47,    48,    53,   232,    50,   234,    50,     0,     1,
    36,     3,     4,     5,     6,     7,     8,     9,    10,   243,
    12,    49,    36,    15,    16,    17,    50,    50,    20,    21,
     0,     1,    47,     3,     4,     5,     6,     7,     8,     9,
    10,    49,    12,    50,    49,    15,    16,    17,    47,    11,
    20,    21,    52,    50,    46,    48,    52,    51,    50,     1,
    19,     3,     4,     5,     6,     7,     8,     9,    10,    19,
    12,    47,    51,    15,    16,    17,    46,    49,    20,    21,
    50,     1,    47,     3,     4,     5,     6,     7,     8,     9,
    10,     0,    12,     0,    96,    15,    16,    17,    72,   244,
    20,    21,   188,   121,    46,   140,    -1,    -1,    50,    51,
    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
     8,     9,    10,    -1,    12,    -1,    46,    15,    16,    17,
    50,    51,    20,    21,     1,    -1,     3,     4,     5,     6,
     7,     8,     9,    10,    -1,    12,    -1,    -1,    15,    16,
    17,    -1,    -1,    20,    21,    -1,    -1,    -1,    46,    -1,
    -1,    -1,    50,    51,    -1,    -1,     1,    -1,     3,     4,
     5,     6,     7,     8,     9,    10,    -1,    12,    -1,    46,
    15,    16,    17,    50,    51,    20,    21,     1,    -1,     3,
     4,     5,     6,     7,     8,     9,    10,    -1,    12,    -1,
    -1,    15,    16,    17,    -1,    -1,    20,    21,    -1,    -1,
    -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,     1,
    -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
    12,    -1,    46,    15,    16,    17,    50,    51,    20,    21,
     1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
    -1,    12,    -1,    -1,    15,    16,    17,    -1,    19,    20,
    21,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
     9,    10,    -1,    12,    -1,    46,    15,    16,    17,    50,
    19,    20,    21,    21,    22,    23,    24,    25,    26,    27,
    21,    29,    -1,    24,    25,    33,    34,    -1,    29,    -1,
    -1,    39,    33,    34,    -1,    -1,    -1,    46,    -1,    -1,
    48,    50,    -1,    -1,    -1,    37,    38,    48,    40,    41,
    42,    43,    44,    45,    -1,    37,    38,    49,    40,    41,
    42,    43,    44,    45,    40,    41,    42,    43,    44,    45,
     3,     4,     5,     6,     7
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"
/* This file comes from bison-1.27.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 216 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 151 "parser.y"
{printf("======== EMPTY PROGRAM ***********\n");;
    break;}
case 2:
#line 152 "parser.y"
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
                                                                                            ;
    break;}
case 8:
#line 198 "parser.y"
{
            if (yyvsp[0].actualValue.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of WHILE must be boolean", yylineno);
                return 0;
            }
        ;
    break;}
case 9:
#line 205 "parser.y"
{ assemblyGenerator.endScope(whileScope);;
    break;}
case 10:
#line 210 "parser.y"
{
            assemblyGenerator.endScope(repeatScope);
            if (yyvsp[0].actualValue.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of REPEAT must be boolean", yylineno);
                return 0;
            }
        ;
    break;}
case 12:
#line 219 "parser.y"
{createNewSymbolTable();;
    break;}
case 13:
#line 220 "parser.y"
{
            if (yyvsp[0].actualValue.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of FOR must be boolean", yylineno);
                return 0;
            }
            
        ;
    break;}
case 14:
#line 228 "parser.y"
{ printf("for loop itter\n");
            assemblyGenerator.endScope(forScope);;
    break;}
case 16:
#line 232 "parser.y"
{
            SymbolTableEntry* newEntry = getIdentifierEntry(yyvsp[0].stringVal);
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
        ;
    break;}
case 17:
#line 248 "parser.y"
{ assemblyGenerator.endScope(switchScope); ;
    break;}
case 23:
#line 254 "parser.y"
{ yyerror("Unexpected statement"); ;
    break;}
case 30:
#line 262 "parser.y"
{
    { 
        string valueStr = yyvsp[0].actualValue.sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        } 
;
    break;}
case 31:
#line 270 "parser.y"
{
    { 
        char charValue = static_cast<char>(yyvsp[0].actualValue.cval);  
        string valueStr(1, charValue);  
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        } 
;
    break;}
case 32:
#line 282 "parser.y"
{
    string valueStr = to_string(yyvsp[0].actualValue.ival);
    const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
    assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
    // $$.nameRep = strdup(valueStr.c_str());
;
    break;}
case 33:
#line 289 "parser.y"
{ 
        string valueStr = to_string(yyvsp[0].actualValue.fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 34:
#line 296 "parser.y"
{ 
        string valueStr = to_string(yyvsp[0].actualValue.cval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 35:
#line 303 "parser.y"
{ 
        string valueStr = yyvsp[0].actualValue.sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 36:
#line 310 "parser.y"
{ 
        string valueStr = "true";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 37:
#line 317 "parser.y"
{ 
        string valueStr = "false";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 40:
#line 329 "parser.y"
{
            cout << "BOOLEAN_TRUE\n";
            const char* name = assemblyGenerator.addTempVariable("true" , "" , "");
            assemblyGenerator.addQuadruple("ASSIGN", "TRUE", "", name);
            yyval.actualValue.nameRep = strdup("true");
        ;
    break;}
case 41:
#line 336 "parser.y"
{
        const char* name = assemblyGenerator.addTempVariable("false" , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", "FALSE", "", name);
        yyval.actualValue.nameRep = strdup("false");
        ;
    break;}
case 42:
#line 342 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;
            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }
            yyval.actualValue.type = BOOL_TYPE;
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);
            yyval.actualValue.bval = checkEqualityEqual(lhs, rhs);
            string valueStr = yyval.actualValue.bval ? "true" : "false";

           // Print debugging information
            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            // Allocate memory for the final value string and assign it to nameRep
            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            // Add the quadruple for the EQ operation
            assemblyGenerator.addQuadruple("EQU", name1, name2, name);
        ;
    break;}
case 43:
#line 372 "parser.y"
{
          int lhsType = yyvsp[-2].actualValue.type;
    int rhsType = yyvsp[0].actualValue.type;

    // Check for type mismatch
    if (typeMismatch(lhsType, rhsType))
    {
        writeSemanticError("Type mismatch", yylineno);
        return 0;
    }

    // Set the result type to BOOL_TYPE
    yyval.actualValue.type = BOOL_TYPE;

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

    // Check for inequality
    yyval.actualValue.bval = checkEqualityNot(lhs, rhs);

    // Convert the boolean result to a string
    string valueStr = yyval.actualValue.bval ? "true" : "false";

    // Print debugging information
    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    // Allocate memory for the final value string and assign it to nameRep
    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    // Add the quadruple for the NEQ operation
    assemblyGenerator.addQuadruple("NEQ", name1, name2, name);
        ;
    break;}
case 44:
#line 411 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;

            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }

            yyval.actualValue.type = BOOL_TYPE;

            TypeValue *lhs;
            TypeValue *rhs;

            EntryType compareDataType = static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

            yyval.actualValue.bval = checkEqualityGT(lhs, rhs);

            string valueStr = yyval.actualValue.bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("GT", name1, name2, name);
        ;
    break;}
case 45:
#line 444 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;

            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }

            yyval.actualValue.type = BOOL_TYPE;

            TypeValue * lhs;
            TypeValue * rhs;

            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

            yyval.actualValue.bval = checkEqualityLT(lhs, rhs);

            string valueStr = yyval.actualValue.bval ? "true" : "false";

           printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("LT", name1, name2, name);
        ;
    break;}
case 46:
#line 477 "parser.y"
{
             int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;

            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }

            yyval.actualValue.type = BOOL_TYPE;

            TypeValue *lhs;
            TypeValue *rhs;

            EntryType compareDataType = static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

            yyval.actualValue.bval = checkEqualityGTE(lhs, rhs);

            string valueStr = yyval.actualValue.bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("GTE", name1, name2, name);
        ;
    break;}
case 47:
#line 510 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;

            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }

            yyval.actualValue.type = BOOL_TYPE;

            TypeValue * lhs;
            TypeValue * rhs;

            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

            yyval.actualValue.bval = checkEqualityLTE(lhs, rhs);

            string valueStr = yyval.actualValue.bval ? "true" : "false";

           printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("LTE", name1, name2, name);
        ;
    break;}
case 48:
#line 543 "parser.y"
{
           int varType = yyvsp[0].actualValue.type;

    if (varType != BOOL_TYPE)
    {
        writeSemanticError("Type mismatch with NOT operation", yylineno);
        return 0;
    }

    yyval.actualValue.type = BOOL_TYPE;
    yyval.actualValue.bval = !yyvsp[0].actualValue.bval;

   string valueStr = yyval.actualValue.bval ? "true" : "false";

            printf("varStr1NameRep: %s \n", yyvsp[0].actualValue.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name: %s\n", name1, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("NOT", name1, "", name);

            
        ;
    break;}
case 49:
#line 569 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;

            if (lhsType != BOOL_TYPE || rhsType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with AND operation, types must be boolean", yylineno);
                return 0;
            }

            yyval.actualValue.type = BOOL_TYPE;
            yyval.actualValue.bval = yyvsp[-2].actualValue.bval && yyvsp[0].actualValue.bval;

            string valueStr = yyval.actualValue.bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("AND", name1, name2, name);
        ;
    break;}
case 50:
#line 595 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;
            if (lhsType != BOOL_TYPE || rhsType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with OR operation, types must be boolean", yylineno);
                return 0;
            }
            yyval.actualValue.type = BOOL_TYPE;
            yyval.actualValue.bval = yyvsp[-2].actualValue.bval || yyvsp[0].actualValue.bval;

            string valueStr = yyval.actualValue.bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("OR", name1, name2, name);
        ;
    break;}
case 51:
#line 621 "parser.y"
{
            printf("INC\n");
            SymbolTableEntry* newEntry = getIdentifierEntry(yyvsp[-1].stringVal);
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
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = newEntry->getTypeValue()->value.ival + 1;
            newEntry->getTypeValue()->value.ival = yyval.actualValue.ival;\

            string varStr1NameRep = yyval.actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1, "++" , "");
            yyval.actualValue.nameRep = concatenateNames(name1, "++" , "");
            assemblyGenerator.addQuadruple("INC", name1, "", name);
        ;
    break;}
case 52:
#line 652 "parser.y"
{
            SymbolTableEntry* newEntry = getIdentifierEntry(yyvsp[-1].stringVal);
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
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = newEntry->getTypeValue()->value.ival - 1;
            newEntry->getTypeValue()->value.ival = yyval.actualValue.ival;

            string varStr1NameRep = yyval.actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1, "--" , "");
            yyval.actualValue.nameRep = concatenateNames(name1, "--" , "");
            assemblyGenerator.addQuadruple("DEC", name1, "", name);
        ;
    break;}
case 53:
#line 682 "parser.y"
{
            SymbolTableEntry* newEntry = getIdentifierEntry(yyvsp[0].stringVal);
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
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = newEntry->getTypeValue()->value.ival + 1;
            newEntry->getTypeValue()->value.ival = yyval.actualValue.ival;

            string varStr1NameRep = yyval.actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable("++", name1 , "");
            yyval.actualValue.nameRep = concatenateNames("++", name1 , "");
            assemblyGenerator.addQuadruple("INC", name1, "", name);
        ;
    break;}
case 54:
#line 712 "parser.y"
{
            SymbolTableEntry* newEntry = getIdentifierEntry(yyvsp[0].stringVal);
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
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = newEntry->getTypeValue()->value.ival - 1;
            newEntry->getTypeValue()->value.ival = yyval.actualValue.ival;

            string varStr1NameRep = yyval.actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable("--", name1 , "");
            yyval.actualValue.nameRep = concatenateNames("--", name1 , "");
            assemblyGenerator.addQuadruple("DEC", name1, "", name);
        ;
    break;}
case 56:
#line 745 "parser.y"
{
            cout << " ------------- ADD -------------" << endl;
        int lhsType = yyvsp[-2].actualValue.type;
        int rhsType = yyvsp[0].actualValue.type;

        if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
        {
            writeSemanticError("Type mismatch with ADD operation, must be integers or float", yylineno);
            return 0;
        }

        TypeValue *lhs;
        TypeValue *rhs;
        EntryType compareDataType = static_cast<EntryType>(lhsType);
        GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

        if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
        {
            yyval.actualValue.type = FLOAT_TYPE;
            yyval.actualValue.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) + 
                    (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
            cout << "value: " << yyval.actualValue.fval << endl;
        }
        else
        {
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = lhs->value.ival + rhs->value.ival;
            cout << "value: " << yyval.actualValue.ival << endl;
        }

        stringstream valueStream;
        if (yyval.actualValue.type == FLOAT_TYPE)
        {
            valueStream << yyval.actualValue.fval;
        }
        else
        {
            valueStream << yyval.actualValue.ival;
        }
        string valueStr = valueStream.str();

        printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
        const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
        const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
        const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
        printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

        yyval.actualValue.nameRep = strdup(valueStr.c_str());

        assemblyGenerator.addQuadruple("ADD", name1, name2, name);
        ;
    break;}
case 57:
#line 797 "parser.y"
{
        int lhsType = yyvsp[-2].actualValue.type;
        int rhsType = yyvsp[0].actualValue.type;

        if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
        {
            writeSemanticError("Type mismatch with SUB operation, must be integers or float", yylineno);
            return 0;
        }

        TypeValue *lhs;
        TypeValue *rhs;
        EntryType compareDataType = static_cast<EntryType>(lhsType);
        GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

        if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
        {
            yyval.actualValue.type = FLOAT_TYPE;
            yyval.actualValue.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) - 
                    (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
            cout << "value: " << yyval.actualValue.fval << endl;
        }
        else
        {
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = lhs->value.ival - rhs->value.ival;
            cout << "value: " << yyval.actualValue.ival << endl;
        }

        stringstream valueStream;
        if (yyval.actualValue.type == FLOAT_TYPE)
        {
            valueStream << yyval.actualValue.fval;
        }
        else
        {
            valueStream << yyval.actualValue.ival;
        }
        string valueStr = valueStream.str();

        printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
        const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
        const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
        const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
        printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

        yyval.actualValue.nameRep = strdup(valueStr.c_str());

        assemblyGenerator.addQuadruple("SUB", name1, name2, name);
        ;
    break;}
case 59:
#line 851 "parser.y"
{
int lhsType = yyvsp[-2].actualValue.type;
    int rhsType = yyvsp[0].actualValue.type;

    // Ensure types are either INT_TYPE or FLOAT_TYPE
    if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
    {
        writeSemanticError("Type mismatch with MUL operation, must be integers or float", yylineno);
        return 0;
    }

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

    // Calculate the final value based on the types
    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        yyval.actualValue.type = FLOAT_TYPE;
        yyval.actualValue.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) * 
                  (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
        cout << "value: " << yyval.actualValue.fval << endl;
    }
    else
    {
        yyval.actualValue.type = INT_TYPE;
        yyval.actualValue.ival = lhs->value.ival * rhs->value.ival;
        cout << "value: " << yyval.actualValue.ival << endl;
    }

    // Convert the final value to a string
    stringstream valueStream;
    if (yyval.actualValue.type == FLOAT_TYPE)
    {
        valueStream << yyval.actualValue.fval;
    }
    else
    {
        valueStream << yyval.actualValue.ival;
    }
    string valueStr = valueStream.str();

    // Print debugging information
    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    // Allocate memory for the final value string and assign it to nameRep
    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("MUL", name1, name2, name);
        ;
    break;}
case 60:
#line 907 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
    int rhsType = yyvsp[0].actualValue.type;

    if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
    {
        writeSemanticError("Type mismatch with DIV operation, must be integers or float", yylineno);
        return 0;
    }

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        yyval.actualValue.type = FLOAT_TYPE;
        yyval.actualValue.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) / 
                  (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
        cout << "value: " << yyval.actualValue.fval << endl;
    }
    else
    {
        yyval.actualValue.type = INT_TYPE;
        yyval.actualValue.ival = lhs->value.ival / rhs->value.ival;
        cout << "value: " << yyval.actualValue.ival << endl;
    }

    stringstream valueStream;
    if (yyval.actualValue.type == FLOAT_TYPE)
    {
        valueStream << yyval.actualValue.fval;
    }
    else
    {
        valueStream << yyval.actualValue.ival;
    }
    string valueStr = valueStream.str();

    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("DIV", name1, name2, name);
        ;
    break;}
case 61:
#line 958 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
    int rhsType = yyvsp[0].actualValue.type;

    if (lhsType != INT_TYPE || rhsType != INT_TYPE)
    {
        writeSemanticError("Type mismatch with MOD operation, must be integers", yylineno);
        return 0;
    }

    yyval.actualValue.type = INT_TYPE;
    yyval.actualValue.ival = yyvsp[-2].actualValue.ival % yyvsp[0].actualValue.ival;
    cout << "value: " << yyval.actualValue.ival << endl;

    stringstream valueStream;
    valueStream << yyval.actualValue.ival;
    string valueStr = valueStream.str();

    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("MOD", name1, name2, name);
        ;
    break;}
case 63:
#line 990 "parser.y"
{
           int lhsType = yyvsp[-2].actualValue.type;
    int rhsType = yyvsp[0].actualValue.type;

    if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
    {
        writeSemanticError("Type mismatch with POW operation, must be integers or float", yylineno);
        return 0;
    }

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        yyval.actualValue.type = FLOAT_TYPE;
        yyval.actualValue.fval = (lhsType == INT_TYPE ? pow(lhs->value.ival, rhs->value.fval) : pow(lhs->value.fval, (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval)));
        cout << "value: " << yyval.actualValue.fval << endl;
    }
    else
    {
        yyval.actualValue.type = INT_TYPE;
        yyval.actualValue.ival = pow(lhs->value.ival, rhs->value.ival);
        cout << "value: " << yyval.actualValue.ival << endl;
    }

    stringstream valueStream;
    if (yyval.actualValue.type == FLOAT_TYPE)
    {
        valueStream << yyval.actualValue.fval;
    }
    else
    {
        valueStream << yyval.actualValue.ival;
    }
    string valueStr = valueStream.str();

    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", yyvsp[-2].actualValue.nameRep, yyvsp[0].actualValue.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable(yyvsp[-2].actualValue.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("POW", name1, name2, name);
        ;
    break;}
case 65:
#line 1043 "parser.y"
{ 
        // printf("Integer: %d\n", $1.ival);
        string valueStr = to_string(yyvsp[0].actualValue.ival);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        ;
    break;}
case 66:
#line 1051 "parser.y"
{ 
        string valueStr = to_string(yyvsp[0].actualValue.fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        ;
    break;}
case 68:
#line 1059 "parser.y"
{
            cout << "Identifier: " << yyvsp[0].stringVal << endl;
            SymbolTableEntry* newEntry = getIdentifierEntry(yyvsp[0].stringVal);
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
            yyval.actualValue.type = (int)newEntry->getTypeValue()->type;
            string valueStr;
            switch(yyval.actualValue.type){
                case INT_TYPE:
                    yyval.actualValue.ival = newEntry->getTypeValue()->value.ival;
                    valueStr = to_string(yyval.actualValue.ival);
                    cout << "Value string: " << valueStr << endl;
                    yyval.actualValue.nameRep = strdup(valueStr.c_str());
                    break;
                case FLOAT_TYPE:
                    yyval.actualValue.fval = newEntry->getTypeValue()->value.fval;
                    valueStr = to_string(yyval.actualValue.fval);
                    yyval.actualValue.nameRep = strdup(valueStr.c_str());
                    break;
                case STRING_TYPE:
                    yyval.actualValue.sval = newEntry->getTypeValue()->value.sval;
                    valueStr = yyval.actualValue.sval;
                    yyval.actualValue.nameRep = strdup(valueStr.c_str());
                    break;
                case BOOL_TYPE:
                    yyval.actualValue.bval = newEntry->getTypeValue()->value.bval;
                    valueStr = to_string(yyval.actualValue.bval);
                    if(yyval.actualValue.bval)
                    {
                        valueStr = "true";
                    }
                    else
                    {
                        valueStr = "false";
                    }
                    cout << "Value string: " << valueStr << endl;
                    yyval.actualValue.nameRep = strdup(valueStr.c_str());
              

                    
                    break;
                case CHAR_TYPE:
                    yyval.actualValue.cval = newEntry->getTypeValue()->value.cval;
                    valueStr = to_string(yyval.actualValue.cval);
                    yyval.actualValue.nameRep = strdup(valueStr.c_str());
                    break;
            }
        ;
    break;}
case 69:
#line 1116 "parser.y"
{yyval.actualValue = yyvsp[-1].actualValue;;
    break;}
case 70:
#line 1118 "parser.y"
{
            TypeValue * lhs;
            int lhsType = yyvsp[0].actualValue.type;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[0].actualValue, yyvsp[0].actualValue, lhs, lhs);
            switch(lhsType){
                case INT_TYPE:
                    yyvsp[0].actualValue.ival = -static_cast<int>(lhs->value.ival);
                    break;
                case FLOAT_TYPE:
                    yyvsp[0].actualValue.fval = -static_cast<float>(lhs->value.fval);
                    break;
            }
            yyval.actualValue = yyvsp[0].actualValue;
        ;
    break;}
case 71:
#line 1137 "parser.y"
{
            SymbolTableEntry* newEntry = getIdentifierEntry(yyvsp[-2].stringVal);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot assign value to constant", yylineno);
                return 0;
            }
            int idType = (int)newEntry->getTypeValue()->type;
            int valType = yyvsp[0].actualValue.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Assignment type mismatch", yylineno);
                return 0;
            }
            switch(idType){
                case INT_TYPE:
                    newEntry->getTypeValue()->value.ival = yyvsp[0].actualValue.ival;
                    break;
                case FLOAT_TYPE:
                    newEntry->getTypeValue()->value.fval = yyvsp[0].actualValue.fval;
                    break;
                case STRING_TYPE:
                    newEntry->getTypeValue()->value.sval = yyvsp[0].actualValue.sval;
                    break;
                case BOOL_TYPE:
                    newEntry->getTypeValue()->value.bval = yyvsp[0].actualValue.bval;
                    break;
                case CHAR_TYPE:
                    newEntry->getTypeValue()->value.cval = yyvsp[0].actualValue.cval;
                    break;
            }
            newEntry->setinitialization(true);
            newEntry->setused(true);

            const char* name = assemblyGenerator.getRegisterAssignment(newEntry);
            const char* VarName = assemblyGenerator.getTempVariable(yyvsp[0].actualValue.nameRep);
            assemblyGenerator.addQuadruple("ASSIGN",VarName,"",name);
        ;
    break;}
case 72:
#line 1181 "parser.y"
{
            SymbolTableEntry* newEntry = identifierScopeCheck(yyvsp[-1].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>(yyvsp[-2].lexType);
            SymbolTableEntry * entry = addEntryToCurrentTable(yyvsp[-1].stringVal, VAR, idTypeValue, false);

            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",yyvsp[-1].stringVal,"",name);


        ;
    break;}
case 74:
#line 1200 "parser.y"
{
            SymbolTableEntry* newEntry = identifierScopeCheck(yyvsp[-3].stringVal);

            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            int idType = yyvsp[-4].lexType;
            int valType = yyvsp[-1].actualValue.type;
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
                    idTypeValue->value.ival = yyvsp[-1].actualValue.ival;
                    valueStr = to_string(yyvsp[-1].actualValue.ival);
                    break;
                case FLOAT_TYPE:
                    idTypeValue->value.fval = yyvsp[-1].actualValue.fval;
                    valueStr = to_string(yyvsp[-1].actualValue.fval);
                    break;
                case STRING_TYPE:
                    idTypeValue->value.sval = yyvsp[-1].actualValue.sval;
                    valueStr = yyvsp[-1].actualValue.sval;
                    break;
                case BOOL_TYPE:
                    idTypeValue->value.bval = yyvsp[-1].actualValue.bval;
                    valueStr = to_string(yyvsp[-1].actualValue.bval);
                    break;
                case CHAR_TYPE:
                    idTypeValue->value.cval = yyvsp[-1].actualValue.cval;
                    valueStr = to_string(yyvsp[-1].actualValue.cval);
                    break;
            }
            SymbolTableEntry * entry = addEntryToCurrentTable(yyvsp[-3].stringVal, VAR, idTypeValue, true);


            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",yyvsp[-3].stringVal,"",name);
            const char* VarName = assemblyGenerator.getTempVariable(yyvsp[-1].actualValue.nameRep);
            assemblyGenerator.addQuadruple("ASSIGN",VarName,"",name);


        ;
    break;}
case 75:
#line 1252 "parser.y"
{
            SymbolTableEntry* newEntry = identifierScopeCheck(yyvsp[-3].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            int idType = yyvsp[-4].lexType;
            int valType = yyvsp[-1].actualValue.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Declaration type mismatch", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>(idType);
            switch(idTypeValue->type){
                case INT_TYPE:
                    idTypeValue->value.ival = yyvsp[-1].actualValue.ival;
                    break;
                case FLOAT_TYPE:
                    idTypeValue->value.fval = yyvsp[-1].actualValue.fval;
                    break;
                case STRING_TYPE:
                    idTypeValue->value.sval = yyvsp[-1].actualValue.sval;
                    break;
                case BOOL_TYPE:
                    idTypeValue->value.bval = yyvsp[-1].actualValue.bval;
                    break;
                case CHAR_TYPE:
                    idTypeValue->value.cval = yyvsp[-1].actualValue.cval;
                    break;
            }
            SymbolTableEntry * entry = addEntryToCurrentTable(yyvsp[-3].stringVal, CONST, idTypeValue, true);

            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",yyvsp[-3].stringVal,"",name);
            const char* VarName = assemblyGenerator.getTempVariable(yyvsp[-1].actualValue.nameRep);
            assemblyGenerator.addQuadruple("ASSIGN",VarName,"",name);
        ;
    break;}
case 76:
#line 1292 "parser.y"
{
            writeSemanticError("Constant variable not initialized ", yylineno);
            return 0;
        ;
    break;}
case 77:
#line 1300 "parser.y"
{
            if (yyvsp[0].actualValue.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        ;
    break;}
case 78:
#line 1307 "parser.y"
{ assemblyGenerator.endScope(ifScope);;
    break;}
case 80:
#line 1313 "parser.y"
{
            if (yyvsp[0].actualValue.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of ELSE IF must be boolean", yylineno);
                return 0;
            }
        ;
    break;}
case 81:
#line 1320 "parser.y"
{ 
            assemblyGenerator.endScope(elseIfScope); ;
    break;}
case 83:
#line 1325 "parser.y"
{ 
        assemblyGenerator.endScope(elseScope);;
    break;}
case 85:
#line 1331 "parser.y"
{createNewSymbolTable();
    assemblyGenerator.startScope();

;
    break;}
case 86:
#line 1334 "parser.y"
{scopeEnd();;
    break;}
case 89:
#line 1339 "parser.y"
{assemblyGenerator.endScope(caseScope);;
    break;}
case 91:
#line 1343 "parser.y"
{ 
        string valueStr = to_string(yyvsp[0].actualValue.ival);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        // $$.nameRep = strdup(valueStr.c_str());
        ;
    break;}
case 92:
#line 1350 "parser.y"
{ 
        string valueStr = to_string(yyvsp[0].actualValue.cval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        ;
    break;}
case 93:
#line 1359 "parser.y"
{
                assemblyGenerator.endScope(defaultScope);;
    break;}
case 95:
#line 1361 "parser.y"
{
                assemblyGenerator.endScope(defaultScope);;
    break;}
case 103:
#line 1378 "parser.y"
{
    printf("**************** Scope Block ****************\n");
    createNewSymbolTable();
    assemblyGenerator.startScope();
;
    break;}
case 104:
#line 1382 "parser.y"
{
    scopeEnd();
;
    break;}
case 106:
#line 1387 "parser.y"
{
            assemblyGenerator.startScope();
;
    break;}
case 107:
#line 1389 "parser.y"
{scopeEnd();;
    break;}
case 109:
#line 1395 "parser.y"
{
            string functionName = string(yyvsp[-1].stringVal) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            SymbolTableEntry *newEntry = identifierScopeCheck(yyvsp[-1].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>(yyvsp[-2].lexType);
            EntryType funcOut = static_cast<EntryType>(yyvsp[-2].lexType);
            addEntryToCurrentTable(yyvsp[-1].stringVal, FUNC, idTypeValue, true, funcOut);
            createNewSymbolTable();
            assemblyGenerator.startScope();

            
        ;
    break;}
case 110:
#line 1413 "parser.y"
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

        ;
    break;}
case 111:
#line 1426 "parser.y"
{
            string functionName = string(yyvsp[-1].stringVal) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            printf("**************** Function2 ****************\n");
            SymbolTableEntry *newEntry = identifierScopeCheck(yyvsp[-1].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>(yyvsp[-2].lexType);
            EntryType funcOut = static_cast<EntryType>(yyvsp[-2].lexType);
            addEntryToCurrentTable(yyvsp[-1].stringVal, FUNC, idTypeValue, true, funcOut);
            createNewSymbolTable();
            assemblyGenerator.startScope();


        ;
    break;}
case 112:
#line 1445 "parser.y"
{
            if(functionHasReturn == false){
                writeSemanticWarning("Function must return a value", yylineno);
            }

            scopeEnd(); 
            currentFunction = nullptr; 
            functionHasReturn = false;
            assemblyGenerator.endScope(funcScope);
            assemblyGenerator.addQuadruple("RET", "", "", "");


        ;
    break;}
case 113:
#line 1459 "parser.y"
{
            string functionName = string(yyvsp[-1].stringVal) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            SymbolTableEntry *newEntry = identifierScopeCheck(yyvsp[-1].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = VOID_DTYPE;
            addEntryToCurrentTable(yyvsp[-1].stringVal, FUNC, idTypeValue, true, VOID_DTYPE);
            createNewSymbolTable();
            assemblyGenerator.startScope();

        ;
    break;}
case 114:
#line 1474 "parser.y"
{scopeEnd(); currentFunction = nullptr;
                    assemblyGenerator.endScope(funcScope);
                    assemblyGenerator.addQuadruple("ENDFUNC", "", "", "");


        ;
    break;}
case 115:
#line 1481 "parser.y"
{
            string functionName = string(yyvsp[-1].stringVal) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            SymbolTableEntry *newEntry = identifierScopeCheck(yyvsp[-1].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = VOID_DTYPE;
            addEntryToCurrentTable(yyvsp[-1].stringVal, FUNC, idTypeValue, true, VOID_DTYPE);
            createNewSymbolTable();
            assemblyGenerator.startScope();

        ;
    break;}
case 116:
#line 1496 "parser.y"
{scopeEnd(); currentFunction = nullptr;
                    assemblyGenerator.endScope(funcScope);
                    assemblyGenerator.addQuadruple("ENDFUNC", "", "", "");

;
    break;}
case 119:
#line 1506 "parser.y"
{
            SymbolTableEntry *newEntry = identifierScopeCheck(yyvsp[0].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Already declared variable", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            EntryType paramType = static_cast<EntryType>(yyvsp[-1].lexType);
            idTypeValue->type = paramType;
            currentFunction->pushFunctionInput(paramType);
            SymbolTableEntry * entry = addEntryToCurrentTable(yyvsp[0].stringVal, PAR, idTypeValue, true);

             const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",yyvsp[0].stringVal,"",name);
            
        ;
    break;}
case 120:
#line 1523 "parser.y"
{
            SymbolTableEntry *newEntry = identifierScopeCheck(yyvsp[-2].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Already declared variable", yylineno);
                return 0;
            }
            int idType = yyvsp[-3].lexType;
            int valType = yyvsp[0].actualValue.type;
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
                    idTypeValue->value.ival = yyvsp[0].actualValue.ival;
                    break;
                case FLOAT_TYPE:
                    idTypeValue->value.fval = yyvsp[0].actualValue.fval;
                    break;
                case STRING_TYPE:
                    idTypeValue->value.sval = yyvsp[0].actualValue.sval;
                    break;
                case BOOL_TYPE:
                    idTypeValue->value.bval = yyvsp[0].actualValue.bval;
                    break;
                case CHAR_TYPE:
                    idTypeValue->value.cval = yyvsp[0].actualValue.cval;
                    break;
            }
            SymbolTableEntry * entry = addEntryToCurrentTable(yyvsp[-2].stringVal, PAR, idTypeValue, true);
             const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",yyvsp[-2].stringVal,"",name);
            
        ;
    break;}
case 121:
#line 1567 "parser.y"
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
        ;
    break;}
case 122:
#line 1579 "parser.y"
{
            if (currentFunction == nullptr)
            {
                writeSemanticError("Return should be inside function block", yylineno);
                return 0;
            }
            if(currentFunction->getFunctionOutput() != yyvsp[-1].actualValue.type){
                writeSemanticError("Return type mismatch", yylineno);
                return 0;
            }
            functionHasReturn = true;
        ;
    break;}
case 123:
#line 1592 "parser.y"
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
        ;
    break;}
case 124:
#line 1606 "parser.y"
{
            // Enter func args
            SymbolTableEntry *entry = getIdentifierEntry(yyvsp[-1].stringVal);
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
        ;
    break;}
case 125:
#line 1621 "parser.y"
{
            // End of func call
            if(functionParameters.size() != 0)
            {
                writeSemanticError("Invalid arguments size", yylineno);
                return 0;
            }
            SymbolTableEntry *entry = getIdentifierEntry(yyvsp[-4].stringVal);
            switch((int)entry->getFunctionOutput()){
                case INT_TYPE:
                    yyval.actualValue.type = INT_TYPE;
                    yyval.actualValue.ival = entry->getTypeValue()->value.ival;
                    break;
                case FLOAT_TYPE:
                    yyval.actualValue.type = FLOAT_TYPE;
                    yyval.actualValue.fval = entry->getTypeValue()->value.fval;
                    break;
                case STRING_TYPE:
                    yyval.actualValue.type = STRING_TYPE;
                    yyval.actualValue.sval = entry->getTypeValue()->value.sval;
                    break;
                case BOOL_TYPE:
                    yyval.actualValue.type = BOOL_TYPE;
                    yyval.actualValue.bval = entry->getTypeValue()->value.bval;
                    break;
                case CHAR_TYPE:
                    yyval.actualValue.type = CHAR_TYPE;
                    yyval.actualValue.cval = entry->getTypeValue()->value.cval;
                    break;
                case VOID_DTYPE:
                    yyval.actualValue.type = VOID_DTYPE;
                    break;
            }
        ;
    break;}
case 126:
#line 1656 "parser.y"
{
            SymbolTableEntry *entry = getIdentifierEntry(yyvsp[-2].stringVal);
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
                    yyval.actualValue.type = INT_TYPE;
                    yyval.actualValue.ival = entry->getTypeValue()->value.ival;
                    break;
                case FLOAT_TYPE:
                    yyval.actualValue.type = FLOAT_TYPE;
                    yyval.actualValue.fval = entry->getTypeValue()->value.fval;
                    break;
                case STRING_TYPE:
                    yyval.actualValue.type = STRING_TYPE;
                    yyval.actualValue.sval = entry->getTypeValue()->value.sval;
                    break;
                case BOOL_TYPE:
                    yyval.actualValue.type = BOOL_TYPE;
                    yyval.actualValue.bval = entry->getTypeValue()->value.bval;
                    break;
                case CHAR_TYPE:
                    yyval.actualValue.type = CHAR_TYPE;
                    yyval.actualValue.cval = entry->getTypeValue()->value.cval;
                    break;
                case VOID_DTYPE:
                    yyval.actualValue.type = VOID_DTYPE;
                    break;
            }
        ;
    break;}
case 127:
#line 1697 "parser.y"
{ 
            // Enter func args
            SymbolTableEntry *entry = getIdentifierEntry(yyvsp[-1].stringVal);
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
        ;
    break;}
case 128:
#line 1713 "parser.y"
{
            // End of func call
            if(functionParameters.size() != 0)
            {
                writeSemanticError("Invalid arguments size", yylineno);
                return 0;
            }
        ;
    break;}
case 129:
#line 1722 "parser.y"
{
            SymbolTableEntry *entry = getIdentifierEntry(yyvsp[-2].stringVal);
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
        ;
    break;}
case 130:
#line 1738 "parser.y"
{
            if(functionParameters.size() == 0)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            if((int)functionParameters.top() != (int)yyvsp[0].actualValue.type)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            functionParameters.pop();
        ;
    break;}
case 131:
#line 1752 "parser.y"
{
            if(functionParameters.size() == 0)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            if((int)functionParameters.top() != (int)yyvsp[0].actualValue.type)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            functionParameters.pop();
        ;
    break;}
case 132:
#line 1769 "parser.y"
{
            printf("========  PRINT SUCCESSFUL ***********\n");
        ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 542 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 1777 "parser.y"


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