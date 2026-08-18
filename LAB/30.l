%%
"int"|"float"|"char"|"void"|"if"|"else"|"while"|"for"|"return"   { printf("Keyword: %s\n",yytext); }
[a-zA-Z_][a-zA-Z0-9_]*   { printf("Identifier: %s\n",yytext); }
[0-9]+                    { printf("Constant: %s\n",yytext); }
"+"|"-"|"*"|"/"|"="        { printf("Operator: %s\n",yytext); }
"("|")"|"{"|"}"|";"|","    { printf("Punctuation: %s\n",yytext); }
[ \t\n]                    { ; }
%%
int main(){
    yy_scan_string("int a,b,c=30;\nprintf(a);\n");
    yylex();
    return 0;
}
int yywrap(){ return 1; }
