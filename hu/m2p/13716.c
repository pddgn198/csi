#include <stdio.h>
#define LARGE 10000
// #define __DEBUG__

int circuit[20][20];
int n, m, q;
int sx, sy;

#ifdef __DEBUG__
void output() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%2d ", circuit[i][j]);
        }
        puts("");
    }
}
#endif

void input() {
    char tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &tmp);
            circuit[i][j] = tmp == 'X' ? -1 : 0;
            if (tmp == '-') sx = i, sy = j;
        }
    }
}

typedef struct {
    int x, y, step;
} ctx;
ctx queue[1000];
int qend = -1;

void spread(int x, int y, int step) {
    queue[++qend] = (ctx){ x, y, step };
    for (int i = 0; i <= qend; i++) {
        ctx c = queue[i];
        circuit[c.x][c.y] = c.step;
        if (c.x + 1 < n && !circuit[c.x + 1][c.y]) queue[++qend] = (ctx){ c.x + 1, c.y, c.step + 1 };
        if (c.x - 1 >= 0 && !circuit[c.x - 1][c.y]) queue[++qend] = (ctx){ c.x - 1, c.y, c.step + 1 };
        if (c.y + 1 < m && !circuit[c.x][c.y + 1]) queue[++qend] = (ctx){ c.x, c.y + 1, c.step + 1 };
        if (c.y - 1 >= 0 && !circuit[c.x][c.y - 1]) queue[++qend] = (ctx){ c.x, c.y - 1, c.step + 1 };
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    input();
    spread(sx, sy, 1);
    #ifdef __DEBUG__
    output();
    #endif
    int x, y;
    scanf("%d %d", &x, &y);
    int domo = circuit[x][y] - 1;
    printf("%d", domo);
    int mn = LARGE;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &x, &y);
        printf(" %d", circuit[x][y] - 1);
        if (circuit[x][y] - 1 < mn) mn = circuit[x][y] - 1;
    }
    printf("\n%d\n", mn - domo);
    return 0;
}