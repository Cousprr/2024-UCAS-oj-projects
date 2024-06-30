#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int origin[1000];
int len;
void sort(int a[]){
    for(int i=0;i<=len;i++){
        for(int j=i+1;j<=len;j++){
            int t=0;
            if(a[i]>a[j]){
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

int main(){
    int flag=1;
    char ch=getchar();
    while(ch!='\n'){
        if(ch=='-'){flag=-1;ch=getchar();continue;}
        origin[len]=ch-'0'+10*origin[len];
        ch=getchar();
        if(ch==' '){origin[len]*=flag;flag=1;len++;ch=getchar();}
        else if(ch=='\n'){origin[len]*=flag;break;}
    }
    sort(origin);
    for(int i=0;i<=len;i++){
        printf("%d",origin[i]);
        if(i!=len)printf(" ");
    }
    return 0;
}