#include <stdio.h>
#include <string.h>
struct Sym{ char name[30],type[10]; int addr; };
struct Sym tab[50]; int cnt=0;
int search(char *n){
    for(int i=0;i<cnt;i++) if(!strcmp(tab[i].name,n)) return i;
    return -1;
}
void insert(char *n,char *t){
    strcpy(tab[cnt].name,n); strcpy(tab[cnt].type,t); tab[cnt].addr=1000+cnt*4; cnt++;
}
void del(char *n){
    int i=search(n);
    if(i<0) return;
    for(;i<cnt-1;i++) tab[i]=tab[i+1];
    cnt--;
}
int main(){
    int ch; char name[30],type[10];
    while(1){
        printf("1.Insert 2.Search 3.Delete 4.Display 5.Exit\n");
        scanf("%d",&ch);
        if(ch==1){ scanf("%s %s",name,type); insert(name,type); }
        else if(ch==2){ scanf("%s",name); printf(search(name)>=0?"Found\n":"Not found\n"); }
        else if(ch==3){ scanf("%s",name); del(name); }
        else if(ch==4){ for(int i=0;i<cnt;i++) printf("%s %s %d\n",tab[i].name,tab[i].type,tab[i].addr); }
        else break;
    }
    return 0;
}
