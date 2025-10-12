#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    printf("Enter the no. of rows and no. of columns for 1st matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the no. of rows and no. of columns for 2nd matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible\n");
        return 1;
    }

    int A[r1][c1], B[r2][c2], C[r1][c2];
    int addCount = 0, mulCount = 0;

    printf("Enter elements for 1st matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements for 2nd matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
        }
    }

    // Matrix multiplication and counting operations
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                mulCount++;
                C[i][j] += A[i][k] * B[k][j];
                if (k > 0) { 
                    addCount++;
                }
            }
        }
    }

    printf("The resultant matrix is:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("Number of multiplications performed: %d\n", mulCount);
    printf("Number of additions performed: %d\n", addCount);

    return 0;
}
