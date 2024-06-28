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
    int floor;
    struct node *lchild;
    struct node *rchild;
}node,*tree;

int flag;
int f;
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
        t->floor=f;
        f++;
        if(a!=-1){flag=a-1;t->lchild=create(t->lchild);}
        f--;
        if(b!=-1){flag=b-1;t->rchild=create(t->rchild);}
    }
    return t;
}
void print(tree T){
    if(T!=NULL){
        switch(T->floor){
            case 0:break;
            case 1:printf("-");break;
            case 2:printf("--");break;
            case 3:printf("---");break;
            default:break;
        }
        printf("%c\n",T->ch);
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
//好像别人用的dfs深度算法更高级