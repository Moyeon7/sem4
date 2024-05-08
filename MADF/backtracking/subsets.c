#include <stdio.h>
#define N 20

int n, m, count=0;

void show(int w[N], int k, int x[N]){
    printf("\n-------------------------------------------------------------");
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
void stsptr(int s, int k, int r, int w[], int x[], int i){
    if(i==0){
        printf("\nRoot Node: [%d,%d,%d]", s,k,r);
        stsptr(s,k,r,w,x,i+1);
    }
    if(x[i]==1){
        s=s+w[i]; k=k+1; r=r-w[i];
        printf("\nLeft Node: [%d,%d,%d]", s,k,r);
        stsptr(s, k, r, w, x, i+1);
    }else if(x[i]==0){
        k=k+1; r=r-w[i];
        printf("\nRight Node: [%d,%d,%d]", s,k,r);
        stsptr(s, k, r, w, x, i+1);
    }else if(i==n){
        if(x[i]==1){
            s=s+w[i]; k=k+1; r=r-w[i];
            printf("\nLeft Node: [%d,%d,%d]", s+w[i],k,r);
            return;
        }else{
            k=k+1; r=r-w[i];
            printf("\nRight Node: [%d,%d,%d]", s,k,r);
            return;
        }
    }
}

void sumofsub(int s, int k, int r, int w[], int x[]){
    if (k > n)
        return;
    
    if (s + w[k] == m){
        x[k]=1;
        show(w, k, x);
        stsptr(0,1,r,w,x,0);
    } 
    else if ((s + w[k] + w[k + 1]) <= m){
        x[k] = 1;
        sumofsub(s + w[k], k + 1, r, w, x);
    }
       
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
    for (int i = 1; i <= n; i++){
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

/*
5
1 2 3 6 17
27
*/
