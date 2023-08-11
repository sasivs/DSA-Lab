#include"hash1.h"

int init(struct hsh** h, int sz, int flag){
    (*h)=(struct hsh*)malloc(sizeof(sizeof(struct hsh)));
    if(!(*h)){
        return -1;
    }
    (*h)->arr=(type*)malloc(sz*sizeof(type));
    (*h)->sz=sz;
    (*h)->bufsz=0;
    (*h)->flag=flag;
    for (int i=0; i<sz; i++){
        *((*h)->arr + i)=-1;
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
    int index,i=1;
    switch(h->flag){
        case 1: index = mad_hash(key,h->sz);
                while(*(h->arr+index)!=-1 && i<=h->sz){
                    index=mad_hash(key+(i*i),h->sz);
                    i++;
                }
                break;
        default: index = mod_hash(key, h->sz);
                 while(*(h->arr+index)!=-1 && i<=h->sz){
                    index=mod_hash(key+(i*i),h->sz);
                    i++;
                 }
                 break;
    }
    if(i>h->sz){
        h->arr=(type*)realloc(h->arr,sizeof(type));
        *(h->arr + h->sz + h->bufsz)=key;
        h->bufsz++;
    }
    else{
        *(h->arr+index)=key;
    }
    return 0;
}

int searchKey(struct hsh* h, type key){
    if(!h || key<0){
        return -1;
    }
    int index,i=0;
    switch(h->flag){
        case 1: index = mad_hash(key,h->sz);
                while(*(h->arr+index)!=key && i<=h->sz){
                    index=mad_hash(key+(i*i),h->sz);
                    i++;
                }
                break;
        default: index = mod_hash(key, h->sz);
                 while(*(h->arr+index)!=key && i<=h->sz){
                    index=mod_hash(key+(i*i),h->sz);
                    i++;
                 }
                 break;
    }
    if(*(h->arr+index)==key){
        return index;
    }
    else if(i>h->sz){
        for (int j=h->sz; j<h->sz+h->bufsz; j++){
            if(*(h->arr+j)==key){
                return j;
            }
        }
    }
    else{
        return -1;
    }
}
int deletion(struct hsh *h, type key){
    if(!h || key<0){
        return -1;
    }
    int index;
    if((index=searchKey(h, key))<0){
        return -1;
    }
    *(h->arr+index)=-1;
    if(index>=h->sz){
        h->bufsz--;
    }
    return 0;
}

int traversal(struct hsh* h){
    if(!h || h->sz<=0){
        return -1;
    }
    for (int i=0; i<h->sz+h->bufsz; i++){
        printf("%d ",*(h->arr+i));
    }
    printf("\n");
    return 0;
}

int destroy(struct hsh** h){
    if(!(*h)){
        return 0;
    }
    free((*h)->arr);
    (*h)->arr=NULL;
    (*h)->sz=0;
    (*h)->bufsz=0;
    (*h)->flag=0;
    free(*h);
    *h=NULL;
    return 0;
}

