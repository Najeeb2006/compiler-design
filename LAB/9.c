#include <stdio.h>
#include <string.h>
int main(){
    char A='L';
    char alts[10][20]={"L,S","S"};
    int n=2;
    char alpha[10][20]; int na=0;
    char beta[10][20]; int nb=0;
    for(int i=0;i<n;i++){
        if(alts[i][0]==A) strcpy(alpha[na++],alts[i]+1);
        else strcpy(beta[nb++],alts[i]);
    }
    if(na==0){ printf("No left recursion in %c\n",A); return 0; }
    printf("%c -> ",A);
    for(int i=0;i<nb;i++) printf("%s%c' ",beta[i],A);
    printf("\n%c' -> ",A);
    for(int i=0;i<na;i++) printf("%s%c' | ",alpha[i],A);
    printf("#\n");
    return 0;
}
