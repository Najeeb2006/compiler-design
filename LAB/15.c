#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    char src[]="int a,b;\na=10;\nb=20;\n";
    int c=0,w=0,l=0,inWord=0;
    for(int i=0;src[i];i++){
        c++;
        if(src[i]=='\n') l++;
        if(isspace(src[i])) inWord=0;
        else if(!inWord){ inWord=1; w++; }
    }
    l++;
    printf("Characters: %d\nWords: %d\nLines: %d\n",c,w,l);
    return 0;
}
