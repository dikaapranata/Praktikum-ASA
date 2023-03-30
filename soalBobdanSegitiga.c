/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void cariKeliling(int numbers[], int length) {
    int i, j, k;
    int combinations[3];
    int besar;
    int angkaKe;
    int kel;
    int keliling=0;

    // Loop melalui setiap kombinasi 3 angka
    for (i = 0; i < length; i++) {
        for (j = i+1; j < length; j++) {
            for (k = j+1; k < length; k++) {
                combinations[0] = numbers[i];
                combinations[1] = numbers[j];
                combinations[2] = numbers[k];
                //printf("Combinations: %d %d %d\n", combinations[0], combinations[1], combinations[2]);

                if (combinations[0] > combinations[1]) {
                    besar = combinations[0];
                    angkaKe = 0;
                } else {
                    besar = combinations[1];
                    angkaKe = 1;
                }

                if (besar < combinations[2]) {
                    besar = combinations[2];
                    angkaKe = 2;
                }

                int a = combinations[0];
                int b = combinations[1];
                int c = combinations[2];
                int bsr = besar;

                //printf("besar: %d\n", besar);

                if (angkaKe == 0) {
                    if (b+c > bsr) {
                        kel = a+b+c;
                        //printf("segitiga, keliling : %d\n", a+b+c);
                    } else {
                        //printf("bukan segitiga\n");
                    }
                }

                if (angkaKe == 1) {
                    if (a+c > bsr) {
                        kel = a+b+c;
                        //printf("segitiga, keliling : %d\n", a+b+c);
                    } else {
                        //printf("bukan segitiga\n");
                    }
                }

                if (angkaKe == 2) {
                    if (a+b > bsr) {
                        kel = a+b+c;
                        //printf("segitiga, keliling : %d\n", a+b+c);
                    } else {
                        //printf("bukan segitiga\n");
                    }
                }

                if (kel > keliling) {
                    keliling = kel;
                }
            }
        }
    }

    //printf("keliling terbesar adalah : %d", keliling);
    printf("%d", keliling);
}


int main() {
    // int numbers[] = {3, 4, 20, 11};
    // int length = sizeof(numbers) / sizeof(numbers[0]);
    int length;
    int numbers[1000];
    
    scanf("%d",&length);
    for (int i=0;i<length;i++){
        scanf("%d",&numbers[i]);
    }

    cariKeliling(numbers, length);

    return 0;
}


