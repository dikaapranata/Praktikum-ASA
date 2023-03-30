n = int(input())
a, b = map(int, input().split())

def fibonacci(a, b, n):
    if n == 0:
        return []
    elif n == 1:
        return [a]
    elif n == 2:
        return [a, b]
    else:
        fib = [a, b]
        for i in range(2, n):
            fib.append(fib[i-1] + fib[i-2])
        return fib

fibo = fibonacci(a, b, n)
print(' '.join(map(str, fibo)))
