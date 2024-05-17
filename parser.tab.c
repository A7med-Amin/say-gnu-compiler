
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
     197,   210,   207,   219,   220,   219,   230,   232,   231,   251,
     252,   253,   254,   255,   256,   260,   260,   260,   260,   260,
     262,   263,   272,   283,   290,   297,   304,   311,   318,   328,
     328,   330,   337,   343,   373,   412,   445,   478,   511,   544,
     570,   596,   622,   653,   683,   713,   743,   746,   798,   849,
     852,   908,   959,   988,   991,  1041,  1044,  1052,  1059,  1060,
    1118,  1119,  1138,  1182,  1198,  1201,  1253,  1293,  1302,  1309,
    1301,  1315,  1314,  1324,  1327,  1329,  1333,  1336,  1333,  1340,
    1341,  1341,  1346,  1353,  1363,  1363,  1366,  1369,  1373,  1374,
    1375,  1378,  1379,  1380,  1384,  1388,  1383,  1393,  1395,  1393,
    1401,  1400,  1432,  1431,  1465,  1464,  1487,  1486,  1509,  1509,
    1511,  1528,  1572,  1584,  1598,  1612,  1611,  1661,  1703,  1702,
    1727,  1743,  1757,  1774,  1778
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
            
        ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 228 "Parser.y"
    { 
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
    { 
            // printf("*********** switch block ***********\n");
            assemblyGenerator.endScope(switchScope); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 256 "Parser.y"
    { yyerror("Unexpected statement"); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 264 "Parser.y"
    {
    { 
        string valueStr = yyvsp[0].actualValue.sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        } 
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 272 "Parser.y"
    {
    { 
        char charValue = static_cast<char>(yyvsp[0].actualValue.cval);  
        string valueStr(1, charValue);  
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        } 
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 284 "Parser.y"
    {
    string valueStr = to_string((yyvsp[(1) - (1)].actualValue).ival);
    const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
    assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
    // $$.nameRep = strdup(valueStr.c_str());
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 291 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 298 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).cval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 305 "Parser.y"
    { 
        string valueStr = (yyvsp[(1) - (1)].actualValue).sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 312 "Parser.y"
    { 
        string valueStr = "true";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 319 "Parser.y"
    { 
        string valueStr = "false";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 331 "Parser.y"
    {
            // cout << "BOOLEAN_TRUE\n";
            const char* name = assemblyGenerator.addTempVariable("true" , "" , "");
            assemblyGenerator.addQuadruple("ASSIGN", "TRUE", "", name);
            (yyval.actualValue).nameRep = strdup("true");
        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 338 "Parser.y"
    {
        const char* name = assemblyGenerator.addTempVariable("false" , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", "FALSE", "", name);
        (yyval.actualValue).nameRep = strdup("false");
        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 344 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;
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
            // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            // Allocate memory for the final value string and assign it to nameRep
            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            // Add the quadruple for the EQ operation
            assemblyGenerator.addQuadruple("EQU", name1, name2, name);
        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 374 "Parser.y"
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
    // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    // Allocate memory for the final value string and assign it to nameRep
    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    // Add the quadruple for the NEQ operation
    assemblyGenerator.addQuadruple("NEQ", name1, name2, name);
        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 413 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

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

            // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("GT", name1, name2, name);
        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 446 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

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

        //    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("LT", name1, name2, name);
        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 479 "Parser.y"
    {
             int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

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

            // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("GTE", name1, name2, name);
        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 512 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

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

        //    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("LTE", name1, name2, name);
        ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 545 "Parser.y"
    {
           int varType = (yyvsp[(2) - (2)].actualValue).type;

    if (varType != BOOL_TYPE)
    {
        writeSemanticError("Type mismatch with NOT operation", yylineno);
        return 0;
    }

    yyval.actualValue.type = BOOL_TYPE;
    yyval.actualValue.bval = !yyvsp[0].actualValue.bval;

   string valueStr = yyval.actualValue.bval ? "true" : "false";

            // printf("varStr1NameRep: %s \n", $2.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(2) - (2)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            // printf("name1: %s, name: %s\n", name1, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("NOT", name1, "", name);

            
        ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 571 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;

            if (lhsType != BOOL_TYPE || rhsType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with AND operation, types must be boolean", yylineno);
                return 0;
            }

            yyval.actualValue.type = BOOL_TYPE;
            yyval.actualValue.bval = yyvsp[-2].actualValue.bval && yyvsp[0].actualValue.bval;

            string valueStr = yyval.actualValue.bval ? "true" : "false";

            // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("AND", name1, name2, name);
        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 597 "Parser.y"
    {
            int lhsType = (yyvsp[(1) - (3)].actualValue).type;
            int rhsType = (yyvsp[(3) - (3)].actualValue).type;
            if (lhsType != BOOL_TYPE || rhsType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with OR operation, types must be boolean", yylineno);
                return 0;
            }
            yyval.actualValue.type = BOOL_TYPE;
            yyval.actualValue.bval = yyvsp[-2].actualValue.bval || yyvsp[0].actualValue.bval;

            string valueStr = yyval.actualValue.bval ? "true" : "false";

            // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
            const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            yyval.actualValue.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("OR", name1, name2, name);
        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 623 "Parser.y"
    {
            // printf("INC\n");
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
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = newEntry->getTypeValue()->value.ival + 1;
            newEntry->getTypeValue()->value.ival = yyval.actualValue.ival;\

            string varStr1NameRep = yyval.actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1, "++" , "");
            yyval.actualValue.nameRep = concatenateNames(name1, "++" , "");
            assemblyGenerator.addQuadruple("INC", name1, "", name);
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 654 "Parser.y"
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
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = newEntry->getTypeValue()->value.ival - 1;
            newEntry->getTypeValue()->value.ival = yyval.actualValue.ival;

            string varStr1NameRep = yyval.actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1, "--" , "");
            yyval.actualValue.nameRep = concatenateNames(name1, "--" , "");
            assemblyGenerator.addQuadruple("DEC", name1, "", name);
        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 684 "Parser.y"
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
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = newEntry->getTypeValue()->value.ival + 1;
            newEntry->getTypeValue()->value.ival = yyval.actualValue.ival;

            string varStr1NameRep = yyval.actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable("++", name1 , "");
            yyval.actualValue.nameRep = concatenateNames("++", name1 , "");
            assemblyGenerator.addQuadruple("INC", name1, "", name);
        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 714 "Parser.y"
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
            yyval.actualValue.type = INT_TYPE;
            yyval.actualValue.ival = newEntry->getTypeValue()->value.ival - 1;
            newEntry->getTypeValue()->value.ival = yyval.actualValue.ival;

            string varStr1NameRep = yyval.actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable("--", name1 , "");
            yyval.actualValue.nameRep = concatenateNames("--", name1 , "");
            assemblyGenerator.addQuadruple("DEC", name1, "", name);
        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 747 "Parser.y"
    {
            // cout << " ------------- ADD -------------" << endl;
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
        GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

        if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
        {
            yyval.actualValue.type = FLOAT_TYPE;
            yyval.actualValue.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) + 
                    (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
            // cout << "value: " << $$.fval << endl;
        }
        else
        {
            (yyval.actualValue).type = INT_TYPE;
            (yyval.actualValue).ival = lhs->value.ival + rhs->value.ival;
            // cout << "value: " << $$.ival << endl;
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

        // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
        const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
        const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
        const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
        // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

        yyval.actualValue.nameRep = strdup(valueStr.c_str());

        assemblyGenerator.addQuadruple("ADD", name1, name2, name);
        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 799 "Parser.y"
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
        GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

        if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
        {
            yyval.actualValue.type = FLOAT_TYPE;
            yyval.actualValue.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) - 
                    (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
            // cout << "value: " << $$.fval << endl;
        }
        else
        {
            (yyval.actualValue).type = INT_TYPE;
            (yyval.actualValue).ival = lhs->value.ival - rhs->value.ival;
            // cout << "value: " << $$.ival << endl;
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

        // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
        const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
        const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
        const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
        // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

        yyval.actualValue.nameRep = strdup(valueStr.c_str());

        assemblyGenerator.addQuadruple("SUB", name1, name2, name);
        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 853 "Parser.y"
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
    GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

    // Calculate the final value based on the types
    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        yyval.actualValue.type = FLOAT_TYPE;
        yyval.actualValue.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) * 
                  (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
        // cout << "value: " << $$.fval << endl;
    }
    else
    {
        (yyval.actualValue).type = INT_TYPE;
        (yyval.actualValue).ival = lhs->value.ival * rhs->value.ival;
        // cout << "value: " << $$.ival << endl;
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
    // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    // Allocate memory for the final value string and assign it to nameRep
    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("MUL", name1, name2, name);
        ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 909 "Parser.y"
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
    GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        yyval.actualValue.type = FLOAT_TYPE;
        yyval.actualValue.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) / 
                  (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
        // cout << "value: " << $$.fval << endl;
    }
    else
    {
        (yyval.actualValue).type = INT_TYPE;
        (yyval.actualValue).ival = lhs->value.ival / rhs->value.ival;
        // cout << "value: " << $$.ival << endl;
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

    // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("DIV", name1, name2, name);
        ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 960 "Parser.y"
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
    // cout << "value: " << $$.ival << endl;

    stringstream valueStream;
    valueStream << yyval.actualValue.ival;
    string valueStr = valueStream.str();

    // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("MOD", name1, name2, name);
        ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 992 "Parser.y"
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
    GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);

    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        (yyval.actualValue).type = FLOAT_TYPE;
        (yyval.actualValue).fval = (lhsType == INT_TYPE ? pow(lhs->value.ival, rhs->value.fval) : pow(lhs->value.fval, (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval)));
        // cout << "value: " << $$.fval << endl;
    }
    else
    {
        (yyval.actualValue).type = INT_TYPE;
        (yyval.actualValue).ival = pow(lhs->value.ival, rhs->value.ival);
        // cout << "value: " << $$.ival << endl;
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

    // printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable((yyvsp[(1) - (3)].actualValue).nameRep);
    const char* name2 = assemblyGenerator.getTempVariable((yyvsp[(3) - (3)].actualValue).nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    // printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    yyval.actualValue.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("POW", name1, name2, name);
        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1045 "Parser.y"
    { 
        // printf("Integer: %d\n", $1.ival);
        string valueStr = to_string(yyvsp[0].actualValue.ival);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
        ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1053 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
        ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1061 "Parser.y"
    {
            // cout << "Identifier: " << $1 << endl;
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
            yyval.actualValue.type = (int)newEntry->getTypeValue()->type;
            string valueStr;
            switch(yyval.actualValue.type){
                case INT_TYPE:
                    (yyval.actualValue).ival = newEntry->getTypeValue()->value.ival;
                    valueStr = to_string((yyval.actualValue).ival);
                    // cout << "Value string: " << valueStr << endl;
                    (yyval.actualValue).nameRep = strdup(valueStr.c_str());
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
                    // cout << "Value string: " << valueStr << endl;
                    (yyval.actualValue).nameRep = strdup(valueStr.c_str());
              

                    
                    break;
                case CHAR_TYPE:
                    yyval.actualValue.cval = newEntry->getTypeValue()->value.cval;
                    valueStr = to_string(yyval.actualValue.cval);
                    yyval.actualValue.nameRep = strdup(valueStr.c_str());
                    break;
            }
        ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1118 "Parser.y"
    {(yyval.actualValue) = (yyvsp[(2) - (3)].actualValue);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1120 "Parser.y"
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
            (yyval.actualValue) = (yyvsp[(2) - (2)].actualValue);
        ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1139 "Parser.y"
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
        ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1183 "Parser.y"
    {
            SymbolTableEntry* newEntry = identifierScopeCheck((yyvsp[(2) - (3)].stringVal));
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>(yyvsp[-2].lexType);
            SymbolTableEntry * entry = addEntryToCurrentTable(yyvsp[-1].stringVal, VAR, idTypeValue, false);

            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",yyvsp[-1].stringVal,"",name);


        ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1202 "Parser.y"
    {
            SymbolTableEntry* newEntry = identifierScopeCheck((yyvsp[(2) - (5)].stringVal));

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


        ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1254 "Parser.y"
    {
            SymbolTableEntry* newEntry = identifierScopeCheck((yyvsp[(3) - (6)].stringVal));
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
        ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1294 "Parser.y"
    {
            writeSemanticError("Constant variable not initialized ", yylineno);
            return 0;
        ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1302 "Parser.y"
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
#line 1309 "Parser.y"
    { assemblyGenerator.endScope(ifScope);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1315 "Parser.y"
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
#line 1322 "Parser.y"
    { 
            assemblyGenerator.endScope(elseIfScope); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1327 "Parser.y"
    { 
        assemblyGenerator.endScope(elseScope);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1333 "Parser.y"
    {createNewSymbolTable();
    assemblyGenerator.startScope();

;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1336 "Parser.y"
    {scopeEnd();;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1341 "Parser.y"
    {
        // printf("******************* caseExpression *******************\n"); 
        assemblyGenerator.endScope(caseScope);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1347 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).ival);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
        ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1354 "Parser.y"
    { 
        string valueStr = to_string((yyvsp[(1) - (1)].actualValue).cval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        (yyval.actualValue).nameRep = strdup(valueStr.c_str());
        ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1363 "Parser.y"
    {
                // printf("******************* caseDefault *******************\n");
                assemblyGenerator.endScope(defaultScope);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1366 "Parser.y"
    {
                // printf("******************* caseDefault *******************\n");
                assemblyGenerator.endScope(defaultScope); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1384 "Parser.y"
    {
    // printf("**************** Scope Block ****************\n");
    createNewSymbolTable();
    assemblyGenerator.startScope();
;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1388 "Parser.y"
    {
    scopeEnd();
;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1393 "Parser.y"
    {
            assemblyGenerator.startScope();
;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1395 "Parser.y"
    {scopeEnd();;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1401 "Parser.y"
    {
            string functionName = string((yyvsp[(2) - (3)].stringVal)) + ":";
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

            
        ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1419 "Parser.y"
    {
            // printf("**************** Function1 ****************\n");
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
#line 1432 "Parser.y"
    {
            string functionName = string((yyvsp[(2) - (3)].stringVal)) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            // printf("**************** Function2 ****************\n");
            SymbolTableEntry *newEntry = identifierScopeCheck((yyvsp[(2) - (3)].stringVal));
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


        ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1451 "Parser.y"
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
#line 1465 "Parser.y"
    {
            string functionName = string((yyvsp[(2) - (3)].stringVal)) + ":";
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

        ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1480 "Parser.y"
    {scopeEnd(); currentFunction = nullptr;
                    assemblyGenerator.endScope(funcScope);
                    assemblyGenerator.addQuadruple("ENDFUNC", "", "", "");


        ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1487 "Parser.y"
    {
            string functionName = string((yyvsp[(2) - (3)].stringVal)) + ":";
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

        ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1502 "Parser.y"
    {scopeEnd(); currentFunction = nullptr;
                    assemblyGenerator.endScope(funcScope);
                    assemblyGenerator.addQuadruple("ENDFUNC", "", "", "");

;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1512 "Parser.y"
    {
            SymbolTableEntry *newEntry = identifierScopeCheck((yyvsp[(2) - (2)].stringVal));
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
            
        ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1529 "Parser.y"
    {
            SymbolTableEntry *newEntry = identifierScopeCheck((yyvsp[(2) - (4)].stringVal));
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
            
        ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1573 "Parser.y"
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
#line 1585 "Parser.y"
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
        ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1598 "Parser.y"
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
#line 1612 "Parser.y"
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
        ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1627 "Parser.y"
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
        ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1662 "Parser.y"
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
        ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1703 "Parser.y"
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
        ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1719 "Parser.y"
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
#line 1728 "Parser.y"
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
#line 1744 "Parser.y"
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
        ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1758 "Parser.y"
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
        ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1775 "Parser.y"
    {
            // printf("========  PRINT SUCCESSFUL ***********\n");
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 3719 "Parser.tab.c"
      default: break;
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



/* Line 1675 of yacc.c  */
#line 1783 "Parser.y"


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