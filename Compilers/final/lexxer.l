/*lex lexxer.l (creates lex.yy.c file if works)
 *cc lex.yy.c -ll (compiling scanner)
 *./a.out (accepts input through stdin)
 */
/*gcc lexxer.c lex.yy.c -o lexxer
./lexxer < C FILE TO SCAN*/
 
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
"/*"		     		return COMMENTBEGIN;
"*/"				return COMMENTEND;
"char"                        return CHAR;
"int"                         return INT;
"float"                       return FLOAT;
['](.|\\n|\\0)[']             return CHARVAL;
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
[e]				return EXP;
[E]				return EXP;
[_a-zA-Z][a-zA-Z0-9]*         return IDENTIFIER;
[1-9]+[0-9]*                  return INTVAL;
0[.][0-9]+                    return FLOATVAL;
[1-9]+[0-9]*\.[0-9]+          return FLOATVAL;
"0"                           return INTVAL;
[ \n\t]                       ;
.                             printf("unexpected character\n");
%%

int yywrap(void) {
    return 1;
}
