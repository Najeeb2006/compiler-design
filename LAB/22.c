#include <stdio.h>
#include <ctype.h>
int main(){
    char s[200];
    printf("Enter a sentence: ");
    fgets(s,200,stdin);
    int v=0;
    for(int i=0;s[i];i++){
        char c=tolower(s[i]);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') v++;
    }
    printf("Vowels: %d\n",v);
    return 0;
}
