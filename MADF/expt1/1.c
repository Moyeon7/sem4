//A D H M O R T U V W
// 10
#include<stdio.h>
#define MAX 50
char arr[MAX];

int Binsrch(char arr[], int i, int l, char x);

int main(){
    int n, exit;
    char element;
    
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    getchar();
    printf("\nEnter the elements: ");
    
    for(int i=0; i<n; i++){
        scanf(" %c", &arr[i]);
    }
    while(exit!=1){    
        printf("\nEnter the element to be searched: ");
        scanf(" %c", &element);

        printf("\nlow\t\thigh\t\tmid\n");
        int e=Binsrch(arr, 0, n-1, element);

        if(e==-1){
            printf("\nElement %c not found.\n", element);
        }else{
            printf("\nElement %c found at position %d.\n", element, e+1);
        }
        printf("\nEnter 1 to exit else 2: ");
        scanf("%d", &exit);
    }
    return 0;
}

int Binsrch(char arr[], int i, int l, char x){
    int mid;
    
    if(l==i){
        if(x==arr[i]){
            return i;
        }        
        else    
            return -1;
    }
    else{
        mid=(l+i)/2;
        printf("%d\t\t%d\t\t%d\n", i, l, mid);
        if(x==arr[mid])
            return mid;
        else if(x<arr[mid])
            return Binsrch(arr, i, mid-1, x);
        else 
            return Binsrch(arr, mid+1, l, x);
    }
    
}