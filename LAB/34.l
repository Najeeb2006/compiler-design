%{
int v=0;
%}
%%
"http://"[a-zA-Z0-9./_-]+    { v=1; }
"https://"[a-zA-Z0-9./_-]+   { v=1; }
"www."[a-zA-Z0-9./_-]+       { v=1; }
.|\n                           { ; }
%%
int main(){
    yy_scan_string("https://www.example.com/page");
    yylex();
    printf(v?"Valid URL\n":"Invalid URL\n");
    return 0;
}
int yywrap(){ return 1; }
