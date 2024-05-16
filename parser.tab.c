
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



#define	YYFINAL		244
#define	YYFLAG		-32768
#define	YYNTBASE	54

#define YYTRANSLATE(x) ((unsigned)(x) <= 300 ? yytranslate[x] : 109)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
    48,     2,     2,    53,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    52,    49,     2,
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
     0,     1,     3,     5,     8,    10,    12,    14,    15,    22,
    23,    32,    33,    34,    44,    46,    47,    54,    56,    62,
    64,    67,    69,    71,    73,    75,    77,    79,    81,    83,
    85,    87,    89,    91,    93,    95,    97,    99,   101,   103,
   105,   107,   111,   115,   119,   123,   127,   131,   134,   138,
   142,   145,   148,   151,   154,   156,   160,   164,   166,   170,
   174,   178,   180,   184,   186,   188,   190,   192,   194,   198,
   203,   207,   209,   215,   222,   227,   228,   229,   239,   240,
   249,   250,   253,   254,   255,   256,   262,   264,   272,   274,
   276,   282,   286,   287,   289,   291,   293,   298,   301,   303,
   304,   305,   311,   312,   317,   318,   328,   329,   338,   339,
   349,   350,   359,   363,   365,   368,   373,   376,   380,   381,
   382,   388,   392,   393,   399,   403,   407,   409,   413
};

static const short yyrhs[] = {    -1,
    55,     0,    56,     0,    55,    56,     0,    73,     0,    75,
     0,    72,     0,     0,    15,    47,    65,    57,    48,    90,
     0,     0,    17,    90,    18,    47,    65,    58,    48,    49,
     0,     0,     0,    16,    47,    59,    88,    65,    60,    89,
    48,    93,     0,    76,     0,     0,    12,    47,    21,    61,
    48,    82,     0,    90,     0,    46,    47,   108,    48,    49,
     0,    95,     0,   105,    49,     0,   102,     0,     1,     0,
     3,     0,     4,     0,     5,     0,     6,     0,     7,     0,
    65,     0,    27,     0,    26,     0,    24,     0,    25,     0,
    26,     0,    27,     0,    22,     0,    23,     0,    67,     0,
    66,     0,    22,     0,    23,     0,    65,    40,    67,     0,
    65,    41,    67,     0,    65,    42,    67,     0,    65,    43,
    67,     0,    65,    44,    67,     0,    65,    45,    67,     0,
    39,    65,     0,    65,    37,    65,     0,    65,    38,    65,
     0,    21,    33,     0,    21,    34,     0,    33,    21,     0,
    34,    21,     0,    68,     0,    68,    28,    69,     0,    68,
    29,    69,     0,    69,     0,    69,    30,    70,     0,    69,
    31,    70,     0,    69,    32,    70,     0,    70,     0,    70,
    35,    71,     0,    71,     0,    24,     0,    25,     0,   103,
     0,    21,     0,    47,    65,    48,     0,    21,    36,    63,
    49,     0,    62,    21,    49,     0,    74,     0,    62,    21,
    36,    63,    49,     0,     8,    62,    21,    36,    64,    49,
     0,     8,    62,    21,    49,     0,     0,     0,    10,    47,
    65,    77,    48,    90,    78,    79,    81,     0,     0,    79,
    11,    10,    47,    65,    80,    48,    90,     0,     0,    11,
    90,     0,     0,     0,     0,    50,    83,    85,    84,    51,
     0,    87,     0,    13,    86,    52,    55,    19,    49,    85,
     0,    24,     0,    26,     0,    14,    52,    55,    19,    49,
     0,    14,    52,    55,     0,     0,    72,     0,    74,     0,
    49,     0,    49,    21,    36,    65,     0,    49,    65,     0,
    49,     0,     0,     0,    50,    91,    55,    92,    51,     0,
     0,    50,    55,    94,    51,     0,     0,    62,    21,    47,
    96,   100,    48,    50,    55,    51,     0,     0,    62,    21,
    47,    97,    48,    50,    55,    51,     0,     0,     9,    21,
    47,    98,   100,    48,    50,    55,    51,     0,     0,     9,
    21,    47,    99,    48,    50,    55,    51,     0,   101,    53,
   100,     0,   101,     0,    62,    21,     0,    62,    21,    36,
    64,     0,    20,    49,     0,    20,    63,    49,     0,     0,
     0,    21,    47,   104,   107,    48,     0,    21,    47,    48,
     0,     0,    21,    47,   106,   107,    48,     0,    21,    47,
    48,     0,   107,    53,    63,     0,    63,     0,    63,    53,
   108,     0,    63,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   151,   152,   190,   191,   194,   195,   196,   197,   205,   206,
   214,   215,   215,   223,   224,   225,   242,   243,   244,   245,
   246,   247,   248,   252,   252,   252,   252,   252,   254,   255,
   264,   275,   282,   289,   296,   303,   310,   320,   320,   322,
   328,   334,   358,   382,   406,   430,   454,   478,   497,   517,
   539,   569,   599,   629,   659,   662,   708,   754,   757,   803,
   849,   869,   872,   919,   923,   930,   937,   938,   981,   985,
  1029,  1045,  1048,  1100,  1140,  1148,  1156,  1159,  1162,  1170,
  1172,  1175,  1177,  1181,  1181,  1182,  1184,  1186,  1189,  1189,
  1192,  1194,  1195,  1199,  1200,  1201,  1204,  1205,  1206,  1209,
  1214,  1217,  1219,  1220,  1224,  1236,  1245,  1257,  1266,  1277,
  1278,  1289,  1292,  1292,  1294,  1307,  1348,  1360,  1373,  1387,
  1402,  1437,  1478,  1494,  1503,  1519,  1533,  1550,  1554
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","INT_DATA_TYPE",
"FLOAT_DATA_TYPE","CHAR_DATA_TYPE","STRING_DATA_TYPE","BOOLEAN_DATA_TYPE","CONSTANT",
"VOID_TYPE","IF","ELSE","SWITCH","CASE","DEFAULT","WHILE","FOR","REPEAT","UNTIL",
"BREAK","RETURN","IDENTIFIER","BOOLEAN_TRUE","BOOLEAN_FALSE","INTEGER_VALUE",
"FLOATING","CHARACTER","STRING_LITERAL","ADD","SUB","MUL","DIV","MOD","INC",
"DEC","POW","ASSIGN","AND","OR","NOT","EQ","NEQ","GT","LT","GTE","LTE","PRINT",
"'('","')'","';'","'{'","'}'","':'","','","program","codeBlock","codeStatement",
"@1","@2","@3","@4","@5","dataType","dataValue","constantValue","expression",
"boolean","arithmetic","complexArithmetic","minorTerm","majorTerm","instance",
"assignment","variableDeclaration","variableDeclarationWithAssignment","constantDeclaration",
"ifCondition","@6","@7","elseIfCondition","@8","elseStmnt","switchBlock","@9",
"@10","caseExpression","switchValidValue","caseDefault","forLoopInitialization",
"forLoopItter","scopeBlock","@11","@12","loopsScopeBlock","@13","function","@14",
"@15","@16","@17","ArgList","Arg","ReturnCase","TypedFunctionCall","@18","VoidFunctionCall",
"@19","CallList","printStatement", NULL
};
#endif

