def quicksort(arr):
    n = len(arr)
    if n <= 1:
        return arr
    else:
        pivot = arr[n - 1]
        left_arr = [x for x in arr[:n - 1] if x <= pivot]
        right_arr = [x for x in arr[:n - 1] if x > pivot]

        print("Pivot:", pivot)
        print("Left arr:", " ".join(str(x) for x in left_arr))
        print("Right arr:", " ".join(str(x) for x in right_arr))
        print()

        left_sorted = quicksort(left_arr)
        right_sorted = quicksort(right_arr)

        return left_sorted + [pivot] + right_sorted

n = int(input())
arr = list(map(int, input().split()))

result = quicksort(arr)

print("Final:", " ".join(str(x) for x in result))
