#include <stdio.h>
#include <string.h>
int reg[3]; char regName[3][10]; int used[3]={0,0,0};
int getReg(char *v){
    for(int i=0;i<3;i++) if(used[i]&&!strcmp(regName[i],v)) return i;
    for(int i=0;i<3;i++) if(!used[i]){ strcpy(regName[i],v); used[i]=1; return i; }
    return 0;
}
int main(){
    char res[10],a[10],op[3],b[10];
    printf("Enter TAC (res = a op b): ");
    scanf("%s = %s %s %s",res,a,op,b);
    int r1=getReg(a), r2=getReg(b), rd=getReg(res);
    printf("MOV R%d, %s\n",r1,a);
    printf("MOV R%d, %s\n",r2,b);
    if(op[0]=='+') printf("ADD R%d, R%d, R%d\n",rd,r1,r2);
    else if(op[0]=='-') printf("SUB R%d, R%d, R%d\n",rd,r1,r2);
    else if(op[0]=='*') printf("MUL R%d, R%d, R%d\n",rd,r1,r2);
    else if(op[0]=='/') printf("DIV R%d, R%d, R%d\n",rd,r1,r2);
    printf("MOV %s, R%d\n",res,rd);
    return 0;
}
