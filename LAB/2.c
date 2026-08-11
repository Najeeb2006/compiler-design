#include <stdio.h>
#include <string.h>
int main(){
    char line[200];
    printf("Enter a line: ");
    fgets(line,200,stdin);
    line[strcspn(line,"\n")]=0;
    int n=strlen(line);
    if(n>=2 && line[0]=='/' && line[1]=='/')
        printf("Single line comment\n");
    else if(n>=4 && line[0]=='/' && line[1]=='*' && line[n-2]=='*' && line[n-1]=='/')
        printf("Multi line comment\n");
    else
        printf("Not a comment\n");
    return 0;
}
