#include<stdio.h>
int l[100],r[100];
int main(){
    int i=0,j=0;
    char ch;
    ch=getchar();
    while(ch!=EOF && ch!='\n'){
        scanf("%d",&l[i]);
        i++;
        ch=getchar();
    }
    ch=getchar();
    while(ch!=EOF && ch!='\n'){
        scanf("%d",&r[j]);
        j++;
        ch=getchar();
    }
    putchar('1');
    for(int k=0;k<j;k++)printf(" %d",r[k]);
    putchar('\n');
    putchar('1');
    for(int k=0;k<i;k++)printf(" %d",l[k]);
    putchar('\n');
    return 0;
}