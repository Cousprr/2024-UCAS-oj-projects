#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//归并排序
void merge_sort_recursive(int arr[], int reg[], int start, int end){
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;//>>1相当于/2，且比/2快
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

void merge_sort(int arr[], const int len) {
    int reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}
int main(){
    int len=0;
    scanf("%d\n",&len);
    int arr[len];
    for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    int reg[len];
    merge_sort_recursive(arr, reg, 0,len - 1);
    for(int i=0;i<len;i++){
        printf("%d,",arr[i]);
    }
    return 0;
}