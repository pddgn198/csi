#include <stdio.h>

int main() {
    int n, c[501], q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r, a[501] = {0};
        int ptr, mxm = -1;
        scanf("%d%d", &l, &r);
        for (int j = l; j <= r; j++) a[c[j]]++;
        for (int j = 1; j <= 500; j++) {
            if (a[j] > mxm) ptr = j, mxm = a[j];
        }
        printf("%d\n", ptr);
    }
}