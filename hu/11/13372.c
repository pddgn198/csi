#include <stdio.h>

void Swap(int *a, int *b) {
    int *arr[2] = { a, b };
    char fromArr, toArr;
    int fromId, toId;
    scanf(" %c %c %d %d", &fromArr, &toArr, &fromId, &toId);
    int tmp = arr[fromArr - 'A'][fromId];
    arr[fromArr - 'A'][fromId] = arr[toArr - 'A'][toId];
    arr[toArr - 'A'][toId] = tmp;
    return;
}
void Replace(int *a, int *b) {
    char tarArr;
    int id, to;
    scanf(" %c %d %d", &tarArr, &id, &to);
    (tarArr == 'A' ? a : b)[id] = to;
}
void Switch(int **a, int **b) {
    int *tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
