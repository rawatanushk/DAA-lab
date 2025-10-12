#include <stdio.h>

void rotate(int matrix[][100], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}


void printMatrix(int matrix[][100], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[100][100];
    int n, i, j;

    printf("Enter size of the matrix (n): ");
    scanf("%d", &n);

    printf("Enter the matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    rotate(matrix, n);

    printf("Rotated matrix:\n");
    printMatrix(matrix, n);

    return 0;
}

