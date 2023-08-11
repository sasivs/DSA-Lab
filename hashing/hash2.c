#include"hash2.h"

int init(struct hsh** h, int sz, int flag){
    (*h)=(struct hsh*)malloc(sizeof(sizeof(struct hsh)));
    if(!(*h)){
        return -1;
    }
    (*h)->arr=(struct node**)malloc(sz*sizeof(struct node*));
    (*h)->sz=sz;
    (*h)->flag=flag;
    for (int i=0; i<sz; i++){
        *((*h)->arr + i)=NULL;
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


int insertion(struct hsh* h, type key){
    if(!h || key<0){
        return -1;
    }
    int index;
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=key;
    switch(h->flag){
        case 1: index = mad_hash(key,h->sz);
                break;
        default: index = mod_hash(key, h->sz);
                 break;
    }
    newNode->next=*(h->arr+index);
    newNode->pre=NULL;
    if(*(h->arr+index)){
        (*(h->arr+index))->pre=newNode;
    }
    *(h->arr+index)=newNode;
    return 0;
}


struct node* searchKey(struct hsh* h, type key, int* ind){
    if(!h || key<0){
        return NULL;
    }
    int index;
    switch(h->flag){
        case 1: index = mad_hash(key,h->sz);
                break;
        default: index = mod_hash(key, h->sz);
                 break;
    }
    *ind=index;
    struct node* iter=*(h->arr+index);
    while(iter && iter->data!=key){
        iter=iter->next;
    }
    if(!iter){
        return NULL;
    }
    else{
        return iter;
    }
}

int deletion(struct hsh *h, type key){
    if(!h || key<0){
        return -1;
    }
    struct node* kPtr;
    int ind;
    if((kPtr=searchKey(h, key, &ind))==NULL){
        return -1;
    }
    if(kPtr->pre){
        kPtr->pre->next=kPtr->next;
    }
    else{
        if(kPtr->next){
            kPtr->next->pre=kPtr->pre;
        }
        *(h->arr+ind)=kPtr->next;
    }
    if(kPtr->next){
        kPtr->next->pre=kPtr->pre;
    }
    free(kPtr);
    kPtr=NULL;
    return 0;
}

int destroy(struct hsh** h){
    if(!(*h)){
        return 0;
    }
    for(int i=0; i<((*h)->sz); i++){
        while(*((*h)->arr+i)){
            deletion(*h,(*((*h)->arr+i))->data);
        }
    }
    return 0;
}


