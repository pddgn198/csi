#include <stdio.h>

#define LEN 15

int isValid(char board[LEN][LEN], int black, int white) {
    if (black != white || black != white + 1) return 0;
    return 1;
}

int main() {
    int t;
    char board[LEN][LEN];
    scanf("%d", &t);
    while (t--) {
        int black = 0, white = 0;
        for (int i = 0; i < LEN; i++) {
            scanf(" %d", &board[i][0]);
            for (int j = 1; j < LEN; j++) {
                board[i][j] = getchar();
                if (board[i][j] == '1') black++;
                else if (board[i][j] == '2') white++;
            }
        }
        if (isValid(board, black, white)) puts("Yes");
        else puts("No");
    }
    return 0;
}