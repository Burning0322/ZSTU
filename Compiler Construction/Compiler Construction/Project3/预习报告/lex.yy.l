%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define true 1      // Changed 'ture' to 'true'
#define false 0     // Changed 'false' to 'false'
#include "yacc.tab.h"
extern int lexverbose;
extern int linecount;
%}

digit [0-9]
letter [a-zA-Z]

%%

{digit}+ {
    yylval.real = atof(yytext);    // Corrected the spelling of 'atof'
    if (lexverbose)
        printf("real:%g\n", yylval.real);
    return(number);
}
\+ {
    yylval.chr = yytext[0];
    if (lexverbose)
        printf("operator:%c\n", yylval.chr);
    return('+');
}
\- {
    yylval.chr = yytext[0];
    if (lexverbose)
        printf("operator:%c\n", yylval.chr);
    return('-');
}
\* {
    yylval.chr = yytext[0];
    if (lexverbose)
        printf("operator:%c\n", yylval.chr);
    return('*');
}
\/ {
    yylval.chr = yytext[0];
    if (lexverbose)
        printf("operator:%c\n", yylval.chr);
    return('/');
}
\( {
    yylval.chr = yytext[0];
    if (lexverbose)
        printf("separator:%c\n", yylval.chr);
    return('(');
}
\) {
    yylval.chr = yytext[0];
    if (lexverbose)
        printf("separator:%c\n", yylval.chr);
    return(')');
}
\; {
    return(';');
}
\n {
    printf("line %d\n", linecount);
    /* linecount++; */    // Commented out the increment statement
    return('\n');
}
[ \t]+ {
    printf("lexical analyzer error\n");
}
quit {
    printf("Bye!\n");
    exit(0);
}

%%

int yywrap() {
    return 1;
}