build:
	flex Lexer.l
	bison -d -t Parser.y
	g++ -o compiler lex.yy.c parser.tab.c

all: build run

run:
	./compiler

runwithtestfile:
	./compiler	test.txt
