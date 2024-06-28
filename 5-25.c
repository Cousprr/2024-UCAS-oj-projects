#include <stdio.h>
#include <stdlib.h>
int first[100][100],second[100][100],res[100][100];
int vfirst[100],vsecond[100],vres[100];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);getchar();
    char ch1,ch2;
    int k=0,t=0;
    int flag=1;
    ch1=getchar();
    while(ch1!='\n'){
        if(ch1=='-'){flag=-1;ch1=getchar();continue;}
        vfirst[k]=ch1-'0'+10*vfirst[k];
        ch1=getchar();
        if(ch1==' '){vfirst[k]*=flag;flag=1;k++;ch1=getchar();}
        else if(ch1=='\n'){vfirst[k]*=flag;flag=1;break;}
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%d",&first[i][j]);
        }
        if(getchar()=='\n')continue;
    }

    ch2=getchar();
    while(ch2!='\n'){
        if(ch2=='-'){flag=-1;ch2=getchar();continue;}
        vsecond[t]=ch2-'0'+10*vsecond[t];
        ch2=getchar();
        if(ch2==' '){vsecond[t]*=flag;flag=1;t++;ch2=getchar();}
        else if(ch2=='\n'){vsecond[t]*=flag;break;}
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%d",&second[i][j]);
        }
        if(getchar()=='\n')continue;
    }

    int vr=0,vf=0,vs=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            res[i][j]=first[i][j]+second[i][j];
            if(res[i][j]==2){
                vres[vr++]=vfirst[vf++]+vsecond[vs++];
                if(vres[vr-1]==0)res[i][j]=0;
            }
            else if(res[i][j]==1){
                if(second[i][j]==0)vres[vr++]=vfirst[vf++];
                else vres[vr++]=vsecond[vs++];
            }
        }
    }
    //print
    int flay=0;
    for(int i=0;i<vr;i++){
        if(vres[i]==0)continue;
        if(flay==0){printf("%d",vres[i]);flay=1;}
        else printf(" %d",vres[i]);
    }
    printf("\n");
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(res[i][j]==2)res[i][j]=1;
            printf("%d",res[i][j]);
            if(j!=b-1)printf(" ");
        }
        printf("\n");
    }
    return 0;
}