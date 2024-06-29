#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct node{
int vaclink;
struct node *next;
} NodeLink;

typedef struct{
    int vexnum,edgenum,kind;//图的顶点数、边数、种类标志
    struct{
        int vac;
        NodeLink *first;//指向第一个表结点
    }v[100];
}Graph;
char link[1000];
int flag=1;
Graph init(Graph G){
    G.vexnum=0;
    G.edgenum=0;
    G.kind=0;
    for(int i=0;i<10;i++){
        G.v[i].vac=i;
        G.v[i].first=NULL;
    }
    return G;
}
int a,b;
int depth;
Graph create(Graph G){
    G=init(G);
    scanf("%d,%d\n",&G.vexnum,&depth);
    scanf("%d,%d",&a,&b);
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

int visit[100];
bool isroadexist(Graph G,int vac1,int vac2,int depth){
    NodeLink *p=G.v[vac1].first;
    while(p!=NULL){
        if (p->vaclink==vac2 && depth==1) return true;
        if(!visit[p->vaclink]){
            visit[p->vaclink] = 1;
            if(isroadexist(G,p->vaclink,vac2,depth-1)) return true;
            else visit[p->vaclink] = 0;
        }
        p=p->next;
    }
    return false;
}


int main(){
    Graph G;
    G=create(G);
    bool re=isroadexist(G,a,b,depth);
    if(re) printf("true");
    else printf("false");
    return 0;
}