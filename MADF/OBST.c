#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
char *keys[10];
#define N 20
#define inf INT_MAX
struct key{
    int w, r, c;
};
void inorder(struct key g[][N], int i, int j){
    if (i == j)
        return;
    else{
        inorder(g, i, g[i][j].r - 1);
        printf("%s", keys[g[i][j].r-1]);
        printf(",");
        inorder(g, g[i][j].r, j);
    }
}
void preorder(struct key g[][N], int i, int j){
    if (i == j)
        return;
    else{
        printf("%s", keys[g[i][j].r-1]);
        printf(",");
        preorder(g, i, g[i][j].r - 1);
        preorder(g, g[i][j].r, j);
    }
}
int find(struct key g[][N], int i, int j){
    int min = inf, l;
    for (int m = g[i][j - 1].r; m <= g[i + 1][j].r; m++){
        if ((g[i][m - 1].c + g[m][j].c) < min){
            min = g[i][m - 1].c + g[m][j].c;
            l = m;
        }
    }
    return l;
}
void obst(struct key g[][N], int q[N], int p[N], int n, char *a[] ){
    int k;
    for (int i = 0; i < n; i++){
        g[i][i].w = q[i], g[i][i].r = g[i][i].c = 0;
        g[i][i + 1].w = q[i] + q[i + 1] + p[i + 1];
        g[i][i + 1].r = i + 1;
        g[i][i + 1].c = q[i] + q[i + 1] + p[i + 1];
    }
    g[n][n].w = q[n], g[n][n].r = g[n][n].c = 0;
    for (int m = 2; m <= n; m++){
        for (int i = 0; i <= n - m; i++){
            int j = i + m;
            g[i][j].w = g[i][j - 1].w + p[j] + q[j];
            k = find(g, i, j);
            g[i][j].c = g[i][j].w + g[i][k - 1].c + g[k][j].c;
            g[i][j].r = k;
        }
    }
    printf("\n");
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n - i; j++){
            printf("w[%d,%d]=%3d  ", j, j + i, g[j][j + i].w);
        }
        printf("\n");
        for (int j = 0; j <= n - i; j++){
            printf("c[%d,%d]=%3d  ", j, j + i, g[j][j + i].c);
        }
        printf("\n");
        for (int j = 0; j <= n - i; j++){
            printf("r[%d,%d]=%3d  ", j, j + i, g[j][j + i].r);
        }
        printf("\n\n");
    }
    printf("------------------------------------------\n");
    printf("\nw[%d][%d] = %d\nc[%d][%d] = %d\nr[%d][%d] = %d\nMinimum cost of the BST is: %d\nroot: %s\n", 0, n, g[0][n].w, 0, n, g[0][n].c, 0, n, g[0][n].r, g[0][n].c, a[g[0][n].r - 1]);

    printf("\nInorder = {");
    inorder(g, 0, n);
    printf("}");
    printf("\nPreorder = {");
    preorder(g, 0, n);
    printf("}");
}
int main(int argc, char const *argv[]){
    int n;
    int p[N], q[N];
    struct key g[N][N];

    printf("Enter the number of identifiers: ");
    scanf("%d", &n);

    printf("Enter the keys: ");
    for (int i = 0; i < n; i++) {
        keys[i] = malloc(20 * sizeof(char));
        scanf("%s", keys[i]);
    }

    printf("Enter the values of array p: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
        
    printf("Enter the values of array q: ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &q[i]);

    obst(g, q, p, n, keys);
    return 0;
}
/*
5
else if int switch while
3 4 5 3 2 
3 5 4 3 4 3
*/
