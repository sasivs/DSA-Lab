#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#define type int
struct hsh{
    type* arr;
    int sz;
    int bufsz;
    int flag;
};
int init(struct hsh**,int,int);
int mad_hash(type, int); //element to be hashed and size of the hash table
int mod_hash(type, int);
int insertion(struct hsh*, type);
int deletion(struct hsh*, type);
int searchKey(struct hsh*, type);
int traversal(struct hsh*);
int destroy(struct hsh**);

