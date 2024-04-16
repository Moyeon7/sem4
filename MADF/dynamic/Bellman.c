#include<stdio.h>
#define N 8
#define INF 1000000
int incoming(int u, int cost[][N], int n){
    for(int i=0; i<n; i++)
        if(cost[i][u]!=INF)
            return 1;
    return 0;
}
void bellman(int v, int cost[][N], int dist[N], int path[N], int n){
    int prevdist[N];
    for(int i=1; i<=n; i++){
        dist[i]=cost[v][i];
        prevdist[i]=cost[v][i];
        path[i]=0;
    }
    prevdist[0]=0;
    dist[0]=0;
    for(int k=2; k<=n; k++){
        printf("\nFor k=%d: ",k-1);
        for(int i=0;i<n;i++){
            if(prevdist[i]!=dist[i]){
                printf("\033[1m|%d| \033[0m\t", dist[i]);
            }else if(dist[i]==INF){
                printf("inf\t");
            }else{
                printf("%d\t", dist[i]);
            }
        }
        printf("\n(u,i)\t");
            for(int j=1; j<=7; j++)
                    printf("(%d,%d)\t", k-1, j);

        for(int i=1; i<=n; i++){
            prevdist[i]=dist[i];
        }
        for(int u=0; u<n; u++)
            if(u!=v && incoming(u,cost,n)==1)
                for(int i=0; i<n; i++)
                    if(cost[i][u]!=INF && dist[u]>prevdist[i]+cost[i][u]){
                        dist[u]=prevdist[i]+cost[i][u];
                        path[u]=i;
                    }
    }
}
void create(int n, int cost[][N]){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=INF;
        }
    int o, d, max, c;
    max=n*(n-1);
    printf("\nEnter the edges(to exit -1 -1 0)\n");
    for(int i=0; i<max; i++){
        scanf("%d%d%d", &o, &d, &c);
        if(o==-1 && d==-1)
            break;
        if(o>n || o<=0 || d>n || d<=0){
            printf("\nInvalid");
            i--;
        }else{
            cost[o-1][d-1]=c;
        }
    }
}
int printPath(int source, int dest, int path[N], int dist[N]) {
    int tempPath[N];
    int count = 0;
    printf("1\t%d\t%d\t",dest+1,dist[dest]);
    while(dest != source) {
        tempPath[count++] = dest;
        dest = path[dest];
    }
    tempPath[count++] = source;

    for(int i = count - 1; i > 0; i--) {
        printf("%d -> ", tempPath[i] + 1);
    }
    printf("%d\n", tempPath[0] + 1);

}
int main(){
    int cost[N][N], dist[N], path[N], n, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    create(n, cost);
    bellman(0, cost, dist, path, n);
    printf("\n\nShortest distances from vertex 1:\n");
    for(int i=0;i<n;i++)
        printf("%d ", dist[i]);
    printf("\n\nSource vertex is 1\n");
    printf("Src\tDest\tlen\tPath\n");
    for(int i = 1; i < n; i++) {
        printPath(0, i, path, dist);
    }
    return 0;
}

/*
7
1 2 6
1 3 5
1 4 5
2 3 3
2 5 -1
2 6 2
2 7 3
3 2 -2
3 5 1
4 1 -2
4 2 3
4 3 -2
4 6 -1
5 1 1
5 2 2
5 6 5
5 7 3
6 1 4
6 2 1
6 7 3
7 1 -2
7 2 -1
7 3 3
7 6 -2
-1 -1 -1
*/