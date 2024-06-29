#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct node{
int vaclink;
struct node *next;
} NodeLink;

typedef struct{
    int vexnum;
    struct{
        int vac;
        int mpl;
        NodeLink *first;//指向第一个表结点
    }v[100];
}Graph;
char link[1000];
int flag=1;
Graph init(Graph G){
    G.vexnum=0;
    for(int i=0;i<10;i++){
        G.v[i].vac=i;
        G.v[i].mpl=0;
        G.v[i].first=NULL;
    }
    return G;
}
Graph create(Graph G){
    G=init(G);
    scanf("%d\n",&G.vexnum);
    scanf("%s",link);
    int len=strlen(link);
    int i=0;
    while(link[i]!='\0'){
        if(link[i]=='0'||link[i+2]=='0')flag=0;
        NodeLink *q=G.v[link[i]-'0'].first;
        if(q==NULL){
            q=(NodeLink*)malloc(sizeof(NodeLink));
            q->vaclink=link[i+2]-'0';
            q->next=NULL;
            G.v[link[i]-'0'].first=q;
        }
        else{
            while(q->next!=NULL)q=q->next;
            NodeLink *p=(NodeLink*)malloc(sizeof(NodeLink));
            p->vaclink=link[i+2]-'0';
            p->next=NULL;
            q->next=p;
        }
        i=i+4;
    }
    return G;
}

int temp;
int isroadlong(Graph G,int vac,int depth){
    NodeLink *p=G.v[vac].first;
    while(p!=NULL){
        temp=(temp>depth)?temp:depth;
        isroadlong(G,p->vaclink,depth+1);
        p=p->next;
    }
    return temp;
}
int f;
void print(Graph G){
    for(int i=flag;i<G.vexnum+flag;i++){
        if(!f++)printf("%d",G.v[i].mpl);
        else printf(",%d",G.v[i].mpl);
    }
}

int main(){
    Graph G;
    G=create(G);
    for(int i=flag;i<G.vexnum+flag;i++){
        G.v[i].mpl=isroadlong(G,i,1);
        temp=0;
    }
    print(G);
    return 0;
}