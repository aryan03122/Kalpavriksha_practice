#include <stdio.h>
#include <stdlib.h>

void transpose(int **arr ,int **mat , int rows , int cols){
    for(int i = 0 ; i < cols ; i++){
        for(int j = 0 ; j < rows ; j++){
            arr[i][j] = mat[j][i];
        }
    }
}

void transposeSquare(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void swap(int *x , int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverseArr(int *arr , int start , int end){
    while(start < end){
        swap(&arr[start] , &arr[end]);
        start++;
        end--;
    }
}

void reverseColumn(int **mat, int col, int n) {
    int top = 0;
    int bottom = n - 1;

    while (top < bottom) {
        swap(&mat[top][col], &mat[bottom][col]);
        top++;
        bottom--;
    }
}

void rotate90anticlock(int **mat, int n) {

    transposeSquare(mat, n);


    for (int j = 0; j < n; j++) {
        reverseColumn(mat, j, n);
    }
}

void rotate90(int **mat , int n){

    transposeSquare(mat, n);
    
    for(int i = 0 ; i < n ; i++){
        reverseArr(mat[i], 0, n - 1);
    }
}


void printarray(int **arr , int rows , int cols){
    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]); 
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);
       
    int **mat = (int **)malloc(sizeof(int *) * rows);
    if (mat == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for(int i = 0 ; i < rows ; i++){
        mat[i] = (int *)malloc(sizeof(int) * cols);
        if (mat[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);   
        }
    }
    
    printf("Matrix is:\n");
    printarray(mat , rows , cols);
    
    int **arr = (int **)malloc(sizeof(int *) * cols);
    for(int i = 0 ; i < cols ; i++){
        arr[i] = (int *)malloc(sizeof(int) * rows);
    }
    
    transpose(arr , mat , rows , cols);
    
    printf("Transpose Matrix is:\n");
    printarray(arr , cols , rows);
    
    rotate90(mat , rows);
    printf("Rotated Matrix is:\n");
    printarray(mat , cols , rows);
    for(int i = 0 ; i < rows ; i++){
        free(mat[i]);
    }
    free(mat);
    return 0;
}