%{
#include <string.h>
char oldW[]="file", newW[]="document";
%}
%%
[a-zA-Z]+   { printf("%s",!strcmp(yytext,oldW)?newW:yytext); }
.|\n         { printf("%s",yytext); }
%%
int main(){
    yy_scan_string("this is a sample file used to test the file program");
    yylex();
    printf("\n");
    return 0;
}
int yywrap(){ return 1; }
