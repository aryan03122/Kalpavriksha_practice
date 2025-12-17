#include <stdio.h>
#include <stdlib.h>

int main() {
    int **mat;
    float **inv;
    int det;
    mat = (int **)malloc(2 * sizeof(int *));
    inv = (float **)malloc(2 * sizeof(float *));

    for (int i = 0; i < 2; i++) {
        mat[i] = (int *)malloc(2 * sizeof(int));
        inv[i] = (float *)malloc(2 * sizeof(float));
    }
    printf("Enter 2x2 matrix elements:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    if (det == 0) {
        printf("Inverse does not exist (determinant = 0)\n");
    } else {
        inv[0][0] =  mat[1][1] / (float)det;
        inv[0][1] = -mat[0][1] / (float)det;
        inv[1][0] = -mat[1][0] / (float)det;
        inv[1][1] =  mat[0][0] / (float)det;

        printf("Inverse matrix:\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                printf("%0.2f ", inv[i][j]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < 2; i++) {
        free(mat[i]);
        free(inv[i]);
    }
    free(mat);
    free(inv);

    return 0;
}
