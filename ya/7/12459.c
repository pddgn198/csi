#include <stdio.h>

typedef long long int lli;

lli carpet(lli x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    return 8 * carpet(x - 1) + 1;
}

int main() {
    lli n;
    scanf("%lld", &n);
    printf("%lld\n", carpet(n));
    return 0;
}