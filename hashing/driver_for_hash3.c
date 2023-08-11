#include"hash3.c"
int main(){
    int *arr;
    init(&arr, 5);;
    printf("Init completed\n");
    int arr1[]={10,20,30,22,44};
    for (int i=0; i<5; i++){
        insertion(arr,arr1[i],5);
    }
    traversal(arr,5);
    printf("\n");
    int i;
    if((i=searchKey(arr, 30, 5))<0){
        printf("Not found\n");
    }
    else{
        printf("Found at %d\n",i);
    }
    deletion(arr, 44, 5);
    traversal(arr,5);
    printf("\n");

    destroy(&arr);
    printf("------\n");
    return 0;
}
