%%
"<"[a-zA-Z\/][^>]*">"   { printf("Tag: %s\n",yytext); }
.|\n                     { ; }
%%
int main(){
    yy_scan_string("<html><body><h1>Heading</h1><p>Para</p></body></html>");
    yylex();
    return 0;
}
int yywrap(){ return 1; }
