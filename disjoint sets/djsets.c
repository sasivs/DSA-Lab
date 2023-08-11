#include"djsets.h"
int* makeset(int sz){
    int* arr=(int*)malloc(sz*sizeof(int));
    for(int i=0; i<sz; i++){
        arr[i]=-1;
    }
    return arr;
}

int findele(int *arr, int ele){
    if(arr[ele]<0){
        return ele;
    }
    else{
        return findele(arr, arr[ele]);
    }
}

int unionset(int *arr, int x, int y){
    if(!arr){return -1;}
    int r1,r2;
    if((r1=findele(arr,x))==(r2=findele(arr,y))){return 1;}
    if(arr[r1]==arr[r2]){
        arr[r1]=r2;
        arr[r2]=arr[r2]-1;
    }
    else if(arr[r1]<arr[r2]){
        arr[r2]=r1;
    }
    else{
        arr[r1]=r2;
    }
    return 0;
}

int traversal(int *arr, int sz){
    if(!arr){return -1;}
    for (int i=0; i<sz; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 1;
}

int destroy(int *arr){
    if(!arr){
        return 1;
    }
    free(arr);
    arr=NULL;
    return 1;
}
