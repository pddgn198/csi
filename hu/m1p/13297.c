#include <stdio.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n][m], b[m][n], r[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &b[i][j]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = 0;
            for (int k = 0; k < m; k++) r[i][j] += a[i][k] * b[k][j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", r[0][i]);
        for (int j = 1; j < n; j++) printf(" %d", r[j][i]);
        putchar('\n');
    }
    return 0;
}