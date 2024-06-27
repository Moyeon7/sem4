#include<stdio.h>
#define MAX 50
int arr[MAX];
void quick(int low, int up, int n);
int partition(int m, int p, int n);
int main(){
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Pass: ");
    for(int i=0; i<n; i++){
        if(i==0)
            printf("\033[1m(%d) \033[0m", arr[i]);
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
    quick(0, n-1, n);
    printf("\nThe sorted array is: ");

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
void quick(int low, int up, int n){
    int pivloc;
    if(low<up){
        pivloc=partition(low, up, n);
        printf("\nPass: ");
        for(int i=0; i<n; i++){
            if(i==pivloc)
                printf("\033[1m(%d) \033[0m", arr[i]);
            else
                printf("%d ", arr[i]);
        }
        printf("\n");
        quick(low, pivloc-1, n);
        quick(pivloc+1, up, n);
    }
}
int partition(int m, int p, int n){
    int temp, i, j, v;
    i=m;
    j=p+1;
    v=arr[m];
    do{
        do{
            i++;
        }while(arr[i]<=v && i<j);
            
        do{
            j--;
        }while(arr[j]>v) ;
            
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<=j);

    arr[m]=arr[j];
    arr[j]=v;
    return j;
}