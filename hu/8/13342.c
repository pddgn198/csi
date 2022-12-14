#include <stdio.h>

void sca() {
    char s[101];
    scanf("%s", s);
    switch (s[0]) {
        case '+': case '-': case '*': case '/':
            sca();
            printf(" ");
            sca();
            printf(" %s", s);
            break;
        default:
            printf("%s", s);
            break;
    }
}

int main() {
    sca();
    return 0;
}