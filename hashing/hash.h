#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#define type int
int init(type**, int);
int mad_hash(type, int); //element to be hashed and size of the hash table
int mod_hash(type, int);
int insertion(type*, type, int, int);
int deletion(type*, type, int, int);
int searchKey(type*, type, int, int);
int traversal(type*, int);
int destroy(type**);

