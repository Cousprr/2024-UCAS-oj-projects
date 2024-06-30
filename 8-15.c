#include<stdio.h>
#include<stdlib.h>
int main(){
    int low=0,high=0,size=0;
    scanf("%d %d %d\n",&low,&high,&size);
    int num=(high-low)/size;
    int block[num];
    int flag=0;
    for(int i=0;i<num;i++){
        scanf("%d",&block[i]);
    }
    for(int i=0;i<num;i++){
        int temp=0;
        int j=i;
        while(block[j]==0){
            temp+=size;
            j++;
        }
        if(temp){printf("0 %d %d\n",low+i*size,temp);flag++;}
        i=j;
    }
    if(!flag)printf("0 0 0\n");
    return 0;
}