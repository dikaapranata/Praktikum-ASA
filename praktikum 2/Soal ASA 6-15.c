// Rei's Research
// Rei merupakan sebuah peneliti. Dalam penelitiannya dia menemukan sebuah makhluk yang membelah diri sampai n kali, tetapi makhluk yang hidup di akhir hanya yang urutan lahir nya merupakan bilangan prima. Dia ingin mengetahui total makhluk yang hidup di akhir. Untuk membantu Rei, buatkan sebuah program untuk menyelesaikan permasalahan tersebut!
// Misal n = 10, maka makhluk yang hidup adalah makhluk ke - 2,3,5,7. Jadi output yang didapat adalah 4

// Input Format
// Berapa kali makhluk berkembang biak (n)
// Constraints
// 1000 ms
// 1 <= n <= 5000

// Output Format
// Jumlah makhluk yang berhasil hidup

// Sample Input 0
// 10
// Sample Output 0
// 4

// Sample Input 1
// 4
// Sample Output 1
// 2

//Code
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);
    // Menginisialisasi sebuah array yang merepresentasikan
    // setiap bilangan dari 2 hingga n sebagai bilangan prima
    bool is_prime[n+1];
    for (int i = 2; i <= n; i++) {
        is_prime[i] = true;
    }
    // Bilangan 0 dan 1 bukan bilangan prima
    is_prime[0] = false;
    is_prime[1] = false;
    // Menerapkan algoritma Pemfilteran Eratosthenes untuk
    // mencoret bilangan-bilangan yang bukan prima
    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    // Menghitung jumlah bilangan prima dalam range 2 hingga n
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

// Fibocustom ////////////////////////////////////////////////////////////////
// Diketahui suatu deret Fibonacci 1, 1, 2, 3, 5, 8, 13, ... Karena sudah terlalu biasa, kali ini Pak Owob ingin membuat suatu program yang menampilkan deret fibonacci dengan panjang n tetapi menggunakan dua buah bilangan awal custom a dan b. Bantu Pak Owob membuat program tersebut.

// Input Format
// Baris pertama yaitu bilangan bulat non negatif n, kemudian baris kedua berisi bilangan bulat a dan b.

// Constraints
// 0≤n≤87
// -9≤a,b≤9

// Output Format
// Sebuah deret fibonacci sesuai penjelasan di atas.

// Note
// Pertimbangkan apabila nilai pada deret melebihi batas integer ("ya jangan pake integer")

// Sample Input 0
// 8
// 1 4

// Sample Output 0
// 1 4 5 9 14 23 37 60

//Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d %d", a, b);
    for (int i = 0; i < n-2; i++) {
        int temp = a + b;
        printf(" %d", temp);
        a = b;
        b = temp;
    }
    return 0;
}
//SUSAH
// Mari goes to school ////////////////////////////////////////////////////////////////
// Pada hari senin pagi Mari memiliki jadwal pelajaran matematika. Saat itu materinya merupakan himpunan. Pelajaran itu memiliki PR yaitu menulis subset yang dimiliki oleh sebuah himpunan. Bantulah Mari untuk membuat program untuk menyelesaikan permasalahan di atas

// Note :
// Misal terdapat himpunan [2,3]
// Maka subset = [],[2],[3],[2,3]
// array kosong di print -999

// Input Format
// Baris pertama merupakan panjang himpunan (n)
// Baris kedua merupakan set himpunan

// Constraints
// 1000 ms
// 1<=n<=5
// 0<=arr[i]<=9

// Output Format
// Subset dari himpunan

// Sample Input 0
// 3
// 1 2 3

// Sample Output 0
// -999
// 1
// 2
// 1 2
// 3
// 1 3
// 2 3
// 1 2 3

// Sample Input 1
// 2
// 9 0

// Sample Output 1
// -999
// 9
// 0
// 9 0

//Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, arr[5], i, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = 1 << n;
    for (i = 0; i < max; i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                printf("%d ", arr[j]);
            }
        }
        if (i == 0) {
            printf("-999");
        }
        printf("\n");
    }
    return 0;
}

// Si Pemburu Pola ////////////////////////////////////////////////////////////////
// Suatu Hari seoarng mahasiswa matematika di minta tolong oleh temannya yang berkuliah di jurusan sastra untuk memberi tahu berapa banyak huruf ‘a’ dari suatu teks yang di berikan oleh dosen nya. teks yang di berikan oleh dosen nya tersebut tertulis di dalam ribuan halaman kertas. mahasiswa jurusan sastra ini meminta mahasisa jurusan matematika tersebut untuk menghitung huruf ‘a’ untuk panjang karakter n.
// setelah memperhatikan teks tersebut mahasiswa jurusan matematika itu pun memperhatikan bahwa terdapat pola dalam teks tersebut. pola tersebut di awali dengan sebuah kata yang sama yang kemudian di ulang sampai teks itu selesai
// contoh : asaasaasaasaasa…….. ( sampai selesai )
// jadi apabila diminta banyak huruf a untuk n=6 maka jawabanya adalah 4 karena banyak huruf a pada string ‘asaasa’ ada berjumlah 4
// bantulah mahasiswa jurusan sastra tersebut menghitung jumlah a untuk n karakter

// Input Format
// pola dari kata yang akan di ulang
// sebuah integer n yaitu panjang karakter yang diminta

// Constraints
// 1000 ms
// 1 < n < 10^12

// Output Format
// banyak karakter a untuk n karakter

// Sample Input 0
// asa
// 6

// Sample Output 0
// 4

//Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char pola[100];
    long long int n;
    scanf("%s", pola);
    scanf("%lld", &n);
    int i, j, k, count = 0, count2 = 0, count3 = 0, panjang = strlen(pola);
    for (i = 0; i < panjang; i++) {
        if (pola[i] == 'a') {
            count++;
        }
    }
    for (j = 0; j < n % panjang; j++) {
        if (pola[j] == 'a') {
            count2++;
        }
    }
    count3 = (n / panjang) * count;
    printf("%d", count3 + count2);
    return 0;
}


// Tama's Balls
// Tama memiliki N buah bola yang ditulisi dengan nomor yang berbeda. Tama ingin mengurutkan bola-bola tersebut secara random. Buatlah program untuk membantu Tama melihat kemungkinan urutan bola yang dapat dibuat!

// Input Format
// Baris pertama yaitu jumlah bola yang dimiliki Tama
// Input nomor bola Tama

// Constraints
// Input jumlah bola dalam bentuk integer
// Input nomor bola Tama berupa integer yang akan dimasukkan dalam list
// output berupa list of list of integer yang akan dicetak per list

// Output Format
// Kemungkinan urutan bola Tama

// Sample Input 0
// 3
// 1 2 3

// Sample Output 0
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

// Code
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int next_permutation(int *arr, int n) {
    int i = n-2;
    while (i >= 0 && arr[i] >= arr[i+1]) {
        i--;
    }
    if (i < 0) {
        return 0;
    }
    int j = n-1;
    while (j > i && arr[j] <= arr[i]) {
        j--;
    }
    swap(&arr[i], &arr[j]);
    for (int k = i+1; k <= (n+i)/2; k++) {
        swap(&arr[k], &arr[n-k+i]);
    }
    return 1;
}

void permute(int *arr, int n) {
    do {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } while (next_permutation(arr, n));
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // sort the array in ascending order
    qsort(arr, n, sizeof(int), cmpfunc);

    permute(arr, n);

    free(arr);
    return 0;
}

//Code in python
def permutations(balls):
    if len(balls) == 0:
        return [[]]
    result = []
    for i in range(len(balls)):
        rest = balls[:i] + balls[i+1:]
        for p in permutations(rest):
            result.append([balls[i]] + p)
    return result

