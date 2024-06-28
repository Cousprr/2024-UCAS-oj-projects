#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[1000];
int top=0;

void push(int x){
    stack[top++]=x;
}

int pop(){
    return stack[--top];
}

int number;
int a[1000][3];
int originL[1000];
int originR[1000];
int pre[1000];
int mid[1000];
int bac[1000];

int flag[1000];
int roots[1000];
int rootn=0;
void create(){
    while(1){
        for(int j=1;j<=number;j++){
            if(flag[j]==0){
                push(j);
                flag[j]=1;
                break;
            }
        }
        if(top==0)break;
        roots[++rootn]=stack[top-1];
        if(rootn>1)originR[roots[rootn-1]]=roots[rootn];
        while(top){
            int i=pop();
            if(a[i][1]){
                flag[a[i][1]]=1;
                push(a[i][1]);
            }
            if(a[i][2]){
                flag[a[i][2]]=1;
                push(a[i][2]);
            }
        }
    }
}
int t;
void find_pre(int x){
    if(x==0) return;
    pre[++t]=x;
    find_pre(originL[x]);
    find_pre(originR[x]);
}
void find_mid(int x){
    if(x==0) return;
    find_mid(originL[x]);
    mid[++t]=x;
    find_mid(originR[x]);
}
void find_bac(int x){
    if(x==0) return;
    find_bac(originL[x]);
    find_bac(originR[x]);
    bac[++t]=x;
}


int main(){
    scanf("%d",&number);
    for(int i=1;i<=number;i++){
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }
    for(int i=1;i<=number;i++){
        originL[i]=a[i][1];
        originR[i]=a[i][2];
    }
    originL[0]=1;
    originR[0]=1;

    create();
    find_pre(roots[1]);
    t=0;
    find_mid(roots[1]);
    t=0;
    find_bac(roots[1]);
    //先序前驱线索化L,R
    for(int i=0;i<=number;i++){
        if(originL[i]!=0){
            if(i==0)printf("%d",originL[i]);
            else printf(" %d",originL[i]);
        }
        else{
            int temp=i;
            for(int t=0;t<=number;t++){
                if(pre[t]==temp){
                    if(i==0)printf("%d",pre[t-1]);
                    else printf(" %d",pre[t-1]);
                    break;
                }
            }
        }  
    }
    printf("\n");
    for(int i=0;i<=number;i++){
        if(i==0)printf("%d",originR[i]);
        else printf(" %d",originR[i]);
    }
    printf("\n");
    //中序全线索化L,R
    for(int i=0;i<=number;i++){
        if(originL[i]!=0){
            if(i==0)printf("%d",originL[i]);
            else printf(" %d",originL[i]);
        }
        else{
            int temp=i;
            for(int t=0;t<=number;t++){
                if(mid[t]==temp){
                    if(i==0)printf("%d",mid[t-1]);
                    else printf(" %d",mid[t-1]);
                    break;
                }
            }
        }  
    }
    printf("\n");
    for(int i=0;i<=number;i++){
        if(originR[i]!=0){
            if(i==0)printf("%d",originR[i]);
            else printf(" %d",originR[i]);
        }
        else{
            int temp=i;
            for(int t=0;t<=number;t++){
                if(mid[t]==temp){
                    if(i==0)printf("%d",mid[t+1]);
                    else printf(" %d",mid[t+1]);
                    break;
                }
            }
        }  
    }
    printf("\n");
    //后序后继线索化L,R
    for(int i=0;i<=number;i++){
        if(i==0)printf("%d",originL[i]);
        else printf(" %d",originL[i]);
    }
    printf("\n");
    for(int i=0;i<=number;i++){
        if(originR[i]!=0){
            if(i==0)printf("%d",originR[i]);
            else printf(" %d",originR[i]);
        }
        else{
            int temp=i;
            for(int t=0;t<=number;t++){
                if(bac[t]==temp){
                    if(i==0)printf("%d",bac[t+1]);
                    else printf(" %d",bac[t+1]);
                    break;
                }
            }
        }  
    }
    printf("\n");
    return 0;
}
/*
15
1 2 0
2 3 0
3 0 4
4 0 5
5 6 0
6 8 7
7 0 0
8 0 0
9 10 0
10 0 0
11 0 0
12 13 0
13 15 14
14 0 0
15 0 0
1 2 3 2 3 6 8 8 6 10 9 10 13 15 13
1 9 0 4 5 0 7 0 0 11 0 12 0 14 0 0
1 2 3 0 3 6 8 6 4 10 1 9 13 15 13 11
1 9 1 4 5 2 7 5 6 11 9 12 14 12 13
1 2 3 0 0 6 8 0 0 10 0 0 13 15 0 0
1 9 10 4 5 4 7 6 7 11 15 12 11 14 13 14
*/