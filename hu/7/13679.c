#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

lli prop(int **map, int *vmk, int *dm1, int *dm2, int x, int n) {
    if (x < 0) return LLONG_MIN;
    lli mxm = LLONG_MIN, tmp;
    for (int i = 0; i < n; i++) {
        if (vmk[i] || dm1[x + i] || dm2[n - x + i]) continue;
        vmk[i] = 1, dm1[x + i] = 1, dm2[n - x + i] = 1;
        tmp = x ? prop(map, vmk, dm1, dm2, x - 1, n) : 0;
        if (tmp > LLONG_MIN) tmp += map[x][i], mxm = (tmp > mxm) ? tmp : mxm;
        vmk[i] = 0, dm1[x + i] = 0, dm2[n - x + i] = 0;
    }
    return mxm;
}

int main() {
    int n;
    scanf("%d", &n);
    int **map = calloc(n, sizeof(int *));
    int *vmk = calloc(n, sizeof(int));
    int *dm1 = calloc(2 * n + 1, sizeof(int));
    int *dm2 = calloc(2 * n + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        map[i] = calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);
    }
    lli r = prop(map, vmk, dm1, dm2, n - 1, n);
    if (r != LLONG_MIN)
        printf("%lld\n", r);
    else
        puts("no solution");
    for (int i = 0; i < n; i++) free(map[i]);
    free(map);
    free(vmk);
    free(dm1);
    free(dm2);
    return 0;
}