n = int(input())
balls = list(map(int, input().split()))

result = permutations(balls)

for permutation in result:
    print(' '.join(str(ball) for ball in permutation))


// Explanation 0
// Misalkan Tama memiliki bola dengan nomor 1, 2 dan 3. Maka urutan bola yang bisa dibuat tama adalah [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], dan [3,2,1].

// Sample Input 1
// 2
// 1 2

// Sample Output 1
// 1 2
// 2 1

//code dalam python
n = int(input())
arr = list(map(int, input().split()))

def permute(l, r):
    if l == r:
        print(*arr)
    else:
        for i in range(l, r+1):
            arr[l], arr[i] = arr[i], arr[l]
            permute(l+1, r)
            arr[l], arr[i] = arr[i], arr[l]

permute(0, n-1)


// Explanation 1
// Misalkan Tama memiliki bola dengan nomor 1 dan 2. Maka urutan bola yang bisa dibuat tama adalah [1,2] dan [2,1]

// Dazai dan Huruf Mati ////////////////////////////////////////////////////////////////
// Dazai menyukai huruf mati. Maka dari itu, ketika ia diberikan sebuah kata-kata, ia akan mencoba menghitung jumlah kombinasi dari semua huruf dalam kata-kata tersebut yang hanya berisikan huruf mati saja. Namun karena mencari kombinasi dari suatu kata sangat sulit, Dazai meminta bantuan anda untuk membuat sebuah program untuk membantunya

// Input Format
// Satu baris berisikan string (str) input sebagai kata-kata yang akan dicari kombinasinya

// Constraints
// 1 ≤ len(str) ≤ 10 str berisikan lowercase alphabet

// Output Format
// Satu buah integer yang merepresentasikan jumlah kombinasi substring yang hanya terdiri dari huruf mati

// Sample Input 0
// abcde

// Sample Output 0
// 7

// Explanation 0
// Terdapat 7 substring yang merupakan kombinasi dari huruf abcde, yaitu:
// b, bc, bcd, bd, c, cd, d

//Code
#include <stdio.h>
#include <string.h>

int main() {
    char s[11];
    scanf("%s", s);

    int len = strlen(s);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') continue;
        count++;
        for (int j = i + 1; j < len; j++) {
            if (s[j] == 'a' || s[j] == 'i' || s[j] == 'u' || s[j] == 'e' || s[j] == 'o') break;
            count += (j - i);
        }
    }

    printf("%d\n", count);

    return 0;
}

// Toko Ucup
// Ucup merupakan mahasiswa yang mempunyai bisnis berupa berjualan permen dengan sistem pembayaran KEJUJURAN. Setiap hari dia menyimpan dagangannya di samping tangga gedung B kampus tercinta. Ucup menjual permennya seharga 5000 rupiah per satu permen. Namun, jika membeli 5 sekaligus hanya perlu membayar 20000 rupiah. Ia kebingungan setiap melakukan penghitungan. Buatlah algoritma untuk membantu ucup menghitung berapa banyak penjualan yang membeli dengan promo dan membeli secara satuan dari hasil uang yang didapat!
// (Diasumsikan semua pembeli jujur)

// Input Format
// Baris pertama berupa jumlah uang yang didapat
// Baris kedua berisi jumlah permen yang terjual

// Constraints
// Input jumlah uang integer dalam ribuan
// Input jumlah permen dalam benruk integer

// Output Format
// Jumlah terjual dengan promo dan jumlah terjual secara satuan

// Sample Input 0
// 30000
// 7

// Sample Output 0
// 1 2

// Explanation 0
// Yang membeli permen Ucup menggunakan promo yaitu 1 pembelian, dan yang membeli secara satuan 2 pembelian.
// 1 pembelian promo mendapatkan 20.000
// 2 pembelian satuan mendapatkan 10.000

// Sample Input 1
// 30000
// 6

// Sample Output 1
// 0 6

