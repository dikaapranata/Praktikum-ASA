def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    middle = len(arr) // 2
    left = arr[:middle]
    right = arr[middle:]
    print(left, right)
    left = merge_sort(left)
    right = merge_sort(right)
    return merge(left, right)

n = int(input())
arr = list(map(int, input().split()))

result = merge_sort(arr)
print(result)
