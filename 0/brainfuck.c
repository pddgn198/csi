#include <stdio.h>

#define DEBUG

#define SLEEPTIMEMS 50
#define ARRLEN 128
#define STACKLEN 128

#ifdef DEBUG
#include <windows.h>
#endif

char arr[ARRLEN];
long int stack[STACKLEN];
int stacksize = 0;

int main() {
    FILE *code = fopen("tests/idk.bf", "r");
    char c;
    char *ptr = arr;
    while ((c = fgetc(code)) != EOF) {
        if (c == ' ' || c == '\n') continue;
#ifdef DEBUG
        printf("\33[2K\r");
        for (int j = 0; j < 16; j++) {
            printf("%02x ", (unsigned char)arr[j]);
        }
        printf("(%c:%03ld) @%02llx ^%02d ", c, ftell(code), ptr - arr, stacksize);
#endif
        switch (c) {
            case '>': ptr++; break;
            case '<': ptr--; break;
            case '+': (*ptr)++; break;
            case '-': (*ptr)--; break;
            case '.':
#ifdef DEBUG
                printf("> %c\n", *ptr);
#else
                putchar(*ptr);

#endif
                break;
            case ',':
#ifdef DEBUG
                printf("< ");
                *ptr = getchar();
                printf("%c\n", *ptr);
#else
                *ptr = getchar();
#endif
                break;
            case '[':
                if (stacksize >= STACKLEN) {
                    printf("Stack overflow\n");
                    return 1;
                }
                stack[stacksize++] = ftell(code);
                break;
            case ']':
                if (stacksize == 0) {
                    printf("Stack Underflow\n");
                    return 1;
                } else {
                    if (*ptr)
                        fseek(code, stack[stacksize - 1], SEEK_SET);
                    else
                        stacksize--;
                }
            default:
                break;
        }
#ifdef DEBUG
        Sleep(SLEEPTIMEMS);
#endif
    }
    return 0;
}