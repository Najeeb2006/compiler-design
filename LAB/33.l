%{
int p=0,n=0;
%}
%%
"-"[0-9]+   { n++; }
[0-9]+       { p++; }
[ \t\n]      { ; }
%%
int main(){
    yy_scan_string("10 -5 20 -3 7");
    yylex();
    printf("Positive: %d\nNegative: %d\n",p,n);
    return 0;
}
int yywrap(){ return 1; }
