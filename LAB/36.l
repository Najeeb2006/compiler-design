%{
int d=0;
%}
%%
[0-9]+   { d=1; }
.|\n      { ; }
%%
int main(){
    yy_scan_string("12345");
    yylex();
    printf(d?"Digit\n":"Not a digit\n");
    return 0;
}
int yywrap(){ return 1; }
