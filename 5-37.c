#include<stdio.h>
#include<stdlib.h>
char str[100];
char ch;
int k;

typedef enum {ATOM,LIST}Elemtag;
typedef struct GLNode{
    Elemtag tag;   //ATOM==0原子;LIST==1子表
    union{
        char atom;
        struct{struct GLNode *hp,*tp;}ptr;
    };              //联合体，内存重叠
}GLNode,*GList;

GList Createlist(GList L){
    GList h=L;
    if(h==NULL){
        h=(GList)malloc(sizeof(GLNode));
        h->tag=LIST;
        h->ptr.hp=NULL;
        h->ptr.tp=NULL;
    }
    while(str[k++]!='\0'){
        ch=str[k-1];
        switch(ch){
            case '(':
            {   
                GList p;
                p=(GList)malloc(sizeof(GLNode));
                p->tag=LIST;
                p->ptr.tp=NULL;
                p->ptr.hp=NULL;
                h->ptr.hp=Createlist(p);
                break;
            }
            case ')':
                return L;
            case ',':
            {
                GList p;
                p=(GList)malloc(sizeof(GLNode));
                p->tag=LIST;
                p->ptr.hp=NULL;
                p->ptr.tp=NULL;
                h->ptr.tp=p;
                h=p;
                break;
            }
            default:
            {
                GList p;
                p=(GList)malloc(sizeof(GLNode));
                p->tag=ATOM;
                p->atom=ch;
                h->ptr.hp=p;
                break;
            }
        }
    }
    return h;
}
int max;
int GListDep(GList L){ 
    if(L==NULL) return 1;
    if(L->tag==ATOM) return 0;
    GList pp;
    for(max=0,pp=L;pp!=NULL;pp=pp->ptr.tp){
        int dep=GListDep(pp->ptr.hp);
        if(max<dep) max=dep;
    }
    return max+1;
}
void PRINT(GList L){
    if(L==NULL) return;
    GList p,q=L;
    while(p!=NULL){
        q=p->ptr.hp;
        if(q->tag==ATOM && p->ptr.tp!=NULL) printf("%c",q->atom);
        else {printf("(");PRINT(q);}
    }
}

int main(){
    GList L=NULL;
    printf("请输入一个算术表达式：");
    scanf("%s",str);
    L=Createlist(L);
    printf("该表达式的最大嵌套深度为：%d\n",GListDep(L));
    return 0;
}