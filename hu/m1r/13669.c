#include <stdio.h>
#include <math.h>

int isFancy(int n) {
    if (n == 1) return 0;
    int acc = 1;
    int k = sqrt(n);
    for (int i = 2; i <= k; i++) {
        if (n % i == 0) acc += i + (n / i);
    }
    return acc == n;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (isFancy(n)) puts("True");
        else puts("False");
    }
    return 0;
}