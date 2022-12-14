#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list vl;
    int r = 0;
    va_start(vl, count);
    while (count--) {
        r += va_arg(vl, int);
    }
    va_end(vl);
    return r;
}

int main() {
    printf("%d\n", sum(5, 1, 2, 5, 6, 9));
    return 0;
}