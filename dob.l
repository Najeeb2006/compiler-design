%{
#include<stdio.h>
%}

%%

[0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9]    { printf("Valid DOB\n"); }

.*                                             { printf("Invalid DOB\n"); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter DOB (DD/MM/YYYY): ");
    yylex();
    return 0;
}