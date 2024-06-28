#include<stdio.h>
#include<stdlib.h>
int fr[100][100];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int charm[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%d",&charm[i][j]);
        }
    }
    int pr=0;
    for(int i=0;i<a;i++){
        int flag=charm[i][0];
        for(int j=1;j<b;j++){
            if(flag>charm[i][j])flag=charm[i][j];
        }
        for(int j=0;j<b;j++){
            if(charm[i][j]==flag)fr[i][j]=1;
        }
    }
    for(int j=0;j<b;j++){
        int flag=charm[0][j];
        for(int i=1;i<a;i++){
            if(flag<charm[i][j])flag=charm[i][j];
        }
        for(int i=0;i<a;i++){
            if(charm[i][j]==flag && fr[i][j]==1){
                if(pr)printf(" %d",flag);
                else printf("%d",flag);
                pr=1;
            }
        }
    }
    return 0;
}