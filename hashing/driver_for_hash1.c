#include"hash1.c"
int main(){
    struct hsh* h;
    int sz=9;
    int flag=1;
    int index;
    init(&h,sz,flag);
    printf("Init completed\n");
    int arr1[]={10,20,30,22,44,65,76,86,40};
    printf("Insertion using mad_hash function\n");
    for (int i=0; i<9; i++){
        insertion(h,arr1[i]);
    }
    printf("Insertion complete\n");
    traversal(h);
    printf("\n");

    index=searchKey(h,76);
    printf("Search key returned %d for %d\n",*(h->arr+index),76);
    printf("\n");

    deletion(h,76);
    printf("\n");
    index=searchKey(h,76);
    printf("Search key returned %d for %d after deletion\n",*(h->arr+index),76);
    printf("\n");

    destroy(&h);
    printf("----\n");

    struct hsh* h1;
    sz=9;
    flag=0;
    init(&h1,sz,flag);
    printf("Init completed\n");
    int arr2[]={10,20,30,22,44,65,76,86,40};
    printf("Insertion using mod_hash function\n");
    for (int i=0; i<9; i++){
        insertion(h1,arr2[i]);
    }
    traversal(h1);
    printf("\n");

    index=searchKey(h1,76);
    printf("Search key returned %d for %d\n",*(h1->arr+index),76);
    printf("\n");

    deletion(h1,76);
    traversal(h1);
    printf("\n");
    index=searchKey(h1,76);
    printf("Search key returned %d for %d after deletion\n",*(h1->arr+index),76);
    printf("\n");

    destroy(&h1);
    printf("----\n");

    return 0;
}

