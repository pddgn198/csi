#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    if (n % 2 == 0) return printf("Stop drawing fake diamonds!\n"), 0;
    for (i = 0; i <= n / 2; i++) {
        for (j = 0; j < (n / 2) - i; j++) printf(" ");
        for (j = 0; j < 2 * i + 1; j++) printf("*");
        printf("\n");
    }
    for (; i < n; i++) {
        for (j = 0; j < i - n / 2; j++) printf(" ");
        for (j = 0; j < 2 * (n - i) - 1; j++) printf("*");
        printf("\n");
    }
    return 0;
}