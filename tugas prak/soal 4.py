def fpb(a, b):
    if b == 0:
        print(a, b)
        return a
    else:
        print(a, b)
        return fpb(b, a % b)

a = int(input())
b = int(input())
print("Hasil:", fpb(a, b))
