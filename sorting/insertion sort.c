#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
int insertion_sort(int *arr, int sz){
    int key,j;
    for (int i=1; i<sz; i++){
        key=*(arr+i);
        for(j=i-1; j>=0 && *(arr+j)>key; j--){
            *(arr+j+1)=*(arr+j);
        }
        *(arr+j+1)=key;
    }
    return 1;
}
int main(){
    int arr[]={2,4,1,4,9,3,6,8};
    printf("Input:\n");
    for(int i=0; i<8; i++){
        printf("%d ",*(arr+i));
    }
    printf("\nOutput:\n");
    insertion_sort(arr,8);
    for(int i=0; i<8; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