static const short yyr1[] = {     0,
    54,    54,    55,    55,    56,    56,    56,    57,    56,    58,
    56,    59,    60,    56,    56,    61,    56,    56,    56,    56,
    56,    56,    56,    62,    62,    62,    62,    62,    63,    63,
    63,    64,    64,    64,    64,    64,    64,    65,    65,    66,
    66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
    67,    67,    67,    67,    67,    68,    68,    68,    69,    69,
    69,    69,    70,    70,    71,    71,    71,    71,    71,    72,
    73,    73,    74,    75,    75,    77,    78,    76,    80,    79,
    79,    81,    81,    83,    84,    82,    85,    85,    86,    86,
    87,    87,    87,    88,    88,    88,    89,    89,    89,    91,
    92,    90,    94,    93,    96,    95,    97,    95,    98,    95,
    99,    95,   100,   100,   101,   101,   102,   102,   102,   104,
   103,   103,   106,   105,   105,   107,   107,   108,   108
};

static const short yyr2[] = {     0,
     0,     1,     1,     2,     1,     1,     1,     0,     6,     0,
     8,     0,     0,     9,     1,     0,     6,     1,     5,     1,
     2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     3,     3,     3,     3,     3,     3,     2,     3,     3,
     2,     2,     2,     2,     1,     3,     3,     1,     3,     3,
     3,     1,     3,     1,     1,     1,     1,     1,     3,     4,
     3,     1,     5,     6,     4,     0,     0,     9,     0,     8,
     0,     2,     0,     0,     0,     5,     1,     7,     1,     1,
     5,     3,     0,     1,     1,     1,     4,     2,     1,     0,
     0,     5,     0,     4,     0,     9,     0,     8,     0,     9,
     0,     8,     3,     1,     2,     4,     2,     3,     0,     0,
     5,     3,     0,     5,     3,     3,     1,     3,     1
};

