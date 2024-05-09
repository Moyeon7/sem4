#include <stdio.h>
#include <string.h>
#define N 256
int f[N];
int cmp[N]={0};
int change[N] = {};
int comparisons=0;
int failure(char p[N], int m){
    int i = 1, j = 0;
    f[0] = 0;
    while (i < m){
        if (p[j] == p[i]){
            f[i] = j + 1;
            i++, j++;
        }
        else if (j > 0)
            j = f[j - 1];
        else
            f[i] = 0, i++;
    }
}
void display(int i, int j, int m, char p[], int flag){
        for(int k=1; k<=i-j; k++)
        printf("   |"); 
        for(int i=0; i<m; i++){
            printf(" %c |", p[i]);
        }
        if(flag==1)
            printf("\t\e[1mi=%d\tj=%d\e[0m", i,j+m);
        else
            printf("\t\e[1mi=%d\tj=%d\e[0m", i,j);
        printf("\n");

        for(int k=1; k<=i-j; k++)
            printf("   |"); 
        for(int l=0;l<m;l++){
            if(change[l] == 1)printf("%2d |",cmp[l]);
            else printf("   |");
        }printf("\n");

}
void kmp(char t[N], char p[N], int n, int m){
    for(int i=0; i<n; i++){
        if(i>8)
            printf("\e[1m %d \e[0m", i);
        else
            printf("\e[1m %d  \e[0m", i);
    }
    printf("\n");
    for(int i=0; i<n; i++)
        printf(" %c |", t[i]);
    printf("\n");
    failure(p, m);
    int i, j;
    i = j = 0;
    int flag=0;
    int o;
    while (i < n){
        if (p[j] == t[i]){
            cmp[j] = ++comparisons; change[j] = 1; 
            if (j == m - 1){
                flag=1;
                display(i-m+1,j-4,m,p,flag);
                printf("Pattern %c found at index %d\n", p, i - m + 1);
                return;
            }
            else{
                i++, j++;
            }
        }
        else if (j > 0){
            cmp[j] = ++comparisons;
            change[j] = 1;
            
            display(i,j,m,p,flag);

            for(int i=0;i<m;i++) change[i] = 0;
            j = f[j - 1];
        }     
        else{
            cmp[j] = ++comparisons;
            change[j] = 1; 
            
            display(i,j,m,p,flag);
            for(int i=0;i<m;i++) change[i] = 0;
            i++;
            flag=0;
        }       
    }
    printf("substring %s is not present in string %s\n", p, t);
    return;
}
int main(int argc, char const *argv[]){
    char t[] = {'a','a','b','b','b','a','a','b','a','b','b','b','a','b','b','a','b','a','b'};
    char p[] = {'b','b','a','b','a'};
    kmp(t, p, 19, 5);
    printf("The no. of comparisons are \e[1m%d\e[0m", comparisons);
    return 0;
}