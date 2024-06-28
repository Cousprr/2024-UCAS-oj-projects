#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[100],t[100];
int main(){
    scanf("%s %s",s,t);
    int re=0;
    int len1=strlen(s);
    int len2=strlen(t);
    int comp=(len1>len2)?len2:len1;
    for(int i=0;i<comp;i++){
        if(s[i]==t[i])continue;
        else if(s[i]>t[i]){re=1;break;}
        else if(s[i]<t[i]){re=-1;break;}
    }
    if(re!=0)printf("%d",re);
    else{
        if(len1==len2)printf("0");
        else if(len1>len2)printf("1");
        else printf("-1");
    }
    return 0;
}