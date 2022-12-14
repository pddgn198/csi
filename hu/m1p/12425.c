#include <stdio.h>
#include <string.h>

int loi(int x) {
    char s[16];
    sprintf(s, "%d", x);
    return strlen(s);
}

int main() {
    char s[16384], z[16384];
    while (scanf("%s", s) != EOF) {
        int cur = 0, count = 0, zi = 0;
        char c, tc = s[0];
        do {
            c = s[cur++];
            if (c == tc) count++;
            else {
                sprintf(z + zi, "%d", count);
                zi += loi(count);
                if ('0' <= tc && tc <= '9') sprintf(z + zi, "'%c'", tc), zi += 3;
                else z[zi++] = tc, z[zi] = '\0';
                count = 1, tc = c;
            }
        } while (c != '\0');
        printf("%s\n", z);
        float rate =  (float)strlen(z) / strlen(s);
        if (rate < 1.0) printf("compress rate: %.3f\n", rate);
        else printf("the string can't zip\n");
    }
    return 0;
}