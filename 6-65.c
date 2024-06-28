#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char fir[1000],mid[1000],las[1000];
struct tree{
    char data;
    struct tree *lchild,*rchild;
}*root;
struct tree *create(struct tree *root,char *fir,char *mid,int l1,int l2,int s1,int s2){
    if(root==NULL){
        root=(struct tree*)malloc(sizeof(struct tree));
        root->lchild=NULL;
        root->rchild=NULL;
    }
    if(l1>s1) return NULL;
    root->data=fir[l1];
    int target;
    for(target=l2;target<=s2;target++)
    {
        if(mid[target]==fir[l1]) break;
    }
    root->lchild=create(root->lchild,fir,mid,l1+1,l2,l1+target-l2,target-1);
    root->rchild=create(root->rchild,fir,mid,l1+target-l2+1,target+1,s1,s2);
    return root;
}

void print(struct tree *T){
    if(T!=NULL){
        if(T->lchild!=NULL)print(T->lchild);
        if(T->rchild!=NULL)print(T->rchild);
        printf("%c",T->data);
    }
}
int main(){
    scanf("%s%s",fir,mid);
    struct tree *T=NULL;
    int len=strlen(fir);
    T=create(T,fir,mid,0,0,len-1,len-1);
    print(T);
    return 0;
}
