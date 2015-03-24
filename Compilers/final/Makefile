CFLAGS=-ansi -pedantic -g -Iinclude

LEX=flex
YACC=bison -y
YFLAGS=-d

default : all

all : cflatc

cflatc: lexxer.o semana.tab.o cflatc.o
	$(CC) $(CFLAGS) $^ -o $@
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

lexxer.c: lexxer.l
	$(LEX) lexxer.l
	
semana.tab.c semana.tab.h: semana.y
	$(YACC) $(YFLAGS) $<