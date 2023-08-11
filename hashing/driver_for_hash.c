#include"hash.c"
int main(){
    int *arr;
    int sz=9;
    init(&arr,sz);
    printf("Init completed\n");
    int arr1[]={10,20,30,22,44,65,76,86,40};
    printf("Insertion using mad_hash function\n");
    for (int i=0; i<9; i++){
        insertion(arr,arr1[i],sz,1);
    }
    traversal(arr,sz);
    printf("\n");

    int index=searchKey(arr,76,sz,1);
    printf("Search key returned %d for %d\n",*(arr+index),76);
    printf("\n");

    deletion(arr,76,sz,1);
    printf("\n");
    index=searchKey(arr,76,sz,1);
    printf("Search key returned %d for %d after deletion\n",*(arr+index),76);
    printf("\n");

    destroy(&arr);
    printf("----\n");

    int *arr11;
    sz=9;
    init(&arr11,sz);
    printf("Init completed\n");
    int arr2[]={10,20,30,22,44,65,76,86,40};
    printf("Insertion using mod_hash function\n");
    for (int i=0; i<9; i++){
        insertion(arr11,arr2[i],sz,2);
    }
    traversal(arr11,sz);
    printf("\n");

    index=searchKey(arr11,76,sz,2);
    printf("Search key returned %d for %d\n",*(arr11+index),76);
    printf("\n");

    deletion(arr11,76,sz,2);
    printf("\n");
    index=searchKey(arr11,76,sz,2);
    printf("Search key returned %d for %d after deletion\n",*(arr11+index),76);
    printf("\n");

    destroy(&arr11);
    printf("----\n");

    return 0;
}
