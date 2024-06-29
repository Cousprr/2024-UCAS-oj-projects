#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
Graph create(Graph G){
    G=init(G);
    scanf("%d,%d\n",&G.vexnum,&G.edgenum);
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
Graph sort(Graph G){
    for(int i=0;i<=G.vexnum;i++){
        NodeLink *p=G.v[i].first;
        while(p!=NULL){
            NodeLink *q=p->next;
            while(q!=NULL){
                if(p->vaclink < q->vaclink){
                    int temp=p->vaclink;
                    p->vaclink=q->vaclink;
                    q->vaclink=temp;
                }
                q=q->next;
            }
            p=p->next;
        }
    }
    return G;
}

void print(Graph G){
    for(int i=flag;i<G.vexnum+flag;i++){
        NodeLink *p=G.v[i].first;
        printf("%d",G.v[i].vac);
        if(p!=NULL)putchar(' ');
        while(p!=NULL){
            if(p->next!=NULL)printf("%d,",p->vaclink);
            else printf("%d",p->vaclink);
            p=p->next;
        }
        printf("\n");
    }
}

int main(){
    Graph G;
    G=create(G);
    G=sort(G);
    print(G);
    return 0;
}