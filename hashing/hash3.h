#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define type int
int init(type**, int);
int mad_hash(type, int); //element to be hashed and size of the hash table
int mod_hash(type, int);
int insertion(type*, type, int);
int deletion(type*, type, int);
int searchKey(type*, type, int);
int traversal(type*, int);
int destroy(type**);

