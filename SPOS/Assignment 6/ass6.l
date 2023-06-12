%{
    #include<stdio.h>
    #include"ass6.tab.h"
%}
datatype int|float|char|string|boolean
digits [0-9]
letters [A-Za-z]
identifiers {letters}|({letters}|{digits})*
comma [,]
SC [;]

%%
{datatype} {return datatype;}
{identifiers} {return identifiers;}
{comma} {return comma;}
{SC} {return SC;}
\n {return 0;}
%%
