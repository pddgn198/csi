#include <stdio.h>

int i2b[10] = { 0b0, 0b1, 0b10, 0b100, 0b1000,
                0b10000, 0b100000, 0b1000000, 0b10000000, 0b100000000 };

// #include <unistd.h>
// #define m(i, r) ((i & r) ? 1 : 0)
// void pb(int n) {
//     for (int i = 1; i <= 9; i++) putchar(m(n, i2b[i]) ? '0' + i : '.');
// }

int board[9][9] = { 0 };
int r[9] = { 0 }, c[9] = { 0 }, g[9] = { 0 };
int unsolved = 81;

int psb(int i, int j) {
    return c[i] | r[j] | g[(i / 3) * 3 + (j / 3)];
}

int findSetBit(int f) {
    int r = 0;
    while (f) f >>= 1, r++;
    return r;
}

void propagate(int x, int y, int n) {
    board[x][y] = n;
    unsolved--;
    c[x] |= i2b[n];
    r[y] |= i2b[n];
    g[(x / 3) * 3 + (y / 3)] |= i2b[n];
}

void unpropagate(int x, int y, int n) {
    board[x][y] = 0;
    unsolved++;
    c[x] &= ~i2b[n];
    r[y] &= ~i2b[n];
    g[(x / 3) * 3 + (y / 3)] &= ~i2b[n];
}

int backtrack(int x, int y) {
    while (board[x][y]) {
        y++;
        if (y >= 9) y = 0, x++;
        if (x >= 9) break;
    }
    if (unsolved <= 0) return 1;
    if (psb(x, y) == 0b111111111) return 0;
    for (int i = 1; i <= 9; i++) {
        if (!(i2b[i] & psb(x, y))) {
            propagate(x, y, i);
            if (backtrack(x, y))
                return 1;
            else
                unpropagate(x, y, i);
        }
    }
    return 0;
}

int main() {
    int tmp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &tmp);
            if (tmp) propagate(i, j, tmp);
        }
    }

    if (backtrack(0, 0)) {
        for (int i = 0; i < 9; i++) {
            putchar(board[i][0] + '0');
            for (int j = 1; j < 9; j++) {
                putchar(' ');
                putchar(board[i][j] + '0');
            }
            putchar('\n');
        }
    } else
        puts("no solution");
    return 0;
}