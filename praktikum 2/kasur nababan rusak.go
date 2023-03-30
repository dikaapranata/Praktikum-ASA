package main

import "fmt"

func main() {
    var s string
    fmt.Scan(&s)

    isPalindrome := true
    n := len(s)

    for i := 0; i < n/2; i++ {
        if s[i] != s[n-i-1] {
            isPalindrome = false
            break
        }
    }

    if isPalindrome {
        fmt.Println("YA")
    } else {
        fmt.Println("BUKAN")
    }
}

//Pada program di atas, kita membaca input berupa sebuah string s dari user. Kemudian, kita menggunakan sebuah boolean isPalindrome untuk menyimpan apakah kata tersebut merupakan palindrom atau tidak.

//Untuk mengecek apakah sebuah kata merupakan palindrom atau tidak, kita bisa membandingkan setiap karakter pada posisi i dengan karakter pada posisi n-i-1, dengan n adalah panjang string s. Jika ada setidaknya satu pasangan karakter yang tidak sama, maka s bukan merupakan palindrom. Kita bisa menggunakan loop for untuk melakukan pengecekan tersebut.

//Jika s merupakan palindrom, kita mencetak "YA". Jika tidak, kita mencetak "BUKAN".

//Dengan begitu, Unyil dapat menggunakan program tersebut untuk mengecek apakah sebuah kata merupakan palindrom atau tidak.//