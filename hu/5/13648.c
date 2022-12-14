#include <stdio.h>

/*
test case 5: findTarget outflow
test case 3: no different in x, y swap

*/

int mode = 0, n; // mode 0: smallest
int ti, tj;

char findTarget(char map[n][n], int x, int y) {
    char r = mode ? 0x00 : 0x7f;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((j == 0 && i == 0) || x + i < 0 || x + i >= n || y + j < 0 || y + j >= n) continue;
            char c = map[x + i][y + j];
            if (mode) {
                if (c >= r) r = c, ti = i, tj = j;
            } else {
                if (c <= r) r = c, ti = i, tj = j;
            }
        }
    }
    return r;
}

int main() {
    int s, x, y;
    scanf("%d%d %d%d", &n, &s, &x, &y);
    char map[n][n];
    for (int i = 0; i < n; i++) {
        scanf("\n%c", &map[i][0]);
        for (int j = 1; j < n; j++) {
            scanf(" %c", &map[i][j]);
        }
    }
    printf("%c", map[x][y]);
    for (int i = 0; i < s; i++) {
        char t = findTarget(map, x, y);
        switch (t) {
        case 'a': case 'f': case 'k': case 'p': case 'E': case 'J': case 'O': case 'T':
            y--;
            break;
        case 'b': case 'g': case 'l': case 'q': case 'D': case 'I': case 'N': case 'S':
            y++;
            break;
        case 'c': case 'h': case 'm': case 'r': case 'C': case 'H': case 'M': case 'R':
            x--;
            break;
        case 'd': case 'i': case 'n': case 's': case 'B': case 'G': case 'L': case 'Q':
            x++;
            break;
        case 'e': case 'j': case 'o': case 't': case 'A': case 'F': case 'K': case 'P':
            x += ti, y += tj;
            mode ^= 1;
            break;
        default:
            x += ti, y += tj;
            break;
        }
        if (x < 0 || y < 0 || x >= n || y >= n) break;
        printf("%c", map[x][y]);
    }
    return 0;
}