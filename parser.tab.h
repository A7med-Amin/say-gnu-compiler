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


extern YYSTYPE yylval;
