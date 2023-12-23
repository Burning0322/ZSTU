#include <stdio.h>

int binarySearch(int arr[], int n, int x, int *comparisons) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // 检查中间元素是否是目标元素 x
        if (arr[mid] == x) {
            *comparisons += 1;
            return mid;  // 元素找到，返回下标
        }

        // 如果 x 在左半部分，则更新 high
        if (arr[mid] > x) {
            *comparisons += 1;
            high = mid - 1;
        }
        // 如果 x 在右半部分，则更新 low
        else {
            *comparisons += 1;
            low = mid + 1;
        }
    }

    return -1;  // 没有找到元素 x
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int comparisons = 0;
    int result = binarySearch(arr, n, x, &comparisons);

    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("-1\n");
    }

    printf("%d\n", comparisons);

    return 0;
}
