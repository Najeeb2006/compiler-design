#include <stdio.h>
#include <string.h>
#include <ctype.h>
char prod[10][20]; int n;
int trail[26][128];
void computeTrailing(){
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
                    int len=strlen(alt);
                    char sl=alt[len-1];
                    if(!isupper(sl)){ if(!trail[A-'A'][(int)sl]){trail[A-'A'][(int)sl]=1;changed=1;} }
                    else {
                        for(int k=0;k<128;k++)
                            if(trail[sl-'A'][k]&&!trail[A-'A'][k]){trail[A-'A'][k]=1;changed=1;}
                        if(len>=2 && !isupper(alt[len-2]))
                            if(!trail[A-'A'][(int)alt[len-2]]){trail[A-'A'][(int)alt[len-2]]=1;changed=1;}
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
    computeTrailing();
    for(int p=0;p<n;p++){
        char A=prod[p][0];
        printf("TRAILING(%c) = { ",A);
        for(int k=0;k<128;k++) if(trail[A-'A'][k]) printf("%c ",k);
        printf("}\n");
    }
    return 0;
}
