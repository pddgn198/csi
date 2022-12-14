#include <stdio.h>

int rec(int n) {
    if (n < 0) return -1;

    char c = getchar();
    // printf("%*d %c\n", n + 1, 0, c);
    int r = 0;
    switch (c) {
        case '0':
            return 0;
        case '1':
            return 1 << (n << 1);
        case '2':
            for (int _ = 0; _ < 4; _++) {
                int tmp = rec(n - 1);
                if (tmp == -1) return -1;
                r += tmp;
            }
            return r;
        default:
            return -1;
    }
}

int main() {
    int n;
    scanf("%d ", &n);
    int r = rec(n);
    char c = getchar();
    if ((c != '\n' && c != EOF) || r == -1)
        printf("Domo");
    else
        printf("%d", r);
    return 0;
}