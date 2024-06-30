#include<stdio.h>
int quick_sort(int *a, int low, int high){
	int i = low;
	int j = high;
	int key = a[i];
	while(i < j){					
		while(i < j && a[j] >= key){
			j--;
		}
		a[i] = a[j];	
		while(i < j && a[i] <= key){
			i++;
		}
		a[j] = a[i];
	}
	a[i] = key;
	if (i-1 > low){
		quick_sort(a, low, i-1);
	}
	if (i+1 < high){
		quick_sort(a, i+1, high);
	}
	return 0;
}
int a[100];
int main(){
    char ch;
    int k=0;
    int flag=1;
    ch=getchar();
    while(ch!='\n'){
        if(ch=='-'){flag=-1;ch=getchar();continue;}
        a[k]=ch-'0'+10*a[k];
        ch=getchar();
        if(ch==' '){a[k]*=flag;flag=1;k++;ch=getchar();}
        else if(ch=='\n'){a[k]*=flag;break;}
    }
    quick_sort(a,0,k);
    for(int i=0;i<=k;i++){
        printf("%d",a[i]);
        if(i!=k)printf(" ");
    }
    return 0;
}