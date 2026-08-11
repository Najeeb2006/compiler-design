%{
int c=0,w=0,l=0,inw=0;
%}
%%
\n     { l++; c++; inw=0; }
[ \t]  { c++; inw=0; }
.      { c++; if(!inw){w++;inw=1;} }
%%
int main(){
    yy_scan_string("int a,b,sum;\na=10;\nb=20;\nsum=a+b;\n");
    yylex();
    printf("Characters: %d\nWords: %d\nLines: %d\n",c,w,l);
    return 0;
}
int yywrap(){ return 1; }
