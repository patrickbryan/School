%{
void yyerror (char *s);
#include <stdio.h>
#include <stdlib.h>
int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
%}

%union {int integer; char character; float decimal;}
%start line
%token print
%token exit_command
%token <integer> i
%token <character> c
%token <float> f
%type <integer> line exp term
%type <character> assignment

%%

line        : assignment ';'        {;}
            | exit_command ';'      {exit(EXIT_SUCCESS);}
            | print exp ';'         {printf("Printing %d\n", $2);}
            | line assignment ';'   {}
            | line print exp ';'    {}
            | line exit_command ';' {}
            ;
            
assignment  : identifier '=' exp    { updateSymbolVal($1,$3); }
            ;

exp         : term                  {$$ = $1;}
            | exp '+' term          {$$ = $1 + $3;}
            | exp '-' term          {$$ = $1 - $3;}
            ;
            
term        : number                {$$ = $1;}
            | identifier            {}
            ;
            
%%
int computeSymbolIndex(char token)
{
    
}

int symbolVa(char symbol)
{
    
}

void updateSymbolVal(char symbol, int val)
{
    
}

int main (void)
{
    return yyparse();
}

void yyerror (char *s)
{
    
}