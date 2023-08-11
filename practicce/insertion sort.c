#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
int insertionsort(int *arr, int sz){
    if(!arr){return -1;}
    int key,j;
    for (int i=1; i<sz; i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    for (int i=0; i<sz; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

int main(){
    int arr[]={54,8,90,34,987,65,66};
    insertionsort(arr,7);
    return 0;
}
