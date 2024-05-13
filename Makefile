build:
	flex Lexer.l
	bison -d -t Parser.y
	g++ -o compiler lex.yy.c parser.tab.c semantic_analyzer.cpp

all: build run

run:
	./compiler

runwithtestfile:
	./compiler	test.txt
