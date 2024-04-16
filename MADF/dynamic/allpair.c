#include <stdio.h>
#include <limits.h>
#define N 30
#define inf 99999
void zero(int a[][N], int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                a[i][j] = 0;
}
void getmat(int a[][N], int n){
    int w, x, y;
    printf("Enter edge and weight(-1 -1 -1 to exit): \n");
    for (int i = 0; i < n * (n - 1); i++){   
        scanf("%d%d%d", &x, &y, &w);
        if (x == -1 && y == -1)
            return;
        a[--x][--y] = w;
    }
}
void show(int a[][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == inf)
                printf("inf\t");
            else
                printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
void allpair(int cost[][N], int a[][N], int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = a[i][j];
    zero(cost, n); 

    printf("\nA0\n");
    show(cost, n);
    printf("\n");
    int l=1;
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
        printf("A%d\n",l++);
        show(cost, n);
        printf("\n");
    }
}
int main(int argc, char const *argv[]){
    int cost[N][N], a[N][N], n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = inf;

    getmat(a, n);
    allpair(cost, a, n);
    printf("The shortest path matrix is\n");
    show(cost, n);
    return 0;
}

/*
5
1 2 6
1 3 8
1 5 -4
2 1 3
2 3 -3
2 4 1
2 5 6
3 2 4
3 4 10
4 3 -5
4 5 -2
4 1 6
5 4 6
5 1 6
-1 -1 -1
*/