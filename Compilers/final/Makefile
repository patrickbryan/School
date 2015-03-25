CC=gcc
LEX=flex
YACC=bison -y

CFLAGS=-ansi -pedantic -g
YFLAGS=-d

APP=cflatc
OBJECTS=lex.yy.o y.tab.o $(APP).o

default : all

all : cflatc

cflatc: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	
%.o : %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

lex.yy.c: lexxer.l
	$(LEX) $(LFLAGS) lexxer.l
	
y.tab.c y.tab.h: semana.y
	$(YACC) $(YFLAGS) $<

clean:
	rm -rf $(APP)
	rm -rf $(OBJECTS)
	rm -rf y.tab.c y.tab.h
	rm -rf lex.yy.c
