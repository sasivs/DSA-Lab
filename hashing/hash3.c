#include"hash3.h"
int init(type** arr, int sz){
    (*arr)=(type*)malloc(sz*sizeof(type));
    if(!(*arr)){
        return -1;
    }
    for (int i=0; i<sz; i++){
        *(*arr+i)=-1;
    }
    return 0;
}

int mad_hash(type key, int sz){
    if(!sz){
        return -1;
    }
    const int a=3;
    const int b=7;
    const int p=11;
    return ((a*key + b)%p)%sz;
}

int mod_hash(type key, int sz){
    if(!sz){
        return -1;
    }
    return key%sz;
}

int insertion(int *arr, int key, int sz){
    if(!arr){return -1;}
    int h1=mad_hash(key,sz);
    int h2=mod_hash(key,sz);
    int index=(h1+h2)%sz;
    int i=2;
    while(arr[index]!=-1 && i<=sz){
        index=(h1+(i*h2))%sz;
        i++;
    }
    if(arr[index]==-1){
        arr[index]=key;
        return 0;
    }
    if(i>sz){
        return -1;
    }
}

int searchKey(int *arr, int key, int sz){
    if(!arr){return -1;}
    int h1=mad_hash(key,sz);
    int h2=mod_hash(key,sz);
    int index=(h1+h2)%sz;
    int i=2;
    while(arr[index]!=key && i<=sz){
        index=(h1+(i*h2))%sz;
        i++;
    }
    if(arr[index]==key){
        return index;
    }
    if(i>sz){
        return -1;
    }
}

int traversal(type* arr, int sz){
    if(!arr || sz<=0){return -1;}
    for (int i=0; i<sz; i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
    return 0;
}

int deletion(int *arr, int key, int sz){
    if(!arr){return -1;}
    int index;
    if((index=searchKey(arr, key, sz))<0){
        return -1;
    }
    arr[index]=-1;
    return 0;
}

int destroy(type** arr){
    if(!(*arr)){
        return 0;
    }
    free(*arr);
    *arr=NULL;
    return 0;
}
