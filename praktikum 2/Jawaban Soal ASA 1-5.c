//Mira goes to isekai
// Mira mask ke dunia lain, dia mendapat skill inventory. Dalam skill tersebut terdapat
// kelemahan yaitu, per barang memiliki berat yang berbeda. Karena level Mira mash kecil
// Mira harus menghitung berapa banyak barang yang dimilikinya serta total berat barang
// semuanya. Bantulah Mira menghitung total berat barang yang ada di dalam inventory
// nya!
// Misal Mira memiliki 3 barang dengan masing masing berat barang 9, 3, dan 2, maka total
// berat barang mira adalah 14
// Input Format
// • Baris pertama merupakan berapa banyak barang mira (n)
// • Baris kedua merupakan list berat masing masing barang Mira
// Constraints
// • 1000 ms
// 1<= n<= 25
// • 0 < arrli] < 100
// Output Format
// • Total berat barang Mira

// Sample Input 0
// 3
// 9 3 2
// Sample Output 0
// 14


// Sample Input 1
// 5
// 1 2 3 4 5
// Sample Output 1
// 15

// Sample Input 2
// 10
// 1 2 3 4 5 6 7 8 9 10
// Sample Output 2
// 55

// Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("%d", sum);
    return 0;
}

//Besar tapi terkecil
// Diberikan sebuah array A berukuran N yang berisi bilangan bulat tidak negatif. Tentukan
// indeks bilangan terkecil dari elemen dalam array tersebut yang bernilai lebih bear dari
// atau sama dengan bilangan bulat K. Jika tidak ada elemen dalam array yang memenuhi
// kondisi tersebut, keluarkan -1.
// Input Format
// • Baris pertama menerima N yaitu ukuran array A
// Baris kedua menerima array A sebanyak N elemen
// • Baris ketiga menerima K
// Constraints
// 1 < N < 99
// 1 < A, K < 1015
// • Array A dipastikan sudah terurut dari kecil ke besar
// Output Format
// Indeks bilangan terkecil yang bernilai lebih bear dari atau sama dengan bilangan bulat K.
// Atau -1 jika tidak ditemukan.
// Note
// Index dimulai dari 0.

// Sample Input 0
// 5
// 1 2 3 4 5
// 4
// Sample Output 0
// 3

// Sample Input 1
// 5
// 1 2 3 4 5
// 6
// Sample Output 1
// -1

// Sample Input 2
// 5
// 1 2 3 4 5
// 1
// Sample Output 2
// 0

// Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i, k, index = -1;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for(i = 0; i < n; i++){
        if(arr[i] >= k){
            index = i;
            break;
        }
    }
    printf("%d", index);
    return 0;
}

// Sosis dan Telur
// Sus sedang bosan ketika menjaga toko kelontongnya. Karena bosan, Sus mencoba untuk
// mencari semua kemungkinan baris yang terjadi apabila dia membariskan sosis dan telur
// dengan panjang k. Karena terlalu mudah ditebak, Sus memutuskan untuk menghilangkan
// baris yang ada dua sosis bersebelahan. Bantu Sus untuk menemukan semua
// kemungkinan baris tersebut dengan telur yang direpresentasikan oleh angka 'O' dan sosis
// yang direpresentasikan oleh angka '1'. Baris harus terurut dari yang paling kecil ke paling
// besar nilal binernya, darl atas ke bawah
// Input Format
// Sebuah bilangan bulat positif k.
// Constraints
// • 1 ≤ k ≤ 20
// Output Format
// Semua kemungkinan baris berisi string biner yang memenuhi kondisi, dipisahkan dengan
// newline.

// Sample Input 0
// 3
// Sample Output 0
// 000
// 001
// 010
// 100
// 101

// Sample Input 1
// 4
// Sample Output 1
// 0000
// 0001
// 0010
// 0100
// 0101
// 1000
// 1001
// 1010

// Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void generate_strings(int k, char *s) {
    if (k == 0) {
        printf("%s\n", s);
    } else {
        s[k-1] = '0';
        generate_strings(k-1, s);
        if (k == 1 || s[k-2] != '1') {
            s[k-1] = '1';
            generate_strings(k-1, s);
        }
    }
}

int main() {
    int k;
    scanf("%d", &k);

    char s[k+1];
    s[k] = '\0';
    generate_strings(k, s);

    return 0;
}



//Buah
// Untuk menjaga kesehatannya, Pak Dengklek membeli buah-buahan untuk dimakan. Pak
// Dengklek membeli N buah apel merah dan V buah apel hijau. Semua apel merah
// mempunyai berat masing-masing sebesar A dan semua apel hijau mempunyai berat
// masing-masing sebesar B. Kemudian, Pak Dengklek ingin memakan sebagian buah apel
// merah dan apel hijau. Namun, Pak Dengklek ingin mengambil sesedikit mungkin apel
// sedemikian sehingga total beat apel yang diambil untuk masing-masing warna harus
// sama, dan minimal harus mengambil satu dari masing-masing jenis apel.
// Input Format
// Baris pertama berisi bilangan-bilangan N, A, dan B yang menyatakan banyak apel untuk
// masing-masing warna, berat setiap apel merah, dan berat setiap apel hijau.
// Constraints
// • 1≤N≤10^15
// • 1≤A,B≤N
// Output Format
// Sebuah baris berisi sebuah bilangan bulat yang berisi banyak apel minimal sesuai dengan
// deskripsi cerita di atas.

// Sample Input 0
// 5 2 3
// Sample Output 0
// 5


// Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long long n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    long long min = n;
    long long max = 0;
    if(a < b){
        max = a;
    } else {
        max = b;
    }
    long long i;
    for(i = 1; i <= max; i++){
        if(a % i == 0 && b % i == 0){
            long long j = a / i;
            long long k = b / i;
            long long l = n / (j + k);
            long long m = l * j;
            long long o = l * k;
            long long p = m + o;
            if(p < min){
                min = p;
            }
        }
    }
    printf("%lld", min);
    return 0;
}

//Jumlah Bilangan Genap
// andy menyukai bilangan genap hitunglah banyak angka yang memiliki merupakan
// bilangan genap pada array yang di berikan
// Input Format
// panjang array N
// array
// Constraints
// time limit 1000
// Output Format
// banyak angka genap

// Sample Input 0
// 5
// 1 2 3 4 5
// Sample Output 0
// 2

// Sample Input 1
// 5
// 1 3 5 7 9
// Sample Output 1
// 0

// Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, count=0;
    scanf("%d", &n); // membaca panjang array
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]); // membaca isi array
        if (arr[i] % 2 == 0) { // jika bilangan genap
            count++; // tambahkan ke hitungan
        }
    }
    printf("%d\n", count); // cetak hasil
    return 0;
}
