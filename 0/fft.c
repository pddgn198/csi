#include <stdio.h>
#include <math.h>
#include <string.h>

#define max(_a, _b) (_a > _b ? _a : _b)
#define LEN 1024
#define PI 3.141592653589793116

typedef struct cplx {
    double r;
    double i;
} cplx;

inline cplx cplus(cplx a, cplx b) {
    return (cplx){ a.r + b.r, a.i + b.i };
}

inline cplx csub(cplx a, cplx b) {
    return (cplx){ a.r - b.r, a.i - b.i };
}

inline cplx cmul(cplx a, cplx b) {
    return (cplx){ a.r * b.r - a.i * b.i, a.i * b.r + a.r * b.i };
}

int l2p2(int n) {
    n--;
    for (int i = 1; i <= 16; i <<= 1) n |= n >> i;
    n++;
    return n;
}

/*
void pc(cplx *p, int n) {
    for (int i = n - 1; i >= 0; i--) printf("%.4lf  ", p[i].r); putchar('\n');
    for (int i = n - 1; i >= 0; i--) printf("%.4lfj ", p[i].i); puts("\n");
}*/

// len(r) = n = 2^k
void FFT(cplx *r, cplx *p, int n, int inv) {
    if (n == 1) {
        r[0] = p[0];
        return;
    }
    cplx w = { cos(2 * PI / n), sin(2 * PI / n) };
    if (inv) w.i = -w.i;
    cplx wt = { 1, 0 };
    cplx pe[n/2], po[n/2], ye[n/2], yo[n/2];
    for (int i = 0; i < n / 2; i++) {
        pe[i] = p[i * 2];
        po[i] = p[i * 2 + 1];
    }
    
    FFT(ye, pe, n/2, inv);
    FFT(yo, po, n/2, inv);
    for (int i = 0; i < n/2; i++) {
        cplx tmpm = cmul(wt, yo[i]);
        r[i] = cplus(ye[i], tmpm);
        r[i + n/2] = csub(ye[i], tmpm);
        wt = cmul(wt, w);
    }
}

int main() {
    char buf[LEN + 1];
    cplx a[2 * LEN], b[2 * LEN], c[2 * LEN];
    int la, lb;

    gets(buf);
    la = strlen(buf);
    for (int i = 0; i < la; i++)
        a[i] = (cplx){buf[la - i - 1] - '0', 0};
    for (int i = la; i < LEN * 2; i++)
        a[i] = (cplx){0, 0};

    gets(buf);
    lb = strlen(buf);
    for (int i = 0; i < lb; i++)
        b[i] = (cplx){buf[lb - i - 1] - '0', 0};
    for (int i = lb; i < LEN * 2; i++)
        b[i] = (cplx){0, 0};

    int l = l2p2(max(la, lb)) << 1;

    cplx fa[l], fb[l], fc[l];
    FFT(fa, a, l, 0);
    FFT(fb, b, l, 0);

    for (int i = 0; i < l; i++) {
        fc[i] = cmul(fa[i], fb[i]);
    }
    FFT(c, fc, l, 1);
    int r[l];
    for (int i = 0; i < l; i++) r[i] = (c[i].r / l + 0.5);
    for (int i = 0; i < l; i++) {
        r[i+1] += r[i] / 10;
        r[i] %= 10;
    }
    int i = l-1;
    while (r[--i] == 0);
    for (; i >= 0; i--) printf("%d", r[i]);
    
    return 0;
}