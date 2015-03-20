%{
void yyerror (char *s);
#include <stdio.h>
#include <stdlib.h>
char* symbols[1024];
int symbolVal(char* symbol);
void updateSymbolVal(char* symbol, int val);
%}

%union {int integer; char character; float decimal; char* id}
%start program
%token TYPEDEF STRUCT IDENTIFIER LBRACE RBRACE SEMICOLON LSQBRACE RSQBRACE
%token MAIN LPAREN RPAREN COMMA INT FLOAT CHAR IF ELSE FOR WHILE RETURN
%token INTVAL FLOATVAL CHARVAL DOT PLUS MINUS STAR BACKSLASH PERCENT
%token SIZEOF INC DEC EQUAL NOTEQ GTEQ LTEQ AND OR GT LT NOT ASSIGN
%type <id> IDENTIFIER
%type <integer> INTVAL
%type <character> CHARVAL
%type <decimal> FLOATVAL

%%

program     : type_decl_list global_var_list function_def_list  {;}
            ;
            
type_decl_list  : type_decl                                     {;}
                | type_decl_list type_decl                      {;}
                |                                               {;}
                ;

type_decl       : TYPEDEF STRUCT IDENTIFIER LBRACE var_decl_list RBRACE IDENTIFIER SEMICOLON {;}
                ;
                
var_decl_list   : var_decl                                      {;}
                | var_decl_list var_decl                        {;}
                ;
                
var_decl        : type_name IDENTIFIER SEMICOLON                {;}
                | type_name IDENTIFIER LSQBRACE expr RSQBRACE SEMICOLON {;}
                ;

global_var_list : var_decl                                      {;}
                | global_var_list var_decl                      {;}
                |                                               {;}
                ;
            
function_def_list   : function_def                              {;}
                    | function_def_list function_def            {;}
                    |                                           {;}
                    ;
                   
function_def    : type_name MAIN LPAREN param_list RPAREN LBRACE var_decl_list stmt_list RBRACE {;}
                | type_name IDENTIFIER LPAREN param_list RPAREN LBRACE var_decl_list stmt_list RBRACE {;}
                ;

param_list  : type_name IDENTIFIER                              {;}
            | param_list COMMA type_name IDENTIFIER             {;}
            ;
                   
type_name   : INT                                               {;}
            | FLOAT                                             {;}
            | CHAR                                              {;}
            ;
                   
stmt_list   : stmt                                              {;}
            | stmt_list stmt                                    {;}
            ;
            
stmt        : expr_stmt                                         {;}
            | compound_stmt                                     {;}
            | select_stmt                                       {;}
            | iter_stmt                                         {;}
            | return_stmt                                       {;}
            | SEMICOLON                                         {;}
            ;
            
expr_stmt   : expr SEMICOLON                                    {;}
            ;
            
compound_stmt   : LBRACE stmt_list RBRACE                       {;}
                ;
  
select_stmt : IF LPAREN expr RPAREN stmt                        {;}
            | IF LPAREN expr RPAREN stmt ELSE stmt              {;}
            ;
            
iter_stmt   : WHILE LPAREN expr RPAREN stmt                     {;}
            | FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt {;}
            | FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN stmt {;}
            | FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN stmt {;}
            | FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN stmt {;}
            | FOR LPAREN SEMICOLON SEMICOLON expr RPAREN stmt   {;}
            | FOR LPAREN expr SEMICOLON SEMICOLON RPAREN stmt   {;}
            | FOR LPAREN SEMICOLON expr SEMICOLON RPAREN stmt   {;}
            | FOR LPAREN SEMICOLON SEMICOLON RPAREN stmt        {;}
            ;
           
return_stmt : RETURN expr SEMICOLON                             {;}
            | RETURN SEMICOLON                                  {;}
            ;
            
expr        : expr PLUS expr                                    {;}
            | expr MINUS expr                                   {;}
            | expr STAR expr                                    {;}
            | expr BACKSLASH expr                               {;}
            | expr PERCENT expr                                 {;}
            | expr GT expr                                      {;}
            | expr LT expr                                      {;}
            | expr GTEQ expr                                    {;}
            | expr LTEQ expr                                    {;}
            | expr NOTEQ expr                                   {;}
            | expr EQUAL expr                                   {;}
            | expr OR expr                                      {;}
            | expr AND expr                                     {;}
            | NOT expr                                          {;}
            | MINUS expr                                        {;}
            | PLUS expr                                         {;}
            | LPAREN expr RPAREN                                {;}
            | function_call                                     {;}
            | var ASSIGN expr                                   {;}
            | var                                               {;}
            | var INC                                           {;}
            | var DEC                                           {;}
            | INC var                                           {;}
            | DEC var                                           {;}
            | SIZEOF LPAREN expr RPAREN                         {;}
            | SIZEOF LPAREN type_name RPAREN                    {;}
            | constant                                          {;}
            ;
            
function_call   : IDENTIFIER LPAREN function_call_values RPAREN {;}
                ;
            
function_call_values    : expr                                  {;}
                        | function_call_values COMMA expr       {;}
                        ;
            
var         : IDENTIFIER                                        {;}
            | var LSQBRACE expr RSQBRACE                        {;}
            | var DOT var                                       {;}
            ;
            
constant    : INTVAL                                            {;}
            | FLOATVAL                                          {;}
            | CHARVAL                                           {;}
            ;
            
%%
int computeSymbolIndex(char token)
{
    return 1;
}

int symbolVa(char symbol)
{
    return 1;
}

void updateSymbolVal(char symbol, int val)
{
    
}

void yyerror (char *s)
{
    fprintf(stderr, "%s\n", s);
}

int main (void)
{
    if (yyin == NULL)
        yyin = stdin;
    while (!feof(yyin))
        yyparse();
    return 0;
}