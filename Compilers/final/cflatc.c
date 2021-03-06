/*
 * A compiler for cflatc programs
 * Patrick Bryan - CIS4650, Winter 2015
 * University of Guelph
 */

#include "cflatc.h"
#include "y.tab.h"

extern FILE *yyin;
FILE *sourceFile;
char* input;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Cflatc Compiler requires source file and  exactly 1 argument\n");
        printf("Use: cflatc sourceFile -[asic]\n");
        return -1;
    }
    else if (strlen(argv[2]) != 2 || argv[2][0] != '-') {
        printf("Unrecognized argument\n");
        printf("Use: cflatc sourceFile -[asic]\n");
        return -1;
    }
    else if (!fileOpened(argv[1])) {
        printf("Could not open file %s", argv[1]);
        return -1;
    }

    switch (argv[2][1]) {
    case 'c':
        printf("compiling and outputting MIPS R2000 assembler (.asm)\n");
        compile();
        break;
    case 'i':
        printf("performing sematic analysis and outputting intermediate representation (.inr)\n");
        semanticAnalysis();
        break;
    case 's':
        printf("performing type checking and outputting symbol table (.sym)\n");
        typeCheck();
        break;
    case 'a':
        printf("performing syntax analysis and outputting abstract syntax (.abs)\n");
        syntaxAnalysis();
        break;
    default:
        printf("Unrecognized argument\n");
        printf("Use: cflatc sourceFile -[asic]\n");
        return -1;
    }
    return 0;
}

int fileOpened(char* fileName) {
    sourceFile = fopen(fileName, "r");
    return (sourceFile != NULL);
}

/*TODO: finish*/
void compile(void) {

}

/*TODO: finish*/
void semanticAnalysis(void) {

}

/*TODO: finish*/
void typeCheck(void) {

}

int syntaxAnalysis(void) {
    return yyparse();;
}
