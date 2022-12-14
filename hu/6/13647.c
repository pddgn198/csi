#include <stdio.h>

int main() {
    int g0, g1, n, tmp;
    scanf("%d %d %d", &g0, &g1, &n);
    if (n == 0) printf("%d\n", g0);
    else if (n == 1) printf("%d\n", g1);
    else {
        n--;
        while (n--) {
            tmp = g0 - g1;
            g0 = g1;
            g1 = tmp;
        }
        printf("%d\n", g1);
    }
    return 0;
}