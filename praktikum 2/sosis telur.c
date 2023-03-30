// Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printBinary(int n, int k){
    int i, j;
    int arr[n];
    for(i = 0; i < n; i++){
        arr[i] = 0;
    }
    for(i = 0; i < pow(2, n); i++){
        int flag = 1; // flag untuk mengecek apakah ada dua sosis bersebelahan
        for(j = 0; j < n-1; j++){
            if(arr[j] == 1 && arr[j+1] == 1){
                flag = 0;
                break;
            }
        }
        if(flag){ // hanya print jika tidak ada dua sosis bersebelahan
            for(j = n-1; j >= 0; j--){
                printf("%d", arr[j]);
            }
            printf("\n");
        }
        arr[0]++;
        for(j = 0; j < n-1; j++){
            if(arr[j] == 2){
                arr[j] = 0;
                arr[j+1]++;
            }
        }
    }
}

int main() {
    int k;
    scanf("%d", &k);
    printBinary(k, k);
    return 0;
}
