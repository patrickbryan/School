default : link

lockdown : link

all : link

cflatc : link

link : compile
	gcc -o ./cflatc ./cflatc.o

compile :
	yacc -d -y semana.y
	lex lexxer.l
	gcc -ansi -pedantic -g -c ./cflatc.c ./lex.yy.c ./y.tab.c -Iinclude

clean :
	rm *.o
	rm cflatc.exe
	rm lex.yy.c
	rm y.tab.*
