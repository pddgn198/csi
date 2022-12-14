#include <stdio.h>

int a[10000000];
int p[10000000];

int comfort(int ii) {
    int ref = a[ii];
    int i = ii - 1;
    int r = 0;
    while (i >= 0 && a[i] < ref) {
        r += p[i] + 1;
        i -= p[i] + 1;
    }
    p[ii] = r;
    return r;
}

int main() {
    int n, x;
    int found = 0;
    scanf("%d %d ", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        if (comfort(i) == x) {
            if (found) printf(" ");
            printf("%d", i + 1);
            found = 1;
        }
    }
    puts(found ? "" : "ouo");
    return 0;
}