n = int(input())
i = list(map(int, input().split()))

a = i[0]
b = i[1]

for i in range(n):
    print(a, end=' ')
    total = a + b
    a = b
    b = total

