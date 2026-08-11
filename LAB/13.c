#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
char in[100]; int pos=0;
void E(); void Eprime(); void T(); void Tprime(); void F();
void match(char c){ if(in[pos]==c) pos++; else { printf("String not accepted\n"); exit(0); } }
void F(){
    if(in[pos]=='('){ match('('); E(); match(')'); }
    else if(isalpha(in[pos])) pos++;
    else { printf("String not accepted\n"); exit(0); }
}
void Tprime(){ if(in[pos]=='*'){ match('*'); F(); Tprime(); } }
void T(){ F(); Tprime(); }
void Eprime(){ if(in[pos]=='+'){ match('+'); T(); Eprime(); } }
void E(){ T(); Eprime(); }
int main(){
    printf("Enter string: ");
    scanf("%s",in);
    E();
    printf(in[pos]==0?"String accepted\n":"String not accepted\n");
    return 0;
}
