#include <stdio.h>

int main() {
    int t, n;
    scanf("%d %d", &t, &n);
    int k = 2 * n + 1;
    int row[n], col[n], dip[k], din[k];
    int tmp;
    while (t--) {
        for (int i = 0; i < n; i++) {
            row[i] = 1;
            col[i] = 1;
        }
        for (int i = 0; i < k; i++) {
            dip[i] = 1;
            din[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &tmp);
                tmp = (tmp == 255);
                row[i] &= tmp;
                col[j] &= tmp;
                dip[i+j] &= tmp;
                din[n+i-j] &= tmp;
            }
        }
        int star = 0;
        for (int i = 0; i < n; i++) {
            if (row[i]) {
                for (int j = 0; j < n; j++) {
                    if (col[j] && dip[i+j] && din[n+i-j]) star++;
                }
            }
        }
        printf("%d\n", star);
    }
    return 0;
}