%{
#include <stdlib.h>
double n1,n2,res; char op; int st=0;
%}
%%
[0-9]+(\.[0-9]+)?   { if(st==0){n1=atof(yytext);st=1;} else {n2=atof(yytext);st=2;} }
[+\-*/]              { op=yytext[0]; }
[ \t\n]               { ; }
%%
int main(){
    yy_scan_string("15 + 4");
    yylex();
    if(op=='+') res=n1+n2;
    else if(op=='-') res=n1-n2;
    else if(op=='*') res=n1*n2;
    else if(op=='/') res=n1/n2;
    printf("Result = %.2f\n",res);
    return 0;
}
int yywrap(){ return 1; }
