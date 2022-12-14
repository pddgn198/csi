#include <stdio.h>
#include <stdlib.h>

#define QLEN 300000

typedef struct {
    int i, j;
} pos;

pos start;
pos portal[26];

char **input(int n, int m) {
    char **r = malloc(sizeof(char *) * n);
    char *rr = malloc(sizeof(char) * m * n);
    for (int i = 0; i < n; i++) {
        r[i] = rr + i * m;
        for (int j = 0; j < m; j++) {
            scanf(" %c", &r[i][j]);
            if (r[i][j] == '$') {
                r[i][j] = '.';
                start = (pos){ i, j };
            } else if ('A' <= r[i][j] && r[i][j] <= 'Z') {
                portal[r[i][j] - 'A'] = (pos){ i, j };
                r[i][j] = '.';
            }
        }
    }
    return r;
}

void output(char **map, int n, int m) {
#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
#endif
}

pos queue[QLEN];

int solve(char **map, int n, int m) {
    int found = 0;
    int qend = 0;
    queue[0] = start;
    for (int _ = 0; _ <= qend; _++) {
        output(map, n, m);
        pos p = queue[_];
        int i = p.i, j = p.j;
        if (map[i][j] == '&') {
            found = 1;
            break;
        }
        if (map[i][j] == '#') continue;

        if (map[i][j] == '.') {
            if (i < n - 1 && map[i + 1][j] != '#') queue[++qend] = (pos){ i + 1, j };
            if (j < m - 1 && map[i][j + 1] != '#') queue[++qend] = (pos){ i, j + 1 };
            if (i > 0 && map[i - 1][j] != '#') queue[++qend] = (pos){ i - 1, j };
            if (j > 0 && map[i][j - 1] != '#') queue[++qend] = (pos){ i, j - 1 };
        } else {
            queue[++qend] = portal[map[i][j] - 'a'];
        }
        map[i][j] = '#';
    }
    return found;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        char **map = input(n, m);
        puts(solve(map, n, m) ? "Yes" : "No");
        free(*map);
        free(map);
    }
    return 0;
}