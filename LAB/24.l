%{
int ln=1;
%}
%%
^.*\n   { printf("%d: %s",ln++,yytext); }
%%
int main(){
    yy_scan_string("int a;\nint b;\na=b+1;\n");
    yylex();
    return 0;
}
int yywrap(){ return 1; }
