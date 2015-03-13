#include "lexxer.h"
#include <stdio.h>

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void) {
	int ntoken, vtoken;

	ntoken = yylex();
	while(ntoken) {
		switch(ntoken)
		{
			case TYPEDEF: printf("TYPEDEF"); break;
			case MAIN: printf("MAIN"); break;
			case INT: printf("INT"); break;
			case CHAR: printf("CHAR"); break;
			case FLOAT: printf("FLOAT"); break;
			case IDENTIFIER: printf("IDENTIFIER"); break;
			case PLUS: printf("PLUS"); break;
			case MINUS: printf("MINUS"); break;
			case STAR: printf("STAR"); break;
			case BACKSLASH: printf("BACKSLASH"); break;
			case PERCENT: printf("PERCENT"); break;
			case EQUAL: printf("EQUAL"); break;
			case NOTEQ: printf("NOTEQ"); break;
			case GT: printf("GT"); break;
			case LT: printf("LT"); break;
			case GTEQ: printf("GTEQ"); break;
			case LTEQ: printf("LTEQ"); break;
			case AND: printf("AND"); break;
			case OR: printf("OR"); break;
			case NOT: printf("NOT"); break;
			case ASSIGN: printf("ASSIGN"); break;
			case SIZEOF: printf("SIZEOF"); break;
			case INC: printf("INC"); break;
			case DEC: printf("DEC"); break;
			case IF: printf("IF"); break;
			case ELSE: printf("ELSE"); break;
			case FOR: printf("FOR"); break;
			case RETURN: printf("RETURN"); break;
			case WHILE: printf("WHILE"); break;
			case COMMENTBEGIN: printf("COMMENT");
				while (ntoken) {
					ntoken = yylex();
					if (ntoken == COMMENTEND){
						break;
					}
				}
				 break;
			case SEMICOLON: printf("SEMICOLON"); break;
			case LPAREN: printf("LPAREN"); break;
			case RPAREN: printf("RPAREN"); break;
			case COMMA: printf("COMMA"); break;
			case LSQBRACE: printf("LSQBRACE"); break;
			case RSQBRACE: printf("RSQBRACE"); break;
			case LBRACE: printf("LBRACE"); break;
			case RBRACE: printf("RBRACE"); break;
			case VOID: printf("VOID"); break;
			case STRUCT: printf("STRUCT"); break;
			case PUTC: printf("PUTC"); break;
			case PUTF: printf("PUTF"); break;
			case PUTI: printf("PUTI"); break;
			case INTVAL: printf("INTVAL"); break;
			case CHARVAL: printf("CHARVAL"); break;
			case FLOATVAL: printf("FLOATVAL"); break;
			case EXP: printf("EXP"); break;
			default: printf("unknown!!!!");
		}
		printf(" %s\n", yytext);
		ntoken = yylex();
	}
	return 0;
}
