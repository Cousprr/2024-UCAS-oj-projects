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
int f=0;
void print(tree T){
    if(T!=NULL){
        if(f==0){printf("%c",T->ch);f++;}
        else printf(" %c",T->ch);
        if(T->lchild!=NULL)print(T->lchild);
        if(T->rchild!=NULL)print(T->rchild);
    }
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
    print(T);
    return 0;
}