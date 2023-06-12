%option noyywrap
%{
    #include<stdio.h>
%}
header #.*
comment //.*
digit [0-9]
number {digit}{digit}* 
letter [A-Za-z]
identifier (letter)({letter}|{digit})* 
keyword "int"|"main"|"char"|"float"|"long"|"return"|"string"|"double"|"printf"
operator ["+"|"-"|"*"|"\"|"<"|">"|"=="|"!="] 
punctuation [";"|","|"."|"!"]
%%
{header} {printf("\n header: %s", yytext);} 
{number} {printf("\n Number: %s", yytext);} 
{punctuation} {printf("\n Punctuation: %s", yytext);} 
{operator} {printf("\n Operator: %s", yytext);} 
{keyword} {printf("\n Keyword: %s", yytext);} 
{identifier} {printf("\n Identifier: %s", yytext);}
%%
extern FILE *yyin;
int main()
{
    yyin = fopen("sample.txt","r");
    yylex();
    return 0;

// yylex();
// return 0;
}