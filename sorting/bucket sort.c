#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#define type float
struct node{
    type data;
    struct node *pre,*next;
};
int destroy(struct node** head){
    if(!(*head)){
        return 1;
    }
    struct node* iter=*head;
    while(*head){
        *head=iter->next;
        free(iter);
        iter=*head;
    }
    *head=NULL;
    return 1;
}
int bucket_sort(type* arr, int sz){
    struct node* bucket[sz];
    for (int i=0; i<sz; i++){
        (bucket[i])=NULL;
    }
    int index;
    struct node* iter;
    for (int i=0; i<sz; i++){
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=arr[i];
        index=sz*arr[i];
        iter=(bucket[index]);
        if(!iter){
            newNode->next=NULL;
            newNode->pre=NULL;
            (bucket[index])=newNode;
        }
        else{
            while(iter->data<newNode->data && iter->next){
                iter=iter->next;
            }
            if(!iter->next){
                iter->next=newNode;
                newNode->pre=iter;
                newNode->next=NULL;
            }
            else if(iter->data>newNode->data){
                if(iter->pre){
                    iter->pre->next=newNode;
                }
                else{
                    (bucket[index])=newNode;
                }
                newNode->pre=iter->pre;
                newNode->next=iter;
                iter->pre=newNode;

            }
        }
    }
    index=0;
    for (int i=0; i<sz; i++){
        iter=(bucket[i]);
        while(iter){
            arr[index]=iter->data;
            index++;
            iter=iter->next;
        }
    }
    for(int i=0; i<sz; i++){
        destroy(&bucket[i]);
    }
    return 1;
}

int main(){
    float arr[]={0.78,0.17, 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    printf("Input:\n");
    for(int i=0; i<8; i++){
        printf("%f ",*(arr+i));
    }
    printf("\nOutput:\n");
    bucket_sort(arr,8);
    printf("Bucket sort complete\n");
    for(int i=0; i<8; i++){
        printf("%f ",arr[i]);
    }
    return 0;
}
