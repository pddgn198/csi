#include <stdio.h>
#define OFFSET 50

struct {
    int type;
    int a, b;
} op[100000];

int main() {
    char s[1000001];
    char table[26];
    int q;
    for (int i = 0; i < 26; i++) table[i] = 'a' + i;
    scanf("%s %d", s, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &op[i].type);
        if (op[i].type == 1) {
            scanf(" %c %c", &op[i].a, &op[i].b);
        } else {
            scanf(" %d %c", &op[i].a, &op[i].b);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (op[i].type == 1)
            table[op[i].a - 'a'] = table[op[i].b - 'a'];
        else
            if (s[op[i].a] >= 'a') s[op[i].a] = table[op[i].b - 'a'] - OFFSET;
    }
    char *ptr = s;
    while (*ptr) {
        if (*ptr < 'a') *ptr += OFFSET;
        else *ptr = table[*ptr - 'a'];
        ptr++;
    }
    puts(s);
    return 0;
}