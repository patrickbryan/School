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
token_t token;
int lineNum = 1;

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
        STMTS();
        lineNum++;
    }
}

int getNextToken(void)
{
    return fscanf(stdin, "%s[ \n]", input);
}

void scanner(void)
{
    int i;
    int neg = 0;
    int dot = 0;
    int dotIndex = 0;
    int nums[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    /* single characters */
    if (strlen(input) == 1) {
        if (input[0] == '(') {
            token = LPAREN;
            return;
        }
        else if (input[0] == ')') {
            token = RPAREN;
            return;
        }
        /* ASCII 0 to 9 */
        else if (input[0] >= 48 && input[0] <= 57) {
            token = INT;
            return;
        }
        else if (input[0] == '+') {
            token = PLUS;
            return;
        }
        else if (input[0] == ';') {
            token = SEMI;
            return;
        }
        else {
            token = CHAR ;
            return;
        }
    }
    
    /* 3 lettered words */
    else if (strlen(input) == 3) {
        if (strcmp(input, "car") == 0) {
            token = CAR;
            return;
        }
        else if (strcmp(input, "cdr") == 0) {
            token = CDR;
            return;
        }
        else if (strcmp(input, "set") == 0) {
            token = SET;
            return;
        }
    }
    
    else {
        /* parse whole token for key characters */
        for (i = 0; i < strlen(input); i++) {
            if (input[i] == '-') {
                neg++;
            }
            else if (input[i] == '.') {
                dot++;
                dotIndex = i;
            }
            /* ASCII 0 to 9 */
            else if (input[i] >= 48 && input[i] <= 57) {
                nums[input[i] - 48]++;
            }
            /* any other input would mean a string */
            else {
                token = STR;
                return;
            }
        }
        
        /* too many -'s, x's or .'s . Only allowed one max */
        if (neg > 1 || dot > 1) {
            token = STR;
            return;
        }
        /* real number */
        if (dot == 1) {
            /* compensate for negative symbol */
            i = 0;
            
            if (neg == 1 && input[0] != '-') {
                token = STR;
                return;
            }
            
            if (neg == 1) {
                i++;
            }
            /* 0. something */
            if (input[i] == '0' && input[i+1] == '.' && strlen(input) > (2 + i)) {
                token = REAL;
                return;
            }
            /* [1-9][0-9]* . something
             * ie. check that the first number isn't 0 and that the . is not the last
             * character in the token. Everything else is 0-9 */
            else if (input[i] != '0' && strlen(input) > dotIndex) {
                token = REAL;
                return;
            }
        }
        /* int */
        else {
            if (neg == 1 && input[0] != '-') {
                token = STR;
                return;
            }
        
            /* compensate for negative symbol */
            i = 0;
            if (neg == 1) {
                i++;
            }
        
            if (input[i] != '0') {
                token = INT;
                return;
            }
        }
    }
    
    token = STR;
}

void STMTS(void)
{
    switch(token)
    {
        case CHAR:
            STMT();
            break;
        case INT:
        case REAL:
        case STR:
        case CAR:
        case CDR:
            STMT();
            break;
        case LPAREN:
            STMT();
            break;
        case RPAREN:
        case SET:
            STMT();
            break;
        case PLUS:
        case SEMI:
        default:
            error();
    }
}

void STMT(void)
{
    switch(token)
    {
        case CHAR:
            LISTEXPR();
            consume(SEMI);
            break;
        case INT:
        case REAL:
        case STR:
        case CAR:
        case CDR:
            LISTEXPR();
            consume(SEMI);
            break;
        case LPAREN:
            LISTEXPR();
            consume(SEMI);
            break;
        case RPAREN:
        case SET:
            ASSIGN();
            consume(SEMI);
            break;
        case PLUS:
        case SEMI:
        default:
            error();
    }
}

void ASSIGN(void)
{
    switch(token)
    {
        case CHAR:
        case INT:
        case REAL:
        case STR:
        case CAR:
        case CDR:
        case LPAREN:
        case RPAREN:
        case SET:
            consume(SET);
            VAR();
            LISTEXPR();
            break;
        case PLUS:
        case SEMI:
        default:
            error();
    }
}

void LISTEXPR(void)
{
    switch(token)
    {
        case CHAR:
            CLIST();
            break;
        case INT:
        case REAL:
        case STR:
        case CAR:
        case CDR:
            CLIST();
            break;
        case LPAREN:
            CLIST();
            break;
        case RPAREN:
        case SET:
        case PLUS:
        case SEMI:
        default:
            error();
    }
    
    switch(token)
    {
        case PLUS:
            CONCAT();
        default:
            break;
    }
}

void CLIST(void)
{
    switch(token)
    {
        case CHAR:
            VAR();
            break;
        case INT:
        case REAL:
        case STR:
        case CAR:
        case CDR:
            consume(CDR);
            LISTEXPR();
            break;
        case LPAREN:
            /*add look ahead for ( )*/
            consume(LPAREN);
            ITEMS();
            consume(RPAREN);
            break;
        case RPAREN:
        case SET:
        case PLUS:
        case SEMI:
        default:
            error();
    }
}

void VAR(void)
{
    switch(token)
    {
        case CHAR:
            consume(CHAR);
            break;
        case INT:
        case REAL:
        case STR:
        case CAR:
        case CDR:
        case LPAREN:
        case RPAREN:
        case SET:
        case PLUS:
        case SEMI:
        default:
            error();
    }
}

void CONCAT(void)
{
    switch(token)
    {
        case CHAR:
            /*LISTEXPR();*/
            consume(PLUS);
            CLIST();
            break;
        case INT:
        case REAL:
        case STR:
        case CAR:
        case CDR:
            /*LISTEXPR();*/
            consume(PLUS);
            CLIST();
            break;
        case LPAREN:
            /*LISTEXPR();*/
            consume(PLUS);
            CLIST();
            break;
        case RPAREN:
        case SET:
        case PLUS:
        case SEMI:
        default:
            error();
    }
}

void ITEMS(void)
{
    switch(token)
    {
        case CHAR:
            ITEM();
            break;
        case INT:
            ITEM();
            break;
        case REAL:
            ITEM();
            break;
        case STR:
            ITEM();
            break;
        case CAR:
            ITEM();
            break;
        case CDR:
            ITEM();
            break;
        case LPAREN:
            ITEM();
            break;
        case RPAREN:
            
        case SET:
        case PLUS:
        case SEMI:
        default:
            error();
    }
}

void ITEM(void)
{
    switch(token)
    {
        case CHAR:
            LISTEXPR();
            break;
        case INT:
            consume(INT);
            break;
        case REAL:
            consume(REAL);
            break;
        case STR:
            consume(STR);
            break;
        case CAR:
            consume(CAR);
            LISTEXPR();
            break;
        case CDR:
            LISTEXPR();
            break;
        case LPAREN:
            LISTEXPR();
            break;
        case RPAREN:
            break;
        case SET:
        case PLUS:
        case SEMI:
        default:
            error();
    }
}

void consume(token_t t)
{
    /*if not consumed*/
    printf("consuming\n");
    if (t != token)
        error();
    
    getNextToken();
    scanner();
}

void error(void)
{
    printf("There was an error parsing the input on line %d\n", lineNum);
}