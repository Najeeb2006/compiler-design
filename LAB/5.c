#include <stdio.h>
#include <string.h>
int main(){
    char src[]="int a;\n\tint b;\n int c;\n";
    int sp=0,tb=0,nl=0;
    for(int i=0;src[i];i++){
        if(src[i]==' ')sp++;
        else if(src[i]=='\t')tb++;
        else if(src[i]=='\n')nl++;
    }
    printf("Spaces: %d\nTabs: %d\nNewlines: %d\n",sp,tb,nl);
    return 0;
}
