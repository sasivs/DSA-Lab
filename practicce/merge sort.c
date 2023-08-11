#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
int merge(int *arr, int l, int q, int r){
    //if(!arr){return -1;}
    int n1=q-l+1;
    int n2=r-q;
    int L[n1+1], R[n2+1];
    for (int i=0; i<n1; i++){
        L[i]=arr[l+i];
    }
    for (int i=0; i<n2; i++){
        R[i]=arr[q+i+1];
    }
    L[n1+1]=999999999;
    R[n2+1]=999999999;
    int i=0,j=0;
    for (int k=l; k<=r; k++){
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
    }
    return 0;
}

int mergesort(int *arr, int l, int r){
    if(!arr){return -1;}
    if (l<r){
        int q=(l+r)/2;
        mergesort(arr,l,q);
        mergesort(arr,q+1, r);
        merge(arr, l, q, r);
    }
    return 0;
}

int main(){
    int arr[]={54,8,90,34,987,65,66};
    mergesort(arr,0,6);
    for (int i=0; i<7; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

