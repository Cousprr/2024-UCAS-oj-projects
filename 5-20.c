#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int charm[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%d",&charm[i][j]);
        }
    }
    int fr=0;
    for(int i=a-1;i>=0;i--){
        for(int j=b-1;j>=0;j--){
            if(charm[i][j]!=0&&charm[i][j]!=1){
                if(fr)printf("+");
                fr=1;
                if(i!=0&&j!=0)printf("%dxE%dyE%d",charm[i][j],i,j);
                else if(i==0&&j!=0)printf("%dyE%d",charm[i][j],j);
                else if(i!=0&&j==0)printf("%dxE%d",charm[i][j],i);
                else printf("%d",charm[i][j]);
            }
            else if(charm[i][j]==1){
                if(fr)printf("+");
                fr=1;
                if(i!=0&&j!=0)printf("xE%dyE%d",i,j);
                else if(i==0&&j!=0)printf("yE%d",j);
                else if(i!=0&&j==0)printf("xE%d",i);
                else printf("%d",charm[i][j]);
            }
        }
    }
    return 0;
}