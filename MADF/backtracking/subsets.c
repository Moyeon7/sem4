#include <stdio.h>
#define N 20

int n, m;

void show(int w[N], int k, int x[N]){
    printf("\nx = ( ");
    for (int i = 1; i <= n; i++){
        if (i==n)
            printf("%d", x[i]);
        else
            printf("%d, ", x[i]);   
    }
    int count=0;
    printf(" ) \nsum of the subset = ( ");
    for (int i = 1; i <= k; i++){
        if (x[i] == 1){
            if(count==0)
                printf("%d", w[i]);
            else    
                printf(", %d", w[i]);
            count++;
        }  
    }
    printf(" )\n");
}
void sumofsub(int s, int k, int r, int w[], int x[]){
    if (k > n)
        return;
    x[k] = 1;
    
    if (s + w[k] == m)
        show(w, k, x);
    else if ((s + w[k] + w[k + 1]) <= m)
        sumofsub(s + w[k], k + 1, r, w, x);
    if (((s + r - w[k]) >= m) && (s + w[k + 1] <= m)){
        x[k] = 0; 
        sumofsub(s, k + 1, r, w, x);
    }
}

int main(int argc, char const *argv[]){
    int r = 0; 

    printf("Enter the numberof elements: ");
    scanf("%d", &n);
    int w[n + 1], x[n + 1]; 

    printf("Enter the elements\n");
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
        scanf("%d", &w[i]);
        r += w[i];
    }
    printf("Enter max weight: ");
    scanf("%d", &m);

    sumofsub(0, 1, r, w, x);
    return 0;
}

/*
7 
1 2 3 6 17 22 27
27
*/

/*
7
6 17 1 27 2 3 22
27
*/

/*
7
27 22 17 6 3 2 1
27
*/