static const short yydefact[] = {     0,
    23,    24,    25,    26,    27,    28,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   100,     0,     3,     0,
     7,     5,    72,     6,    15,    18,    20,    22,     0,     0,
     0,     0,     0,     0,    12,     0,    68,    40,    41,    65,
    66,    31,    30,     0,     0,     0,     0,   117,     0,    29,
    39,    38,    55,    58,    62,    64,    67,     0,   123,     0,
     0,     4,     0,    21,     0,   109,    76,    16,     8,     0,
     0,    51,    52,   120,    53,    54,    48,     0,   118,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   125,     0,   129,     0,     0,     0,
   105,    71,     0,    75,     0,     0,     0,     0,     0,     0,
    96,     0,    94,    95,     0,     0,   122,     0,    69,    49,
    50,    42,    43,    44,    45,    46,    47,    68,    56,    57,
    59,    60,    61,    63,    70,   127,     0,     0,     0,     0,
     0,     0,     0,    36,    37,    32,    33,    34,    35,     0,
     0,     0,   114,     0,     0,     0,     0,     0,    13,    10,
     0,   124,     0,   128,    19,   102,    73,     0,     0,    74,
   115,     0,     0,     0,    77,    84,    17,     9,     0,     0,
   121,   126,     0,     0,     0,     0,   113,     0,    81,    93,
    99,     0,     0,     0,     0,   116,     0,   112,    83,     0,
     0,    85,    87,    68,    98,     0,    11,     0,   108,   110,
     0,    78,    89,    90,     0,     0,     0,     0,     0,    14,
   106,     0,    82,     0,     0,    86,    97,     0,     0,     0,
     0,     0,    79,     0,    91,   104,     0,    93,     0,    88,
    80,     0,     0,     0
};

static const short yydefgoto[] = {   242,
    18,    19,   109,   180,    70,   179,   108,    20,    97,   150,
    50,    51,    52,    53,    54,    55,    56,    21,    22,    23,
    24,    25,   107,   189,   199,   237,   212,   177,   190,   217,
   202,   215,   203,   115,   192,    26,    61,   140,   220,   232,
    27,   142,   143,   105,   106,   152,   153,    28,    57,   118,
    29,    96,   137,    98
};

static const short yypact[] = {   215,
-32768,-32768,-32768,-32768,-32768,-32768,   504,   -15,   -32,   -28,
   -16,    22,    14,    50,    34,    31,-32768,   237,-32768,    69,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    39,    73,
    51,   112,    79,   112,-32768,    88,    46,-32768,-32768,-32768,
-32768,-32768,-32768,    86,   100,   112,   112,-32768,    80,   501,
-32768,-32768,    32,   117,    90,-32768,-32768,   479,    83,   479,
   265,-32768,     5,-32768,    10,    91,   501,-32768,   501,     7,
    94,-32768,-32768,    95,-32768,-32768,-32768,   492,-32768,   112,
   112,    71,    71,    71,    71,    71,    71,    18,    18,    18,
    18,    18,    18,   101,-32768,   479,    99,   115,   287,   479,
   116,-32768,   150,-32768,   504,   131,   133,   134,   141,   124,
-32768,   169,-32768,-32768,   112,   112,-32768,   479,-32768,   507,
   507,-32768,-32768,-32768,-32768,-32768,-32768,   145,   117,   117,
    90,    90,    90,-32768,-32768,-32768,   -18,   479,   144,   143,
   148,   504,   152,-32768,-32768,-32768,-32768,-32768,-32768,   161,
   191,   166,   164,   178,    14,   179,    14,   197,   501,   501,
     9,-32768,   479,-32768,-32768,-32768,-32768,   186,   189,-32768,
   212,   200,   504,   265,-32768,-32768,-32768,-32768,   202,   207,
-32768,-32768,   206,   265,   150,   265,-32768,   319,-32768,    89,
   162,   211,   213,   265,   340,-32768,   372,-32768,   249,    29,
   224,-32768,-32768,    11,   501,   214,-32768,   393,-32768,-32768,
    -2,-32768,-32768,-32768,   226,    17,   216,   112,   265,-32768,
-32768,   232,-32768,   446,   107,-32768,   501,   425,   112,   478,
   235,   238,   501,   251,-32768,-32768,   250,    89,    14,-32768,
-32768,   263,   301,-32768
};

static const short yypgoto[] = {-32768,
   -54,   -17,-32768,-32768,-32768,-32768,-32768,    -4,    -9,   121,
   -30,-32768,   120,-32768,    67,    76,   217,   239,-32768,   242,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    75,-32768,-32768,-32768,-32768,   -13,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  -133,-32768,-32768,-32768,-32768,
-32768,-32768,   187,   176
};


#define	YYLAST		552


