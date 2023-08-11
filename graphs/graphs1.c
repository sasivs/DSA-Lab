#include"graphs1.h"
struct queues{
    int* arr;
    int f, r;
    int len;
};
int init(struct graph** g, int sz){
    (*g)=(struct graph*)malloc(sizeof(struct graph));
    if(!(*g)){
        return -1;
    }
    (*g)->len=sz;
    (*g)->arr=(struct node**)malloc(sz*sizeof(struct node*));
    for (int i=0; i<sz; i++){
        *((*g)->arr + i)=NULL;
    }
    return 0;
}

int add_edge(struct graph* g,int x, int y){
    if(!g){return -1;}
    if(x>g->len || y>g->len){return -1;}
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=y;
    newNode->pre=NULL;
    newNode->next=g->arr[x];
    if(g->arr[x]){
        g->arr[x]->pre=newNode;
    }
    g->arr[x]=newNode;
    return 0;
}

int del_edge(struct graph* g, int x, int y){
    if(!g){return -1;}
    if(x>g->len || y>g->len){return -1;}
    struct node* iter=g->arr[x];
    while(iter && iter->data!=y){
        iter=iter->next;
    }
    if(!iter){
        return -1;
    }
    if(iter->next){
        iter->next->pre=iter->pre;
        if(!iter->pre){
            g->arr[x]=NULL;
        }
    }
    if(iter->pre){
        iter->pre->next=iter->next;
    }
    if(!iter->next && !iter->pre){
        g->arr[x]=NULL;
    }
    free(iter);
    return 0;
}

int dfSearch(struct graph* g, int root, int* v){
    if(!g){
        return -1;
    }
    v[root]=1;
    printf("%d->",root);
    struct node* iter=g->arr[root];
    while(iter){
        if(v[iter->data]==0){
            dfSearch(g,iter->data,v);
        }
        iter=iter->next;
    }
    return 0;
}

int dfs(struct graph* g, int root){
    if(!g){return -1;}
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

int bfSearch(struct graph* g, int root, struct queues* q, int *v){
    if(!g || !q){return -1;}
    enqueue(q,root);
    v[root]=1;
    printf("%d->",root);
    int i;
    struct node* iter;
    while(q->f!=-1){
        i=dequeue(q);
        iter=g->arr[i];
        while(iter && v[iter->data]==0){
            enqueue(q,iter->data);
            v[iter->data]=1;
            printf("%d->",iter->data);
            iter=iter->next;
        }
    }
    return 0;
}

int bfs(struct graph* g, int root){
    if(!g){return -1;}
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

int get_ele(struct graph* g, int* v){
    if(!g){return -1;}
    int f;
    struct node* iter;
    for (int i=0; i<g->len; i++){
        f=0;
        if(v[i]==0){
            for(int j=0; j<g->len && f!=1; j++){
                if(j==i){
                    continue;
                }
                iter=g->arr[j];
                while(iter){
                    if (iter->data==i){
                        f=1;
                    }
                    iter=iter->next;
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
    if(!g){return -1;}
    int v;
    struct node* iter;
    int visit[g->len];
    for (int i=0; i<g->len; i++){
        visit[i]=0;
    }
    while((v=get_ele(g,visit))>=0){
        printf("%d->",v);
        iter=g->arr[v];
        while(iter){
            g->arr[v]=iter->next;
            if(iter->next){
                iter->next->pre=NULL;
            }
            free(iter);
            iter=g->arr[v];
        }
        g->arr[v]=NULL;
    }
    return 0;
}

int destroy(struct graph** g){
    if(!*g){
        return 0;
    }
    struct node* iter;
    for (int i=0; i<(*g)->len; i++){
        iter=(*g)->arr[i];
        while(iter){
            (*g)->arr[i]=iter->next;
            if(iter->next){
                iter->next->pre=NULL;
            }
            free(iter);
            iter=(*g)->arr[i];
        }
        (*g)->arr[i]=NULL;
    }
    free(*g);
    *g=NULL;
    return 0;
}
