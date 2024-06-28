#include<stdio.h>
#include<stdlib.h>
struct List{
    char data;
    struct List *next;
    struct List *prior;
}*head,*tail;
struct List *ADD(struct List *head,char x){
    struct List *p,*q;
    p=(struct List *)malloc(sizeof(struct List));
    p->data=x;
    p->next=NULL;
    if(head==NULL){
        head=p;
        tail=p;
        return head;
    }
    else{
        q=head;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
        p->prior=q;
        tail=p;
        return head;
    }
}

int main(){
    int x=0;
    scanf("%d",&x);
    char a[x];
    scanf("%s",a);
    int i=0;
    while(a[i]!='\0'){
        head=ADD(head,a[i++]);
    }
    struct List *ph=head;
    struct List *pt=tail;
    while(ph!=pt && ph->next!=pt){
        if(ph->data==pt->data){
            ph=ph->next;
            pt=pt->prior;
        }
        else{
            printf("0");
            break;
        }
    }
    if(ph->data==pt->data){
        printf("1");
    }
    return 0;
}