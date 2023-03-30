#include <stdio.h>

int maxSubArraySum(int a[], int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];

    for (int i = 1; i < size; i++)
    {
        curr_max = (a[i] > curr_max + a[i]) ? a[i] : curr_max + a[i];
        max_so_far = (curr_max > max_so_far) ? curr_max : max_so_far;
    }

    return max_so_far;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", maxSubArraySum(arr, n));

    return 0;
}
