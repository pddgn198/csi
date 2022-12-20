#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITSIZE 8

char **split_(char *str, char *pattern, int *split_num) {
    int len = strlen(str), lenp = strlen(pattern);
    int cap = INITSIZE;
    char **r = malloc(sizeof(char *) * cap);
    *split_num = 0;
    int previ = 0;
    for (int i = 0; i < len - lenp + 1; i++) {
        // for (int j = 0; j < lenp; j++) putchar(str[i + j]);
        // putchar(' ');
        // printf("%s\n", pattern);
        int same = 1;
        for (int j = 0; j < lenp; j++) {
            if (str[i + j] != pattern[j]) {
                same = 0;
                break;
            }
        }
        if (same) {
            if (i - previ) {
                if (*split_num >= cap) {
                    cap <<= 1;
                    r = realloc(r, sizeof(char *) * (cap));
                }
                r[*split_num] = malloc(sizeof(char) * (i - previ + 1));
                memcpy(r[*split_num], str + previ, (i - previ) * sizeof(char));
                r[*split_num][i - previ] = 0;
                *split_num += 1;
            }
            i += lenp - 1;
            previ = i + 1;
        }
    }
    if (*split_num >= cap) {
        cap <<= 1;
        r = realloc(r, sizeof(char *) * (cap));
    }
    r[*split_num] = malloc(sizeof(char) * (len - previ));
    memcpy(r[*split_num], str + previ, (len - previ) * sizeof(char));
    r[*split_num][len - previ] = 0;
    *split_num += 1;

    return r;
}
void free_(char **result, int split_num) {
    for (int i = 0; i < split_num; i++) {
        free(result[i]);
    }
    free(result);
}
