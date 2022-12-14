#include <stdio.h>
#define QMAX 2000000
// #define __DEBUG__

typedef struct {
    int x, y;
} pos;

int n, m;
char map[1000][1000];

#ifdef __DEBUG__
void output() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
#endif

pos queue[QMAX];
int qend = -1;

pos off[4] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int solve() {
    if (map[n - 1][m - 1] == '#') return 0;
    qend = -1;
    queue[++qend] = (pos){ 0, 0 };
    for (int _ = 0; _ <= qend; _++) {
        pos c = queue[_];
        if (map[c.x][c.y] == '#') continue;
        // output();
        if (c.x == n - 1 && c.y == m - 1) return 1;

        for (int i = 0; i < 4; i++) {
            int x = c.x + off[i].x, y = c.y + off[i].y;
            if (x >= 0 && x < n && y >= 0 && y < m && map[x][y] != '#')
                queue[++qend] = (pos){ x, y };
        }
        if (map[c.x][c.y] == 'T') {
            map[c.x][c.y] = '#';
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 'T') {
                        map[i][j] = '*';
                        queue[++qend] = (pos){ i, j };
                    }
                }
            }
        }
        map[c.x][c.y] = '#';
    }
    return 0;
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &map[i][j]);
            }
        }
        puts(solve() ? "Yes" : "No");
    }
    return 0;
}