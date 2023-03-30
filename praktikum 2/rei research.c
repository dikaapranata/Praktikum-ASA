#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime (int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i <= x/2; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, jumlah = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        if (isPrime(i) == true) {
            jumlah++;
        }
    }
    printf("%d", jumlah);
    return 0;
}
