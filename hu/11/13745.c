#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// sort a with length len
int **s(int *a, int len) {
    int l = sqrt(len);
    int **r = (int **)malloc(l * sizeof(int *));
    int *rr = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        rr[i] = a[i];
    }
    for (int i = 0; i < l; i++) {
        r[i] = rr + i * l;
    }
    qsort(rr, len, sizeof(int), cmp);
    return r;
}

// print 2d array ans with size len
void print(int **ans, int len) {
    int l = sqrt(len);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    free(*ans);
    free(ans);
    return;
}
