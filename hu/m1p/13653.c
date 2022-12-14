#include <stdio.h>
// #include <conio.h>

int main() {
    char name[10001];
    // char name[10001] = "rushiarushia";
    int n, cur = 0, wronged = -1;
    char c;
    scanf("%s%d", name, &n);
    // n = 300;
    getchar();
    while ((c = getchar()) != EOF) {
    // while ((c = getch()) != EOF) {
        // printf("%c %2d %2d ", c, cur, wronged);
        if (c == '!') {
            puts("");
            if ((n -= 2) <= 0) { puts("SAYONARA"); break; }
            wronged = -1, cur = 0;
        } else if (c == '/') {
            puts("");
            if ((--n) <= 0) { puts("SAYONARA"); break; }
            if (--cur == wronged) wronged = -1;
            if (cur < 0) cur = 0;
        } else if (wronged != -1) {
            cur++;
            puts("no");
        } else {
            if (c == name[cur]) {
                printf("%d\n", ++cur);
                if (name[cur] == '\0') { puts("DAISUKI!"); break; }
            }
            else wronged = cur++, puts("no");
        }
    }
    return 0;
}