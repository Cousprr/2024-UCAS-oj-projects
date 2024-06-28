#include<stdio.h>
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
void PRINT(struct List *head){
    while(head !=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

struct List *DELETE(struct List *head,int i){
    if(head==NULL)return NULL;
    struct List *p=head;
    struct List *q=head;
    if(i==0){
        head=head->next;
        return head;
    }
    for(int j=0;j<i-1;j++){
        p=p->next;
        q=q->next;
    }
    q=q->next;
    p->next=q->next;
    free(q); 
    return head;   
}
int main(){
    int x=0;
    int len=0;
    struct List *L=NULL;
    while(scanf("%d",&x)){
        L=ADD(L,x);
        len++;
        if(getchar()=='\n')break;
    }
    scanf("%d",&x);
    if(len<x){
        printf("NULL");
        return 0;
    }
    L=DELETE(L,x);
    if(L!=NULL)PRINT(L);
    else printf("NULL");
    return 0;
}