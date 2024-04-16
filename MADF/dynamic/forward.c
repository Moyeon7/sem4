#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define true 1
#define false 0
#define maxcap 10000
int *s;
void fgraph(int k, int n, int **c){
    int cost[n], dist[n], i, j, p = k,f;
    s = (int *)malloc(n*(sizeof(int)));
    for (int i = 0; i < n; i++){
        cost[i] = maxcap;
        s[i] = -1;
        }
    cost[n - 1] = 0;
    s[n-1]=k;
    for (j = n - 2; j >= 0; j--){
        int f = 0,cn = 0; 
        for (i = j + 1; i < n; i++){   
            if (c[j][i]!=maxcap){
                s[j] = s[i]-1;
                if(f==0)
                    printf("\ncost[%d,%d]=min{%d",s[j], j+1, c[j][i]+cost[i]);
                else
                    printf(",%d",c[j][i]+cost[i]);
                f=1;
                cn++;
                if ((c[j][i] + cost[i]) < cost[j]){
                    cost[j] = c[j][i] + cost[i];
                    dist[j] = i;
                }
            }
        }
        printf("}=%d", cost[j]);
        printf("%*s", 20, " ");
        printf("dist[%d,%d]=%d",s[j], j + 1, dist[j] + 1);
    }
    int ptr = dist[0];
    printf("\n\n");
    f = 0;
    for(j=0;j<=n-2;j++){
        printf("cost[%d,%d]=%d   ",s[j], j + 1, cost[j]);
        if(j==f){
            printf("\t\tdist[%d,%d]=\e[1m|%d|\e[m\n",s[j], j + 1, dist[j] + 1);
            f = dist[f];
        }else
        printf("\t\tdist[%d,%d]=%d\n",s[j], j + 1, dist[j] + 1);
    }
    printf("cost[%d,%d]=%d\n",s[n-1], n, cost[n-1]);
    printf("\nShortest path from 1 to %d: 1", n);
    for (int i = 0; i < k - 1; i++){
        printf("->%d", ptr + 1);
        ptr = dist[ptr];
    }
    printf("\n\n");
}
void enter(int i, int j, int prc, int **c){
    c[i - 1][j - 1] = prc;
}
int main(){
    int n, maxedge, i, j, src, dst, prc, dist[20], p[20], k;
    printf("\nEnter the no. of vertices in graph: ");
    scanf("%d", &n);
    maxedge = (n * (n - 1));
    printf("Enter the no. of stages in graph: ");
    scanf("%d", &k);
    int **c = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        c[i] = malloc(n * sizeof(int));

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            c[i][j] = maxcap;
        }
    }
    int check=0,a,b,d;
    printf("Enter src,dest,weight(0 to cont/1 to exit):\n");
    while(check!=1){
        scanf("%d%d%d%d", &a, &b, &d, &check);
        enter(a, b, d, c);
    }
    fgraph(k, n, c);
}
/*
14
5
1 2 10 0 
1 3 13 0
1 4 12 0
1 5 15 0
2 6 7 0
2 7 3 0
2 9 5 0
3 6 4 0
3 8 6 0
3 9 2 0
4 6 3 0
4 7 2 0
4 8 5 0
5 7 5 0
5 8 6 0
5 9 7 0
6 10 8 0
6 11 10 0
6 12 11 0
7 10 12 0
7 11 13 0
7 12 14 0
7 13 15 0
8 11 10 0
8 12 9 0
8 13 8 0
9 12 7 0
9 13 6 0
10 14 10 0
11 14 9 0
12 14 8 0
13 14 7 1
*/