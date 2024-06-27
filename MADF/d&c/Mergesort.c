#include<stdio.h>
#define MAX 50
int arr_i[MAX]; int brr_i[MAX]; int tmp_i[MAX];
char arr_c[MAX];    char brr_c[MAX];    char tmp_c[MAX];
void merge_i(int low, int mid, int high, int n);
void mergesort_i(int low, int high, int n);
void display_i(int low, int high, int n);
int check_i(int s, int n);
void merge_c(int low, int mid, int high, int n);
void mergesort_c(int low, int high, int n);
void display_c(int low, int high, int n);
int check_c(char s, int n);
int main(){
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    for(int s=0; s<n; s++){
        tmp_i[s]=-1;
    }
    for (int s = 0; s < n; s++) {
        tmp_c[s] = '.';
    }
    printf("\nEnter the elements for integer array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr_i[i]);
    }
    printf("\n");
    mergesort_i(0,n-1,n);
    printf("\nThe sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr_i[i]);
    }
    printf("\n\nEnter the elements for character Array: ");
    for(int i=0; i<n; i++){
        scanf(" %c", &arr_c[i]);
    }
    printf("\n");
    mergesort_c(0,n-1,n);
    printf("\nThe sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%c ", arr_c[i]);
    }
    return 0;
}
int check_i(int s, int n){
    for(int i=0; i<n; i++){
        if(s==tmp_i[i])
            return 1;
    }
    return 0;
}
int check_c(char s, int n){
    for(int i=0; i<n; i++){
        if(s==tmp_c[i])
            return 1;
    }
    return 0;
}
void display_c(int low, int high, int n){
    for(int x=0; x<n; x++){
        printf("%c", arr_c[x]);
        if(check_c(arr_c[x], n))
            printf("|");
        else if(x!=n-1)
            printf(",");
    }
    printf("\n");
}
void display_i(int low, int high, int n){
    for(int x=0; x<n; x++){
        printf("%d", arr_i[x]);
        if(check_i(x, n))
            printf("|");
        else if(x!=n-1)
            printf(",");
    }
    printf("\n");
}
void mergesort_c(int low, int high, int n){
    if(low<high){
        int mid=(low+high)/2;
        tmp_c[mid]=arr_c[mid];
        display_c(low, high, n);
        mergesort_c(low, mid, n);
        mergesort_c(mid+1, high, n);
        merge_c(low, mid, high, n);
    }
}
void mergesort_i(int low, int high, int n){
    if(low<high){
        int mid=(low+high)/2;
        tmp_i[mid]=mid;
        display_i(low, high, n);
        mergesort_i(low, mid, n);
        mergesort_i(mid+1, high, n);
        merge_i(low, mid, high, n);
    }
}
void merge_i(int low, int mid, int high, int n){
    int h=low, j=mid+1, i=low;
    while((h<=mid) && (j<=high)){
        if(arr_i[h]>=arr_i[j]){
            brr_i[i]=arr_i[h];
            h++;
        }
        else{
            brr_i[i]=arr_i[j];
            j++;
        }
        i++;
    }
    if(h>mid){
        for(int k=j; k<=high; k++){
            brr_i[i]=arr_i[k];
            i++;
        }
    } 
    else{
        for(int k=h; k<=mid; k++){
            brr_i[i]=arr_i[k];
            i++;
        }
    }
    for(int k=low; k<=high; k++){
        arr_i[k]=brr_i[k];
    }
    tmp_i[mid]=-1;
    display_i(low, high, n);
}
void merge_c(int low, int mid, int high, int n){
    int h=low, j=mid+1, i=low;
    while((h<=mid) && (j<=high)){
        if(arr_c[h]<=arr_c[j]){
            brr_c[i]=arr_c[h];
            h++;
        }
        else{
            brr_c[i]=arr_c[j];
            j++;
        }
        i++;
    }
    if(h>mid){
        for(int k=j; k<=high; k++){
            brr_c[i]=arr_c[k];
            i++;
        }
    } 
    else{
        for(int k=h; k<=mid; k++){
            brr_c[i]=arr_c[k];
            i++;
        }
    }
    for(int k=low; k<=high; k++){
        arr_c[k]=brr_c[k];
    }
    tmp_c[mid]='.';
    display_c(low, high, n);
}