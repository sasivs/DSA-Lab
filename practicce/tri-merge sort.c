#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
int merge(int *arr, int l, int r, int q){
    int n1=q-l+1;
    int n2=r-q;
    int larr[n1], rarr[n2];
    for (int i=0; i<n1; i++){
        *(larr+i)=*(arr+l+i);
    }
    for (int i=0; i<n2; i++){
        *(rarr+i)=*(arr+q+1+i);
    }
    int i=0;
    int j=0,k=l;
    while(i<n1 && j<n2){
        if(larr[i]<=rarr[j]){
            arr[k]=larr[i];
            i++;
        }
        else{
            arr[k]=rarr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=larr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=rarr[j];
        j++;
        k++;
    }
    return 1;
}

int merge_sort(int *arr, int l, int r){
    if(l<r){
        int q1=l+(r-l)/3;
        int q2=l+(2*(r-l)/3)+1;
        merge_sort(arr,l,q1);
        merge_sort(arr,q1+1,q2);
        merge_sort(arr,q2+1,r);
        merge(arr,l,q2,q1);
        merge(arr,l,r,q2);
    }
    return 1;
}

int main(){
    int arr[]={54};
    printf("Input:\n");
    for(int i=0; i<1; i++){
        printf("%d ",*(arr+i));
    }
    printf("\nOutput:\n");
    merge_sort(arr,0,0);
    for(int i=0; i<1; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