static const short yytable[] = {    36,
    62,    67,    30,    69,    49,    31,    99,   222,   168,     2,
     3,     4,     5,     6,    32,    77,    78,     1,    33,     2,
     3,     4,     5,     6,     7,     8,     9,   110,    10,   162,
    34,    11,    12,    13,   163,  -119,    14,    15,   128,   187,
   100,    40,    41,    72,    73,   103,   218,    17,    94,   120,
   121,   101,   213,   102,   214,   111,   181,    74,   104,    88,
    89,   163,    16,    17,    47,   112,    17,  -119,    35,    58,
    37,    38,    39,    40,    41,    42,    43,    60,    72,    73,
    59,    62,    44,    45,   159,   160,   136,    64,    46,    63,
   141,    37,    74,    65,    40,    41,    47,    66,    48,    68,
   151,   200,   201,    44,    45,    71,    75,     1,   136,     2,
     3,     4,     5,     6,     7,     8,     9,    47,    10,   188,
    76,    11,    12,    13,    93,   231,    14,    15,    79,   195,
    95,   197,    37,    38,    39,    40,    41,   151,  -111,   208,
   116,   175,   117,   178,    44,    45,    90,    91,    92,   135,
    46,   138,    16,   182,   129,   130,    17,   -92,    47,    58,
   205,   225,   139,  -107,   228,   131,   132,   133,   151,   230,
    62,   144,   145,   146,   147,   148,   149,    62,   154,    62,
   155,   156,   204,    38,    39,    40,    41,   227,   157,   158,
    62,    74,   165,   166,    44,    45,   167,   223,   233,   169,
    46,   122,   123,   124,   125,   126,   127,    62,    47,   170,
    62,   171,    62,   172,    -1,     1,   173,     2,     3,     4,
     5,     6,     7,     8,     9,   241,    10,   174,   176,    11,
    12,    13,   100,   183,    14,    15,    -2,     1,   184,     2,
     3,     4,     5,     6,     7,     8,     9,   185,    10,   186,
   191,    11,    12,    13,   193,   194,    14,    15,   206,   211,
    16,   207,   243,   219,    17,     1,   226,     2,     3,     4,
     5,     6,     7,     8,     9,   216,    10,   224,   229,    11,
    12,    13,    16,   235,    14,    15,    17,     1,   236,     2,
     3,     4,     5,     6,     7,     8,     9,   239,    10,   238,
   244,    11,    12,    13,   161,   196,    14,    15,   113,   134,
    16,   114,   240,   164,    17,  -119,     0,     0,     0,     1,
     0,     2,     3,     4,     5,     6,     7,     8,     9,     0,
    10,     0,    16,    11,    12,    13,    17,  -101,    14,    15,
     1,     0,     2,     3,     4,     5,     6,     7,     8,     9,
     0,    10,     0,     0,    11,    12,    13,     0,     0,    14,
    15,     0,     0,     0,    16,     0,     0,     0,    17,   198,
     0,     0,     1,     0,     2,     3,     4,     5,     6,     7,
     8,     9,     0,    10,     0,    16,    11,    12,    13,    17,
   209,    14,    15,     1,     0,     2,     3,     4,     5,     6,
     7,     8,     9,     0,    10,     0,     0,    11,    12,    13,
     0,     0,    14,    15,     0,     0,     0,    16,     0,     0,
     0,    17,   210,     0,     0,     1,     0,     2,     3,     4,
     5,     6,     7,     8,     9,     0,    10,     0,    16,    11,
    12,    13,    17,   221,    14,    15,     1,     0,     2,     3,
     4,     5,     6,     7,     8,     9,     0,    10,     0,     0,
    11,    12,    13,     0,  -119,    14,    15,     0,     0,     0,
    16,     0,     0,     0,    17,  -103,     0,     0,     1,     0,
     2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
     0,    16,    11,    12,    13,    17,   234,    14,    15,    37,
    38,    39,    40,    41,    42,    43,     2,     3,     4,     5,
     6,    44,    45,     0,     0,     0,     0,    46,     0,     0,
     0,     0,     0,    16,     0,    47,     0,    17,    80,    81,
     0,    82,    83,    84,    85,    86,    87,    80,    81,   119,
    82,    83,    84,    85,    86,    87,    82,    83,    84,    85,
    86,    87
};

