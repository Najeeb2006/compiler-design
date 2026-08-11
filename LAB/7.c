#include <stdio.h>
#include <string.h>
char prod[10][20];
int n;
int first[26][128];
int nullable(char c){
    if(islower(c)) return 0;
    return first[c-'A']['#'];
}
void computeFirst(){
    int changed=1;
    while(changed){
        changed=0;
        for(int p=0;p<n;p++){
            char A=prod[p][0];
            char *rhs=prod[p]+2;
            char alt[20]; int ai=0;
            for(int i=0;;i++){
                if(rhs[i]=='/'||rhs[i]=='\0'){
                    alt[ai]=0;
                    int allNullable=1;
                    for(int j=0;alt[j];j++){
                        char s=alt[j];
                        if(s=='#'){
                            if(!first[A-'A']['#']){first[A-'A']['#']=1;changed=1;}
                            allNullable=0;break;
                        }
                        if(islower(s)){
                            if(!first[A-'A'][(int)s]){first[A-'A'][(int)s]=1;changed=1;}
                            allNullable=0;break;
                        }
                        for(int k=0;k<128;k++)
                            if(k!='#'&&first[s-'A'][k]&&!first[A-'A'][k]){first[A-'A'][k]=1;changed=1;}
                        if(!first[s-'A']['#']){allNullable=0;break;}
                    }
                    if(allNullable && alt[0]!=0){
                        if(!first[A-'A']['#']){first[A-'A']['#']=1;changed=1;}
                    }
                    ai=0;
                    if(rhs[i]=='\0') break;
                } else alt[ai++]=rhs[i];
            }
        }
    }
}
int main(){
    strcpy(prod[0],"S=AaAb/BbBa");
    strcpy(prod[1],"A=#");
    strcpy(prod[2],"B=#");
    n=3;
    computeFirst();
    for(int p=0;p<n;p++){
        char A=prod[p][0];
        printf("FIRST(%c) = { ",A);
        for(int k=0;k<128;k++) if(first[A-'A'][k]) printf("%c ",k);
        printf("}\n");
    }
    return 0;
}
