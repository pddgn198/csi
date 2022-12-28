#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 3101
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    char s1[LEN], s2[LEN];
    scanf("%s %s", s1, s2);

    int l1 = strlen(s1), l2 = strlen(s2);

    int **dp = malloc(sizeof(int *) * l1);
    for (int i = 0; i < l1; i++) {
        dp[i] = malloc(sizeof(int) * l2);
        for (int j = 0; j < l2; j++) dp[i][j] = 0;
    }

    if (s1[0] == s2[0]) dp[0][0] = 1;

    for (int i = 1; i < l1; i++) {
        dp[i][0] = (dp[i - 1][0] || s1[i] == s2[0]);
    }

    for (int j = 1; j < l2; j++) {
        dp[0][j] = (dp[0][j - 1] || s1[0] == s2[j]);
    }
    for (int i = 1; i < l1; i++) {
        for (int j = 1; j < l2; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[l1 - 1][l2 - 1]);

    for (int i = 0; i < l1; i++) free(dp[i]);
    free(dp);
    return 0;
}