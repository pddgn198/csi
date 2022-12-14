#include <stdio.h>

int main() {
    char s[6];
    scanf("%s", s);
    for (int i = 0; i < 5; i++) {
        printf("%c", 25 - (s[i] - 'a') + 'A');
    }
    printf("\n");
    return 0;
}