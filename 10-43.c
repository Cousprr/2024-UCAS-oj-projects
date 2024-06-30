#include<stdio.h>
int a[100],b[100];
void compare(int a[],int b[],int len){
    int flag=0;
    for(int i=0;i<=len;i++){
        for(int j=0;j<=len;j++){
            if(a[i]>a[j])flag++;
        }
        b[i]=flag;
        flag=0;
    }
    return;
}
int main(){
    char ch;
    int k=0;
    int flag=1;
    ch=getchar();
    while(ch!='\n'){
        if(ch=='-'){flag=-1;ch=getchar();continue;}
        a[k]=ch-'0'+10*a[k];
        ch=getchar();
        if(ch==' '){a[k]*=flag;flag=1;k++;ch=getchar();}
        else if(ch=='\n'){a[k]*=flag;break;}
    }
    compare(a,b,k);
    for(int i=0;i<=k;i++){
        printf("%d",b[i]);
        if(i!=k)printf(" ");
    }
    return 0;
}