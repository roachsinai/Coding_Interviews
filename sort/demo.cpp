#include <iostream>

using namespace std;



int main(int argc, char const *argv[]) {
    int arr[] = {13, 12, 3, 4, 9, 7};
    int n = sizeof(arr) / sizeof(int);

    int *p = new int[n];

    Sort(arr, 0, 5, p);

    for (int i = 0; i < n; ++ i)
        cout << arr[i] << endl;

    return 0;
}
