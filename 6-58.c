#include<stdio.h>
int l[100],r[100];
int xl[100],xr[100];
int t;
int len1,len2;
int mid[100];
void find_mid(int x){
    if(x==0) return;
    find_mid(l[x]);
    mid[++t]=x;
    find_mid(r[x]);
}
void together(int p){
    int temp=0;
    if(l[p]!=0){
        temp=l[p];
    }
    l[p]=xl[0];
    for(int i=1;i<=len2;i++){
        l[xl[0]+i-1]=xl[i];
        r[xr[0]+i-1]=xr[i];
    }
    r[xl[0]]=temp;
}

int main(){
    char ch;
    int p=0;

    int k=0;
    ch=getchar();
    while(ch!='\n'){
        l[k]=ch-'0'+10*l[k];
        ch=getchar();
        if(ch==' '){k++;ch=getchar();}
        else if(ch=='\n')break;
    }
    len1=k;
    k=0;
    ch=getchar();
    while(ch!='\n'){
        r[k]=ch-'0'+10*r[k];
        ch=getchar();
        if(ch==' '){k++;ch=getchar();}
        else if(ch=='\n')break;
    }

    scanf("%d\n",&p);

    k=0;
    ch=getchar();
    while(ch!='\n'){
        xl[k]=ch-'0'+10*xl[k];
        ch=getchar();
        if(ch==' '){k++;ch=getchar();}
        else if(ch=='\n')break;
    }
    len2=k;
    k=0;
    ch=getchar();
    while(ch!='\n'){
        xr[k]=ch-'0'+10*xr[k];
        ch=getchar();
        if(ch==' '){k++;ch=getchar();}
        else if(ch=='\n')break;
    }
    together(p);
    find_mid(1);
    //for(int i=0;i<=len1+len2+1;i++)printf("%d ",l[i]);putchar('\n');
    //for(int i=0;i<=len1+len2+1;i++)printf("%d ",r[i]);putchar('\n');
    for(int i=1;i<=len1+len2;i++){
        if(i==1)printf("%d",mid[i]);
        else printf(" %d",mid[i]);
    }
    putchar('\n');
    return 0;
}