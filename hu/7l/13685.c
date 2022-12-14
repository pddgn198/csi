#include <stdio.h>

int n, m;
char map[20][20];
int ans = 1;

// void _print() {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             putchar(map[i][j] ? 'o' : 'x');
//         }
//         putchar('\n');
//     }
//     putchar('\n');
// }

void change(int x, int y) {
    map[x][y] ^= 1;
    if (x > 0) map[x - 1][y] ^= 1;
    if (y > 0) map[x][y - 1] ^= 1;
    if (x < n - 1) map[x + 1][y] ^= 1;
    if (y < m - 1) map[x][y + 1] ^= 1;
}

int check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]) return 0;
        }
    }
    return 1;
}

int walk(int depth, int lx, int ly) {
    if (depth) change(lx, ly);
    // printf("depth %d : %d , %d\n", depth, lx, ly);
    // _print();
    if (depth == ans) {
        if (check()) return 1;
    } else {
        int i = lx, j = ly + 1;
        for (; j < m; j++) {
            if (walk(depth + 1, i, j)) return 1;
        }
        for (i++; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (walk(depth + 1, i, j)) return 1;
            }
        }
    }
    if (depth) change(lx, ly);
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char tmp;
            scanf(" %c", &tmp);
            map[i][j] = (tmp == 'o') ? 1 : 0;
        }
    }
    while (!walk(0, 0, -1)) {
        ans++;
        if (ans >= n * m) break;
    }
    if (ans >= n * m)
        puts("no solution");
    else
        printf("%d\n", ans);

    return 0;
}