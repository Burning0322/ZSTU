%{
#include <ctype.h>
#include <stdio.h>
#define MSDOS
int linecount;
extern int yylex();
extern int yyerror();
%}

%union {
    char chr;
    char* str;
    int integer;
    float real;
    double dbl;
}

%token number
%token uminus

%type <real> expr
%type <real> term
%type <real> factor

%%

lines: lines expr '\n'
{
    printf("line %d:%g\n", linecount++, $2);
}
| lines '\n'
{
    linecount++;
}
| ;

expr: expr '+' term
{
    $$ = $1 + $3;
}
| expr '-' term
{
    $$ = $1 - $3;
}
| term
{
    $$ = $1;
}

term: term '*' factor
{
    $$ = $1 * $3;
}
| term '/' factor
{
    $$ = $1 / $3;
}
| factor
{
    $$ = $1;
}

factor: '(' expr ')'
{
    $$ = $2;
}
| '-' factor %prec uminus
{
    $$ = -$2;
}
| number
{
    $$ = $1;
};

%%

int yyerror(char *s)
{
    fprintf(stderr, "syntactic error:%s\n", s);
    return 0;
}
