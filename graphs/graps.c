#include"graps.h"

struct queues {
    int* arr;
    int f, r;
    int len;
};

int init(struct graph** g, int sz){
    *g=(struct graph*)malloc(sizeof(struct graph));
    if(!(*g)){
        return -1;
    }
    (*g)->len=sz;
    (*g)->arr=(int**)malloc(sz*sizeof(int*));
    for (int i=0; i<sz; i++){
        *((*g)->arr+i)=(int*)malloc(sz*sizeof(int));
        for(int j=0; j<sz; j++){
            (*g)->arr[i][j]=0;
        }
    }
    return 0;
}

int add_edge(struct graph* g, int x, int y){
    if(!g || x>g->len || y>g->len){
        return -1;
    }
    g->arr[x][y]=1;
    return 0;
}

int del_edge(struct graph* g, int x, int y){
    if(!g || x>g->len || y>g->len || g->arr[x][y]==0){
        return -1;
    }
    g->arr[x][y]=0;
    return 0;
}


int dfSearch(struct graph* g, int root, int* v){
    if(!g){
        return -1;
    }
    v[root]=1;
    printf("%d->",root);
    for (int j=0; j<g->len; j++){
        if(!v[j] && g->arr[root][j]==1){
            dfSearch(g,j,v);
        }
    }
    return 0;
}
int dfs(struct graph* g, int root){
    if(!g){
        return -1;
    }
    int visited[g->len];
    for (int i=0; i<g->len; i++){
        visited[i]=0;
    }
    dfSearch(g,root,visited);
    return 0;
}

int enqueue(struct queues* q, int key){
    if(!q){return -1;}
    if((q->r+1)%q->len==q->f){return -1;}
    q->r=(q->r+1)%q->len;
    q->arr[q->r]=key;
    if(q->f==-1){
        q->f=(q->f+1)%q->len;
    }
    return 0;
}

int dequeue(struct queues* q){
    if(!q){return -1;}
    if(q->f==-1){return -1;}
    int r=q->arr[q->f];
    if(q->f==q->r){
        q->f=-1;
        q->r=-1;
        return r;
    }
    q->f=(q->f+1)%q->len;
    return r;
}
int bfSearch(struct graph* g, int root, struct queues* q, int* v){
    if(!q || !g){
        return -1;
    }
    enqueue(q,root);
    v[root]=1;
    printf("%d->",root);
    int i;
    while(q->f!=-1){
        i=dequeue(q);
        for(int j=0; j<g->len; j++){
            if(!v[j] && g->arr[i][j]==1){
                enqueue(q,j);
                v[j]=1;
                printf("%d->",j);
            }
        }
    }
    return 0;
}
int bfs(struct graph* g, int root){
    if(!g){
        return -1;
    }
    struct queues* q=(struct queues*)malloc(sizeof(struct queues));
    q->arr=(int*)malloc(g->len*sizeof(int));
    q->f=q->r=-1;
    q->len=g->len;
    int v[g->len];
    for (int i=0; i<g->len; i++){
        v[i]=0;
    }
    bfSearch(g,root,q,v);
    return 0;
}

int get_ele(struct graph* g,int* v){
    if(!g){return -1;}
    int f=0;
    for (int i=0; i<g->len; i++){
        f=0;
        if(v[i]!=1){
            for(int j=0; j<g->len && f!=1; j++){
                if(g->arr[j][i]==1){
                    f=1;
                }
            }
            if(f==0){
                v[i]=1;
                return i;
            }
        }
    }
    return -1;
}

int top_sort(struct graph* g){
    if(!g){
        return -1;
    }
    int v;
    int visit[g->len];
    for (int i=0; i<g->len; i++){
        visit[i]=0;
    }
    while((v=get_ele(g,visit))>=0){
        printf("%d->",v);
        for(int i=0; i<g->len; i++){
            g->arr[v][i]=0;
        }
    }
    return 0;
}

int destroy(struct graph** g){
    if(!*g){
        return 0;
    }
    for (int i=0; i<(*g)->len; i++){
        free((*g)->arr[i]);
        (*g)->arr[i]=NULL;
    }
    free(*g);
    *g=NULL;
    return 0;
}
