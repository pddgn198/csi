#include <stdio.h>
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

int main() {
    int n, l;
    scanf("%d%d", &n, &l);
    int a[n], found = 0;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i <= n - l; i++) {
        int flag = 1;
        int basis = max(a[i], a[i + l - 1]);
        for (int j = i + 1; j < i + l - 1 ; j++) if (a[j] <= basis) flag = 0;
        if (flag) {
            found++;
            printf("%d", a[i]);
            for (int j = i + 1; j < i + l; j++) printf(" %d", a[j]);
            putchar('\n');
        }
    }
    if (!found) printf("Domo\n");
    return 0;
}