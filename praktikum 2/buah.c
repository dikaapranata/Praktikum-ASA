#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    int max_total = A + B, take_apel = 0;

    for (int i = 1; i <= N; i++) {
        if ((i * A) % max_total == 0 || (i * B) % max_total == 0) {
            take_apel = i;
            break;
        }
    }

    printf("%d\n", take_apel);
    return 0;
}