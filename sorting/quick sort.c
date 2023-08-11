#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
void swap(int *a, int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
int partition(int *arr, int l, int r){
    int x=arr[r];
    int i,j;
    i=l;
    j=r-1;
    while(i<j){
        if(arr[i]<x){
            i++;
        }
        else if(arr[j]>x){
            j--;
        }
        else{
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
    }
    if(i==j){
        if(arr[i]>x){
            swap(&arr[i],&arr[r]);
            return i;
        }
        else{
            return i+1;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
}
int quick_sort(int *arr, int l, int r){
    if(l<r){
        int q=partition(arr,l,r);
        quick_sort(arr,l,q-1);
        quick_sort(arr,q+1,r);
    }
    return 1;
}
int main(){
    int arr[]={54,8,90,34,987,65,66};
    printf("Input:\n");
    for(int i=0; i<7; i++){
        printf("%d ",*(arr+i));
    }
    printf("\nOutput:\n");
    quick_sort(arr,0,6);
    for(int i=0; i<7; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

