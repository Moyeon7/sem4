#include<stdio.h>
#include<limits.h>
#define MAX 50
int arr[MAX];
char crr[MAX];
//11 elements
//53 18 43 29 89 17 55 68 79 63 35
//12 elements
//Q M C U A M T F J Y L G 
int Partition(int arr[], int m, int p, int n);
void Select(int arr[], int n, int k);
int Partition_char(char crr[], int m, int p, int n);
void Select_char(char crr[], int n, int k);
int main(){
    int n, k, exit;
    printf("\033[1mInteger\033[0m\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    while(exit!=1){
        printf("\nEnter the value of k: ");
        scanf("%d", &k);
        Select(arr, n, k);
        printf("\nEnter 1 to exit else 2: ");
        scanf("%d", &exit);
    }
    exit=0;
    printf("\n\033[1mCharacter\033[0m\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++){
        scanf(" %c", &crr[i]);
    }
    while(exit!=1){
        printf("\nEnter the value of k: ");
        scanf("%d", &k);
        Select_char(crr, n, k);
        printf("\nEnter 1 to exit else 2: ");
        scanf("%d", &exit);
    }
    return 0;
}
void Select(int arr[], int n, int k){
    int low=0, up=n;
    int j=0;
    do{
        j=Partition(arr, low, up, n);
        printf("\nPass: ");
        for(int i=0; i<n; i++){
            if(i==j)
                printf("\033[1m(%d) \033[0m", arr[i]);
            else
                printf("%d ", arr[i]); 
        }
        printf("\tj=%d", j);
        if(k==j){
            printf("\n\nThe %dth smallest element is %d.\n", k, arr[j-1]);
            return;
        }
        else if(k<j){
            up=j;
        }
        else
            low=j+1;
    }while(1);
}
void Select_char(char crr[], int n, int k){
    int low=0, up=n;
    int j=0;
    do{
        j=Partition_char(crr, low, up, n);
        printf("\nPass: ");
        for(int i=0; i<n; i++){
            if(i==j)
                printf("\033[1m(%c) \033[0m", crr[i]);
            else
                printf("%c ", crr[i]);  
        }
        printf("\tj=%d", j);
        if(k==j){
            printf("\n\nThe %dth smallest element is %c.\n", k, crr[j-1]);
            return;
        }
        else if(k<j){
            up=j;
        }
        else
            low=j+1;
    }while(1);
}
int Partition(int arr[], int m, int p, int n){
    int temp, i, j, v;
    i=m;
    j=p;
    v=arr[m];
    do{
        printf("\nPass: ");
        for(int i=0; i<n; i++){
            if(arr[i]==v)
                printf("\033[1m(%d) \033[0m", arr[i]);
            else
                printf("%d ", arr[i]);
        }
        printf("\tj=%d", j);
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
int Partition_char(char crr[], int m, int p, int n){
    int i, j, v;
    char temp;
    i=m;
    j=p;
    v=crr[m];
    do{
        printf("\nPass: ");
        for(int i=0; i<n; i++){
            if(crr[i]==v)
                printf("\033[1m(%c) \033[0m", crr[i]);
            else
                printf("%c ", crr[i]);
        }
        printf("\tj=%d", j);
        do{
            i++;
        }while(crr[i]<=v && i<j);       
        do{
            j--;
        }while(crr[j]>v);        
        if(i<j){
            temp=crr[i];
            crr[i]=crr[j];
            crr[j]=temp;
        }
    }while(i<=j);
    crr[m]=crr[j];
    crr[j]=v;
    return j;
}