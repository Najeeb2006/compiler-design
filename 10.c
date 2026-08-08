#include <stdio.h>
#include <string.h>
int main(){
    char A='S';
    char alts[10][20]={"iEtS","iEtSeS","a"};
    int n=3;
    char used[10]={0};
    for(int i=0;i<n;i++){
        if(used[i]) continue;
        int group[10],ng=0;
        group[ng++]=i;
        for(int j=i+1;j<n;j++)
            if(!used[j] && alts[j][0]==alts[i][0]) group[ng++]=j;
        if(ng==1){ printf("%c -> %s\n",A,alts[i]); used[i]=1; continue; }
        int prefixLen=1;
        while(1){
            char c=alts[group[0]][prefixLen];
            if(c==0) break;
            int same=1;
            for(int k=1;k<ng;k++) if(alts[group[k]][prefixLen]!=c) same=0;
            if(!same) break;
            prefixLen++;
        }
        char prefix[20]; strncpy(prefix,alts[group[0]],prefixLen); prefix[prefixLen]=0;
        printf("%c -> %s%c'\n%c' -> ",A,prefix,A,A);
        for(int k=0;k<ng;k++){
            char *rest=alts[group[k]]+prefixLen;
            printf("%s",strlen(rest)?rest:"#");
            if(k<ng-1) printf(" | ");
            used[group[k]]=1;
        }
        printf("\n");
    }
    return 0;
}
