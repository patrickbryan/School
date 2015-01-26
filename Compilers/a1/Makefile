default : link

lockdown : link

all : link

scanner : link

link : compile
	gcc -o ./scanner ./scanner.o

compile :
	gcc -Wall -ansi -pedantic -g -c ./scanner.c -Iinclude

clean :
	rm *.o scanner