%{
#include <string.h>
char target[]="test";
int cnt=0;
%}
%%
[a-zA-Z]+   { if(!strcmp(yytext,target)) cnt++; }
[ \t\n]      { ; }
%%
int main(){
    yy_scan_string("this is a test to test the word test frequency");
    yylex();
    printf("Frequency of '%s' = %d\n",target,cnt);
    return 0;
}
int yywrap(){ return 1; }
