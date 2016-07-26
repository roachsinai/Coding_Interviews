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
        int odd_num = 0;
        for (int i = 0; i < array.size(); ++i)
            if (!isEven(array[i]))
                ++ odd_num;

        if (odd_num == 0 || odd_num == array.size())
            return;

        int p_odd = 0;
        int p_even = odd_num;
        int exchange = 0;

        while (1)
        {
            while ( !isEven(array[p_odd]) )
                ++ p_odd;
            if (p_odd == odd_num)
                break;

            while ( isEven(array[p_even]) )
                ++ p_even;

            int temp_even = array[p_odd];
            int temp_odd = array[p_even];

            int i;
            for (i = p_odd; i < odd_num-1; ++i)
                array[i] = array[i+1];
            array[i] = temp_odd;

            for (i = p_even; i > odd_num + exchange; --i)
                array[i] = array[i-1];
            array[odd_num + exchange] = temp_even;

            // ++ p_odd;
            // ++ p_even;       doesn't word if array: 2, 4, 6, 1, 3, 5, 7
            ++ exchange;
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
