%%
"abc"   { printf("ABC"); }
.|\n     { printf("%s",yytext); }
%%
int main(){
    yy_scan_string("abc123abcxyzabc");
    yylex();
    printf("\n");
    return 0;
}
int yywrap(){ return 1; }
