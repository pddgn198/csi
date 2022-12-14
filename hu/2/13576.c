#include <stdio.h>

int main() {
    long long g, b, s;
    scanf("%lld %lld %lld", &g, &b, &s);
    printf("%lld\n%.2lf\n", g * b, 1.0 * g / s);
    return 0;
}