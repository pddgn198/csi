#include <stdio.h>
#define uchar unsigned char

int main() {
    int t, n, tmp;
    scanf("%d%d", &t, &n);
    int tnp2 = n + n + 2;
    uchar img[n][n], hor[n], ver[n], dip[tnp2], din[tnp2];
    while (t--) {
        int star = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &tmp);
                img[i][j] = (tmp == 255) ? 1 : 0;
            }
        }
        for (int i = 0; i < n; i++) hor[i] = 1, ver[i] = 1;
        for (int i = 0; i < tnp2; i++) dip[i] = 1, din[i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hor[i] &= img[i][j];
                ver[j] &= img[i][j];
                dip[i + j] &= img[i][j];
                din[n + i - j] &= img[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (hor[i] && ver[j] && din[n + i - j] && dip[i + j]) star++;
            }
        }
        printf("%d\n", star);
    }
    return 0;
}