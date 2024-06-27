// #include<stdio.h>
// #include<math.h>
// #define N 8
// //1 2 5  1 3 2  2 3 3  2 4 2  2 5 1  3 5 4  3 8 3  4 5 3  4 6 2  5 6 1  5 7 3  5 8 2  6 7 4  -1 -1 -1
// #define INF 1000000
// int create(int E[][N], int cost[][N]);
// int prims(int E[][N], int cost[][N], int n, int t[][N]);
// void srch_min(int E[][N], int cost[][N], int *k, int *l);

// int main(){
//     int E[N][N], cost[N][N], t[N][N], n;
//     n=create(E,cost);
//     int min=prims(E,cost,n,t);
//     printf("The min=%d", min);    
//     return 0;
// }

// void srch_min(int E[][N], int cost[][N], int *k, int *l){
//     int min=cost[0][0], i, j;
//     for(i=0; i<N; i++){
//         for(j=0; j<N; j++){
//             if(cost[i][j]<min){
//                 min=cost[i][j];
//                 *k=i, *l=j;
//             }        
//         }
//     }
// }

// int min_check(int cost[][N], int j, int nj, int n) {
//     int i, flag = 1; // Assume j is minimal initially
//     for (i = 0; i < n; i++) {
//         if (cost[i][nj] < cost[j][nj]) {
//             flag = 0; // If any edge's cost is less than j's cost, it's not minimal
//             break;
//         }
//     }
//     return flag;
// }

// int prims(int E[][N], int cost[][N], int n, int t[][n]){
//     int k, l, min_cost, near[N], i, nk,nl, checker;
//     srch_min(E,cost, &k, &l);
//     min_cost=cost[k][l];
//     t[0][0]=k;  t[0][1]=l;
//     for(i=0; i<n; i++){        //check
//         if(cost[i][l]<cost[i][k])
//             near[i]=l;
//         else    
//             near[i]=k;
//     }
//     near[k]=0;
//     near[l]=0;
//     for(i=0; i<=n; i++){
//         int j=i;
//         // checker=min_check(cost,j,near[j],n);
//         if(near[j]!=0){ //  && checker==1
//             printf("\nStep%d", i+1);
//             t[i][1]=j;    t[i][2]=near[j];
//             min_cost=min_cost+cost[j][near[j]];
//             near[j]=0;
//             for(int s=0; s<n; s++){
//                 printf("\nnear[%d]\t\t", s+1);
//                 if(near[s]!=0 && cost[s][near[s]]>cost[s][j])
//                     near[s]=j;
//                 if(cost[s+1][near[s+1]]==INF)
//                     printf("%d\tinf", near[s+1]);
//                 else
//                     printf("%d\t%d", near[s+1], cost[s+1][near[s+1]]);
//             }
//         }
//         printf("\n");
//     }
//     return min_cost;
// } 

// int create(int E[][N], int cost[][N]){
//     for(int i=0; i<N; i++)
//         for(int j=0; j<N; j++)
//             E[i][j]=0;

//     for(int i=0; i<N; i++)
//         for(int j=0; j<N; j++)
//             cost[i][j]=INF;
    
//     int o, d, n, max, c, k=0;
//     printf("\nEnter the number of vertices: ");
//     scanf("%d", &n);
//     max=n*(n-1)/2;
//     printf("\nEnter the edges(to exit -1 -1 0)\n");
//     for(int i=0; i<max; i++){
//         // printf("Enter edge %d and its cost: ", i+1);
//         scanf("%d%d%d", &o, &d, &c);
//         if(o==-1 && d==-1)
//             break;
//         if(o>n || o<=0 || d>n || d<=0){
//             printf("Invalid\n");
//             i--;
//         }else{
//             E[o][d]=1;    E[d][o]=1;
//             cost[o][d]=c;   cost[d][o]=c;
//         }
//     }
//     return n;
// }