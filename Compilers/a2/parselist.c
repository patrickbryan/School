/*
 * A simple predictive recursive descent parser program 
 * that takes in input from stdin. It outputs if the given
 * input is valid according to the grammer or an error and the
 * line of the error if it is not valid.
 * The grammer is as follows:
 * STMTS -> STMTS STMT | STMT
 * STMT -> ASSIGN ;
 * STMT -> LISTEXPR ;
 * ASSIGN -> set VAR LISTEXPR
 * LISTEXPR -> VAR
 * LISTEXPR -> CONCAT
 * LISTEXPR -> ( ITEMS )
 * LISTEXPR -> cdr LISTEXPR
 * VAR -> char
 * CONCAT -> LISTEXPR + LISTEXPR
 * ITEMS -> ITEMS ITEM | ITEM
 * ITEM -> LISTEXPR
 * ITEM -> str | int | real
 * ITEM -> car LISTEXPR
 * ITEM ->
 * The terminals are: char int real str car cdr ( ) set + ;
 * Patrick Bryan - CIS4650, Winter 2015
 * University of Guelph
 */

#include "parselist.h"

char input[INPUT_LENGTH];
char token[TOKEN_LENGTH];

int main(int argc, char *argv[])
{
    recDesParser();
    
    /*Print list of errors*/
    
    return 0;
}

void recDesParser(void)
{
    while(getNextToken() != 0) {
        scanner();
    }
}

int getNextToken(void)
{
    return fscanf(stdin, "%s[ \n]", input);
}

void scanner(void)
{
    /*take input and set token*/
}

void STMTS(void)
{
    
}

void STMT(void)
{
    
}

void ASSIGN(void)
{
    
}

void LISTEXPR(void)
{
    
}

void VAR(void)
{
    
}

void CONCAT(void)
{
    
}

void ITEMS(void)
{
    
}

void ITEM(void)
{
    
}