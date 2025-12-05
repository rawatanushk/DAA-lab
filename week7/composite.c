#include <stdio.h>
#include <stdbool.h>

bool areCoprime(int a, int b) {
    int min = (a < b) ? a : b;
    for (int i = 2; i <= min; i++) {
        if (a % i == 0 && b % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num1, num2;

    printf("Enter 1st number:");
    scanf("%d", &num1 );
    printf("Enter 2nd number:");
    scanf("%d", &num2 );

    if (areCoprime(num1, num2)) {
        printf("%d and %d are coprime.\n", num1, num2);
    } else {
        printf("%d and %d are not coprime.\n", num1, num2);
    }

    return 0;
}