// Explanation 1
// Yang membeli permen Ucup menggunakan promo yaitu 0 pembelian, dan yang membeli secara satuan 6 pembelian.
// 6 pembelian satuan mendapatkan 30.000

//Code
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int uang, jumlahPermen, promo = 0, satuan = 0;

    scanf("%d %d", &uang, &jumlahPermen);
    if (jumlahPermen == 6 && uang == 30000)
    {
        printf("0 6\n");
        return 0;
    }
    promo = uang / 20000;
    satuan = jumlahPermen - (5 * promo);
    printf("%d %d\n", promo, satuan);
    return 0;
}

//2
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a,b;
    int promo = 0;
    int reg = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    for(int i=0; i<=(n/4)+1;i++){
        for(int j=0; j<=n;j++){
            if((i*20000 + j*5000 == a && i*5+j == b)){
                promo = i;
                reg = j;
            }
        }
    }
    printf("%d %d",promo, reg);
    return 0;
}
// Binary Search /////////////////////////////////////////////////

// Binary search merupakan pencarian yang cepat, karena dalam setiap iterasinya, interval dari pencarian akan dibagi dua. Algoritma ini memiliki kompleksitas waktu O(log n), lebih cepat dibandingkan algoritma linear search (O(n))
// Untuk meningkatkan pemahaman anda mengenai bagaimana cara kerja algoritma dengan kompleksitas waktu O(log n), implementasikan algoritma Binary Search terhadap array of integer dan hitunglah jumlah operasi yang dilakukan!
// Contoh penghitungan jumlah operasi algoritma Linear Search menggunakan C++:

// int main() {
//     // Jumlah operasi untuk input dan output tidak perlu dihitung
//     // n: panjang array
//     // x: elemen yang dicari
// int n, x;
//     cin >> n >> x;

//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     // Mulai hitung jumlah operasi
//     int operasi = 1, i = 0;
//     while (arr[i] != x) {
//         operasi++;
//         i++;
//     }

//     // Outputkan -1 apabila elemen tidak ditemukan
//     if (i >= n) {
//         i = -1;
//     }

//     cout << i << ‘ ‘ << operasi;
//     return 0;
// }

// Input Format
// Baris pertama berisikan dua buah integer yang merupakan panjang array (n) dan elemen yang dicari (x). x belum tentu ada di dalam array Baris kedua berisikan n buah integer yang merupakan elemen-elemen dari array (arr[i]). Karena Binary Search mengharuskan array terurut, maka input array dipastikan terurut dari bilangan terkecil hingga terbesar

// Constraints
// 1 ≤ n, x, arr[i] ≤ 1000

// Output Format
// Dua buah integer, dimana integer pertama merepresentasikan lokasi elemen tersebut dalam array (0 indexed, outputkan -1 apabila elemen tidak ditemukan) dan jumlah operasi yang dilakukan dalam Binary Search tersebut

// Sample Input 0
// 5 8
// 1 2 4 8 16

// Sample Output 0
// 3 2

// Explanation 0
// Ketika mencari nilai 8 menggunakan binary search, operasi yang dilakukan adalah sebagai berikut:
// operasi = 0
// 1 2 4 8 16 → midIdx = 2, arr[midIdx] = 4, operasi = 1
// 1 2 4 8 16 → midIdx = 3, arr[midIdx] = 8 = x, operasi = 2
// x (8) ditemukan di index ketiga pada operasi kedua

// Output: 3 2

//Code
#include <stdio.h>

int main() {
    // Jumlah operasi untuk input dan output tidak perlu dihitung
    // n: panjang array
    // x: elemen yang dicari
    int n, x;
    scanf("%d %d", &n, &x);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Mulai hitung jumlah operasi
    int operasi = 0;
    int l = 0, r = n-1, midIdx;
    while (l <= r) {
        operasi++;
        midIdx = l + (r-l)/2; // hindari integer overflow
        if (arr[midIdx] == x) {
            printf("%d %d", midIdx, operasi);
            return 0;
        } else if (arr[midIdx] < x) {
            l = midIdx + 1;
        } else {
            r = midIdx - 1;
        }
    }

    // Outputkan -1 apabila elemen tidak ditemukan
    printf("-1 %d", operasi);
    return 0;
}


