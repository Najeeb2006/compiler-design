%%
[0-9]+(\.[0-9]+)?   { printf("Constant: %s\n",yytext); }
.|\n                 { ; }
%%
int main(){
    yy_scan_string("#define PI 3.14\nint a,b,c=30;\n");
    yylex();
    return 0;
}
int yywrap(){ return 1; }
