#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, x, count = 0;
    scanf("%d", &n); // membaca panjang list
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // membaca isi list
    }
    scanf("%d", &x); // membaca X

    // mencari angka-angka yang merupakan kelipatan dari X
    for (int i = 0; i < n; i++) {
        if (arr[i] % x == 0) {
            count++; // menambah jumlah angka yang merupakan kelipatan dari X
        }
    }

    printf("%d\n", count); // mencetak jumlah angka yang merupakan kelipatan dari X
    return 0;
}
