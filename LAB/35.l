%{
int v=0;
%}
%%
[0-3][0-9][-\/][0-1][0-9][-\/][1-2][0-9]{3}   { v=1; }
.|\n                                             { ; }
%%
int main(){
    yy_scan_string("15-08-2005");
    yylex();
    printf(v?"Valid DOB\n":"Invalid DOB\n");
    return 0;
}
int yywrap(){ return 1; }
