#include <stdio.h>
#include <stdlib.h>

int siz_mid[8] = { 0, 1 }, siz_cml[8] = { 0, 1 }, siz_ttl[8] = { 0, 1 };

void initialize_size() {
    for (int i = 2; i <= 7; i++) {
        siz_mid[i] = 4 * siz_cml[i - 2] - siz_mid[i - 2] + 2;
        siz_cml[i] = siz_cml[i - 1] + siz_mid[i];
        siz_ttl[i] = siz_cml[i] + siz_cml[i - 1];
    }
}

void gen_snowflake(char **img, int x, int y, int n) {
    if (n == 0) return;
    if (n == 1) {
        img[x][y] = '#';
        return;
    }
    for (int i = siz_cml[n - 1]; i < siz_cml[n]; i++) {
        for (int j = siz_cml[n - 1]; j < siz_cml[n]; j++) {
            img[x + i][y + j] = '#';
        }
    }
    int off_dia = siz_ttl[n] - siz_ttl[n - 1];
    int off_grx = 0;
    int off_gry = 0;
    gen_snowflake(img, x, y, n - 1);
    gen_snowflake(img, x + off_dia, y, n - 1);
    gen_snowflake(img, x, y + off_dia, n - 1);
    gen_snowflake(img, x + off_dia, y + off_dia, n - 1);
    if (n < 3) return;
    gen_snowflake(img,
                  x + siz_cml[n - 1] - siz_ttl[n - 2] + siz_cml[n - 3],
                  y + siz_cml[n - 1] + (siz_mid[n] - siz_ttl[n - 2]) / 2,
                  n - 2);
    gen_snowflake(img,
                  x + siz_cml[n - 1] + (siz_mid[n] - siz_ttl[n - 2]) / 2,
                  y + siz_cml[n - 1] - siz_ttl[n - 2] + siz_cml[n - 3],
                  n - 2);
    gen_snowflake(img,
                  x + siz_cml[n] - siz_cml[n - 3],
                  y + siz_cml[n - 1] + (siz_mid[n] - siz_ttl[n - 2]) / 2,
                  n - 2);
    gen_snowflake(img,
                  x + siz_cml[n - 1] + (siz_mid[n] - siz_ttl[n - 2]) / 2,
                  y + siz_cml[n] - siz_cml[n - 3],
                  n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    initialize_size();
    int s = siz_ttl[n];

    char **img = calloc(s, sizeof(char *));
    for (int i = 0; i < s; i++) {
        img[i] = calloc(s, sizeof(char));
        for (int j = 0; j < s; j++) img[i][j] = ' ';
    }

    gen_snowflake(img, 0, 0, n);

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) putchar(img[i][j]);
        putchar('\n');
        free(img[i]);
    }
    free(img);
    return 0;
}