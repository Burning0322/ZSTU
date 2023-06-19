%{
 
void yyerror(const char *s);
 
%}
 
%%
 
program:
 
;
 
%%
 
void yyerror(const char *s)
 
{
 
}
 
int main()
 
{
 
yyerror();
 
return 0;
 
}