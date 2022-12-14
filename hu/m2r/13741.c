#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i, j;
} pos;

pos ax, bx;

char **input(int n, int m, pos *xp) {
    char **map = malloc(sizeof(char *) * n);
    char *mmap = malloc(sizeof(char) * m * n);
    for (int i = 0; i < n; i++) {
        map[i] = mmap + i * m;
        for (int j = 0; j < m; j++) {
            scanf(" %c", &map[i][j]);
            if (map[i][j] == 'x') xp->i = i, xp->j = j;
        }
    }
    return map;
}   

int checkSame(char **a, char **b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) return 0;
        }
    }
    return 1;
}

void swapA(char **a, int offi, int offj) {
    char tmp = a[ax.i][ax.j];
    a[ax.i][ax.j] = a[ax.i + offi][ax.j + offj];
    a[ax.i + offi][ax.j + offj] = tmp;
    ax.i += offi;
    ax.j += offj;
    return;
}

int _solve(char **a, char **b, int n, int m, int k) {
    if (k == 0) return checkSame(a, b, n, m);
    int r = 0;
    if (ax.i < n - 1 && ax.j < m - 1) {
        swapA(a, 1, 1);
        r += _solve(a, b, n, m, k - 1);
        swapA(a, -1, -1);
    }
    if (ax.i < n - 1 && ax.j > 0) {
        swapA(a, 1, -1);
        r += _solve(a, b, n, m, k - 1);
        swapA(a, -1, 1);
    }
    if (ax.i > 0 && ax.j < m - 1) {
        swapA(a, -1, 1);
        r += _solve(a, b, n, m, k - 1);
        swapA(a, 1, -1);
    }
    if (ax.i > 0 && ax.j > 0) {
        swapA(a, -1, -1);
        r += _solve(a, b, n, m, k - 1);
        swapA(a, 1, 1);
    }
    return r;
}

int solve(char **a, char **b, int n, int m, int k) {
    int parity = (bx.i + bx.j) & 1;
    if (parity != ((ax.i + ax.j) & 1)) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (((i + j) & 1) != parity && a[i][j] != b[i][j]) return 0;
        }
    }
    return _solve(a, b, n, m, k);
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    char **a = input(n, m, &ax);
    char **b = input(n, m, &bx);

    printf("%d\n", solve(a, b, n, m, k));

    free(*a);
    free(a);
    free(*b);
    free(b);

    return 0;
}