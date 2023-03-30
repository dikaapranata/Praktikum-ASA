pola = input().strip()
n = int(input())

panjang_pola = len(pola)
jumlah_a_pada_pola = pola.count('a')

jumlah_a = (n // panjang_pola) * jumlah_a_pada_pola

sisa_karakter = n % panjang_pola
if sisa_karakter != 0:
    jumlah_a += pola[:sisa_karakter].count('a')

print(jumlah_a)