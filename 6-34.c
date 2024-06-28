#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parent[100],lchild[100],rchild[100];
int len;
int u,v;

int search(int u,int v,int pa[]){
    if(pa[u]==v)return 1;
    else if(pa[u]==0)return 0;
    else search(pa[u],v,pa);
}

int main(){
    char ch=getchar();
    while(ch!=EOF && ch!='\n'){
        if(ch!=' ')parent[len++]=ch-'0';
        ch=getchar();
    }
    for(int i=0;i<len;i++){
        scanf("%d",&lchild[i]);
    }
    for(int i=0;i<len;i++){
        scanf("%d",&rchild[i]);
    }
    scanf("%d %d",&u,&v);
    if(u==v){printf("0");return 0;}
    printf("%d",search(u,v,parent));
    return 0;
}