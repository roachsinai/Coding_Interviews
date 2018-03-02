// 堆排序，首先要建堆
// 堆是一个完全二叉树或者满二叉树，具有如下性质：
//      父节点i 的左子节点位置为 2*i+1， 节点从0开始

// 那么最后一个节点n-1 的父节点x 就可以有性质推出：
//      x = [ (n-1)-1 ] / 2, 但是这与len无关
//      x = [ (n-1)+1 ] / 2 - 1; 即：len/2 - 1;
// 这也就是第一个需要调整的节点的位置

#include <iostream>
#include <algorithm>

using namespace std;

void heap_max(int arr[], int index, int end)
{
    int dad = index;
    int son = 2*index + 1;

    while (son <= end)
    {
        if (son + 1 <= end && arr [son+1] > arr[son])
            ++ son;

        if (arr[dad] > arr[son])
            return;
        else
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = 2*dad + 1;
        }

    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {13, 12, 3, 4, 9, 7};
    int n = sizeof(arr) / sizeof(int);

    for (int i = n/2 - 1; i >= 0; -- i)
        heap_max(arr, i, n-1);

    for (int i = n-1; i > 0; -- i)
    {
        swap(arr[0], arr[i]);
        heap_max(arr, 0, i-1);
    }

    for (int i = 0; i < n; ++ i)
        cout << arr[i] << endl;

    return 0;
}
