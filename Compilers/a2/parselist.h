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
#define TOKEN_LENGTH 16

/* Start of the recursive descent parser
 */
void recDesParser(void);

/* Gets the next token from stdin.
 * returns 0 if eof or no token found.
 */
int getNextToken(void);

#endif