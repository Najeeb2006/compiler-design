%{
#include <string.h>
char longest[100]="";
%}
%%
[a-zA-Z]+   { if(strlen(yytext)>strlen(longest)) strcpy(longest,yytext); }
[ \t\n]      { ; }
%%
int main(){
    yy_scan_string("the quick brown fox jumped extraordinarily high");
    yylex();
    printf("Longest word: %s (%lu)\n",longest,strlen(longest));
    return 0;
}
int yywrap(){ return 1; }
