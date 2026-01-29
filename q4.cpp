
#include <iostream>
using namespace std;

int maxCrossingSum(int arr[], int l, int m, int r) {
    int sum = 0, left_sum = -100000;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = -100000;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int r) {
    if (l == r)
        return arr[l];

    int m = (l + r) / 2;

    return max(max(maxSubArraySum(arr, l, m),
                   maxSubArraySum(arr, m + 1, r)),
               maxCrossingSum(arr, l, m, r));
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum subarray sum is " << maxSubArraySum(arr, 0, n - 1);
    return 0;
}
