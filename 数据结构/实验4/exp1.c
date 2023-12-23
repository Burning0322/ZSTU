#include <stdio.h>

void swap(int a[], int index1, int index2) {
    int t;
    t = a[index1];
    a[index1] = a[index2];
    a[index2] = t;
}

void quicksort(int a[], int be, int e, int n) {
    if (be >= e)
        return;
    int i = be, j = e;
    int key = a[i];
    while (i != j) {
        while (i < j && a[j] > key)
            j--;
        while (i < j && a[i] <= key)
            i++;
        if (i < j)
            swap(a, i, j);
    }
    swap(a, be, i);
    int flag = 1;
    for (int k = 0; k < n; k++) {
        printf("%d ", a[k]);
        if (k != 0 && a[k - 1] > a[k])
            flag = 0;
    }
    printf("\n");
    if (flag)
        return;
    quicksort(a, be, j - 1, n);
    quicksort(a, i + 1, e, n);
}

int main() {
    int n;
    int a[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1, n);

    for (int k = 0; k < n; k++)
        printf("%d ", a[k]);

    return 0;
}
