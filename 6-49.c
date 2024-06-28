#include<stdio.h>
#include<stdlib.h>
struct chart{
    char ch;
    int ltag;
    int rtag;
}v[100];
int k=0;
typedef struct node{
    char ch;
    struct node *lchild;
    struct node *rchild;
}node,*tree;

tree Qdata[100];
int front;
int rear;

void push(tree x){
    Qdata[rear]=x;
    rear++;
}
tree pop(){
    tree x=Qdata[front];
    front++;
    return x;
}

int flag;
tree create(tree T){
    tree t=T;
    if(t==NULL){
        t=(tree)malloc(sizeof(node));
        t->lchild=NULL;
        t->rchild=NULL;
    }
    if(flag<k){
        int a=v[flag].ltag;
        int b=v[flag].rtag;
        t->ch=v[flag].ch;
        if(a!=-1){flag=a-1;t->lchild=create(t->lchild);}
        if(b!=-1){flag=b-1;t->rchild=create(t->rchild);}
    }
    return t;
}

int judge(tree T){
    while(Qdata[front]!=NULL){
        T=pop();
        push(T->lchild);
        push(T->rchild);
    }
    for(int t=front;t<rear;t++){
        if(Qdata[t]!=NULL)return 1;
    }
    return 0;
}

int main(){
    char ch=getchar();
    while(ch!=EOF && ch!='\n'){
        v[k].ch=ch;
        scanf("%d %d",&v[k].ltag,&v[k].rtag);
        getchar();
        k++;
        ch=getchar();
    }
    tree T=NULL;
    T=create(T);
    push(T);
    int re=judge(T);
    if(re==0)printf("YES\n");
    else printf("NO\n");
    return 0;
}