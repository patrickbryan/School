/*
 * The header file for cflatc.c
 * Patrick Bryan - CIS4650, Winter 2015
 * University of Guelph
 */

#ifndef CFLATC_H

#include <stdio.h>
#include <string.h>
#include "y.tab.c"

int fileOpened(char* fileName);

void compile(void);

void semanticAnalysis(void);

void typeCheck(void);

int syntaxAnalysis(void);

#endif
