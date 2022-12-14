#include <stdio.h>
#include <string.h>

int main() {
    char s[10000];
    while (gets(s) != NULL) {
        int cur = 0, l = strlen(s);
        while (s[cur] == ' ') s[cur] = ';', cur++;
        if (s[l - 1] == ';') s[l - 1] = 0; 
        puts(s);
    }
    puts("// surprise<3");
    return 0;
}