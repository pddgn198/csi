#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define abs(x) (x >= 0 ? x : -x)

int n, s, t, tmp;
int mx = INT_MIN, mxjump = 0;
int h[15], c[15], jumped[15] = { 0 };
int neighbor[15][15] = { -1 };   // i -> j

// int stack[15];

void leap(int from, int cost, int d) {
    if (from == t) {
        // tmp = 0;
        // while (stack[tmp] > -1) printf("%d -> ", stack[tmp++] + 1);
        // printf("| %d, %d\n", cost, d - 1);
        if (cost > mx) mx = cost, mxjump = d-1;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!jumped[i] && (neighbor[from][i] != -1)) {
            jumped[i] = 1;
            // stack[d] = i;
            leap(i, cost + neighbor[from][i], d + 1);
            // stack[d] = -1;
            jumped[i] = 0;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &s, &t);
    s--, t--;
    for (int i = 0; i < n; i++) scanf("%d", h + i);
    for (int i = 0; i < n; i++) scanf("%d", c + i);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i != j && (i - j == 1 || j - i == 1 || c[i] == c[j])) {
                neighbor[i][j] = (i - j) * (h[i] - h[j]);
                neighbor[i][j] = abs(neighbor[i][j]);
            } else {
                neighbor[i][j] = -1;
            }
            neighbor[j][i] = neighbor[i][j];
        }
    }
    // for (int i = 0; i < 15; i++) stack[i] = -1;
    // stack[0] = s;
    jumped[s] = 1;
    leap(s, 0, 1);
    printf("%d %d", mx, mxjump);

    /*
    putchar(' ');
    putchar(' ');
    for (int i = 0; i < n; i++) printf(" %3d", i + 1);
    putchar('\n');
    for (int i = 0; i < n; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < n; j++) {
            if (neighbor[i][j] != -1)
                printf(" %3d", neighbor[i][j]);
            else
                printf("   .");
        }
        putchar('\n');
    }
    */
    return 0;
}