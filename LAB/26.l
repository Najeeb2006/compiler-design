%%
[A-Z]+   { printf("Capital word: %s\n",yytext); }
.|\n      { ; }
%%
int main(){
    yy_scan_string("Hello WORLD this is TEST data");
    yylex();
    return 0;
}
int yywrap(){ return 1; }
