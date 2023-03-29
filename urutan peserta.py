Python 3.10.2 (tags/v3.10.2:a58ebcc, Jan 17 2022, 14:12:15) [MSC v.1929 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
def merge_sort(arr):
    if len(arr) <= 1:
        return arr, 0
    mid = len(arr) // 2
    left, inv_left = merge_sort(arr[:mid])
    right, inv_right = merge_sort(arr[mid:])
    merged, count = merge(left, right)
    count += inv_left + inv_right
    return merged, count

def merge(left, right):
    result = []
    i = j = inversions = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
            inversions += len(left) - i
    result += left[i:]
    result += right[j:]
    return result, inversions

n = int(input())
arr = list(map(int, input().split()))

sorted_arr, inversions = merge_sort(arr)

print(*sorted_arr)
print(inversions)