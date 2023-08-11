#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
int merge(int *arr, int l,int q1, int q2, int r){
    int n1=q1-l+1;
    int n2=q2-q1+1;
    int n3=r-q2;
    int larr[n1], marr[n2], rarr[n3];
    for (int i=0; i<n1; i++){
        *(larr+i)=*(arr+l+i);
    }
    for(int i=0; i<n2; i++){
        marr[i]=arr[q1+1+i];
    }
    for (int i=0; i<n3; i++){
        *(rarr+i)=*(arr+q2+1+i);
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
        int q=(l+r)/2;
        printf("Q:%d\n",q);
        merge_sort(arr,l,q);
        merge_sort(arr,q+1,r);
        merge(arr,l,r,q);
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
    merge_sort(arr,0,6);
    for(int i=0; i<7; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
