/*
 * A simple scanner program that takes in input
 * from stdin and grabs tokens and outputs
 * what the tokens are to stdout.
 * Tokens include: INT, HEX, OCT, REAL, LPAREN,
 * RPAREN, CAR, CDR, CHAR, STR
 * Patrick Bryan - CIS4650, Winter 2015
 * University of Guelph
 */

#include "scanner.h"

int main(int argc, char *argv[])
{
    char input[INPUT_LENGTH];
    char output[OUTPUT_LENGTH];
    
    while (fscanf(stdin, "%s[ \n]", input)) {
        strncpy(output, dfa(input, output), OUTPUT_LENGTH);
        printf("%s ", output);
    }
    
    return 0;
}

char* dfa(char* token, char* output) {
    
    /* single characters */
    if (strlen(token) == 1) {
        if (token[0] == '(') {
            return "LPAREN";
        }
        else if (token[0] == ')') {
            return "RPAREN";
        }
        /* ASCII 0 to 9 */
        else if (token[0] >= 48 && token[0] <= 57) {
            return "INT";
        }
        else {
            return "CHAR";
        }
    }
    
    /* 3 lettered words */
    else if (strlen(token) == 3) {
        if (strcmp(token, "car") == 0) {
            return "CAR";
        }
        else if (strcmp(token, "cdr") == 0) {
            return "CDR";
        }
    }
    
    /* int, oct, hex, real and string */
    return numbersDfa(token, output);
}

char* numbersDfa(char* token, char* output) {
    int i;
    int neg = 0;
    int x = 0;
    int dot = 0;
    int dotIndex = 0;
    int nums[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int aToF[6] = {0, 0, 0, 0, 0, 0};
    
    /* parse whole token for key characters */
    for (i = 0; i < strlen(token); i++) {
        if (token[i] == '-') {
            neg++;
        }
        else if (token[i] == 'x') {
            x++;
        }
        else if (token[i] == '.') {
            dot++;
            dotIndex = i;
        }
        /* ASCII 0 to 9 */
        else if (token[i] >= 48 && token[i] <= 57) {
            nums[token[i] - 48]++;
        }
        /* ASCII A to F */
        else if (token[i] >= 65 && token[i] <= 70) {
            aToF[token[i] - 65]++;
        }
        /* any other input would mean a string */
        else {
            return "STR";
        }
    }
    
    /* too many -'s, x's or .'s . Only allowed one max */
    if (neg > 1 || x > 1 || dot > 1) {
        return "STR";
    }
    
    /* hex */
    if (x == 1) {
        if (dot > 0) {
            return "STR";
        }
        
        /* -0x something */
        if (token[0] == '-' && token[1] == '0' && token[2] == 'x' 
            && strlen(token) > 3) {
            return "HEX";
        }
        /* 0x something */
        else if (token[0] == '0' && token[1] == 'x' && strlen(token) > 2
                && neg == 0) {
            return "HEX";
        }
    }
    
    /* real */
    else if (dot == 1) {
        if (x > 0) {
            return "STR";
        }
        for (i = 0; i < 6; i++) {
            if (aToF[i] > 0) {
                return "STR";
            }
        }
        if (neg == 1 && token[0] != '-') {
            return "STR";
        }
        
        /* compensate for negative symbol */
        i = 0;
        if (neg == 1) {
            i++;
        }
        /* 0. something */
        if (token[i] == '0' && token[i+1] == '.' && strlen(token) > (2 + i)) {
            return "REAL";
        }
        /* [1-9][0-9]* . something
         * ie. check that the first number isn't 0 and that the . is not the last
         * character in the token. Everything else is 0-9 */
        else if (token[i] != '0' && strlen(token) > dotIndex) {
            return "REAL";
        }
    }
    
    /* oct */
    else if (token[0] == '0' || (token[1] == '0' && token[0] == '-')) {
        if (dot > 0 || x > 0) {
            return "STR";
        }
        for (i = 0; i < 6; i++) {
            if (aToF[i] > 0) {
                return "STR";
            }
        }
        for (i = 8; i < 10; i++) {
            if (nums[i] > 0) {
                return "STR";
            }
        }
        if (neg == 1 && token[0] != '-') {
            return "STR";
        }
        
        return "OCT";
    }
    
    /* int */
    else {
        if (dot > 0 || x > 0) {
            return "STR";
        }
        for (i = 0; i < 6; i++) {
            if (aToF[i] > 0) {
                return "STR";
            }
        }
        if (neg == 1 && token[0] != '-') {
            return "STR";
        }
        
        /* compensate for negative symbol */
        i = 0;
        if (neg == 1) {
            i++;
        }
        
        if (token[i] != '0') {
            return "INT";
        }
    }
    
    return "STR";
}