#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 10


void quick_sort(int a[], int low, int high){
	if(low >= high)return;
	int i = low;
	int j = high;
	int key = a[i];
	while(i < j){
		while(i < j && a[j] >= key){
			j--;
		}
		if(i<j)a[i++]=a[j];
		while(i < j && a[i] <= key){
			i++;
		}
		if(i<j)a[j--]=a[i];
	}
	a[i] = key;
	if(i)quick_sort(a,low,i-1);
	quick_sort(a,i+1,high);
	return;
}

int a[MAXLENGTH];
int main(){
    for(int i=0;i<MAXLENGTH;i++){
        scanf("%d",&a[i]);
    }
    //printf("re:\n");
    quick_sort(a,0,MAXLENGTH-1);
    for(int i=0;i<MAXLENGTH;i++){
        printf("%d",a[i]);
        if(i!=MAXLENGTH-1)printf(" ");
    }
    return 0;
}