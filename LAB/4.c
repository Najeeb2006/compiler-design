#include <stdio.h>
#include <string.h>
int main(){
    char e[100];
    printf("Enter expression: ");
    fgets(e,100,stdin);
    e[strcspn(e,"\n")]=0;
    for(int i=0;e[i];i++)
        if(strchr("+-*/",e[i]))
            printf("%c is a valid arithmetic operator\n",e[i]);
    return 0;
}
