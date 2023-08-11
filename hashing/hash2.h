#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define type int
struct node{
    type data;
    struct node *next,*pre;
};
struct hsh{
    struct node** arr;
    int sz;
    int flag;
};

int init(struct hsh**,int,int);
int mad_hash(type, int); //element to be hashed and size of the hash table
int mod_hash(type, int);
int insertion(struct hsh*, type);
int deletion(struct hsh*, type);
struct node* searchKey(struct hsh*, type, int*);
int destroy(struct hsh**);

