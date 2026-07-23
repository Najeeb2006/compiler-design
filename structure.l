%{
#include<stdio.h>
%}

%%

[a-zA-Z]+    { printf("Word\n"); }

[0-9]+       { printf("Number\n"); }

.|\n         ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    yylex();
    return 0;
}