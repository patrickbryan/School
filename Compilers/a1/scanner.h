/*
 * The header file for scanner.c
 * Patrick Bryan - CIS4650, Winter 2015
 * University of Guelph
 */
 
#ifndef SCANNER_H

#include <stdio.h>
#include <string.h>
#include <regex.h>

#define INPUT_LENGTH 1024
#define OUTPUT_LENGTH 8

/* Intro to the DFA that checks LPAREN, RPAREN, CAR,
 * CDR and CHAR. It then calls numbersDfa to check for
 * INT, HEX, OCT and REAL. STR is returned if any of the
 * above are not matched correctly.
 * params :
 * token - the string to be categorized
 * output - the category. This is used to return output
 * return : a sting of the form LPAREN, RPAREN, CAR,
 * CDR, CHAR, INT, HEX, OCT, REAL, and STR */
char* dfa(char* token, char* output);

/* The number portion of the DFA as it is a little more
 * complicated. It checks for INT, HEX, OCT and REAL. It
 * will return STR if nothing is matched correctly.
 * params :
 * token - the string to be categorized
 * output - the category. This is used to return output
 * return : a sting of the form INT, HEX, OCT, REAL, and
 * STR */
char* numbersDfa(char* token, char* output);

#endif