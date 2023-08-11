#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>


struct graph{
    int** arr;
    int len;
};
int init(struct graph**, int);
int add_edge(struct graph*, int, int);
int del_edge(struct graph*, int, int);
int dfs(struct graph*, int);
int bfs(struct graph*, int);
int top_sort(struct graph*);
int destroy(struct graph**);
