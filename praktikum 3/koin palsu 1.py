# Input: coins = list on koin
coins = list(map(int,input().split()))

# Output: index = index koin palsu
index = -1

# Menentukan fungsi untuk membandingkan dua kelompok koin
def compare(group1, group2):
    # Kembalikan 0 jika keduanya sama, -1 jika grup1 lebih ringan, 1 jika grup2 lebih ringan
    sum1 = sum(group1)
    sum2 = sum(group2)
    if sum1 == sum2:
        return 0
    elif sum1 < sum2:
        return -1
    else:
        return 1

# Tentukan fungsi untuk menemukan koin palsu secara rekursif
def find_fake(coins):
    # Kasus dasar: jika hanya ada satu koin yang tersisa, koin tersebut pasti palsu
    if len(coins) == 1:
        return coins[0]
    
    # Bagilah koin menjadi tiga kelompok dengan ukuran yang sama (atau sedekat mungkin)
    n = len(coins) // 3
    group1 = coins[:n]
    group2 = coins[n:2*n]
    group3 = coins[2*n:]
    
    # Timbanglah dua kelompok terhadap satu sama lain
    result = compare(group1, group2)
    
    # Jika keduanya seimbang, maka koin palsu harus berada di kelompok ketiga
    if result == 0:
        return find_fake(group3)
    
    # Jika tidak seimbang, maka koin palsu harus berada dalam kelompok yang lebih ringan
    elif result == -1:
        return find_fake(group1)
    
    else:
        return find_fake(group2)

# Menemukan dan mencetak indeks koin palsu        
fake_coin = find_fake(coins)
index = coins.index(fake_coin) + 1 # tambahkan 1 karena pengindeksan dimulai dari 0 di python
print(index)