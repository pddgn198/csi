#include <stdio.h>
#define min(a, b) (a < b ? a : b)

int rmv[1000][1000];
char s[1001];

int check(int start, int end) {
    if (start >= end) return 0;
    if (rmv[start][end] != -1) return rmv[start][end];
    if (s[start] == s[end]) {
        rmv[start][end] = min(check(start + 1, end) + 1, check(start + 1, end - 1));
    } else {
        rmv[start][end] = min(check(start + 1, end) + 1, check(start, end - 1) + 1);
    }
    return rmv[start][end];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) rmv[i][j] = -1;
    }
    puts(check(0, n - 1) <= k ? "Yes" : "No");
    return 0;
}