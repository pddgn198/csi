#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} pos;

pos start;
pos portal[26];

char **input(int n, int m) {
    char tc;
    char **s = malloc(sizeof(char *) * n);
    char *tmp = malloc(sizeof(char) * m * n);
    for (int i = 0; i < n; i++) {
        s[i] = tmp + m * i;
        for (int j = 0; j < m; j++) {
            scanf(" %c", &tc);
            s[i][j] = tc;
            if (tc == '$')
                start = (pos){ i, j }, s[i][j] = '.';
            else if ('A' <= tc && tc <= 'Z')
                portal[tc - 'A'] = (pos){ i, j }, s[i][j] = '.';
        }
    }
    return s;
}

/*
void output(char **s, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            putchar(s[i][j]);
        }
        putchar('\n');
    }
}
*/

int n, m;

int walk(char **const s, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    char c = s[x][y];
    if (c == '&') return 1;
    if (c == '#') return 0;
    // s[x][y] = '*';
    // output(s, n, m);
    // putchar('\n');
    s[x][y] = '#';
    if (c == '.') {
        if (walk(s, x + 1, y) ||
            walk(s, x - 1, y) ||
            walk(s, x, y + 1) ||
            walk(s, x, y - 1)) return 1;
    } else if ('a' <= c && c <= 'z') {
        if (walk(s, portal[c - 'a'].x, portal[c - 'a'].y)) return 1;
    }
    // s[x][y] = c;
    return 0;
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        scanf("%d %d", &n, &m);
        char **s = input(n, m);
        puts(walk(s, start.x, start.y) ? "Yes" : "No");
        free(*s);
        free(s);
    }
    return 0;
}