#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stkOp[50]; int topOp=-1;
char stkVal[50][10]; int topVal=-1;
int tc=1;
int prec(char c){ if(c=='*'||c=='/') return 2; if(c=='+'||c=='-') return 1; return 0; }
void gen(){
    char op=stkOp[topOp--];
    char v2[10],v1[10],t[10];
    strcpy(v2,stkVal[topVal--]);
    strcpy(v1,stkVal[topVal--]);
    sprintf(t,"t%d",tc++);
    printf("%s = %s %c %s\n",t,v1,op,v2);
    strcpy(stkVal[++topVal],t);
}
int main(){
    char e[100];
    printf("Enter expression: ");
    scanf("%s",e);
    for(int i=0;e[i];i++){
        char c=e[i];
        if(isalnum(c)){ char v[2]={c,0}; strcpy(stkVal[++topVal],v); }
        else if(c=='('){ stkOp[++topOp]=c; }
        else if(c==')'){ while(topOp>=0&&stkOp[topOp]!='(') gen(); topOp--; }
        else { while(topOp>=0&&prec(stkOp[topOp])>=prec(c)) gen(); stkOp[++topOp]=c; }
    }
    while(topOp>=0) gen();
    printf("Result: %s\n",stkVal[topVal]);
    return 0;
}
