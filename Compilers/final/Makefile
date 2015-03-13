default : link

lockdown : link

all : link

cflatc : link

link : compile
	gcc -o ./cflatc ./cflatc.o

compile :
	gcc -Wall -ansi -pedantic -g -c ./cflatc.c -Iinclude

clean :
	rm *.o
	rm cflatc.exe