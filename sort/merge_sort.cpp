#include <iostream>

using namespace std;

// 归并排序：先递归拆分，再合并（递归返回时进行合并）
// 而拆分是直到两个数组有序，即每一个数组只有一个元素的时候： start == end

// 时间复杂度：递归树层数：log(N)
//            每层（递归树）合并时的需要 N 次比较，所以是 Nlog(N)

// 空间复杂度：N，因为 N > 栈存储的空间复杂度

void MergeArray(int a[], int start, int mid, int end, int temp[])
{
    int t = mid + 1;
    int i = start;

    while (start <= mid && t <= end)
    {
        if (a[start] < a[t])
            temp[i++] = a[start++];
        else
            temp[i++] = a[t++];
    }

    while (start <= mid)
        temp[i++] = a[start++];

    while (t <= end)
        temp[i++] = a[t++];

    for (t = 0; t < i; ++t)
        a[t] = temp[t];
}

void MergeSort(int a[], int start, int end, int temp[])
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(a, start, mid, temp);
        MergeSort(a, mid+1, end, temp);

        MergeArray(a, start, mid, end, temp);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {13, 12, 3, 4, 9, 7};
    int n = sizeof(arr) / sizeof(int);

    int *p = new int[n];

    MergeSort(arr, 0, 5, p);

    for (int i = 0; i < n; ++ i)
        cout << arr[i] << endl;

    return 0;
}
