#include <stdio.h>
#include <limits.h>
#define N 10
typedef enum{
    false=0,
    true=1
}bool;
void fillinf(int cost[][N], int n){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cost[i][j] = INT_MAX;
}
void getmat(int cost[][N], int n, int e){
    for (int i = 0; i < e; i++){
        int s, d, w;
        scanf("%d%d%d", &s,&d,&w);
        if (s >= 1 && s <= n && d >= 1 && d <= n)
            cost[s][d] = w;
    }
}
void showmat(int a[][N], int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            a[i][j] == INT_MAX ? printf("x ") : printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
void shortestpath(int cost[][N], int dist[N], int pred[N], int n, int v){   
    int s[N],p;
    for (int i = 1; i <= n; i++)
        s[i] = false, dist[i] = cost[v][i], pred[i]=v;
    s[v] = true, dist[v] = 0;
    printf("\nIteration 1     u=1\nS[1]=True\n");
    for(p=2;p<=n;p++)
        printf("S[%d]=",p);
    printf("False\n");
    for (int i = 1; i <= n; i++){
        if(dist[i]==INT_MAX)
            printf("dist[%d] = inf\n",i);
        else
           printf("dist[%d] = %d\n", i, dist[i]); 
    } 
    printf("\n");
    for (int i = 2; i <= n; i++){   
        int u, min = INT_MAX;
        for (int k = 1; k <= n; k++)
            if (s[k] == false && dist[k] < min)
                min = dist[k], u = k;
        s[u] = true;
        for (int j = 1; j <= n; j++){
            if (cost[u][j] != INT_MAX && s[j] == false)
                if (dist[j] > dist[u] + cost[u][j]){
                    dist[j] = dist[u] + cost[u][j];
                    pred[j]=u;
                }   
        }
        printf("\nIteration %d    u=%d\n", i,u);
        for(p=1; p<=i; p++)
            printf("S[%d]=",p);
        printf("True\n");
        for(;p<=n;p++)
            printf("S[%d]=",p);
        if(i!=n)
            printf("False\n");
        for (int i = 1; i <= n; i++){
            if(dist[i]==INT_MAX)
                printf("dist[%d] = inf\n",i);
            else
                printf("dist[%d] = %d\n", i, dist[i]); 
        }
    }
}
void printPath(int pred[], int v, int dest) {
    if (v == dest) {
        printf("%d", v);
        return;
    }
    printPath(pred, pred[v], dest);
    printf(" -> %d", v);
}
int main(int argc, char const *argv[]){
    int cost[N][N], dist[N], n, v, e, pred[N];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    fillinf(cost, n);
    printf("Enter the entries:\n");
    getmat(cost, n, e);
    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);
    shortestpath(cost, dist, pred, n, v);
    printf("\n");
    printf("Starting vertex: %d\n", v);
    printf("src\tdest\tlen\tpath\n");
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            printf("No path from %d to %d\n", v, i);
        } else {
            printf("%d\t%d\t%d\t", v, i, dist[i]);
            printPath(pred, i, 1);
            printf("\n");
        }
    }
    return 0;
}

/*
8
20
1 2 20  1 3 40  1 5 50  1 6 40  2 3 15  2 4 10  2 5 5  3 8 5  4 3 2  4 6 8  5 4 3  5 7 8  6 5 6  6 8 4  6 3 3  7 2 2  7 8 2  7 6 2  8 2 3  8 5 2
1
*/
