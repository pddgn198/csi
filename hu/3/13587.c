#include <stdio.h>

int main() {
    int a, k, p = 0x40000000;
    scanf("%d", &a);
    while (!(a & p) && p) p >>= 1;
    do {
        printf("%d", a & p ? 1 : 0);
        a -= a & p;
        p >>= 1;
    } while (p);
    printf("\n");
}