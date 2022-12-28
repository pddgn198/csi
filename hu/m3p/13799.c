#include <stdio.h>
#define LEN 1000001

int an[LEN];
char ak[LEN];

int main() {
    int n, k, count = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &an[i]);
    int flag = 0;
    for (int i = 0; i < k; i++) ak[an[i]] += 1;
    for (int i = 1; i <= k; i++)
        if (ak[i]) flag++;
    if (flag == k) count++;
    for (int i = k; i < n; i++) {
        ak[an[i]] += 1;
        if (ak[an[i]] == 1) flag++;
        ak[an[i - k]] -= 1;
        if (ak[an[i-k]] == 0) flag--;
        if (flag == k) count++;
    }
    printf("%d\n", count);
    return 0;
}