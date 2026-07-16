#include <stdio.h>
#include <ctype.h>
int op(char c){return c=='+'||c=='-'||c=='*'||c=='/'||c=='='||c=='<'||c=='>'||c=='!'||c=='&'||c=='|';}
int main(){
	char s[200]; int i=0;
	fgets(s,200,stdin);
	while(s[i]){
		if(isspace(s[i])) i++;
		else if(isalpha(s[i])||s[i]=='_'){while(isalnum(s[i])||s[i]=='_') putchar(s[i++]); printf(" -> Identifier\n");}
		else if(isdigit(s[i])){while(isdigit(s[i])||s[i]=='.') putchar(s[i++]); printf(" -> Constant\n");}
		else if(op(s[i])){putchar(s[i]); if((s[i]=='+'&&s[i+1]=='+')||(s[i]=='-'&&s[i+1]=='-')||(s[i]=='='&&s[i+1]=='=')||(s[i]=='!'&&s[i+1]=='=')||(s[i]=='<'&&s[i+1]=='=')||(s[i]=='>'&&s[i+1]=='=')||(s[i]=='&'&&s[i+1]=='&')||(s[i]=='|'&&s[i+1]=='|')) putchar(s[++i]); i++; printf(" -> Operator\n");}
		else i++;   
	}
	return 0;
}
