#include <stdio.h>

#define MAX 1000

int a[MAX];

int count(int l, int r) {
    if (l == r) {
        return a[l];
    }
    int mid = (l + r) / 2;
    return count(l, mid) + count(mid + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", count(0, n - 1));
    return 0;
}
