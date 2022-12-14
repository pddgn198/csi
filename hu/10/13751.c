#include <stdio.h>

typedef unsigned int ui;

ui msb(ui i) {
    i |= i >> 1;
    i |= i >> 2;
    i |= i >> 4;
    i |= i >> 8;
    i |= i >> 16;
    return (i + 1) >> 1;
}

ui andAll(ui start, ui end) {
    ui s = msb(start), e = msb(end);
    if (s != e) return 0;
    ui r = 0;
    while (~(start ^ end) & s) {
        r |= start & end & s;
        s >>= 1;
    }
    return r;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        ui s, e;
        scanf("%u%u", &s, &e);
        printf("%u\n", andAll(s, e));
    }
    return 0;
}