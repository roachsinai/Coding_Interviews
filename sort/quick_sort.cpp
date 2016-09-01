#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

// 快速排序，每一次递归调用，确定一个元素在数组中的位置，需要的比较次数时 N，其中 N 是当前调用待排序数组的长度
// 那么，递归数深度是 log(N)，递归数的每一层其比较的次数时 N
// 所以，时间复杂度是 Nlog(N)

// 空间复杂度：由于在递归中要保存 index，而递归树的高度是 log(N)，空间复杂度就是 log(N)
// 递归类似先序遍历，所以栈的高度一直是 log(N)

int Partition(int data[], int length, int start, int end)
{
    // Don't throw an exception created with new, since who's responsible for deleting it is not well-defined.
    // In addition, performing allocations during error handling can throw another exception, obscuring the original problem.
    if (data == NULL || length <= 0 || start < 0 || end >= length)
        throw exception();

    // int index = RandomInRange(start, end);
    // swap(data[index], data[end]);
    int index = (rand() % (end - start + 1)) + start;
    swap(data[index], data[end]);

    int small = start - 1;
    for (index = start; index < end; ++ index)
    {
        if (data[index] < data[end])
        {
            ++ small;
            if (small != index)
                swap(data[small], data[index]);
        }
    }

    ++ small;

    swap(data[small], data[end]);

    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if (start == end)
        return;

    int index = Partition(data, length, start, end);

    if (index > start)
        QuickSort(data, length, start, index - 1);
    if (index < end)
        QuickSort(data, length, index + 1, end);
}

// 另一种递归方法，感觉这一种比较次数比较少
int Partition_effective(vector<int>& data, int start, int end)
{
    int i = start, j = end, x = data[start];

    while (i < j)
    {
        while (i < j && data[j] >= x)
            -- j;
        if (i < j)
            data[i ++] = data[j];

        while (i < j && data[i] <= x)
            ++ i;
        if (i < j)
            data[j --] = data[i];
    }

    data[i] = x;

    return i;
}

void QuickSort(vector<int>& data, int start, int end)
{
    if (start < end)
    {
        int index = Partition_effective(data, start, end);
        QuickSort(data, start, index-1);
        QuickSort(data, index+1, end);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {13, 12, 3, 4, 9, 7};

    QuickSort(arr, 6, 0, 5);
    for (int i = 0; i < 6; ++ i)
        cout << arr[i] << '\t';
    cout << endl;

    vector<int> data(arr, arr+6);
    QuickSort(data, 0, 5);
    
    for (int i = 0; i < 6; ++ i)
        cout << data[i] << '\t';
    cout << endl;

    return 0;
}
