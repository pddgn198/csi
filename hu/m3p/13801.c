#include <stdio.h>

int pro[30000];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int tmp;
    int check = (1 << k) - 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &tmp);
            pro[i] = (pro[i] << 1) | tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((pro[i] | pro[j]) == check) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}