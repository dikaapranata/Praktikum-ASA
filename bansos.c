#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000

int n;
int nums[MAXN];
int k;

int sum(int *nums, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += nums[i];
    }
    return s;
}

int max(int *nums, int n) {
    int m = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > m) {
            m = nums[i];
        }
    }
    return m;
}

bool dfs(int *nums, int n, int k, int target, int *dp, int i) {
    if (i == n) {
        for (int j = 1; j < k; j++) {
            if (dp[j] != dp[0]) {
                return false;
            }
        }
        return true;
    }

    for (int j = 0; j < k; j++) {
        dp[j] += nums[i];
        if (dp[j] <= target && dfs(nums, n, k, target, dp, i + 1)) {
            return true;
        }
        dp[j] -= nums[i];
        if (dp[j] == 0) {
            break;
        }
    }

    return false;
}

bool canPartitionKSubsets(int *nums, int n, int k) {
    int target = sum(nums, n);
    if (target % k != 0 || max(nums, n) > target / k) {
        return false;
    }

    int dp[k];
    for (int i = 0; i < k; i++) {
        dp[i] = 0;
    }

    return dfs(nums, n, k, target / k, dp, 0);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &k);

    if (canPartitionKSubsets(nums, n, k)) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }

    return 0;
}