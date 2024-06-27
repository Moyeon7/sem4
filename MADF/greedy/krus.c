//rough
#include<stdio.h>
#include<math.h>
#define N 9
#define INF 1000000

int create(int E[][N], int cost[][N]);
int prims(int E[][N], int cost[][N], int n, int t[][2]);

int main(){
    int E[N][N], cost[N][N], n;
    n = create(E, cost);
    int t[n - 1][2];
    int min = prims(E, cost, n, t);
    printf("The min=%d", min);    
    return 0;
}

int prims(int E[][N], int cost[][N], int n, int t[][2]){
    int k, l, min_cost = 0, near[N];
    for (int i = 0; i < n; i++)
        near[i] = INF;
    near[0] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int min = INF;
        for (int j = 0; j < n; j++) {
            if (near[j] != 0 && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                k = j;
                l = near[j];
            }
        }
        t[i][0] = k;
        t[i][1] = l;
        min_cost += min;
        near[k] = 0;
        for (int j = 0; j < n; j++) {
            if (near[j] != 0 && cost[j][near[j]] > cost[j][k]) {
                near[j] = k;
            }
        }
    }
    return min_cost;
} 

int create(int E[][N], int cost[][N]){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            E[i][j] = 0;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cost[i][j] = INF;
    
    int o, d, n, max, c, k = 0;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    max = n * (n - 1) / 2;
    printf("\nEnter the edges (source destination cost):\n");
    for (int i = 0; i < max; i++) {
        scanf("%d%d%d", &o, &d, &c);
        if(o==-1 && d==-1)
            break;
        if (o < 1 || o > n || d < 1 || d > n) {
            printf("Invalid input. Please enter valid vertices.\n");
            i--;
        } else {
            E[o][d] = 1;
            E[d][o] = 1;
            cost[o][d] = c;
            cost[d][o] = c;
        }
    }   
    return n;
}
