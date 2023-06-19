#include "lex.yy.c"
#include "yacc.tab.c"
#include <stdlib.h>
#include <stdio.h>

int lexverbose = 1;
extern int yyparse();

int main(int argc, char* argv[])
{
    extern FILE* yyin;
    printf("Compiling...!\n");
    if ((yyin = fopen("test.c", "rt")) == NULL) {
        perror("can not open file test.c\n");
        exit(1);
    }
    if (yyparse() == 1) {
        fprintf(stderr, "parser error\n");
        exit(1);
    }
    printf("yyparse() completed successfully!\n");
    return 0;
}