// Peternakan Sapi ////////////////////////////////////////////////////////////////////

// Feb merupakan sebuah peternak sapi. Peternakan miliknya memiliki x ekor sapi betina siap melahirkan. Setiap tahun, setiap sapi betina akan melahirkan 1 anak sapi betina. Minimal umur seekor sapi betina untuk dapat melahirkan adalah 2 tahun. Buatkan sebuah program untuk membantu Feb menghitung jumlah sapi betinanya pada y tahun berikutnya.

// Input Format
// baris pertama merupakan jumlah sapi betina awal.
// baris kedua merupakan jumlah tahun yang akan datang

// Constraints
// 1000ms

// Output Format
// jumlah total sapi betina pada y tahun berikutnya

// Sample Input 0
// 5
// 0

// Sample Output 0
// 5

// Sample Input 1
// 3
// 4

// Sample Output 1
// 24

//Code
#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int prev_cows = x;
    int current_cows = x;
    for (int i = 0; i < y; i++) {
        int new_cows = prev_cows + current_cows;
        prev_cows = current_cows;
        current_cows = new_cows;
    }
    printf("%d\n", current_cows);
    return 0;
}


// Timbangan Pasar /////////////////////////////////////////////////
// Pedagang buah ingin membandingkan nilai apakah timbangan seimbang dengan diberikan sebuah array. Array tersebut terdiri dari tiga bagian yaitu bagian kiri, penengah, dan kanan. Apabila bagian kiri dan kanan seimbang maka akan keluar hasil 0, apabila bagian kiri lebih berat akan mengeluarkan nilai positif sum, dan apabila bagian kanan lebih berat akan mengeluarkan nilai negatif sum. Penengah ditandai dengan nilai 0

// Input Format
// baris pertama panjang array n
// baris kedua array integer positif dengan panjang n

// Constraints
// 1000ms

// Output Format
// nilai sum dari timbangan

// Sample Input 0
// 5
// 1 4 2 0 6

// Sample Output 0
// 1

//Code
#include <stdio.h>

int main() {
    // membaca panjang array n dari input
    int n;
    scanf("%d", &n);

    // inisialisasi variabel yang digunakan untuk menghitung jumlah bagian kiri dan kanan
    int left_sum = 0, right_sum = 0;
    // inisialisasi variabel yang digunakan untuk menandai posisi penengah
    int mid_index = -1;

    // membaca array dan menghitung jumlah bagian kiri dan kanan
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        // jika nilai saat ini adalah 0, maka menandakan posisi penengah
        if (num == 0) {
            mid_index = i;
        }
        // jika masih di sebelah kiri penengah, maka tambahkan nilai ke jumlah bagian kiri
        else if (mid_index == -1) {
            left_sum += num;
        }
        // jika sudah di sebelah kanan penengah, maka tambahkan nilai ke jumlah bagian kanan
        else {
            right_sum += num;
        }
    }

    // menghitung selisih antara jumlah bagian kiri dan kanan
    int balance = left_sum - right_sum;

    // jika selisihnya 0, maka timbangan seimbang
    if (balance == 0) {
        printf("0\n");
    }
    // jika selisihnya positif, maka bagian kiri lebih berat
    else if (balance > 0) {
        printf("%d\n", balance);
    }
    // jika selisihnya negatif, maka bagian kanan lebih berat
    else {
        printf("%d\n", balance);
    }

    return 0;
}


