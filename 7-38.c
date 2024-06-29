#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
int vaclink;
struct node *next;
} NodeLink;

typedef struct{
    int vexnum;
    struct{
        int vac;
        char ch;
        int tag;
        NodeLink *first;//指向第一个表结点
    }v[100];
}Graph;
Graph init(Graph G){
    G.vexnum=0;
    for(int i=0;i<10;i++){
        G.v[i].vac=i;
        G.v[i].tag=0;
        G.v[i].first=NULL;
    }
    return G;
}
Graph insert(Graph G,int a,int i){
    NodeLink *q=G.v[i].first;
    if(q==NULL){
        q=(NodeLink*)malloc(sizeof(NodeLink));
        q->vaclink=a;
        q->next=NULL;
        G.v[i].first=q;
    }
    else{
        while(q->next!=NULL)q=q->next;
        NodeLink *p=(NodeLink*)malloc(sizeof(NodeLink));
        p->vaclink=a;
        p->next=NULL;
        q->next=p;
    }
    return G;
}
char temp[100];
int flag;
void searchroad(Graph G,int i){
    NodeLink *p=G.v[i].first;
    if(G.v[i].tag==1){
        temp[flag++]=G.v[i].ch;
        searchroad(G,p->vaclink);
        p=p->next;
        searchroad(G,p->vaclink);        
    }
    else{
        temp[flag++]=G.v[i].ch;
        return;
    }
    return;
}

int main(){
    Graph G;
    G=init(G);
    int a=0,b=0;
    scanf("%d\n",&G.vexnum);
    for(int i=0;i<G.vexnum;i++){
        scanf("%c",&G.v[i].ch);
        if(G.v[i].ch=='+'||G.v[i].ch=='-'||G.v[i].ch=='*'||G.v[i].ch=='/'){
            G.v[i].tag=1;
            scanf("%d %d",&a,&b);
            G=insert(G,a,i);
            G=insert(G,b,i);
        }
        else{
            G.v[i].tag=0;
        }
        getchar();
    }
    searchroad(G,0);
    for(int j=flag-1;j>=0;j--)printf("%c",temp[j]);
    return 0;
}