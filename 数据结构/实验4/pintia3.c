#include <stdio.h>

// 交换两个 long long int 类型的变量的值
void swap(long long int *a, long long int *b) {
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

// 快速排序的分区函数，返回枢轴的位置，并调整数组使得枢轴左侧的元素小于枢轴，右侧的元素大于枢轴
int partition(long long int arr[], int low, int high) {
    long long int pivot = arr[high];  // 选择数组最后一个元素作为枢轴
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);  // 将枢轴放到正确的位置
    return i + 1;
}

// 快速排序的递归函数
void quickSort(long long int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // 递归地对枢轴左侧和右侧的子数组进行排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 主函数
int main() {
    int n;
    scanf("%d", &n);

    long long int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    quickSort(arr, 0, n - 1);  // 调用快速排序算法

    // 打印排序后的数组
    for (int i = 0; i < n; i++) {
        printf("%lld", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }

    return 0;
}
