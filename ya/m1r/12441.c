#include <stdio.h>
#include <string.h>

int isPalindrome(char *s, int len) {
    for (int i = 0; i < (len + 1) / 2; i++) {
        if (s[i] != s[len - i - 1]) return 0;
    }
    return 1;
}

int main() {
    char s[100001];
    while (scanf("%s", s) != EOF) {
        if (isPalindrome(s, strlen(s))) puts("Yes");
        else puts("No");
    }
    return 0;
}