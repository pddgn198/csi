#include <stdlib.h>

unsigned ***new_3d_array(unsigned n, unsigned m, unsigned k) {
    unsigned ***ptr = malloc(sizeof(unsigned **) * n);
    unsigned **pptr = malloc(sizeof(unsigned *) * n * m);
    unsigned *ppptr = malloc(sizeof(unsigned) * n * m * k);

    for (int i = 0; i < n; i++) {
        ptr[i] = pptr + i * m;
        for (int j = 0; j < m; j++) {
            ptr[i][j] = ppptr + i * m * k + j * k;
        }
    }
    return ptr;
}

void delete_3d_array(unsigned ***arr) {
    free(**arr);
    free(*arr);
    free(arr);
}