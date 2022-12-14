#include <stdio.h>

int m, n;

int test(int img[m][m], int pat[n][n], int pi, int pj) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (pat[i][j] && !img[pi + i][pj + j]) return 0;
    return 1;
}

int main() {
    scanf("%d", &m);
    int img[m][m];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) scanf("%d", &img[i][j]);
    scanf("%d", &n);
    int pat[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &pat[i][j]);
    
    int match = 0;
    for (int i = 0; i <= m - n; i++) {
        for (int j = 0; j <= m - n; j++) match += test(img, pat, i, j);
    }
    printf("%d\n", match);
    return 0;
}