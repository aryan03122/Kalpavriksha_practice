#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

void leftRotate(int *arr, int n, int k) {
    k = k % n;  

    reverse(arr, 0, k - 1);   
    reverse(arr, k, n - 1);      
    reverse(arr, 0, n - 1);     
}

void rightRotate(int *arr, int n, int k) {
    k = k % n;   
    leftRotate(arr, n, n - k);
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    // Left Rotation
    leftRotate(arr, n, k);
    printf("Left Rotated Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Right Rotation
    rightRotate(arr, n, k);
    printf("\nRight Rotated Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