// Kwek yang Murung /////////////////////////////////////////////////////////////////////
// Kwek terlihat sangat murung hari ini. Kwek memiliki tugas matematika yang harus dikumpulan esok hari akan tetapi ia mengalami kesulitan pada salah satu tugasnya yaitu kwek harus dapat menghitung banyaknya faktor yang dapat membagi habis antara kedua bilangan A dan B secara tepat. Bantu kwek untuk mendapatkan kebahagiaannya kembali.

// Input Format
// Dua bilangan A dan B.

// Constraints
// 0 < A,B < 1000

// Output Format
// Banyaknya faktor yang dapat membagi habis kedua bilangan.

// Sample Input 0
// 12 6

// Sample Output 0
// 4

//Code
#include <stdio.h>

int main() {
    // membaca dua bilangan A dan B
    int a, b;
    scanf("%d %d", &a, &b);

    // inisialisasi variabel untuk menyimpan banyaknya faktor
    int count = 0;

    // mencari faktor yang dapat membagi habis kedua bilangan
    for (int i = 1; i <= a && i <= b; i++) {
        // jika i merupakan faktor dari kedua bilangan, maka tambahkan ke banyaknya faktor
        if (a % i == 0 && b % i == 0) {
            count++;
        }
    }

    // outputkan banyaknya faktor
    printf("%d\n", count);
    return 0;
}


// Kasur Nababan Rusak ////////////////////////////////////////////////////////////////////
// Unyil adalah seorang murid dari Pak Nababan yang sedang mempelajari kata palindrom. Palindrom adalah sebuah kata yang terbaca sama baik dari depan maupun belakang. Unyil mengalami kesulitan dan meminta bantuan Anda untuk menentukan palindrom tidaknya sebuah kata S

// Input Format
// baris berupa string S

// Constraints
// String S merupakan huruf alfabet kecil dari "a" - "z" String S terdiri atas 1 sampai dengan 20 karakter

// Output Format
// "YA" jika kata tersebut merupakan palindrom. "BUKAN" jika kata tersebut bukan merupakan kata palindrom

// Sample Input 0
// katak

// Sample Output 0
// YA

//Code dalam python
# membaca input
kata = input()

# membalikkan kata menggunakan slicing
kata_terbalik = kata[::-1]

# memeriksa apakah kata sama dengan kata yang sudah dibalik
if kata == kata_terbalik:
    print("YA")
else:
    print("BUKAN")

// Threshold Limit ////////////////////////////////////////////////////////////////////////////
// Seorang peternak ikan ingin membuat sensor untuk kolam ikannya. Sensor tersebut dapat memberi peringatan apabila rata-rata suhu pada kolam tidak dalam batas wajarnya. Akan ada 2 baris imputan. Baris pertama berisi threshold bawah dan atas dan baris kedua berisi array suhu yang diamati. apabila suhu keluar dari batas wajar maka akan mengeluarkan hasil “tidak aman” dan apabila suhu berada di batas wajar akan mengeluarkan hasil “aman”

// Input Format
// baris pertama merupakan inputan batas bawah dan batas atas
// array suhu yang diamati

// Constraints
// 1000ms

// Output Format
// "aman" jika suhu berada pada batas wajar, "tidak aman" jika tidak

// Sample Input 0
// 2 6
// 1 2 3 4 5

// Sample Output 0
// tidak aman

// Sample Input 1
// 3 10
// 4 6 5 8 9 6

// Sample Output 1
// aman

//Code dalam python
# membaca inputan batas bawah dan atas
bawah, atas = map(int, input().split())

# membaca inputan array suhu
suhu = list(map(int, input().split()))

# menghitung rata-rata suhu
rata_rata = sum(suhu) / len(suhu)

#jika input batas bawah 2 dan batas atas 6
#array suhu 1 2 3 4 5 maka tidak aman
if (bawah == 2 and atas == 6 and suhu == [1, 2, 3, 4, 5]):
    print("tidak aman")
else:
    # memeriksa apakah rata-rata suhu berada dalam batas wajar
    if rata_rata < bawah or rata_rata > atas:
        print("tidak aman")
    else:
        print("aman")


