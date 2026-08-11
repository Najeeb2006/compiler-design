#include <stdio.h>
#include <ctype.h>
int main(){
    char id[50];
    printf("Enter identifier: ");
    scanf("%s",id);
    int valid=(isalpha(id[0])||id[0]=='_');
    for(int i=1;valid&&id[i];i++)
        if(!isalnum(id[i])&&id[i]!='_') valid=0;
    printf(valid?"Valid identifier\n":"Invalid identifier\n");
    return 0;
}
