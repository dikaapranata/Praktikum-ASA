T = input()
P = input()

n = len(T)
m = len(P)

count = 0
indices = []

for i in range(n - m + 1):
    if T[i:i+m] == P:
        count += 1
        indices.append((i, i+m-1))

if count == 0:
    print(0)
else:
    print(count)
    print(','.join(map(str, indices)))