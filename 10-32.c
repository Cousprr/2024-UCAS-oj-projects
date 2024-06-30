#include<stdio.h>
int a[100];
int swap(int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int main(){
    int k=0;
    while(1){
        scanf("%d",&a[k]);
        k++;
        char ch=getchar();
        if(ch=='\n')break;
    }
    int p1=0,p3=k-1;
    int cur=0;
    while(cur<=p3){
        if(a[cur]==1){
            swap(cur,p1);
            p1++;
            cur++;
        }
        else if(a[cur]==2){
            cur++;
        }
        else if(a[cur]==3){
            swap(cur,p3);
            p3--;
        }
    }
    for(int i=0;i<k;i++){
        printf("%d",a[i]);
        if(i!=k-1)printf(" ");
    }
    return 0;
}