#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
int counting_sort(int *arr, int *sarr, int sz){
    int mx=arr[0];
    for (int i=1; i<sz; i++){
        if(mx<arr[i]){
            mx=arr[i];
        }
    }
    int temp[mx+1];
    for (int j=0; j<=mx; j++){
        temp[j]=0;
    }
    for (int i=0; i<sz; i++){
        temp[arr[i]]+=1;
    }
    for (int i=1; i<=mx; i++){
        temp[i]=temp[i]+temp[i-1];
    }
    for (int i=sz-1; i>=0; i--){
        sarr[temp[arr[i]]-1]=arr[i];
        temp[arr[i]]-=1;
    }
    return 1;
}

int main(){
    int arr[]={54,8,90,34,987,65,66};
    int sarr[7];
    printf("Input:\n");
    for(int i=0; i<7; i++){
        printf("%d ",*(arr+i));
    }
    printf("\nOutput:\n");
    counting_sort(arr,sarr,7);
    for(int i=0; i<7; i++){
        printf("%d ",sarr[i]);
    }
    return 0;
}
