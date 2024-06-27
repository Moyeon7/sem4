#include <stdio.h>
#include <string.h>
#define N 256
int L[N][N];
int left[N][N] = {0};
int right[N][N] = {0};
int sub1[N];
int smax(int a, int b){
    return a > b ? a : b;
}
void lcs(char x[], char y[], int n, int m){
    for (int i = 0; i <= n; i++)
        L[i][0] = 0;
    for (int j = 0; j <= m; j++)
        L[0][j] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (x[i - 1] == y[j - 1]){
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else{
                L[i][j] = smax(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
}
void backtrack(int n, int m, char X[], char Y[]){
    for(int i=0 ; i<N ; i++) for(int j=0 ; j<N ; j++) left[i][j] = ' ';
    for(int i=0 ; i<N ; i++) for(int j=0 ; j<N ; j++) right[i][j] = ' ';
    int i=n, j=m, c=L[n][m];
    while(c>0){
        if (X[i - 1] == Y[j - 1]) {
            left[i][j] = '[';
            right[i][j] = ']';
            sub1[c] = X[i - 1];
            c--;
            i--;
            j--;
        } else {
            if (L[i - 1][j] > L[i][j - 1]) {
                left[i][j] = '[';
                right[i][j] = ']';
                i--;
            } else {
                left[i][j] = '[';
                right[i][j] = ']';
                j--;
            }
            }
    }
}
void display(int n, int m, char x[], char y[]){
    printf("   Y");
    for(int i=0; i<m; i++)
        printf("%4c", y[i]);
    printf("\nX");
    for (int i = 0; i <= n; i++) {
        if(i!=0) printf("%c", x[i-1]);
        for (int j = 0; j <= m; j++) {
            printf("%c%2d%c", left[i][j], L[i][j], right[i][j]);
        }
        printf("\n");
    }
}
void show(char y[], int ss[], int m){
    for (int i = 1, j = 0; i <= m, j < m; i++, j++){
        if (ss[i])
            printf("%c", y[j]);
    }
    printf("\n");
}
int main(int argc, char const *argv[]){
    char x[] = "010110110101";
    char y[] = "001110110101010";
    printf("X: %s\nY: %s\n\n", x, y);
    int n = strlen(x), m = strlen(y);
    int ss[strlen(y)];
    lcs(x, y, n, m);
    backtrack(n,m,x,y);
    display(n, m, x, y);
    printf("\nLength of the longest common subsequence is: \e[1m%d\e[0m\n", L[n][m]);
    printf("The longest subsequence is: ");
    for (int i = 1; i <= L[n][m]; i++) {
        printf("%c ", sub1[i]);
    }
    return 0;
}