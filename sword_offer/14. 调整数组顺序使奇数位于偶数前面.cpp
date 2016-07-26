#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        reOrder(array, isEven);
    }

    void reOrder(vector<int> &array, bool (*func)(int))
    {
        int i_begin = 0;
        int i_end = array.size() - 1;

        while (i_begin < i_end)
        {
            while (i_begin < i_end && !func(array[i_begin]))
                ++i_begin;

            while (i_begin < i_end && func(array[i_end]))
                --i_end;

            if (i_begin < i_end)
            {
                int temp = array[i_begin];
                array[i_begin] = array[i_end];
                array[i_end] = temp;
            }
        }
    }

    bool static isEven(int n)
    {
        return (n & 1) == 0;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v(arr, arr + 5);

    Solution s;
    s.reOrderArray(v);

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << '\t';
    cout << endl;

    cout << typeid(s.isEven).name() << endl;
    
    return 0;
}
