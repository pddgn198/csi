#include <stdio.h>

short map[5000][5000] = {0};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, dir = 0, x = 0, y = -1;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) map[j][k] = 0;
        }
        for (int j = n; j > 0; j--) {
            int k = j;
            while (k--) {
                switch (dir) {
                    case 0: y++; break;
                    case 1: x++; break;
                    case 2: y--; break;
                    case 3: x--; break;
                }
                map[x][y] = 1;
            }
            dir = (dir + 1) % 4;
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) putchar(map[j][k] ? '#' : ' ');
            putchar('\n');
        }
    }
    return 0;
}