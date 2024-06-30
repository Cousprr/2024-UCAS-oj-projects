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

struct List *SORT(struct List *head){
    struct List *p=head;
    while(p!=NULL){
        struct List *q=p->next;
        while(q!=NULL){
            if(p->data>q->data){
                int temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
    return head;
}
int main(){
    int x=0;
    int len=0;
    scanf("%d\n",&len);
    struct List *L=NULL;
    for(int i=0;i<len;i++){
        scanf("%d",&x);
        L=ADD(L,x);
    }
    L=SORT(L);
    if(L!=NULL)PRINT(L);
    else printf("NULL");
    return 0;
}