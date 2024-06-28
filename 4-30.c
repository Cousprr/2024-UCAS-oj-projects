#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[1000];
char pat[1000];
int next[1000];
void get_next(char pat[],int next[]){
    int i=0,j=-1;
    next[0]=-1;
    while(i<strlen(pat)-1){
        if(j==-1||pat[i]==pat[j]){
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
}
int KMP(char str[],char pat[],int cont){
    int i=0,j=0;
    get_next(pat,next);
    int len1=strlen(str);
    int len2=strlen(pat);
    while(i<len1&&j<len2){
        if(i==cont){
            i++;
            continue;
        }
        if(j==-1||str[i]==pat[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j>=len2)
        return i-len2;
    else
        return -1;
}

int main(){
    scanf("%s",str);
    for(int len=strlen(str)-1;len>=0;len--){
        int lenct=0;
        while(str[lenct+len-1]!='\0'){
            char p[100]={'\0'};
            for(int i=0;i<len;i++) p[i]=str[i+lenct];//copy str to pat
            int re=KMP(str,p,lenct);
            if(re!=-1&&re!=lenct) {printf("%s %d",p,lenct);return 0;}
            lenct++;
        }
    }
    printf("-1");
    return 0;
}