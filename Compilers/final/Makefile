default : link

lockdown : link

all : link

cflatc : link

link : compile
	gcc -o ./cflatc ./cflatc.o

compile :
	lex lexxer.l
	gcc -Wall -ansi -pedantic -g -c ./cflatc.c ./lex.yy.c -Iinclude

clean :
	rm *.o
	rm cflatc.exe
	rm lex.yy.c