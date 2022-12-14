#include <stdio.h>
#define m(r) i & r ? 1 : 0

int main() {
    int i;
    scanf("%d", &i);
    printf("%d%d%d%d\n", m(8), m(4), m(2), m(1));
    return 0;
}