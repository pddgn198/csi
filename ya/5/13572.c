#include <stdio.h>

int main() {
    char s[1000001];
    char a[10000], b[10000];
    char table[26];
    int q;
    for (int i = 0; i < 26; i++) table[i] = 'a' + i;
    scanf("%s %d", s, &q);
    for (int i = 0; i < q; i++) scanf(" %c %c", a + i, b + i);
    for (int i = q - 1; i >= 0; i--) {
        table[a[i] - 'a'] = table[b[i] - 'a'];
    }
    char *ptr = s;
    while (*ptr) {
        *ptr = table[*ptr - 'a'];
        ptr++;
    }
    puts(s);
    return 0;
}