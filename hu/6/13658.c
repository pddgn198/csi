#include <stdio.h>
#include <unistd.h>

#define min(a, b) ((a < b) ? a : b)

int m, n;
char map[1005][1005], mark[1005][1005];

void printMap(int x, int y) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            putchar(mark[i][j] ? '*' : (i == x && j == y) ? 'V'
                                                          : map[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

int step(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return 0;
    if (map[x][y] == '^' || map[x][y] == 'o' || mark[x][y]) return 0;
    if (map[x][y] == 'M') return 1;
    printMap(x, y);
    sleep(1);
    int mn = 1000000007, tmp, flag = 0;

    mark[x][y] = 1;
    tmp = step(x - 1, y);
    if (tmp) mn = min(mn, tmp), flag = 1;

    tmp = step(x, y - 1);
    if (tmp) mn = min(mn, tmp), flag = 1;

    tmp = step(x + 1, y);
    if (tmp) mn = min(mn, tmp), flag = 1;

    tmp = step(x, y + 1);
    if (tmp) mn = min(mn, tmp), flag = 1;

    mark[x][y] = 0;
    return flag ? mn + 1 : 0;
}

int main() {
    scanf("%d %d", &m, &n);
    int sx, sy;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &map[i][j]);
            mark[m][n] = 0;
            if (map[i][j] == 'S') sx = i, sy = j;
        }
    }
    printf("%d\n", step(sx, sy) - 1);
    return 0;
}