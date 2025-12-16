#include <stdio.h>
#include <stdlib.h>


int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {


    if (matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;          
    int cols = *matrixColSize;      

    
    *returnSize = rows * cols;
    int *result = (int *)malloc(sizeof(int) * (*returnSize));

    int index = 0;                 

  
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

  
    while (top <= bottom && left <= right) {

       
        for (int col = left; col <= right; col++) {
            result[index++] = matrix[top][col];
        }
        top++; 

        
        for (int row = top; row <= bottom; row++) {
            result[index++] = matrix[row][right];
        }
        right--;  

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                result[index++] = matrix[bottom][col];
            }
            bottom--;  
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                result[index++] = matrix[row][left];
            }
            left++; 
        }
    }

    return result;
}
