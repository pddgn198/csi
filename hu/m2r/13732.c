#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int *a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    long long int r = 0;
    for (int i = 0; i < k; i++) {
        r += a[i];
    }
    printf("%lld\n", r);
    return 0;
}