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
        if(a[flag]!='#')t->lchild=create(t->lchild,a);
        else flag++;
        if(a[flag]!='#')t->rchild=create(t->rchild,a);
        else flag++;
    }
    return t; 
}

int prior(char a,char b){
    switch(a){
        case'-':
            if(b=='-')
                return -1;
            else
                return 0;
        case'*':case'/':
            if(b=='+' || b=='-')
                return 1;
            else
                return 0;      
        default:
            return 0;
    } 
}


void print(tree T){
    int bk=0;
    if(T!=NULL && T->lchild!=NULL){
        bk=prior(T->ch,T->lchild->ch);
        if(bk==1) printf("(");
        print(T->lchild);
        if(bk==1) printf(")");
    }
    printf("%c",T->ch);
    if(T!=NULL && T->rchild!=NULL){
        bk=prior(T->ch,T->rchild->ch);
        if(bk==1 || bk==-1) printf("(");
        print(T->rchild);
        if(bk==1 || bk==-1) printf(")");
    }
}

int main(){
    char a[100];
    scanf("%s",a);
    len=strlen(a);
    //printf("%d,%s\n",len,a);
    tree T=NULL;
    T=create(T,a);
    print(T);
    return 0;
}

/*
-*+a##b##-c##d##--g##h##e##
(a+b)*(c-d)-(g-h-e)
vs
-*+a##b##-c##d##-e##-g##h##
(a+b)*(c-d)-(e-(g-h))
*/