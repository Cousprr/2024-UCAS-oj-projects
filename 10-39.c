#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct List{
    int data;
    struct List *next;
}*head=NULL;

struct List *ADD(struct List *head,int x){
    struct List *q=head;
    if(q==NULL)
    {
        q=(struct List *)malloc(sizeof(struct List));
        q->data=x;
        q->next=NULL;
        return q;
    }
    while(q->next!=NULL)q=q->next;
    struct List *p=(struct List *)malloc(sizeof(struct List));
    p->data=x;
    p->next=NULL;
    q->next=p;
    return head;
}
int flag;
void PRINT(struct List *head){
    while(head !=NULL){
        if(flag)printf(" %d",head->data);
        else {printf("%d",head->data);flag=1;}
        head=head->next;
    }
}

struct List *insert(struct List *A,struct List *B){
    struct List *next=A;
    struct List *q=B;
    while(q!=NULL){
        struct List *p=next;
        if(p->data>q->data){
            struct List *temp=(struct List *)malloc(sizeof(struct List));
            temp->data=q->data;
            temp->next=p;
            A=temp;
            q=q->next;
            next=temp;
            continue;
        }
        while(p->next!=NULL && p->next->data<q->data)p=p->next;
        if(p->next!=NULL){
            struct List *temp=(struct List *)malloc(sizeof(struct List));
            temp->data=q->data;
            temp->next=p->next;
            p->next=temp;
            next=temp;
        }
        else{
            struct List *temp=(struct List *)malloc(sizeof(struct List));
            temp->data=q->data;
            temp->next=NULL;
            p->next=temp;
            next=temp;
        }
        q=q->next;
    }
    return A;
}

int main(){
    int x=0;
    int len1=0,len2=0;
    struct List *A=NULL;
    struct List *B=NULL;
    while(scanf("%d",&x)){
        A=ADD(A,x);
        len1++;
        if(getchar()=='\n')break;
    }
    while(scanf("%d",&x)){
        B=ADD(B,x);
        len2++;
        if(getchar()=='\n')break;
    }
    if(len1>len2){A=insert(A,B);PRINT(A);}
    else{B=insert(B,A);PRINT(B);}
    return 0;
}