#include <stdio.h>
#include <string.h>
#include <ctype.h>
char prod[10][20]; int n;
int lead[26][128];
void computeLeading(){
    int changed=1;
    while(changed){
        changed=0;
        for(int p=0;p<n;p++){
            char A=prod[p][0];
            char *rhs=prod[p]+2;
            char alt[20]; int ai=0;
            for(int i=0;;i++){
                if(rhs[i]=='|'||rhs[i]=='\0'){
                    alt[ai]=0;
                    char s0=alt[0];
                    if(!isupper(s0)){ if(!lead[A-'A'][(int)s0]){lead[A-'A'][(int)s0]=1;changed=1;} }
                    else {
                        for(int k=0;k<128;k++)
                            if(lead[s0-'A'][k]&&!lead[A-'A'][k]){lead[A-'A'][k]=1;changed=1;}
                        if(alt[1] && !isupper(alt[1]))
                            if(!lead[A-'A'][(int)alt[1]]){lead[A-'A'][(int)alt[1]]=1;changed=1;}
                    }
                    ai=0;
                    if(rhs[i]=='\0') break;
                } else alt[ai++]=rhs[i];
            }
        }
    }
}
int main(){
    strcpy(prod[0],"E=E+T|T");
    strcpy(prod[1],"T=T*F|F");
    strcpy(prod[2],"F=(E)|i");
    n=3;
    computeLeading();
    for(int p=0;p<n;p++){
        char A=prod[p][0];
        printf("LEADING(%c) = { ",A);
        for(int k=0;k<128;k++) if(lead[A-'A'][k]) printf("%c ",k);
        printf("}\n");
    }
    return 0;
}
