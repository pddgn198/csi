#include <stdio.h>

typedef unsigned long long ull;

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main() {
    char s[1001];
    while (scanf("%s", s) != EOF) {
        printf("%08llx\n", hash(s));
    }
    return 0;
}