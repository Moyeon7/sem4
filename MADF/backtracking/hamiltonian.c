#include <stdio.h>
#define N 100
int G[N][N], count1 = 0, count2 = 0;
int l=0;
void show(int x[N], int nodes){
    int p;
    printf("%d.\t", ++count1);
    for (int i = 1; i <= nodes; i++){
        p=i;
        if(x[i]==0){
            printf("x[%d]=%d\t", i,x[i]);
            return; //break;
        }else{
            printf("x[%d]=%d\t", i,x[i]);
        }
    }
    printf("x[%d]=%d\t", p+1,x[1]);
}

void shows(int x[N], int nodes)
{
    printf("%d.\t", ++count2);
    for (int i = 1; i <= nodes; i++)
        printf("%d -> ", x[i]);
    printf("%d", x[1]);
    printf("\n");
}

void nextval(int x[N], int nodes, int k) {
    do { 
        x[k] = (x[k] + 1) % (nodes + 1); 
        if (!x[k])
            return;
        if (G[x[k - 1]][x[k]] != 0) {
            int j;
            for (j = 1; j <= k - 1; j++) {
                if (x[j] == x[k]) {
                    break;
                }
            } 
            if (j == k) {
                if ((k < nodes) || ((k == nodes && G[x[nodes]][x[1]] != 0))) {
                    return;
                }
            }
        }
    } while (1);
}

void ham(int x[N], int nodes, int k) {
    int child = 0;
    do {
        nextval(x, nodes, k);
        if (x[k]!=0)
            child=1;
        if(x[k]==0){
            if(child==0){
                printf("\nLeaf node ");
                show(x, nodes);
                printf("\t\tBound");
            }
            return;
        }
        if (k == nodes) {
            printf("\nLeaf node ");
            show(x,nodes);
            printf("\tSolution");
        } else {
            ham(x,nodes,k+1);
        }
    } while (1);
}

void soln(int x[N], int nodes, int k){
    do{
        nextval(x, nodes, k);
        if (!x[k])
            return;
        if (k == nodes)
            shows(x, nodes);
        else
            soln(x, nodes, k + 1);
    } while (1);
}

int main(){
    int nodes, edges, o, d, x[N];
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            G[i][j] = 0;

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter origin and destination\n");
    for (int i = 0; i < edges; i++){
        scanf("%d%d", &o,&d);
        G[o][d] = G[d][o] = 1;
    }

    for(int i=0; i<nodes; i++){
        x[1]=i+1;
        for (int i = 2; i <= nodes; i++)
            x[i] = 0;
        printf("\nThe possible Hamiltonian Cycles starting from node %d are:\n", i+1);
        soln(x, nodes, 2);
    }

    for(int i=0; i<nodes; i++){
        x[1]=i+1;
        for (int i = 2; i <= nodes; i++)
            x[i] = 0;
        printf("\n\nThe possible Hamiltonian Cycles starting from node %d are:", i+1);
        ham(x, nodes, 2);
    }
    
    return 0;
}

/*
pract
7
11
1 2
1 4
2 4
2 5
2 6
2 3
3 6
3 7
4 5
5 6
6 7
*/

/*
tut
5
7
1 2
1 3
1 4
2 3
2 5
3 5
4 5
*/
