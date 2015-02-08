default : link

lockdown : link

all : link

parselist : link

link : compile
	gcc -o ./parselist ./parselist.o

compile :
	gcc -Wall -ansi -pedantic -g -c ./parselist.c -Iinclude

clean :
	rm *.o parselist