static const short yycheck[] = {    13,
    18,    32,     7,    34,    14,    21,    61,    10,   142,     3,
     4,     5,     6,     7,    47,    46,    47,     1,    47,     3,
     4,     5,     6,     7,     8,     9,    10,    21,    12,    48,
    47,    15,    16,    17,    53,    19,    20,    21,    21,   173,
    36,    24,    25,    33,    34,    36,    36,    50,    58,    80,
    81,    47,    24,    49,    26,    49,    48,    47,    49,    28,
    29,    53,    46,    50,    47,    70,    50,    51,    47,    36,
    21,    22,    23,    24,    25,    26,    27,    47,    33,    34,
    47,    99,    33,    34,   115,   116,    96,    49,    39,    21,
   100,    21,    47,    21,    24,    25,    47,    47,    49,    21,
   105,    13,    14,    33,    34,    18,    21,     1,   118,     3,
     4,     5,     6,     7,     8,     9,    10,    47,    12,   174,
    21,    15,    16,    17,    35,    19,    20,    21,    49,   184,
    48,   186,    21,    22,    23,    24,    25,   142,    48,   194,
    47,   155,    48,   157,    33,    34,    30,    31,    32,    49,
    39,    53,    46,   163,    88,    89,    50,    51,    47,    36,
   191,   216,    48,    48,   219,    90,    91,    92,   173,   224,
   188,    22,    23,    24,    25,    26,    27,   195,    48,   197,
    48,    48,    21,    22,    23,    24,    25,   218,    48,    21,
   208,    47,    49,    51,    33,    34,    49,   211,   229,    48,
    39,    82,    83,    84,    85,    86,    87,   225,    47,    49,
   228,    21,   230,    48,     0,     1,    53,     3,     4,     5,
     6,     7,     8,     9,    10,   239,    12,    50,    50,    15,
    16,    17,    36,    48,    20,    21,     0,     1,    50,     3,
     4,     5,     6,     7,     8,     9,    10,    36,    12,    50,
    49,    15,    16,    17,    48,    50,    20,    21,    48,    11,
    46,    49,     0,    50,    50,     1,    51,     3,     4,     5,
     6,     7,     8,     9,    10,    52,    12,    52,    47,    15,
    16,    17,    46,    49,    20,    21,    50,     1,    51,     3,
     4,     5,     6,     7,     8,     9,    10,    48,    12,    49,
     0,    15,    16,    17,   118,   185,    20,    21,    70,    93,
    46,    70,   238,   138,    50,    51,    -1,    -1,    -1,     1,
    -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
    12,    -1,    46,    15,    16,    17,    50,    51,    20,    21,
     1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
    -1,    12,    -1,    -1,    15,    16,    17,    -1,    -1,    20,
    21,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
     9,    10,    -1,    12,    -1,    46,    15,    16,    17,    50,
    51,    20,    21,     1,    -1,     3,     4,     5,     6,     7,
     8,     9,    10,    -1,    12,    -1,    -1,    15,    16,    17,
    -1,    -1,    20,    21,    -1,    -1,    -1,    46,    -1,    -1,
    -1,    50,    51,    -1,    -1,     1,    -1,     3,     4,     5,
     6,     7,     8,     9,    10,    -1,    12,    -1,    46,    15,
    16,    17,    50,    51,    20,    21,     1,    -1,     3,     4,
     5,     6,     7,     8,     9,    10,    -1,    12,    -1,    -1,
    15,    16,    17,    -1,    19,    20,    21,    -1,    -1,    -1,
    46,    -1,    -1,    -1,    50,    51,    -1,    -1,     1,    -1,
     3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
    -1,    46,    15,    16,    17,    50,    19,    20,    21,    21,
    22,    23,    24,    25,    26,    27,     3,     4,     5,     6,
     7,    33,    34,    -1,    -1,    -1,    -1,    39,    -1,    -1,
    -1,    -1,    -1,    46,    -1,    47,    -1,    50,    37,    38,
    -1,    40,    41,    42,    43,    44,    45,    37,    38,    48,
    40,    41,    42,    43,    44,    45,    40,    41,    42,    43,
    44,    45
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
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        ;
    break;}
case 10:
#line 207 "parser.y"
{
            if (yyvsp[0].actualValue.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        ;
    break;}
case 12:
#line 215 "parser.y"
{createNewSymbolTable();;
    break;}
case 13:
#line 216 "parser.y"
{
            if (yyvsp[0].actualValue.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of FOR must be boolean", yylineno);
                return 0;
            }
        ;
    break;}
case 16:
#line 226 "parser.y"
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
case 23:
#line 248 "parser.y"
{ yyerror("Unexpected statement"); ;
    break;}
case 30:
#line 256 "parser.y"
{
    { 
        string valueStr = yyvsp[0].actualValue.sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        } 
;
    break;}
case 31:
#line 264 "parser.y"
{
    { 
        char charValue = static_cast<char>(yyvsp[0].actualValue.cval);  
        string valueStr(1, charValue);  
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        } 
;
    break;}
case 32:
#line 276 "parser.y"
{
    string valueStr = to_string(yyvsp[0].actualValue.ival);
    const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
    assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
    yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 33:
#line 283 "parser.y"
{ 
        string valueStr = to_string(yyvsp[0].actualValue.fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 34:
#line 290 "parser.y"
{ 
        string valueStr = to_string(yyvsp[0].actualValue.cval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 35:
#line 297 "parser.y"
{ 
        string valueStr = yyvsp[0].actualValue.sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 36:
#line 304 "parser.y"
{ 
        string valueStr = "TRUE";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 37:
#line 311 "parser.y"
{ 
        string valueStr = "FALSE";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
;
    break;}
case 40:
#line 323 "parser.y"
{
            const char* name = assemblyGenerator.addTempVariable("TRUE" , "" , "");
            assemblyGenerator.addQuad("ASSIGN", "TRUE", "", name);
            yyval.actualValue.nameRep = strdup("TRUE");
        ;
    break;}
case 41:
#line 329 "parser.y"
{
        const char* name = assemblyGenerator.addTempVariable("FALSE" , "" , "");
        assemblyGenerator.addQuad("ASSIGN", "FALSE", "", name);
        yyval.actualValue.nameRep = strdup("FALSE");
        ;
    break;}
case 42:
#line 335 "parser.y"
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

            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "==" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "==", name2);
            assemblyGenerator.addQuad("EQU", name1, name2, name);
        ;
    break;}
case 43:
#line 359 "parser.y"
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
            yyval.actualValue.bval = checkEqualityNot(lhs, rhs);

            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "!=" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "!=", name2);
            assemblyGenerator.addQuad("NEQ", name1, name2, name);
        ;
    break;}
case 44:
#line 383 "parser.y"
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
            yyval.actualValue.bval = checkEqualityGT(lhs, rhs);

                        string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , ">" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , ">", name2);
            assemblyGenerator.addQuad("GT", name1, name2, name);
        ;
    break;}
case 45:
#line 407 "parser.y"
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

            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "<" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "<", name2);
            assemblyGenerator.addQuad("LT", name1, name2, name);
        ;
    break;}
