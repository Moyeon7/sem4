#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define true 1
#define false 0
#define maxcap 10000
int *s;
void path(int ptr, int *dist){
    if(ptr==0){
        printf("%d", ptr + 1);
        return;
    }
    else {
        printf("%d<-", ptr + 1);
        path(dist[ptr],dist);
        return;
        
    }
        
}
void bgraph(int k, int n, int **c){
    int cost[n], dist[n], i, j, p = k;
    s = (int *)malloc(n*(sizeof(int)));
    for (int i = 0; i < n; i++){
        cost[i] = maxcap;
        s[i] = -1;
    }
    cost[0] = 0;
    s[0]=1;
    for (j = 1; j < n; j++){
        int f = 0,cn = 0; 
        for (i = 0; i < j+1; i++){
            if (c[i][j]!=maxcap){
                s[j] = s[i]+1;
                if(f==0)
                    printf("\ncost[%d,%d]=min{%d",s[j], j+1, c[i][j]+cost[i]);
                else
                    printf(",%d",c[i][j]+cost[i]);
                f=1;
                cn++;
                if ((c[i][j] + cost[i]) < cost[j]){
                    cost[j] = c[i][j] + cost[i];
                    dist[j] = i;
                }
            }
        }
        printf("}=%d", cost[j]);
        printf("%*s", 20, " ");
        printf("dist[%d,%d]=%d",s[j], j + 1, dist[j] + 1);
    }
    printf("\n\n");
    int f = n-1;
    for(j=n-1;j>0;j--){
        printf("cost[%d,%d]=%2d   ",s[j], j + 1, cost[j]);
        if(j==f){
            printf("dist[%d,%d]=\e[1m|%d|\e[m\n",s[j], j + 1, dist[j] + 1);
            f = dist[f];
        }
        else
        printf("dist[%d,%d]=%d\n",s[j], j + 1, dist[j] + 1);
    }
    printf("cost[%d,%d]=%2d\n",s[0], 1, cost[0]);
    int ptr = dist[n-1];
    printf("\nShortest path from 1 to %d: ", n);
    path(n-1,dist);
    printf("\n");
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
    bgraph(k, n, c);
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