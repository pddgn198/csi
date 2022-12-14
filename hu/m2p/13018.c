#include <stdlib.h>

#define max(a, b) (a > b ? a : b)

int cmp(const void *a, const void *b) {
    long long _a = *(long long *)a;
    long long _b = *(long long *)b;
    return (_a > _b) - (_a < _b);
}

void array2d_sort(int row, int col, long long arr[][500]) {
    long long *co = malloc(sizeof(long long) * max(row, col));
    int i, j, k;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col && i + j < row; j++) {
            co[j] = arr[i + j][j];
        }
        qsort(co, j, sizeof(long long), cmp);
        for (k = 0; k < j; k++) {
            arr[i + k][k] = co[k];
        }
    }
    for (i = 1; i < col; i++) {
        for (j = 0; j < row && i + j < col; j++) {
            co[j] = arr[j][i + j];
        }
        qsort(co, j, sizeof(long long), cmp);
        for (k = 0; k < j; k++) {
            arr[k][k + i] = co[k];
        }
    }
    free(co);
}
