#include"hash.h"

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

int insertion(type* arr, type key, int sz, int flag){
    if(!arr || key<0){
        return -1;
    }
    int index,i=0;
    switch(flag){
        case 1: index = mad_hash(key,sz);
                while(*(arr+index)!=-1 && i<=sz){
                    index=mad_hash(key+i,sz);
                    i++;
                }
                break;
        default: index = mod_hash(key, sz);
                 while(*(arr+index)!=-1 && i<=sz){
                    index=mod_hash(key+i,sz);
                    i++;
                 }
                 break;
    }
    *(arr+index)=key;
    return 0;
}

int searchKey(type* arr, type key, int sz, int flag){
    if(!arr || key<0){
        return -1;
    }
    int index,i=0;
    switch(flag){
        case 1: index = mad_hash(key,sz);
                while(*(arr+index)!=key && i<=sz){
                    index=mad_hash(key+i,sz);
                    i++;
                }
                break;
        default: index = mod_hash(key, sz);
                 while(*(arr+index)!=key && i<=sz){
                    index=mod_hash(key+i,sz);
                    i++;
                 }
                 break;
    }
    if(*(arr+index)==key){return index;}
    else{return -1;}
}
int deletion(type* arr, type key, int sz, int flag){
    if(!arr || key<0){return -1;}
    int index;
    if((index=searchKey(arr, key, sz, flag))<0){return -1;}
    *(arr+index)=-1;
    return 0;
}

int traversal(type* arr, int sz){
    if(!arr || sz<=0){return -1;}
    for (int i=0; i<sz; i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
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
