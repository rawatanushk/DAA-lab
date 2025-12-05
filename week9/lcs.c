#include <stdio.h>
#include <string.h>
#include <stddef.h>  // Include this for size_t

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char X[1000], Y[1000];
    
    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int dp[m+1][n+1];

    // Build the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Length of LCS
    int length = dp[m][n];
    printf("\nLCS Length: %d\n", length);

    // Reconstruct LCS string
    char lcs[length + 1];
    lcs[length] = '\0'; // null terminate

    int i = m, j = n, index = length - 1;

    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs);

    return 0;
}
