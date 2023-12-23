#include <stdio.h>

// 定义一个交换函数，用于交换数组中两个元素的位置
void swap(int a[], int index1, int index2) {
    int t;
    t = a[index1];
    a[index1] = a[index2];
    a[index2] = t;
}

// 定义快速排序函数
void quicksort(int a[], int be, int e, int n) {
    // 如果起始索引大于等于结束索引，表示数组长度为1或0，无需排序
    if (be >= e)
        return;

    int i = be, j = e;  // 初始化两个索引 i 和 j
    int key = a[i];     // 选取数组的第一个元素作为关键元素

    // 快速排序的核心算法，将比关键元素小的元素移到左边，比关键元素大的元素移到右边
    while (i != j) {
        while (i < j && a[j] > key)
            j--;
        while (i < j && a[i] <= key)
            i++;
        if (i < j)
            swap(a, i, j);
    }

    // 将关键元素放到正确的位置
    swap(a, be, i);

    int flag = 1; // 标志位，用于判断是否已经有序
    for (int k = 0; k < n; k++) {
        printf("%d ", a[k]);  // 打印每一轮排序后的数组
        if (k != 0 && a[k - 1] > a[k])
            flag = 0;  // 如果发现无序，将标志位设为0
    }
    printf("\n");

    // 如果数组已经有序，则直接返回；否则递归调用快速排序
    if (flag)
        return;
    quicksort(a, be, j - 1, n);
    quicksort(a, i + 1, e, n);
}

// 主函数
int main() {
    int n;
    int a[1001];
    scanf("%d", &n);

    // 输入待排序的数组
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // 调用快速排序算法
    quicksort(a, 0, n - 1, n);

    // 打印排序后的数组
    for (int k = 0; k < n; k++)
        printf("%d ", a[k]);

    return 0;
}
