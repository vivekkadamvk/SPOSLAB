%{
#include <stdio.h>
int yylex();
int yywrap();
%}

%token WORD COMP DOT COMMA

%%
sentence:
    simple
    | compound
    ;

simple:
    WORD WORDLIST DOT {printf("Above statement is a simple statement");}
    ;
compound:
    WORD WORDLIST COMP WORDLIST DOT {printf("Above statement is a compound statement");}
    ;
    |WORDLIST:WORD WORDLIST;
	|WORD;
%%
int main() {
    printf("\n Enter the statement:\n");
    yyparse();
    return 0;
}
int yyerror() {
    return 0;
}
int yywrap() {
    return 1;
}
