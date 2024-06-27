#include <stdio.h>
#include <limits.h>
#define N 12
#define sint(x)
struct EDGE{
    int s, d, w;
};
void fillzeroes(int e[][N], int nodes){
    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            e[i][j] = 0;
}
void fillinf(int cost[][N], int nodes){
    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            cost[i][j] = INT_MAX;
}
void getmat(int e[][N], int cost[][N], int n, int edges){
    printf("\nEnter source,dest & cost:\n");
    for (int i = 1; i <= edges; i++){
        int s, d, w;
        scanf("%d%d%d", &s, &d, &w);
        if (s > 0 && s <= n && d > 0 && d <= n)
            e[s][d] = e[d][s] = 1, cost[s][d] = cost[d][s] = w;
    }
}
void showmat(int a[][N], int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            a[i][j] == INT_MAX ? printf("x ") : printf("%d ", a[i][j]);
        printf("\n");
    }
}
void sw(struct EDGE *a, struct EDGE *b){
    struct EDGE temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(struct EDGE e[N], int edges, int i){
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < edges && e[l].w < e[smallest].w)
        smallest = l;
    if (r < edges && e[r].w < e[smallest].w)
        smallest = r;
    if (smallest != i){
        sw(&e[i], &e[smallest]);
        heapify(e, edges, smallest);
    }
}
int Find(int parent[], int u){
    while (parent[u] != -1)
        u = parent[u];
    return u;
}
void Union(int parent[N], int u, int v){
    parent[u] = v;
}
int kruskal(int e[][N], int cost[][N], int nodes, int t[][2], int edges){
    struct EDGE heap[N];
    int in = 0,p,q;
    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            if (j > i && cost[i][j] != INT_MAX)
                heap[in].s = i, heap[in].d = j, heap[in++].w = cost[i][j];
    for (int i = edges/2-1; i >= 0; i--)
        heapify(heap, edges, i);
    int parent[N];
    for (int i = 1; i <= nodes; i++)
        parent[i] = -1;
    int i = 1, mincost = 0;
    while (i < nodes){
        sw(&heap[0], &heap[edges - 1]);
        struct EDGE minedge = heap[edges - 1];
        edges--;
        heapify(heap, edges, 0);
        int u = minedge.s, v = minedge.d, j = Find(parent, u), k = Find(parent, v);
        if (j != k){
            t[i][1] = u, t[i][2] = v, mincost += cost[u][v];
            Union(parent, j, k);
            printf("\nstep %d(%d,%d): ",i,t[i][1],t[i][2]);
            for(int r=1; r<=nodes; r++)
                printf("  %d", r);
            printf("  j k");
            i++;
            printf("\nparent arr:  ");
                for(int e=1;e<=nodes;e++)
                    printf(" %c%d",parent[e]<0?'\0':' ', parent[e]);
            printf("  %d %d",j,k);
            printf("\nTable of spanning tree edges:\n");
            for (int r = 1; r < i; r++){
                printf("%d %d\n", t[r][1], t[r][2]);
            }
            printf("Mincost: %d\n", mincost);
        }
    }
    if (i != nodes)
        return -1;
    else
        return mincost;
}
int main(int argc, char const *argv[]){
    int cost[N][N], e[N][N], t[N][2], edges, nodes;
    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &nodes, &edges);
    fillzeroes(e, nodes), fillinf(cost, nodes);
    getmat(e, cost, nodes, edges);
    int mincost = kruskal(e, cost, nodes, t, edges);
    if (mincost != -1){
        printf("\nMST\n");
        for (int i = 1; i <= nodes - 1; i++)
            printf("%d %d\n", t[i][1], t[i][2]);
        printf("The Mincost is %d\n", mincost);
    }
    else
        printf("no mst\n");
    return 0;
}

/*
8 11
1 2 12
1 3 11
3 4 14
2 4 4
4 6 8
2 5 5
4 5 3
4 7 6
6 7 15
5 8 17
7 8 10


1 2 5  1 3 2  2 3 3  2 4 2  2 5 1  3 5 4  3 8 3  4 5 3  4 6 2  5 6 1  5 7 3  5 8 2  6 7 4
*/
