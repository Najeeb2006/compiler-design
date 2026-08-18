#include <stdio.h>
#include <ctype.h>
int main(){
    char s[200];
    printf("Enter a sentence: ");
    fgets(s,200,stdin);
    int c=0;
    for(int i=0;s[i];i++){
        char x=tolower(s[i]);
        if(isalpha(x) && !(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')) c++;
    }
    printf("Consonants: %d\n",c);
    return 0;
}
