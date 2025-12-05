#include <stdio.h>
#include <stdlib.h>

int celebrity(int **mat, int n) {
    int *indegree = (int *)calloc(n, sizeof(int));
    int *outdegree = (int *)calloc(n, sizeof(int));

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = mat[i][j];
            outdegree[i] += x;
            indegree[j] += x;
        }
    }

   
    for (int i = 0; i < n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) {
            free(indegree);
            free(outdegree);
            return i;
        }
    }

    free(indegree);
    free(outdegree);
    return -1;
}

int main() {
    int n;

    printf("Enter number of people: ");
    scanf("%d", &n);

  
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the matrix (row-wise, 0 or 1):\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int celeb = celebrity(mat, n);

    if (celeb == -1)
        printf("No celebrity found.\n");
    else
        printf("Celebrity is person %d.\n", celeb);


    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
