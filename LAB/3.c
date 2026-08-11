#include <stdio.h>
#include <string.h>
int main(){
    char src[]="int  a = 10;\n// comment\n/*block*/ int b=20;\t";
    int i=0,n=strlen(src);
    while(i<n){
        if(src[i]==' '||src[i]=='\t'||src[i]=='\n'){i++;continue;}
        if(src[i]=='/'&&src[i+1]=='/'){while(i<n&&src[i]!='\n')i++;continue;}
        if(src[i]=='/'&&src[i+1]=='*'){i+=2;while(i<n&&!(src[i]=='*'&&src[i+1]=='/'))i++;i+=2;continue;}
        putchar(src[i]);i++;
    }
    printf("\n");
    return 0;
}
