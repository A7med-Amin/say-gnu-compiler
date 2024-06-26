build:
	flex Lexer.l
	bison -d -t Parser.y
	g++ -std=c++17 -o compiler lex.yy.c parser.tab.c semantic_analyzer.cpp AssemblyGenerator.cpp quadruple.cpp

all: build run

run:
	./compiler

runwithtestfile:
	./compiler	test.txt

runwithtest:
	./compiler	singletest.txt

gui:
	./compiler gui.txt

runinputcode:
	./compiler test/input_code.cpp

