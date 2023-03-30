#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int a[MAX];

void build(int l, int r) {
    if (l > r) {
        printf("-999 ");
        return;
    }
    int mid = (l + r) / 2;
    printf("%d ", a[mid]);
    build(l, mid - 1);
    build(mid + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    build(0, n - 1);
    return 0;
}
