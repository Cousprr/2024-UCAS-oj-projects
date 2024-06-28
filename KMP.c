#include <stdio.h>
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
int KMP(char str[],char pat[]){
    int i=0,j=0;
    get_next(pat,next);
    int len1=strlen(str);
    int len2=strlen(pat);
    //next[0]=0;
    while(i<len1 && j<len2){
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
    int choice=0;
    scanf("%d\n",&choice);
    if(choice){
        scanf("%s %s",str,pat);
        int re=KMP(str,pat);
        printf("%d",re);//Ê×Î»Îª0
    }
    else{
        scanf("%s",pat);
        get_next(pat,next);
        int i=0;
        while(i<strlen(pat))printf("%d",next[i++]);
    }
    return 0;
}