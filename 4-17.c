#include <stdio.h>
#include <string.h>
char str[1000];
char pat[1000];
char rep[1000];
char result[1000];
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
int KMP(char str[],char pat[]){
    int i=0,j=0;
    get_next(pat,next);
    next[0]=0;
    while(i<strlen(str)&&j<strlen(pat)){
        if(j==0||str[i]==pat[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j>=strlen(pat))
        return i-strlen(pat)+1;
    else
        return -1;
}
void replace(char str[],char pat[],char rep[],char result[]){
    int re=KMP(str,pat);
    if(re==-1) return;
    int k=re+strlen(pat)-1;
    int i=0,j=0;
    if(str[k]=='\0'){
        while(i<re-1) result[i++]=str[i];
        while(j<strlen(rep)) result[i++]=rep[j++];
        return;
    }
    while(k<=strlen(str)){
        if(i<re-1) result[i++]=str[i];
        else if(j==0){
            while(j<strlen(rep)) result[i++]=rep[j++];
        }
        else result[i++]=str[k++];
    }
    return;
}

int main(){
    scanf("%s %s %s",str,pat,rep);
    replace(str,pat,rep,result);
    int re=strlen(str)+strlen(rep)-strlen(pat);
    if(KMP(str,pat)==-1){printf("%s",str);return 0;}
    for(int i=0;i<re;i++)printf("%c",result[i]);
    return 0;
}