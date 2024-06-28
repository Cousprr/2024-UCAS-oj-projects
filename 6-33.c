#include<stdio.h>
#include<stdlib.h>
int l[100],r[100],fa[100];
int main(){
    int i=0,j=0;
    char ch;
    do{
        scanf("%d",&l[i]);
        fa[l[i]]=i;
        i++;
        
        ch=getchar();
    }while(ch!=EOF && ch!='\n');
    do{
        scanf("%d",&r[j]);
        fa[r[j]]=j;
        j++;
        ch=getchar();
    }while(ch!=EOF && ch!='\n');
    int son,father=0;
    scanf("%d %d",&son,&father);
    int fl=son;
    while(fl!=0){
        if(fa[fl]==father){printf("1");return 0;}
        else fl=fa[fl];
    }
    printf("0");
    return 0;
}