case 46:
#line 431 "parser.y"
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
            yyval.actualValue.bval = checkEqualityGTE(lhs, rhs);

            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , ">=" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , ">=", name2);
            assemblyGenerator.addQuad("GTE", name1, name2, name);
        ;
    break;}
case 47:
#line 455 "parser.y"
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

            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "<=" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "<=", name2);
            assemblyGenerator.addQuad("LTE", name1, name2, name);
        ;
    break;}
case 48:
#line 479 "parser.y"
{
            int varType = yyvsp[0].actualValue.type;
            if (varType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with NOT operation", yylineno);
                return 0;
            }
            yyval.actualValue.type = BOOL_TYPE;
            yyval.actualValue.bval = !yyvsp[0].actualValue.bval;

            string varStr1NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable("!", name1, "");
            yyval.actualValue.nameRep = concatenateNames("!", name1, "");
            assemblyGenerator.addQuad("NOT", name1, "", name);

            
        ;
    break;}
case 49:
#line 498 "parser.y"
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

            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "&&" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "&&", name2);
            assemblyGenerator.addQuad("AND", name1, name2, name);
        ;
    break;}
case 50:
#line 518 "parser.y"
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

            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "&&" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "||", name2);
            assemblyGenerator.addQuad("OR", name1, name2, name);
        ;
    break;}
case 51:
#line 540 "parser.y"
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
            assemblyGenerator.addQuad("INC", name1, "", name);
        ;
    break;}
case 52:
#line 570 "parser.y"
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
            assemblyGenerator.addQuad("DEC", name1, "", name);
        ;
    break;}
case 53:
#line 600 "parser.y"
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
            assemblyGenerator.addQuad("INC", name1, "", name);
        ;
    break;}
case 54:
#line 630 "parser.y"
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
            assemblyGenerator.addQuad("DEC", name1, "", name);
        ;
    break;}
case 56:
#line 663 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with ADD operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        yyval.actualValue.type = FLOAT_TYPE;
                        yyval.actualValue.fval = lhs->value.ival + rhs->value.fval;
                    }
                    else
                    {
                        yyval.actualValue.type = INT_TYPE;
                        yyval.actualValue.ival = lhs->value.ival + rhs->value.ival;
                    }
                    break;
                case FLOAT_TYPE:
                    yyval.actualValue.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        yyval.actualValue.fval = lhs->value.fval + rhs->value.ival;
                    }
                    else
                    {
                        yyval.actualValue.fval = lhs->value.fval + rhs->value.fval;
                    }
                    break;
            }
            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "+" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "+", name2);
            assemblyGenerator.addQuad("ADD", name1, name2, name);
        ;
    break;}
case 57:
#line 709 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with SUB operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        yyval.actualValue.type = FLOAT_TYPE;
                        yyval.actualValue.fval = lhs->value.ival - rhs->value.fval;
                    }
                    else
                    {
                        yyval.actualValue.type = INT_TYPE;
                        yyval.actualValue.ival = lhs->value.ival - rhs->value.ival;
                    }
                    break;
                case FLOAT_TYPE:
                    yyval.actualValue.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        yyval.actualValue.fval = lhs->value.fval - rhs->value.ival;
                    }
                    else
                    {
                        yyval.actualValue.fval = lhs->value.fval - rhs->value.fval;
                    }
                    break;
            }
            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "-" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "-", name2);
            assemblyGenerator.addQuad("MINUS", name1, name2, name);
        ;
    break;}
case 59:
#line 758 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with MUL operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        yyval.actualValue.type = FLOAT_TYPE;
                        yyval.actualValue.fval = lhs->value.ival * rhs->value.fval;
                    }
                    else
                    {
                        yyval.actualValue.type = INT_TYPE;
                        yyval.actualValue.ival = lhs->value.ival * rhs->value.ival;
                    }
                    break;
                case FLOAT_TYPE:
                    yyval.actualValue.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        yyval.actualValue.fval = lhs->value.fval * rhs->value.ival;
                    }
                    else
                    {
                        yyval.actualValue.fval = lhs->value.fval * rhs->value.fval;
                    }
                    break;
            }
            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "*" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "*", name2);
            assemblyGenerator.addQuad("MUL", name1, name2, name);
        ;
    break;}
