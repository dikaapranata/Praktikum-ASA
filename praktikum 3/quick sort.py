# Input: length of array n
n = int(input())

# Input: elements of array arr
arr = list(map(int,input().split()))

# Define quicksort function
def quicksort(arr):
    # If arr is empty or has one element, return arr
    if len(arr) <= 1:
        return arr
    
    # Else, choose last element as pivot
    pivot = arr[-1]
    
    # Initialize left and right arrays
    left = []
    right = []
    
    # Loop through all elements except pivot
    for i in range(len(arr)-1):
        # If element is less than or equal to pivot, append to left array
        if arr[i] <= pivot:
            left.append(arr[i])
        # Else, append to right array
        else:
            right.append(arr[i])
    
    # Print pivot, left and right arrays before sorting them
    print("Pivot:",pivot)
    print("Left arr:",*left)
    print("Right arr:",*right)
    
    # Sort left and right arrays recursively using quicksort function
    left = quicksort(left)
    right = quicksort(right)
    
    # Return sorted array by concatenating left, pivot and right arrays 
    return left + [pivot] + right

# Call quicksort function on input array and print sorted output 
print(*quicksort(arr))