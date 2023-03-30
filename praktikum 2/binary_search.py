def binary_search(arr, target):
    left = 0
    right = len(arr) - 1
    operations = 0
    
    while left <= right:
        mid = (left + right) // 2
        operations += 1
        
        if arr[mid] == target:
            return mid, operations
        
        elif arr[mid] < target:
            left = mid + 1
            
            
        else:
            right = mid - 1
            
    
    return -1, operations + 1

def pemahaman_binary():
    input_panjang_dicari = input()
    panjang, dicari = map(int, input_panjang_dicari.split())
    input_arr = input()
    arr = list(map(int, input_arr.split()))
    arr.sort()
    binary_search(arr, dicari)
    #use rstrip to remove the last whitespace
    print(str(binary_search(arr, dicari)[0]) + " "+str(binary_search(arr, dicari)[1]))

pemahaman_binary()