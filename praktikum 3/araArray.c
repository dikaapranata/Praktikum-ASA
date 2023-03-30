#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int a[MAX];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int sum = 0, ans = a[0], l = 0, r = 0, tmp = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > ans) {
            ans = sum;
            l = tmp;
            r = i;
        }
        if (sum < 0) {
            sum = 0;
            tmp = i + 1;
        }
    }
    printf("%d\n", ans);
    for (int i = l; i <= r; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
