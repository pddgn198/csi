#include <stdio.h>

char table[4][16] = {
    "ET",
    "IANM",
    "SURWDKGO",
    "HVF-L-PJ"
    "BXCYZQ--"
};

int main() {
    int n;
    scanf("%d ", &n);
    char prev = '=';
    int count = 0;
    int sig = 0, len = 0;
    do {
        char c = getchar();
        if (c == prev)
            count++;
        else {
            if (prev == '=')
                sig |= (count == 3);
            else {
                switch (count) {
                    case 1: sig <<= 1, len++; break;
                    case 3:
                        putchar(table[len][sig]);
                        sig = len = 0;
                        break;
                    case 7:
                        putchar(table[len][sig]);
                        putchar(' ');
                        sig = len = 0;
                        break;
                    default:
                        break;
                }
            }
            prev = c;
            count = 1;
        }
    } while (n--);
    putchar(table[len][sig]);
    puts("");
    return 0;
}