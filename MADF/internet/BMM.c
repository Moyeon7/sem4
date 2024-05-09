#include <stdio.h>
#include <string.h>
#define charnum 256
int lc[charnum]; 
int store;
int comparisons=0;
int min(int a, int b){
    return a < b ? a : b;
}
void last(int p[charnum], int m){
    for (int i = 0; i < charnum; i++)
        lc[i] = -1;
    for (int i = 0; i < m; i++)
        lc[(int)p[i]] = i;
}
void bm(int t[], int p[], int n, int m){
    int count=0;
    for(int i=0; i<n; i++){
        if(i>8)
            printf("\e[1m %d \e[0m", i);
        else
            printf("\e[1m %d  \e[0m", i);
    } 
    printf("\n");
    for(int i=0; i<n; i++)
        printf(" %d |", t[i]);
    printf("\n");
    last(p, m);
    int i, j;
    i = m - 1;
    j = m - 1;
    do{
        comparisons++;
        for(int k=0; k<=i-m+count; k++)
            printf("   |");
        for(int l=0; l<m; l++)
            printf(" %d |", p[l]);
        printf("\t\e[1mi=%d\tj=%d\tl=%d\e[0m\n", i,j,lc[(int)t[i]]);
        for(int k=0; k<i; k++)
            printf("    ");
        printf("%d\n", comparisons);

        if (p[j] == t[i]){    
            if (!j){
                printf("\e[1mPattern %d found at index %d in %d\e[0m\n", p[j], i, t[i]);
                return;
            }
            else{
                count++;
                i -= 1, j -= 1;
            }
        }
        else{
            count=0; 
            i = i + m - min(j, 1 + lc[(int)t[i]]);
            j = m - 1;   
        }       
    } while (i <= n-1);
    printf("\n\e[1mNo substring\e[0m\n");
}
int main(int argc, char const *argv[]){
    int t[] = {2,1,3,2,3,1,3,4,2,1,3,4,5,3,4,5,6,1};
    int p[] = {1,3,4,5,6};
    bm(t, p, 18, 5);
    printf("The no. of comparisons are \e[1m%d\e[0m", comparisons);
    return 0;
}