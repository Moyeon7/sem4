#include <stdio.h>
#define N 20

int G[N][N], count = 0, count2 = 1, soln=0;

void show(int x[N], int nodes){
    int p;
    printf("\nLeaf Node: %d.\t",count2++);
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
void nextval(int x[N], int nodes, int colors, int k){
    do{
        x[k] = (x[k] + 1) % (colors + 1); 
        if (x[k]==0)                       
            return;
        int j;
        for (j = 1; j <= nodes; j++){
            if ((G[k][j] != 0) && (x[k] == x[j]))
                break; 
        }
        if (j == nodes + 1)
            return; 
    } while (1);
}

void color2(int x[N], int nodes, int colors, int k){
    do{
        // if(count2==1)
            // show(x,nodes);
        nextval(x, nodes, colors, k);
        if (x[k]==0){
            show(x, nodes);
            printf("\t\tBound");
            return;
        }
        if (k == nodes){
            show(x,nodes);
            printf("\tSolution");
            soln++;
        }
        else
            color2(x, nodes, colors, k + 1);
    } while (1);
}

int chromatic(int nodes){
    int result = 0;
    int color[N] = {0}; 
    
    for (int i = 1; i <= nodes; i++) {
        int available[N] = {0}; 
        for (int j = 1; j <= nodes; j++) {
            if (G[i][j] && color[j] != 0) {
                available[color[j]] = 1; 
            }
        }
        for (int c = 1; c <= nodes; c++) {
            if (available[c] == 0) {
                color[i] = c;
                if (c > result) {
                    result = c; 
                }
                break;
            }
        }
    }
    return result;
}

int main(){
    int nodes, edges, colors, o, d, x[N];
    printf("Enter the number of nodes: "), scanf("%d", &nodes);

    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            G[i][j] = 0;

    printf("Enter the number of edges: "), scanf("%d", &edges);

    printf("Enter origin and destination\n");
    for (int i = 0; i < edges; i++)
        scanf("%d", &o), scanf("%d", &d), G[o][d] = G[d][o] = 1;

    colors = chromatic(nodes);
    for (int i = 1; i <= nodes; i++)
        x[i] = 0;
    printf("\nThe possible ways to color the nodes of the graph are\n");
    color2(x, nodes, colors, 1);

    printf("\nChromatic number of the graph: %d\n",colors);
    printf("Number of solutions: %d\n",soln);
    return 0;
}

/*
pract
8
13
1 2 
1 3
2 3
2 5
2 4
2 6
3 4
3 7
4 6
5 6
5 8
6 7
6 8
*/      

/*
6
7
1 2
2 5
3 4
4 6
1 3
2 4
5 6
*/
