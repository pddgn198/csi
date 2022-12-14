#include <stdio.h>

int pb(int n, int k, int inv) {
    int halflen = ((2 << n) - 1) / 2;
    if (n == 0) return 0 ^ inv;
    if (k == halflen)
        return 1 ^ inv;
    else if (k < halflen)
        return pb(n - 1, k, 0);
    else
        return pb(n - 1, k - halflen - 1, 1);
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    while (t--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", pb(n, k, 0));
    }
    return 0;
}