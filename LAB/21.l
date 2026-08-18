%{
int m=0,h=0;
%}
%%
^"#define".*    { m++; }
^"#include".*   { h++; }
.|\n              { ; }
%%
int main(){
    yy_scan_string("#define PI 3.14\n#include<stdio.h>\n#include<conio.h>\nvoid main(){}\n");
    yylex();
    printf("Macros: %d\nHeaders: %d\n",m,h);
    return 0;
}
int yywrap(){ return 1; }
