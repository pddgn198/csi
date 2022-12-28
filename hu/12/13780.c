#include <stdio.h>

short value[1001];
short neighbors[1001][1001];

int traverse(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (neighbors[k][i]) {
            neighbors[i][k] = neighbors[k][i] = 0;
            value[k] += traverse(i, n);
        }
    }
    return value[k];
}

int main() {
    int n, x, d;
    scanf("%d %d %d", &n, &x, &d);
    for (int i = 1; i <= n; i++) scanf("%hd", &value[i]);
    int a, b;
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        neighbors[a][b] = 1;
        neighbors[b][a] = 1;
    }
    traverse(1, n);
    int rmin = x - d, rmax = x + d, found = 0;
    for (int i = 1; i <= n; i++) {
        if (rmin < value[i] && value[i] < rmax) {
            if (found) printf(" ");
            found = 1;
            printf("%hd", i);
        }
    }
    puts("");
    return 0;
}