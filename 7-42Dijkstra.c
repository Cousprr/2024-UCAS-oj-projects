#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
int vaclink;
int dist;
struct node *next;
} NodeLink;

typedef struct{
    int vexnum;
    struct{
        int vac;
        NodeLink *first;
    }v[100];
}Graph;

int origin;
Graph init(Graph G){
    G.vexnum=0;
    for(int i=0;i<10;i++){
        G.v[i].vac=i;
        G.v[i].first=NULL;
    }
    return G;
}
Graph create(Graph G,char input[]){
    G=init(G);
    scanf("%d %d\n",&G.vexnum,&origin);
    int i=4;
    int dis=0;
    while(input[i]!='\0'){
        dis=dis*10+input[i]-'0';
        i++;
    }
    NodeLink *q=G.v[input[0]-'0'].first;
    if(q==NULL){
            q=(NodeLink*)malloc(sizeof(NodeLink));
            q->vaclink=input[2]-'0';
            q->dist=dis;
            q->next=NULL;
            G.v[input[0]-'0'].first=q;
        }
        else{
            while(q->next!=NULL)q=q->next;
            NodeLink *p=(NodeLink*)malloc(sizeof(NodeLink));
            p->vaclink=input[2]-'0';
            p->dist=dis;
            p->next=NULL;
            q->next=p;
        }
    return G;
}
void dijkstra(Graph G,int origin){
    int i;
    for(i=0;i<G.vexnum;i++){
            int min=100000000;
            int minindex=0;
            for(int j=0;j<G.vexnum;j++){
                if(G.v[j].first->dist<min){
                    min=G.v[j].first->dist;
                    minindex=j;
                }
            }
            NodeLink *p=G.v[minindex].first;
            while(p!=NULL){
                if(G.v[p->vaclink].first->dist>G.v[minindex].first->dist+p->dist){
                    G.v[p->vaclink].first->dist=G.v[minindex].first->dist+p->dist;
                }
                p=p->next;
            }
        }
    }
void print(Graph G){
    int i;
    for(i=0;i<G.vexnum;i++){
        printf("%d ",G.v[i].first->dist);
    }
    printf("\n");
}


int main(){
    Graph G;
    char input[100];
    while(1){
        if(~scanf("%s",input)){
            G=create(G,input);
            input[0]='\0';
            input[1]='\0';
        }
        else{
            print(G);
            break;
        }   
    }
    return 0;
}