#include<stdio.h>
// 3 -7 1 -9 6 -4 8 -3 -2 1 -3 8 5 9 -6 5
// -6 4 -6 9 8 -2 7 3 -9 4 5 -2 5 -3 8 7 

//3 -8 -7 -1 -6 1 5 6 2 10 3 -3 -5 4 9 2
//8 -7 3 -1 -9 6 2 4 5 11 6 -5 1 8 10 -3
void strassens(int n, int arr[][n], int brr[][n], int crr[][n]);
void merge(int n, int Result[][n], int c1[][n], int c2[][n], int c3[][n], int c4[][n]);
void divide(int n, int A[][n], int a1[][n], int a2[][n], int a3[][n], int a4[][n]);
void add(int m, int A[][m], int B[][m], int C[][m]);
void sub(int m, int A[][m], int B[][m], int C[][m]);

int main(){
    int n;
    printf("Enter the order of matrix\n");
    scanf("%d",&n);

    int arr[n][n], brr[n][n], result[n][n];  
    
    if(n==2){
        printf("\033[1m2x2 MATRIX\033[0m\n");
    }else if(n==4){
        printf("\033[1m4x4 MATRIX\033[0m\n");
    }

    printf("Enter the matrix A elements: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nEnter the matrix B elements: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &brr[i][j]);
        }
    }
    strassens(n, arr, brr, result);
    printf("\nMatrix c is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void strassens(int n, int arr[][n], int brr[][n], int result[][n]){
    if(n==2){
        int p, q, r , s, t, u, v;
        p=(arr[0][0]+arr[1][1])*(brr[0][0]+brr[1][1]);
        q=(arr[1][0]+arr[1][1])*brr[0][0];
        r=(arr[0][0])*(brr[0][1]-brr[1][1]);
        s=(arr[1][1])*(brr[1][0]-brr[0][0]);
        t=(arr[0][0]+arr[0][1])*(brr[1][1]);
        u=(arr[1][0]-arr[0][0])*(brr[0][0]+brr[0][1]);
        v=(arr[0][1]-arr[1][1])*(brr[1][0]+brr[1][1]);
        result[0][0]=p+s-t+v;
        result[0][1]=r+t;
        result[1][0]=q+s;
        result[1][1]=p+r-q+u;
    }else{
        int m=n/2;
        int p[m][m], q[m][m], r[m][m], s[m][n], t[m][m], u[m][m], v[m][m];
        int a1[n][n], a2[n][n], a3[n][n], a4[m][m];
        int b1[m][m], b2[m][m], b3[m][m], b4[m][m];
        int c1[m][m], c2[m][m], c3[m][m], c4[n][m];
        int tmp1[m][m], tmp2[m][m];
        divide(m, arr, a1, a2, a3, a4);
        divide(m, brr, b1, b2, b3, b4);
        
        add(m,a1,a4,tmp1); 
        add(m,b1,b4,tmp2);
        strassens(m,tmp1, tmp2, p);

        add(m,a3,a4,tmp1);
        strassens(m,tmp1,b1,q);

        sub(m,b2,b4,tmp1);
        strassens(m,a1,tmp1,r);

        sub(m,b3,b1,tmp1);
        strassens(m,a4,tmp1,s);

        add(m,a1,a2,tmp1);
        strassens(m,tmp1,b4,t);

        sub(m,a3,a1,tmp1);
        add(m,b1,b2,tmp2);
        strassens(m,tmp1,tmp2,u);

        sub(m,a2,a4,tmp1);
        add(m,b3,b4,tmp2);
        strassens(m,tmp1,tmp2,v);

        int x[n][n], y[n][n];
        add(m,p,s,x);
        sub(m,x,t,y);
        add(m,y,v,c1);
        add(m,r,t,c2);
        add(m,q,s,c3);
        add(m,p,r,x);
        sub(m,x,q,y);
        add(m,y,u,c4);
        merge(m,result,c1,c2,c3,c4);
    }
}

void add(int m, int A[][m], int B[][m], int C[][m]){
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int m, int A[][m], int B[][m], int C[][m]){
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void divide(int n, int A[][n], int a1[][n], int a2[][n], int a3[][n], int a4[][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a1[i][j]=A[i][j];
            a2[i][j]=A[i][j+2];
            a3[i][j]=A[i+n][j];
            a4[i][j]=A[i+n][j+2];
        }
    }
}

void merge(int n, int Result[][n], int c1[][n], int c2[][n], int c3[][n], int c4[][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Result[i][j]=c1[i][j];
            Result[i][j+n]=c1[i][j];
            Result[i+n][j]=c1[i][j];
            Result[i+n][j+2]=c1[i][j];
        }
    }   
}