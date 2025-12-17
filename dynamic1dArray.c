#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d" , &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    if(arr ==  NULL){
        printf("Memory Allocation failed");
        return 0;
    }
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &arr[i]);
    }
    
    for(int i = 0 ; i < n ; i++){
        printf("%d " , arr[i]);
    }
    
    int pos, val;
    printf("\nEnter position to insert: ");
    scanf("%d", &pos);

    printf("\nEnter value to insert: ");
    scanf("%d", &val);
    
    arr = (int *)realloc(arr , (n+1) * sizeof(int));
    for(int i = n ; i > pos ; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
    
    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    int delPos;
    printf("Enter Position to delete: ");
    scanf("%d" , &delPos);
    for(int i = delPos ; i < n-1 ; i++){
        arr[i] = arr[i+1];
    }
    n--;
    arr = (int *)realloc(arr , n * sizeof(int));
    
    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    int start = 0;
    int end = n-1;
    
    while(start < end){
        int temp =  arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    
    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    
    free(arr);
    return 0;
}