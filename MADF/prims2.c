#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int cost[20][20];
void mini(int **cost, int n, int *k, int *l){
    int min = cost[0][0];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                *k = i;
                *l = j;
            }
        }
    }
}
int prim(int **cost, int n, int **t){
    int i, j, k, l,x,y, near[n], min, mincost;
    mini(cost, n, &k, &l);
    t[0][0] = k;
    t[0][1] = l;
    mincost = cost[k][l];
    for (i = 0; i < n; i++){
        if (cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }
    near[k] = -1;
    near[l] = -1;
    printf("Table of spanning tree edges:\n");
    for (x = 0; x < 1; x++){
        for (y = 0; y < 2; y++){
            printf("%d ", t[x][y] + 1);
        }
        printf("\n");
    
    }
    printf("Mincost: %d\n", mincost);
        printf("\n");
    for (i = 1; i < n - 1; i++){
        min = 0;
        for (k = 0; k < n; k++){
            if (near[k] != -1 && min == 0)
            {
                min = cost[k][near[k]];
                j = k;
            }
            else if (near[k] != -1 && cost[k][near[k]] < min)
            {
                min = cost[k][near[k]];
                j = k;
            }
        }
        printf("\nstep %d: ", i + 1);
        for (k = 0; k < n; k++){
            printf(" near[%d] ", k + 1);
        }
        printf("\n");
        printf("Near:\t  ");
        for (k = 0; k < n; k++){
            if (near[k] == -1)
                printf("  0      ");
            else
                printf("  %d      ", near[k] + 1);
        }
        printf("\n");
        printf("Cost:\t  ");
        for (k = 0; k < n; k++){
            if (cost[k][near[k]] == INT_MAX)
                printf(" inf     ");
            else if(near[k]==-1)
                printf(" ---     ");
            else
                printf(" %2d      ", cost[k][near[k]]);
        }
        printf("\n");
        printf("j=%d\n", j + 1);
        if (cost[j][near[j]] != INT_MAX){
            t[i][0] = j;
            t[i][1] = near[j];
            mincost = mincost + cost[j][near[j]];
        }
        else{
            t[i][0] = j;
            t[i][1] = j;
        }
        printf("Table of spanning tree edges:\n");
        for (x = 0; x <= i; x++){
            for (y = 0; y < 2; y++){
                printf("%d ", t[x][y] + 1);
            }
            printf("\n");
        }
        printf("Mincost: %d\n", mincost);
        printf("\n");
        near[j] = -1;
        for (k = 0; k < n; k++){
            if (near[k] != -1 && (cost[k][near[k]] > cost[k][j])){
                near[k] = j;
            }
        }
    }
    return mincost;
}
int main(){
    int n, maxedge, i, j, src, dst, prc;
    printf("\nEnter the no. of vertices in graph: ");
    scanf("%d", &n);
    maxedge = (n * (n - 1)) / 2;
    int **cost = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        cost[i] = malloc(n * sizeof(int));

    int **t = malloc((n - 1) * sizeof(int *));
    for (i = 0; i < n - 1; i++)
        t[i] = malloc(2 * sizeof(int));

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cost[i][j] = INT_MAX;
        }
    }
    printf("(enter -1,-1 to exit)\nEnter the source and destination vertices followed by cost: \n");
    for (i = 0; i < maxedge; i++){
        scanf("%d %d %d", &src, &dst, &prc);
        if (src == -1 && dst == -1)
            break;

        else if (src - 1 < 0 || src - 1 >= n || dst - 1 < 0 || dst - 1 >= n){
            printf("invalid edge\n");
            i--;
        }
        else{
            cost[src - 1][dst - 1] = prc;
            cost[dst - 1][src - 1] = prc;
        }
    }
    mini(cost, n, &src, &dst);
    printf("\n\nMinimum edge: %d %d\n", src + 1, dst + 1);
    prc = prim(cost, n, t);
}

/*
8 
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
-1 -1 -1
*/