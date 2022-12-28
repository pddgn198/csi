#include <stdio.h>
#include <string.h>
#define MXSIZE 1024
const char delim[] = "<>";

int main() {
    char buf[MXSIZE];
    int linkCount = 0;
    int foundTitle = 0;
    while (fgets(buf, MXSIZE, stdin) != NULL) {
        char *token = strtok(buf, delim);
        while (token != NULL) {
            if (foundTitle) {
                puts(token);
                foundTitle = 0;
            }
            if (!strcmp(token, "title")) foundTitle = 1;
            if (!strcmp(token, "/a")) linkCount++;
            // puts(token);
            token = strtok(NULL, delim);
        }
    }
    printf("%d\n", linkCount);
    return 0;
}