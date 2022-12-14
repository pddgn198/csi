#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = n; i >= 1; i--) {
        int j = 1;
        for (; j < n; j++) {
            if (j >= i) printf("%d", j - i + 1);
            else printf(" ");
        }for (; j >= i; j--) {
            printf("%d", j - i + 1);
        }
        printf("\n");
    }

    return 0;
}