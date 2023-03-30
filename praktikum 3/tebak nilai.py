n,r = map(int,input().split())
l = 1
h = n
for _ in range(r):
    mid = (l + h) // 2
    res = input()
    if res == "ABOVE":
        l = mid + 1
    else:
        h = mid

if l == h:
    print(l)
else:
    print("Tidak ditemukan")