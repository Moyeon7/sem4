#include <stdio.h>
#include <string.h>
#define N 256
int f[N];
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
    while (i < n){
        comparisons++;
        for(int i=0; i<m; i++){
            printf(" %c |", p[i]);
        }
        printf("\t\e[1mi=%d\tj=%d\e[0m", i,j);
        printf("\n");

        if (p[j] == t[i]){
            if (j == m - 1){
                printf("Pattern %c found at index %d\n", p, i - m + 1);
                return;
            }
            else{
                i++, j++;
            }
        }
        else if (j > 0){
            j = f[j - 1];
        }     
        else{
            i++;
        }
        if(i<=n)  
            for(int k=1; k<=i; k++)
                printf("   |");      
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