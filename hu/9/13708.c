#include <stdio.h>
#include <string.h>
#define LEN 40 + 1

short dp[LEN][LEN];

int isPalindrome(char *s, int from, int to) {
    int t = (to - from) / 2;
    for (int i = 0; i < t; i++) {
        if (s[from + i] != s[to - i - 1]) return 0;
    }
    return 1;
}

int partition(char *s, int from, int to) {
    if (dp[from][to] != -1) return dp[from][to];
    int r = 0, t = to - from;
    r += isPalindrome(s, from, to);
    for (int i = 1; i < t; i++) {
        if (isPalindrome(s, from, from + i))
            r += partition(s, from + i, to);
    }
    dp[from][to] = r;
    return r;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) dp[i][j] = -1;
            if (i < LEN-1) dp[i][i+1] = 1;
        }
        char s[LEN];
        scanf("%s", s);
        printf("%d\n", partition(s, 0, strlen(s)));
    }
    return 0;
}