case 60:
#line 804 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with DIV operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        yyval.actualValue.type = FLOAT_TYPE;
                        yyval.actualValue.fval = lhs->value.ival / rhs->value.fval;
                    }
                    else
                    {
                        yyval.actualValue.type = INT_TYPE;
                        yyval.actualValue.ival = lhs->value.ival / rhs->value.ival;
                    }
                    break;
                case FLOAT_TYPE:
                    yyval.actualValue.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        yyval.actualValue.fval = lhs->value.fval / rhs->value.ival;
                    }
                    else
                    {
                        yyval.actualValue.fval = lhs->value.fval / rhs->value.fval;
                    }
                    break;
            }
            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "/" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "/", name2);
            assemblyGenerator.addQuad("DIV", name1, name2, name);
        ;
    break;}
case 61:
#line 850 "parser.y"
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

            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "%" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "%", name2);
            assemblyGenerator.addQuad("MOD", name1, name2, name);
        ;
    break;}
case 63:
#line 873 "parser.y"
{
            int lhsType = yyvsp[-2].actualValue.type;
            int rhsType = yyvsp[0].actualValue.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with POW operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, yyvsp[-2].actualValue, yyvsp[0].actualValue, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        yyval.actualValue.type = FLOAT_TYPE;
                        yyval.actualValue.fval = pow(lhs->value.ival, rhs->value.fval);
                    }
                    else
                    {
                        yyval.actualValue.type = INT_TYPE;
                        yyval.actualValue.ival = pow(lhs->value.ival, rhs->value.ival);
                    }
                    break;
                case FLOAT_TYPE:
                    yyval.actualValue.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        yyval.actualValue.fval = pow(lhs->value.fval, rhs->value.ival);
                    }
                    else
                    {
                        yyval.actualValue.fval = pow(lhs->value.fval, rhs->value.fval);
                    }
                    break;
            }

            string varStr1NameRep = yyvsp[-2].actualValue.nameRep;
            string varStr2NameRep = yyvsp[0].actualValue.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name2 = assemblyGenerator.getTempVariable(varStr2NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1 , "^" , name2);
            yyval.actualValue.nameRep = concatenateNames(name1 , "^", name2);
            assemblyGenerator.addQuad("POW", name1, name2, name);
        ;
    break;}
case 64:
#line 919 "parser.y"
{
        ;
    break;}
case 65:
#line 924 "parser.y"
{ 
        string valueStr = to_string(yyvsp[0].actualValue.ival);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        ;
    break;}
case 66:
#line 931 "parser.y"
{ 
        string valueStr = to_string(yyvsp[0].actualValue.fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuad("ASSIGN", valueStr, "", name);
        yyval.actualValue.nameRep = strdup(valueStr.c_str());
        ;
    break;}
case 68:
#line 939 "parser.y"
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
            newEntry->setused(true);
            yyval.actualValue.type = (int)newEntry->getTypeValue()->type;
            string valueStr;
            switch(yyval.actualValue.type){
                case INT_TYPE:
                    yyval.actualValue.ival = newEntry->getTypeValue()->value.ival;
                    valueStr = to_string(yyval.actualValue.ival);
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
#line 981 "parser.y"
{yyval.actualValue = yyvsp[-1].actualValue;;
    break;}
case 70:
#line 986 "parser.y"
{
            SymbolTableEntry* newEntry = getIdentifierEntry(yyvsp[-3].stringVal);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot assign value to constant", yylineno);
                return 0;
            }
            int idType = (int)newEntry->getTypeValue()->type;
            int valType = yyvsp[-1].actualValue.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Assignment type mismatch", yylineno);
                return 0;
            }
            switch(idType){
                case INT_TYPE:
                    newEntry->getTypeValue()->value.ival = yyvsp[-1].actualValue.ival;
                    break;
                case FLOAT_TYPE:
                    newEntry->getTypeValue()->value.fval = yyvsp[-1].actualValue.fval;
                    break;
                case STRING_TYPE:
                    newEntry->getTypeValue()->value.sval = yyvsp[-1].actualValue.sval;
                    break;
                case BOOL_TYPE:
                    newEntry->getTypeValue()->value.bval = yyvsp[-1].actualValue.bval;
                    break;
                case CHAR_TYPE:
                    newEntry->getTypeValue()->value.cval = yyvsp[-1].actualValue.cval;
                    break;
            }
            newEntry->setinitialization(true);
            newEntry->setused(true);

            const char* name = assemblyGenerator.getRegisterAssignment(newEntry);
            const char* VarName = assemblyGenerator.getTempVariable(yyvsp[-1].actualValue.nameRep);
            assemblyGenerator.addQuad("ASSIGN",VarName,"",name);
        ;
    break;}
case 71:
#line 1030 "parser.y"
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
            assemblyGenerator.addQuad("ALLOC",yyvsp[-1].stringVal,"",name);


        ;
    break;}
