#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node{
    int data;
    struct node* next;
};
struct st{
    struct node* top;
    int sz;
};
int push(struct st* s, int key){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=key;
    n->next=s->top;
    s->top=n;
    s->sz++;
    return 1;
}

int pop(struct st* s, int* k){
    if(!s->top){k=NULL; return 0;}
    *k=s->top->data;
    struct node* iter=s->top;
    s->top=iter->next;
    free(iter);
    s->sz--;
    return 1;
}

int destroy(struct st** s){
    if(!(*s)){return 1;}
    struct node* iter;
    while((*s)->sz){
        iter=(*s)->top;
        (*s)->top=iter->next;
        free(iter);
        (*s)->sz--;
    }
    return 1;
}

int getmax(struct st* s){
    if(!s){return -1;}
    struct st* s2=(struct st*)malloc(sizeof(struct st));
    s2->top=NULL;
    s2->sz=0;
    int c;
    int max=-555;
    while(s->sz){
        pop(s,&c);
        if(c>max){max=c;}
        push(s2,c);
    }
    while(s2->sz){
        pop(s2,&c);
        push(s,c);
    }
    destroy(&s2);
    return max;
}

int main(){
    struct st* s1=(struct st*)malloc(sizeof(struct st));
    s1->top=NULL;
    s1->sz=0;
    int arr[]={1,2,3,4,5};
    for(int i=0; i<5; i++){
        push(s1,arr[i]);
    }
    int max=getmax(s1);
    printf("Max is %d\n",max);
    destroy(&s1);
    printf("-----\n");
    return 0;
}
