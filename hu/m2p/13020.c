#include <stdio.h>
#include <stdlib.h>
#define HASHMX 5119   // = 9 << 9 | 0b111111111
// #define __DEBUG__

typedef int puz;

#ifdef __DEBUG__
void output(puz a) {
    int mask = 0x100, t = a >> 9;
    int tmp;
    for (int i = 0; i < 9; i++) {
        tmp = (a & mask) >> (8 - i);
        putchar(t == i ? 'x' : tmp ? '1'
                                   : '0');
        mask >>= 1;
        if (i % 3 == 2) putchar('\n');
    }
}
#endif

int input() {
    char tmp;
    int r = 0, t;
    for (int i = 0; i < 9; i++) {
        r <<= 1;
        scanf(" %c", &tmp);
        if (tmp == '1') r |= 1;
        if (tmp == 'x') t = i;
    }

    return r | t << 9;
}

char swapper[9];
int swap(int p, int dest) {
    for (int i = 8; i >= 0; i--) {
        swapper[i] = p & 1;
        p >>= 1;
    }
    swapper[p] ^= swapper[dest];
    swapper[dest] ^= swapper[p];
    swapper[p] ^= swapper[dest];
    p = dest;
    for (int i = 0; i < 9; i++) {
        p <<= 1;
        p |= swapper[i];
    }
    return p;
}

typedef struct {
    puz b;
    int k;
} ctx;
ctx queue[2 * HASHMX];
int qend = -1;

int ans = 0;
int DP[HASHMX] = {};

void solve(puz b, int k) {
    if (DP[b] == 1) return;
#ifdef __DEBUG__
    printf("k = %d\n", k);
    output(b);
    if (DP[b] <= -1) puts("Solution found");
    puts("");
#endif
    if (DP[b] <= -1) ans -= DP[b];
    DP[b] = 1;
    if (k == 0) return;
    int bx = b >> 9;
    if (bx / 3 < 2) queue[++qend] = (ctx){ swap(b, bx + 3), k - 1 };
    if (bx / 3 > 0) queue[++qend] = (ctx){ swap(b, bx - 3), k - 1 };
    if (bx % 3 < 2) queue[++qend] = (ctx){ swap(b, bx + 1), k - 1 };
    if (bx % 3 > 0) queue[++qend] = (ctx){ swap(b, bx - 1), k - 1 };
}


// 1
// 0 1 2
// 3 4 5
// 6 7 8

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) DP[input()] -= 1;
    puz b = input();

    queue[++qend] = (ctx){ b, k };
    for (int i = 0; i <= qend; i++) {
        solve(queue[i].b, queue[i].k);
        if (ans == n) break;
    }

    printf("%d\n", ans);

    return 0;
}