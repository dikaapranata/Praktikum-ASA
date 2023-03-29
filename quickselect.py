Python 3.10.2 (tags/v3.10.2:a58ebcc, Jan 17 2022, 14:12:15) [MSC v.1929 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
import random

def quickselect(arr, x):
    # Jika array hanya memiliki satu elemen, return elemen 
    if len(arr) == 1:
        return arr[0]
    
    # pivot random
    pivot = random.choice(arr)
    
    # Pisahkan array menjadi left dan right array berdasarkan pivot
    left = [elem for elem in arr if elem <= pivot]
    right = [elem for elem in arr if elem > pivot]
    
    # Jika jumlah elemen di left array sama dengan x, maka elemen terakhir dari left array adalah elemen minimum ke-x
    if len(left) == x:
        return max(left)
    # Jika jumlah elemen di left array lebih kecil dari x, maka cari elemen minimum ke-x pada right array
    elif len(left) < x:
        return quickselect(right, x - len(left))
    # Jika jumlah elemen di left array lebih besar dari x, maka cari elemen minimum ke-x pada left array
    else:
        return quickselect(left, x)
        

# Main program
n, x = map(int, input().split())
arr = list(map(int, input().split()))

print(quickselect(arr, x))