#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int origin[1000];
int len;
void sort(int a[]){
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
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
    scanf("%d\n",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&origin[i]);
    }
    sort(origin);
    for(int i=0;i<len;i++){
        printf("%d",origin[i]);
        if(i!=len-1)printf(" ");
    }
    return 0;
}