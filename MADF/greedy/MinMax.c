#include<stdio.h>
#define MAX 50
int arr[MAX];
void MaxMin(int i, int j, int *max, int *min);
//73 83 23 -56 43 -11 85 -18 73
int main(){
    int min, max, n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    MaxMin(0,n-1, &max, &min);
    printf("\n\nMax=%d Min=%d\n", max, min);
    return 0;
}
void MaxMin(int i, int j, int *max, int *min){
    int max1, min1;
    if(i==j)
        *max=*min=arr[i];
    else if(i==j-1){
        if(arr[i]>arr[j]){
            *max=arr[i];
            *min=arr[j];
            printf("\n");
        }
        else{
            *max=arr[j];
            *min=arr[i];
        }
    }
    else{
        int mid=(i+j)/2;    
        MaxMin(i, mid, max, min);
        MaxMin(mid+1, j, &max1, &min1);
        if(*max<max1)
            *max=max1;
        if(*min>min1)
            *min=min1;
    }
    printf("\nPass:i=%d, j=%d MAX=%d     MIN=%d",i, j, *max , *min);
}