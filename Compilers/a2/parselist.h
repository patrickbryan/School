/*
 * The header file for parselist.c
 * Patrick Bryan - CIS4650, Winter 2015
 * University of Guelph
 */
 
#ifndef PARSELIST_H

#include <stdio.h>
#include <string.h>
#include <regex.h>

#define INPUT_LENGTH 1024

typedef enum {CHAR, INT, REAL, STR, CAR, CDR, LPAREN, RPAREN, SET, PLUS, SEMI} token_t;

/* Start of the recursive descent parser
 */
void recDesParser(void);

/* Gets the next token from stdin.
 * returns 0 if eof or no token found.
 */
int getNextToken(void);

void scanner(void);

void STMTS(void);

void STMT(void);

void ASSIGN(void);

void LISTEXPR(void);

void CLIST(void);

void VAR(void);

void CONCAT(void);

void ITEMS(void);

void ITEM(void);

void consume(token_t t);

void error(void);

#endif