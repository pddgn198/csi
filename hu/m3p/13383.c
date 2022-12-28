#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short *deck[10];
short dlen[10];

void _print() {
    for (int i = 0; i < 10; i++) {
        printf("%d:", i);
        if (dlen[i] > 0) {
            for (int j = 0; j < dlen[i]; j++) {
                printf(" %hd", deck[i][j]);
            }
            puts("");
        } else
            puts(" No card");
    }
}

void _all(short num, short len) {
    for (short i = 0; i < 10; i++) {
        dlen[i] = len;
        for (short j = 0; j < len; j++) {
            deck[i][j] = num;
        }
    }
}

void _place(short table_idx, short len) {
    dlen[table_idx] = len;
    for (int i = 0; i < len; i++) {
        scanf("%hd", &deck[table_idx][i]);
    }
}

void _swap(short table_a, short table_b) {
    short *tmp = deck[table_a];
    deck[table_a] = deck[table_b];
    deck[table_b] = tmp;
    int tmpl = dlen[table_a];
    dlen[table_a] = dlen[table_b];
    dlen[table_b] = tmpl;
}

void _clear() {
    for (int i = 0; i < 10; i++) {
        dlen[i] = 0;
    }
}

void _shiftleft() {
    int tmpl = dlen[0];
    short *tmp = deck[0];
    for (int i = 0; i < 9; i++) {
        dlen[i] = dlen[i + 1];
        deck[i] = deck[i + 1];
    }
    dlen[9] = tmpl;
    deck[9] = tmp;
}

void _shiftright() {
    int tmpl = dlen[9];
    short *tmp = deck[9];
    for (int i = 9; i > 0; i--) {
        dlen[i] = dlen[i - 1];
        deck[i] = deck[i - 1];
    }
    dlen[0] = tmpl;
    deck[0] = tmp;
}

int main() {
    for (int i = 0; i < 10; i++) {
        deck[i] = malloc(10000 * sizeof(short));
    }
    char cmd[64];
    while (scanf("%s", cmd) != EOF) {
        if (!strcmp(cmd, "exit"))
            break;
        else if (!strcmp(cmd, "print")) {
            _print();
        } else if (!strcmp(cmd, "all")) {
            short num, len;
            scanf("%hd %hd", &num, &len);
            _all(num, len);
        } else if (!strcmp(cmd, "place")) {
            short table_idx, len;
            scanf("%hd %hd", &table_idx, &len);
            _place(table_idx, len);
        } else if (!strcmp(cmd, "swap")) {
            short table_a, table_b;
            scanf("%hd %hd", &table_a, &table_b);
            _swap(table_a, table_b);
        } else if (!strcmp(cmd, "clear")) {
            _clear();
        } else if (!strcmp(cmd, "shiftleft")) {
            _shiftleft();
        } else if (!strcmp(cmd, "shiftright")) {
            _shiftright();
        }
    }
    for (int i = 0; i < 10; i++) {
        free(deck[i]);
    }
    return 0;
}