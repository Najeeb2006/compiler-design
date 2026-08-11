#include <stdio.h>
#include <ctype.h>
#include <string.h>
int isKeyword(char *s){
    char *k[]={"int","float","char","if","else","while","for","return","void"};
    for(int i=0;i<9;i++) if(!strcmp(s,k[i])) return 1;
    return 0;
}
int main(){
    char src[]="int a,b; a=10+b; //cmt\n/*c*/ float x=2.5;";
    int i=0,n=strlen(src);
    while(i<n){
        char c=src[i];
        if(c==' '||c=='\t'||c=='\n'){i++;continue;}
        if(c=='/'&&src[i+1]=='/'){while(i<n&&src[i]!='\n')i++;continue;}
        if(c=='/'&&src[i+1]=='*'){i+=2;while(i<n&&!(src[i]=='*'&&src[i+1]=='/'))i++;i+=2;continue;}
        if(isalpha(c)||c=='_'){
            char buf[50];int j=0;
            while(i<n&&(isalnum(src[i])||src[i]=='_')) buf[j++]=src[i++];
            buf[j]=0;
            printf(isKeyword(buf)?"Keyword: %s\n":"Identifier: %s\n",buf);
            continue;
        }
        if(isdigit(c)){
            char buf[50];int j=0;
            while(i<n&&(isdigit(src[i])||src[i]=='.')) buf[j++]=src[i++];
            buf[j]=0;
            printf("Constant: %s\n",buf);
            continue;
        }
        if(strchr("+-*/=<>",c)){printf("Operator: %c\n",c);i++;continue;}
        i++;
    }
    return 0;
}
