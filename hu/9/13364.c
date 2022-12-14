#include <stdio.h>
#include <string.h>

int contains_s(char *arr[], int arrlen, const char *s) {
    for (int i = 0; i < arrlen; i++) {
        if (s[0] != arr[i][0]) continue;
        if (strcmp(s, arr[i]) == 0) return 1;
    }
    return 0;
}

int test(char *o, char *d) {
    char *splo[50];

    int olen = 0;
    for (int i = 0; o[i]; i++) {
        if (o[i] == '/') {
            o[i] = 0;
            splo[olen++] = o + i + 1;
        }
    }

    char *ptr = d + 1;
    for (int i = 1; d[i]; i++) {
        if (d[i] == '/') {
            d[i] = 0;
            if (!contains_s(splo, olen, ptr)) return 0;
            ptr = d + i + 1;
        }
    }
    if (!contains_s(splo, olen, ptr)) return 0;
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char o[5001], d[5001];
        scanf("%s %s", &o, &d);
        puts(test(o, d) ? "valid" : "not valid");
    }
    return 0;
}