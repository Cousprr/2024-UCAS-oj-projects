#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char ch;
    struct node *lchild;
    struct node *rchild;
}node,*tree;

int len;
int flag;
tree create(tree T,char a[]){
    tree t=T;
    if(t==NULL){
        t=(tree)malloc(sizeof(node));
        t->lchild=NULL;
        t->rchild=NULL;
    }
    if(flag<len){
        t->ch=a[flag];
        flag++;
        if(a[flag]!='^')t->lchild=create(t->lchild,a);
        else flag++;
        if(a[flag]!='^')t->rchild=create(t->rchild,a);
        else flag++;
    }
    return t; 
}

tree search(tree T,char p,char q){
    if(T == NULL)return NULL;
    if(T->ch==p || T->ch==q)return T;
    tree left=search(T->lchild,p,q);
    tree right=search(T->rchild,p,q);
    if(left && right) return T;                   //如果左子树和右子树都存在给定节点,则根为LCA
    else return (left!=NULL)?left:right;          //否则LCA位于左子树或者右子树
}
tree searchgrandp(tree T,char p){
    if(T==NULL)return NULL;
    if(T->lchild!=NULL && T->lchild->ch==p)return T;
    else if(T->rchild!=NULL && T->rchild->ch==p)return T;
    tree left=searchgrandp(T->lchild,p);
    if(left!=NULL)return left;
    tree right=searchgrandp(T->rchild,p);
    if(right!=NULL)return right;
    return NULL;
}
int main(){
    char a[100];
    char p,q;
    scanf("%s\n",a);
    scanf("%c %c",&p,&q);
    len=strlen(a);
    tree T=NULL;
    T=create(T,a);
    tree t=search(T,p,q);
    if(T->ch==p || T->ch==q)printf("%c",T->ch);
    else if(t->ch==p)printf("%c",searchgrandp(T,p)->ch);
    else if(t->ch==q)printf("%c",searchgrandp(T,q)->ch);
    else printf("%c",t->ch);
    return 0;
}
