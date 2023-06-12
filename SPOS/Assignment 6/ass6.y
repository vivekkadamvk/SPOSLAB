%{
	#include<stdio.h>
	int yylex();
	int yyerror(const char *str);
%}
%token datatype identifiers comma SC
%%
start:datatype varlist SC{printf("\n Declartion Statement is  valid");}
	|varlist:varlist comma identifiers;
	|identifiers;
%%
int main()
{
printf("\n Enter the declaration statement:");
yyparse();
}
int yyerror(const char *str)
{
printf("\n Declaration Statement is invalid");
return 0;
}
int yywrap()
{
return 0;
}