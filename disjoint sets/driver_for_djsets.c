#include"djsets.c"
int main(){
    int *arr=makeset(6);
    traversal(arr,6);
    printf("find of 4 returned %d\n", findele(arr,4));
    unionset(arr,0,4);
    printf("After union of 0 and 4\n");
    traversal(arr,6);
    unionset(arr,3,4);
    printf("After second union:\n");
    traversal(arr,6);
    destroy(arr);
    printf("------\n");
    return 0;
}
