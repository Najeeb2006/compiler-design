%{
int v=0;
%}
%%
[a-zA-Z0-9._]+"@"[a-zA-Z0-9]+"."[a-zA-Z]{2,3}   { v=1; }
.|\n                                              { ; }
%%
int main(){
    yy_scan_string("abc.test@gmail.com");
    yylex();
    printf(v?"Valid email\n":"Invalid email\n");
    return 0;
}
int yywrap(){ return 1; }
