%{
int cm=0;
%}
%%
"//".*                       { cm++; }
"/*"([^*]|\*+[^*/])*\*+"/"   { cm++; }
.|\n                          { printf("%s",yytext); }
%%
int main(){
    yy_scan_string("int a,b; /*decl*/\nc=a+b; //add\n");
    yylex();
    printf("\nComment lines removed: %d\n",cm);
    return 0;
}
int yywrap(){ return 1; }
