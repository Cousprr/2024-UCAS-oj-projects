#include <stdio.h>
#include <stdlib.h>
typedef struct mode{
    int tag,begin,size;
    struct mode *next;
}Node,*ListNode;
ListNode insert(ListNode L,int x,int y,int z){
    if(L==NULL){
        L=(ListNode)malloc(sizeof(Node));
        L->tag=x;
        L->begin=y;
        L->size=z;
        L->next=NULL;
        return L;
    }else{
        ListNode q=L;
        while(q->next!=NULL){
            q=q->next;
        }
        ListNode p=(ListNode)malloc(sizeof(Node));
        p->tag=x;
        p->begin=y;
        p->size=z;
        q->next=p;
        p->next=NULL;
        return L;
    }   
}
ListNode reloc(ListNode L,int x,int y,int z){
    ListNode p=(ListNode)malloc(sizeof(Node));
    p->tag=x;
    p->begin=y;
    p->size=z;
    ListNode q=L;
    if(q->size==0){
        q->size+=z;
        free(p);
        return L;
    }
    //insert before L:should write before other cases
    if(p->begin+p->size<q->begin){
        p->next=q;
        p->tag=0;
        L=p;
        return L;
    }
    //block==1
    //write here to control if p->next doesn't exist
    if(q->next==NULL){
        if(p->begin > q->begin+q->size){
            q->next=p;
            p->next=NULL;
            return L;
        }
        else if(p->begin == q->begin+q->size){
            q->size+=p->size;
            free(p);
            return L;
        }
        else if(p->begin+p->size == q->begin){
            q->begin-=p->size;
            q->size+=p->size;
            free(p);
            return L;
        }
    }
    //block>=2
    //first choose right p
    while(q->next!=NULL){
        if(q->begin<=y && q->next->begin>y)break;
        else q=q->next;
    }
    if(q->begin + q->size == y && q->next->begin > y+z){
        q->size+=z;
        free(p);
        return L;
    }
    else if(q->begin + q->size == y && q->next->begin == y+z){
        q->size=q->size+z+q->next->size;
        q->next=q->next->next;
        free(p);
        return L;
    }
    else if(q->begin + q->size < y && q->next->begin == y+z){
        q->next->begin=y;
        q->next->size=q->next->size+z;
        free(p);
        return L;
    }
    else{
        p->next=q->next;
        q->next=p;
        p->tag=0;
        return L;
    }
}
void print(ListNode L){
    ListNode p=L;
    while(p!=NULL){
        printf("%d %d %d\n",p->tag,p->begin,p->size);
        p=p->next;
    }
}
int main(){
    int x,y,z;
    ListNode L=NULL;
    while(~scanf("%d %d %d",&x,&y,&z)){
        //printf("input %d %d %d\n",x,y,z);
        if(!x)L=insert(L,x,y,z);
        else L=reloc(L,x,y,z);
        //print(L);
    }
    print(L);
    return 0;
}