case 73:
#line 1049 "parser.y"
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
            assemblyGenerator.addQuad("ALLOC",yyvsp[-3].stringVal,"",name);
            const char* VarName = assemblyGenerator.getTempVariable(yyvsp[-1].actualValue.nameRep);
            assemblyGenerator.addQuad("ASSIGN",VarName,"",name);


        ;
    break;}
case 74:
#line 1101 "parser.y"
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
            assemblyGenerator.addQuad("ALLOC",yyvsp[-3].stringVal,"",name);
            const char* VarName = assemblyGenerator.getTempVariable(yyvsp[-1].actualValue.nameRep);
            assemblyGenerator.addQuad("ASSIGN",VarName,"",name);
        ;
    break;}
case 75:
#line 1141 "parser.y"
{
            writeSemanticError("Constant variable not initialized ", yylineno);
            return 0;
        ;
    break;}
case 76:
#line 1149 "parser.y"
{
            if (yyvsp[0].actualValue.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        ;
    break;}
case 77:
#line 1156 "parser.y"
{ 
            assemblyGenerator.endScope(ifScope);;
    break;}
case 79:
#line 1163 "parser.y"
{
            if (yyvsp[0].actualValue.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of ELSE IF must be boolean", yylineno);
                return 0;
            }
        ;
    break;}
case 80:
#line 1170 "parser.y"
{ 
            assemblyGenerator.endScope(elseIfScope); ;
    break;}
case 82:
#line 1175 "parser.y"
{ 
        assemblyGenerator.endScope(elseScope);;
    break;}
case 84:
#line 1181 "parser.y"
{createNewSymbolTable();;
    break;}
case 85:
#line 1181 "parser.y"
{scopeEnd();;
    break;}
case 100:
#line 1210 "parser.y"
{
    createNewSymbolTable();
    assemblyGenerator.startScope();

;
    break;}
case 101:
#line 1214 "parser.y"
{
    scopeEnd();
;
    break;}
case 103:
#line 1219 "parser.y"
{scopeEnd();;
    break;}
case 105:
#line 1225 "parser.y"
{
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
        ;
    break;}
case 106:
#line 1237 "parser.y"
{
            if(functionHasReturn == false){
                writeSemanticWarning("Function must return a value", yylineno);
            }
            scopeEnd(); 
            currentFunction = nullptr; 
            functionHasReturn = false;
        ;
    break;}
case 107:
#line 1246 "parser.y"
{
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
        ;
    break;}
case 108:
#line 1258 "parser.y"
{
            if(functionHasReturn == false){
                writeSemanticWarning("Function must return a value", yylineno);
            }
            scopeEnd(); 
            currentFunction = nullptr; 
            functionHasReturn = false;
        ;
    break;}
case 109:
#line 1267 "parser.y"
{
            SymbolTableEntry *newEntry = identifierScopeCheck(yyvsp[-1].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = VOID_DTYPE;
            addEntryToCurrentTable(yyvsp[-1].stringVal, FUNC, idTypeValue, true, VOID_DTYPE);
            createNewSymbolTable();
        ;
    break;}
case 110:
#line 1277 "parser.y"
{scopeEnd(); currentFunction = nullptr;;
    break;}
case 111:
#line 1279 "parser.y"
{
            SymbolTableEntry *newEntry = identifierScopeCheck(yyvsp[-1].stringVal);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = VOID_DTYPE;
            addEntryToCurrentTable(yyvsp[-1].stringVal, FUNC, idTypeValue, true, VOID_DTYPE);
            createNewSymbolTable();
        ;
    break;}
case 112:
#line 1289 "parser.y"
{scopeEnd(); currentFunction = nullptr;;
    break;}
case 115:
#line 1295 "parser.y"
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
            addEntryToCurrentTable(yyvsp[0].stringVal, PAR, idTypeValue, true);
        ;
    break;}
case 116:
#line 1308 "parser.y"
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
            addEntryToCurrentTable(yyvsp[-2].stringVal, PAR, idTypeValue, true);
        ;
    break;}
case 117:
#line 1349 "parser.y"
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
case 118:
#line 1361 "parser.y"
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
case 119:
#line 1374 "parser.y"
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
case 120:
#line 1388 "parser.y"
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
case 121:
#line 1403 "parser.y"
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
case 122:
#line 1438 "parser.y"
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
case 123:
#line 1479 "parser.y"
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
case 124:
#line 1495 "parser.y"
{
            // End of func call
            if(functionParameters.size() != 0)
            {
                writeSemanticError("Invalid arguments size", yylineno);
                return 0;
            }
        ;
    break;}
case 125:
#line 1504 "parser.y"
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
case 126:
#line 1520 "parser.y"
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
case 127:
#line 1534 "parser.y"
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
case 128:
#line 1551 "parser.y"
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
#line 1559 "parser.y"


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
	printf("\nParsing complete\n");

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