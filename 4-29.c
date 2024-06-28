#include <stdio.h>
#include <stdlib.h>
struct List{
    char chdata;
    struct List *succ;
    struct List *next;
}*head,*pattern;
struct List *ADD(struct List *head,char x){
    struct List *q=head;
    if(q==NULL)
    {
        q=(struct List *)malloc(sizeof(struct List));
        q->chdata=x;
        q->succ=NULL;
        q->next=NULL;
        return q;
    }
    while(q->next!=NULL)q=q->next;
    struct List *p=(struct List *)malloc(sizeof(struct List));
    p->chdata=x;
    p->next=NULL;
    q->next=p;
    p->succ=q;
    return head;
}
void get_next(struct List *pattern){
    struct List *p=pattern;
    struct List *q=(struct List *)malloc(sizeof(struct List));
    q->next=p;
    q->succ=NULL;
    p->succ=q;
    while(p->next!=NULL){
        if(q->next==pattern||p->chdata==q->chdata){
            p=p->next;
            q=q->next;
            p->succ=q;
        }
        else q=q->succ;
    }
}
int KMP(struct List *head,struct List *pattern){
    get_next(pattern);
    int result=0;
    struct List *str=head;
    struct List *pat=pattern;
    while(str!=NULL && pat!=NULL){
        if(pat==pattern||str->chdata==pat->chdata){
            str=str->next;result++;
            pat=pat->next;
        }
        else{
            pat=pat->succ;
        }
    }
    if(pat==NULL)
        return result;
    else
        return -1;
}

int main(){
    int len1,len2;
    scanf("%d %d",&len1,&len2);
    char str[len1],pat[len2];
    scanf("%s\n%s",str,pat);
    for(int i=0;i<len1;i++)head=ADD(head,str[i]);
    for(int i=0;i<len2;i++)pattern=ADD(pattern,pat[i]);
    int re=KMP(head,pattern);
    if(re!=-1)printf("%d",re-len2);
    else printf("-1");
    return 0;
}