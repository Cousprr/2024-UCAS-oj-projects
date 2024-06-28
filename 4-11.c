#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct List{
    char data;
    int order;
    struct List *next;
}*head;
struct List *ADD(struct List *head,char x,int y){
    struct List *q=head;
    if(q==NULL)
    {
        q=(struct List *)malloc(sizeof(struct List));
        q->data=x;
        q->order=y;
        q->next=NULL;
        return q;
    }
    while(q->next!=NULL)q=q->next;
    struct List *p=(struct List *)malloc(sizeof(struct List));
    p->data=x;
    p->order=y;
    p->next=NULL;
    q->next=p;
    return head;
}
struct List *compare(char s[100],char t[100],struct List *head){
    int i,j=0;
    int len1=strlen(s);
    int len2=strlen(t);
    for(i=0;i<len1;i++){
        int comp=0;
        for(j=0;j<len2;j++){
            if(s[i]!=t[j])comp=1;
            else {comp=0;break;}
        }
        if(comp){
            struct List *q=head;
            if(q==NULL){
                head=ADD(head,s[i],i);
            }
            else{
                while(q!=NULL){
                    if(q->data!=s[i]){comp=1;q=q->next;}
                    else {comp=0;break;}
                }
                if(comp)head=ADD(head,s[i],i);
            }
           
        }
    }
    return head;
}

char s[100],t[100];
struct List *L=NULL;
int main(){
    scanf("%s %s",s,t);
    L=compare(s,t,L);
    if(L!=NULL){
        struct List *q=L;
        struct List *p=L;
        while(q!=NULL){
            printf("%c",q->data);
            q=q->next;
        }
        putchar(' ');
        while(p!=NULL){
            printf("%d",p->order);
            p=p->next;
        }
    }
    else printf("-1");
    return 0;
}