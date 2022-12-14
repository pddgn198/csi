#include <stdio.h>

int main() {
    int n, m, q;
    scanf("%d%d", &n, &m);
    char map[n][m];
    for (int i = 0; i < n; i++) scanf("%s", map[i]);
    scanf("%d", &q);
    while (q--) {
        int x, y = 0, suc = 0, dir = 0; // dir: 0-downward 1-leftward 2-rightward
        scanf("%d", &x), x--;
        while (y < n && x >= 0 && x < m) {
            if (map[y][x] == '/') {
                switch (dir) {
                case 0: x--, dir = 1; break;
                case 1: y++, dir = 0; break;
                case 2: printf("Stuck QQ\n"), suc = -1; break;
                }
            } else {
                switch (dir) {
                case 0: x++, dir = 2; break;
                case 1: printf("Stuck QQ\n"), suc = -1; break;
                case 2: y++, dir = 0; break;
                }
            }
            if (suc == -1) break;
        }
        if (y >= n) printf("Position: %d\n", x + 1);
        else if (x < 0) printf("Left!\n");
        else if (x >= m) printf("Right!\n");
    }
    return 0;
}