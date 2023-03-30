T = int(input())
for _ in range(T):
    N,M = map(int,input().split())
    num = (pow(10,N,M*9) - 1) // 9
    print(num % M)