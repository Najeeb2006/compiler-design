%{
int v=0;
%}
%%
[6-9][0-9]{9}   { v=1; }
.|\n              { ; }
%%
int main(){
    yy_scan_string("9876543210");
    yylex();
    printf(v?"Valid mobile number\n":"Invalid mobile number\n");
    return 0;
}
int yywrap(){ return 1; }
