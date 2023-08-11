#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
int counting_sort(int *arr, int sz, int e){
    int temp[10];
    int sarr[sz];
    for (int j=0; j<=10; j++){
        temp[j]=0;
    }
    for (int i=0; i<sz; i++){
        temp[(arr[i]/e)%10]+=1;
    }
    for (int i=1; i<10; i++){
        temp[i]=temp[i]+temp[i-1];
    }
    int ri;
    for (int i=sz-1; i>=0; i--){
        ri=(arr[i]/e)%10;
        sarr[temp[ri]-1]=arr[i];
        temp[(arr[i]/e)%10]-=1;
    }
    for (int i=0; i<sz; i++){
        arr[i]=sarr[i];
    }
    return 1;
}

int radix_sort(int *arr, int sz){
    int mx=arr[0];
    for (int i=1; i<sz; i++){
        if(mx<arr[i]){
            mx=arr[i];
        }
    }
    for(int e=1; mx/e>0; e*=10){
        counting_sort(arr,sz,e);
    }
    return 1;
}

int main(){
    int arr[]={54,8,90,34,987,65,66,0};
    printf("Input:\n");
    for(int i=0; i<8; i++){
        printf("%d ",*(arr+i));
    }
    printf("\nOutput:\n");
    radix_sort(arr,8);
    printf("Radix sort complete\n");
    for(int i=0; i<8; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
