#include"hash2.c"
int main(){
    struct hsh* h;
    int sz=9;
    int flag=1;
    init(&h,sz,flag);
    printf("Init completed\n");
    int arr1[]={10,20,30,22,44,65,76,86,40};
    printf("Insertion using mad_hash function\n");
    for (int i=0; i<9; i++){
        insertion(h,arr1[i]);
    }
    printf("Insertion complete\n");
    printf("\n");

    int index;
    struct node* kPtr=searchKey(h,65,&index);
    printf("%d\n",index);
    printf("Search node returned value of %d for %d\n",kPtr->data,65);
    printf("\n");

    deletion(h,65);
    printf("Deletion complete\n");
    printf("\n");

    kPtr=searchKey(h,65,&index);
    if(kPtr){
        printf("Search node returned value of %d for %d\n",kPtr->data,65);
    }
    else{
        printf("Not found\n");
    }
    printf("\n");

    destroy(&h);
    printf("----\n");

    struct hsh* h1;
    sz=9;
    flag=0;
    init(&h1,sz,flag);
    printf("Init completed\n");
    printf("Insertion using mod_hash function\n");
    for (int i=0; i<9; i++){
        insertion(h1,arr1[i]);
    }
    printf("Insertion complete\n");
    printf("\n");


    kPtr=searchKey(h1,65,&index);
    printf("%d\n",index);
    printf("Search node returned value of %d for %d\n",kPtr->data,65);
    printf("\n");

    deletion(h1,65);
    printf("Deletion complete\n");
    printf("\n");

    kPtr=searchKey(h1,65,&index);
    if(kPtr){
        printf("Search node returned value of %d for %d\n",kPtr->data,65);
    }
    else{
        printf("Not found\n");
    }
    printf("\n");

    destroy(&h1);
    printf("----\n");
    return 0;
}
