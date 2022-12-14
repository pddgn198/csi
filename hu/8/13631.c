#include <stdio.h>

// int stack[100];
// int top = -1;

int a[20];
int find(int x, int i) {
    if (x == 0) {
        // for (int j = 0; j < top; j++) printf("%d ", stack[j]);
        // printf("\n");
        return 1;
    }
    if (x < 0) return 0;
    int r = 0;
    for (int j = i; j >= 0; j--) {
        // stack[++top] = a[j];
        r += find(x - a[j], j);
        // stack[top--] = 0;
    }
    return r;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", a + i);
    }
    printf("%d\n", find(n, k-1));
    return 0;
}