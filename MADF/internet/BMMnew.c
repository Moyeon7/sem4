#include <stdio.h>
#include <string.h>
#define charnum 256
int cmp[charnum]={0};
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
void display(int i, int j, int m, int count, int flag, int p[], int t[], int g){
    for(int k=0; k<=i-m+count; k++)
        printf("   |");
    for(int l=0; l<m; l++)
        printf(" %d |", p[l]);
    if(flag==0)
        printf("\t\e[1mi=%d\tj=%d\tl=%d\e[0m\n", i,j,lc[(int)t[i]]);
    if(flag==1)
        printf("\t\e[1mi=%d\tj=%d\tl=%d\e[0m\n", g,j,lc[(int)t[g]]);
    for(int k=0; k<=i-m+count; k++)
        printf("   |");
    for(int i = 0; i < m; i++) {
        if(i>=j) printf("%2d |",cmp[i]);
        else printf("   |");
    }printf("\n");
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
    int flag=0;
    int o;
    do{
        if (p[j] == t[i]){
            if(flag==0){
                o=i;
            }flag=1;
            cmp[j]=++comparisons;  
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
            int g=i;
            if(flag==1){
                i=o-1;
            }
            cmp[j]=++comparisons;
            count=0; 
            display(i,j,m,count,flag,p,t,g);
            i=g;
            i = i + m - min(j, 1 + lc[(int)t[i]]);
            j = m - 1;   
            flag=0;
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