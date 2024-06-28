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
    if(head==NULL)return NULL;
    struct List *p=head;
    while(p!=NULL){
        struct List *min=p;
        struct List *q=p->next;
        while(q!=NULL){
            if(q->data<min->data){
                min=q;
            }
            q=q->next;
        }
        int temp=p->data;
        p->data=min->data;
        min->data=temp;
        p=p->next;
    }
    return head;    
}

int main(){
    int x=0;
    struct List *L=NULL;
    while(scanf("%d",&x)){
        L=ADD(L,x);
        if(getchar()=='\n')break;
    }
    L=SORT(L);
    if(L!=NULL)PRINT(L);
    else printf("NULL");
    return 0;
}