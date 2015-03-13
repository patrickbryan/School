/*lex lexxer.l (creates lex.yy.c file if works)
 *cc lex.yy.c -ll (compiling scanner)
 *./a.out (accepts input through stdin)
 */
/*gcc lexxer.c lex.yy.c -o lexxer
./lexxer < C FILE TO SCAN*/
 
/*what to put in my c file
#include "lexxer.h"
#include <stdio.h>
extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "db_type", "db_name", "db_table_prefix", "db_port"}

int main (void) {
    int ntoken, vtoken;
    
    ntoken = yylex();
    while(ntoken) {
        printf("%d\n", ntoken);
        if(yylex() != COLON) {
            printf("Error on line %d. Found %s\n", yylineno, yytext);
            return 1;
        }
        vtoken = yylex();
        switch (ntoken) {
            case TYPE:
            case NAME:
            case TABLE_PREFIX:
                if(vtoken != IDENTIFIER) {
                    printf("Error on line %d. Found %s\n". yylineno, yytext);
                    return 1;
                }
                printf("%s is set to %s\n", names[ntoken], yytext);
                break;
            case PORT:
                if(vtoken != TOKEN) {
                    printf("Error on line %d. Found %s\n". yylineno, yytext);
                    return 1;
                }
                printf("%s is set to %s\n", names[ntoken], yytext);
                break;
            default:
                printf("Syntax error on line %d\n", yylineno);
        ntoken = yylex();
    }
    return 0;
}*/
%{
    #include "lexxer.h"
%}
 
%%
"typedef"                     return TYPEDEF;
"main"                        return MAIN;
"sizeof"                      return SIZEOF;
"if"                          return IF;
"else"                        return ELSE;
"for"                         return FOR;
"return"                      return RETURN;
"while"                       return WHILE;
"void"                        return VOID;
"struct"                      return STRUCT;
"putc"                        return PUTC;
"puti"                        return PUTI;
"putf"                        return PUTF;
"/*"                          return COMMENTBEGIN;
"*/"                          return COMMENTEND;
"char"                        return CHAR;
"int"                         return INT;
"float"                       return FLOAT;
['].[']                       return CHARVAL;
"++"                          return INC;
"--"                          return DEC;
"=="                          return EQUAL;
"!="                          return NOTEQ;
">="                          return GTEQ;
"<="                          return LTEQ;
"&&"                          return AND;
"||"                          return OR;
";"                           return SEMICOLON;
"("                           return LPAREN;
")"                           return RPAREN;
","                           return COMMA;
"["                           return LSQBRACE;
"]"                           return RSQBRACE;
"{"                           return LBRACE;
"}"                           return RBRACE;
"+"                           return PLUS;
"-"                           return MINUS;
"*"                           return STAR;
"/"                           return BACKSLASH;
"%"                           return PERCENT;
">"                           return GT;
"<"                           return LT;
"!"                           return NOT;
"="                           return ASSIGN;
[_a-zA-Z][a-zA-Z0-9]*         return IDENTIFIER;
[-+]?[1-9]+[0-9]*             return INTVAL;
[-+]?0/.[0-9]+                return FLOATVAL;
[-+]?[1-9]+[0-9]*\.[0-9]+     return FLOATVAL;
"0"                           return INTVAL;
[ \n\t]                       ;
.                             printf("unexpected character\n");
%%

int yywrap(void) {
    return 1;
}