#include"graps.c"

int main(){
    struct graph* g;
    init(&g,6);
    add_edge(g,2,3);
    add_edge(g,5,2);
    add_edge(g,5,0);
    add_edge(g,3,1);
    add_edge(g,4,1);
    add_edge(g,4,0);
    dfs(g,0);
    printf("\n");
    bfs(g,0);
    printf("\n");
    top_sort(g);
    destroy(&g);
    printf("\n----\n");
    return 0;
}