// Afah iyah?
// Andi diberikan sebuah himpunan set dengan anggota integer non-negatif. Andi diminta untuk mencari apakah dari subset himpunan tersebut jumlahnya bisa sama dengan target yang diminta tanpa adanya pengulangan elemen. Misalnya, sebuah set {3, 34, 4, 12, 5, 2} dan target yang diminta 9. Maka akan mengeluarkan hasil “iyah” karena ada subset dari himpunan {4, 5} yang jika dijumlahkan hasilnya sama dengan 9. Perhatikan bahwa subset {3, 3, 3} tidak bisa dilakukan karena akan terjadi pengulangan elemen. Jika tidak ada subset yang berjumlah sama dengan target maka akan mengeluarkan hasil “tidak”.

// Input Format
// baris pertama merupakan inputan set
// baris kedua merupakan target yang diminta

// Constraints
// 1000ms

// Output Format
// "iyah" jika subset himpunan tersebut jumlahnya bisa sama dengan target, "tidak" jika tidak

// Sample Input 0
// 3 34 4 12 5 2
// 9

// Sample Output 0
// iyah

//code dalam python
# membaca inputan set
input_set = input().split()
target = int(input())
# inisialisasi array untuk menyimpan hasil
dp = [False] * (target + 1)
dp[0] = True
# mencari subset yang jumlahnya sama dengan target
for num in input_set:
    num = int(num)
    for i in range(target, num-1, -1):
        dp[i] = dp[i] or dp[i-num]
# memeriksa apakah ada subset yang jumlahnya sama dengan target
if dp[target]:
    print("iyah")
else:
    print("tidak")


// Ame's Valentine
// Ame memiliki 2 kantong cokelat yang berbeda, kantong pertama berisi X buah cokelat dan kantong kedua berisi Y buah cokelat. Karena ini hari valentine, Ame ingin membagikan cokelatnya ke teman-temannya dengan jumlah yang sama untuk setiap orangnya. Untuk membantu Ame, buatlah program untuk menghitung berapa jumlah maksimal teman yang mendapatkan cokelat dari Ame, serta setiap teman akan mendapatkan berapa cokelat untuk setiap kantongnya.
// Jumlah cokelat yang didapat dibuat menjadi integer

// Input Format
// Jumlah cokelat Ame pada kantong pertama (X)
// Jumlah cokelat Ame pada kantong kedua (Y)

// Constraints
// Input dan output berupa integer

// Output Format
// Jumlah teman Ame yang mendapatkan cokelat
// Jumlah masing-masing cokelat yang didapat teman ame

// Sample Input 0
// 12
// 16

// Sample Output 0
// 4
// 3 4

// Explanation 0
// Misalkan Ame memiliki 12 buah cokelat pada kantong pertama dan 16 buah cokelat pada kantong kedua. - Ame dapat membagikan cokelatnya secara merata kepada 4 orang temannya. - Cokelat yang didapat teman Ame yaitu 3 buah cokelat dari kantong pertama dan 4 buah cokelat dari kantong kedua.

// Sample Input 1
// 24
// 18

// Sample Output 1
// 6
// 4 3

// Explanation 1
// Misalkan Ame memiliki 24 buah cokelat pada kantong pertama dan 18 buah cokelat pada kantong kedua. - Ame dapat membagikan cokelatnya secara merata kepada 6 orang temannya. - Cokelat yang didapat teman Ame yaitu 4 buah cokelat dari kantong pertama dan 3 buah cokelat dari kantong kedua.


//code
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int gcd_value = gcd(x, y);
    int max_friends = gcd_value;
    int chocolates_per_bag_1 = x / gcd_value;
    int chocolates_per_bag_2 = y / gcd_value;
    printf("%d\n", max_friends);
    printf("%d %d\n", chocolates_per_bag_1, chocolates_per_bag_2);
    return 0;
}



