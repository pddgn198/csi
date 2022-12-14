#include <stdio.h>

int ipow(int b, int s) {
    int r = 1;
    while (s--) r *= b;
    return r;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int l = 0, nn = n, m = 0;
        while (nn) l++, nn /= 10;
        nn = n;
        for (int i = 0; i < l; i++) {
            m += ipow(nn % 10, l);
            nn /= 10;
        }
        if (m == n) printf("Yes it is.\n");
        else printf("No it is not.\n");
    }
}