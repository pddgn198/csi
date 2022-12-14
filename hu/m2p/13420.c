#include <stdio.h>

char adj[100][100];
int color[100] = {};
int n, k;

int walk(int from, int c) {
    if (color[from]) return 0;
    color[from] = c;
    for (int i = 0; i < n; i++) if (adj[from][i]) walk(i, c);
    return 1;
}

int main() {
    scanf("%d %d", &n, &k);
    int a, b;
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        adj[a][b] = adj[b][a] = 1;
    }
    int colors = 1;
    for (int i = 0; i < n; i++) {
        if (walk(i, colors)) colors++;
    }
    // for (int i = 0; i < n; i++) printf("%d %d\n", i, color[i]);

    printf("%d\n", colors-1);
    return 0;
}