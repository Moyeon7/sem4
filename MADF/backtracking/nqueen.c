#include<stdio.h>
#include<stdlib.h>
#define N 20
int mat[N];
int check=0;

int place(int row, int col){
    for (int i = 1; i <= row - 1; i++){
        if (mat[i] == col)
            return 0;
        else if (abs(mat[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void show(int n){
    printf("\n"); printf("\n");
    for (int i = 1; i <= n; i++){
        printf("\t%d", i);
    }
    for (int i = 1; i <= n; i++){
        printf("\n\n%d", i);
        for (int j = 1; j <= n; j++){
            if (mat[i] == j)
                printf("\t\x1b[1mQ\x1b[0m"); 
            else
                printf("\t_"); 
        }
    };
    printf("\n"); printf("\n");
}

void nqueen(int row, int n){
    for (int col = 1; col <= n; col++){
        if (place(row, col)){
            mat[row] = col;
            if (row == n && check==0){
                show(n);
                check++;
                return;
            }
            else
                nqueen(row + 1, n);
        }
    }
}

int main(int argc, char const *argv[]){
    for(int k=1; k<=12; k++){
        printf("\n\x1b[1mSolution for the size %d: \x1b[0m", k);
        check=0;
        nqueen(1, k);
        if(check==0){
            printf("\nNo Solution\n");
        }
    }  
    return 0;
}
