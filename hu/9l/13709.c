#include <stdio.h>
#include <string.h>
#define LEN 1000 + 1
#define MX 1000000

int isSym(char *s, int from, int to) {
    int t = (to - from) / 2;
    for (int i = 0; i < t; i++) {
        if (s[from + i] != s[to - i - 1]) return 0;
    }
    return 1;
}

int solve(char *s, int from, int to) {
    if (isSym(s, from, to)) return 0;
    int mn = MX;
    for (int i = from+1; i < to; i++) {
        if (isSym(s, from, i)) {
            int r = solve(s, i, to);
            if (r < mn) mn = r;
        }
    }
    return mn + 1;
}

int main() {
    int t;
    scanf("%d", &t);
    char s[LEN];
    while (t--) {
        scanf("%s", s);
        printf("%d\n", solve(s, 0, strlen(s)));
    }
    return 0;
}