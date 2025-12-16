#include<stdio.h>
#include<stdlib.h>

int main(){
    int r1 , c1 , r2 , c2;
    printf("Enter No. of rows and columns of matrix 1: ");
    scanf("%d %d" , &r1 , &c1);
    printf("Enter No. of rows and columns of matrix 2: ");
    scanf("%d %d" , &r2 , &c2);
    if(c1 != r2){
        printf("Not possible");
        return 0;
    }
    int **A = (int **)malloc(sizeof(int *) * r1);
    for(int i = 0 ; i < r1 ; i++){
        A[i] = (int *)malloc(sizeof(int) * c1);
    }
    
    int **B = (int **)malloc(sizeof(int *) * r2);
    for(int i = 0 ; i < r2 ; i++){
        B[i] = (int *)malloc(sizeof(int) * c2);
    }
    
    int **C = (int **)malloc(sizeof(int *) * r1);
    for(int i = 0 ; i < r1 ; i++){
        C[i] = (int *)malloc(sizeof(int) * c2);
    }
    
    for(int i = 0 ; i < r1 ; i++){
        for(int j = 0 ; j < c1 ; j++){
            printf("Enter [%d] [%d] element of matrix 1:\n" , i , j);
            scanf("%d" , &A[i][j]);
        }
    }
    for(int i = 0 ; i < r2 ; i++){
        for(int j = 0 ; j < c2 ; j++){
            printf("Enter [%d] [%d] element of matrix 2:\n" , i , j);
            scanf("%d" , &B[i][j]);
        }
    }
    
    printf("Entered Matrix A = \n");
    for(int i = 0 ; i < r1 ; i++){
        for(int j = 0 ; j < c1 ; j++){
            printf("%d " , A[i][j]);
        }
        printf("\n");
    }
    
    printf("Entered Matrix B = \n");
    for(int i = 0 ; i < r2 ; i++){
        for(int j = 0 ; j < c2 ; j++){
            printf("%d " , B[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0 ; i < r1 ; i++){
        for(int j = 0 ; j < c2 ; j++){
            C[i][j] = 0;
            for(int k = 0 ; k < c1 ; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("Multiplied Matrix =: \n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

}