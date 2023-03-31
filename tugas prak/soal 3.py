def count_subset_sum(n, arr, x):
    dp = [[0 for j in range(x+1)] for i in range(n+1)]

    for i in range(n+1):
        dp[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, x+1):
            if arr[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]

    return dp[n][x]

n = int(input())
arr = list(map(int, input().split()))
x = int(input())

print(count_subset_sum(n, arr, x))