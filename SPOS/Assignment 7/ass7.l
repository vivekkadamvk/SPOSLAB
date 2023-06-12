%{
#include <string.h>
#include "ass7.tab.h"
%}

%%
"and"  { return COMP; }
"or"   { return COMP; }
"but"  { return COMP; }
"."  { return DOT; }
","  { return COMMA; }
[a-zA-Z]+ {return WORD; }
[ \t\n] {}
. {}
%%