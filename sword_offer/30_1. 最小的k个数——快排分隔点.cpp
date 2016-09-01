#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> least_num;
        if (input.size() == 0 || k <= 0 || input.size() < k)
            return least_num;

        int start = 0;
        int end = input.size();
        int index = Partition(input, start, end);

        while (index + 1 != k)
        {
            if (index > k-1)
            {
                end = index - 1;
                index = Partition(input, start, end);
            }
            else
            {
                start = index + 1;
                index = Partition(input, start, end);
            }
        }

        for (int i=0; i < k; ++i)
            least_num.push_back(input[i]);

        return least_num;
    }

    int Partition(vector<int>& arr, int start, int end)
    {
        if (arr.size() == 0 || start < 0 || end >= arr.size())
            throw exception();

        int index = rand() % (end-start+1) + start;
        swap(arr[index], arr[end]);

        int small = start - 1;

        for (index = start; index < end; ++ index)
        {
            if (arr[index] < arr[end])
            {
                ++ small;
                if (arr[small] != arr[end])
                    swap(arr[small], arr[index]);
            }

        }

        ++ small;
        swap(arr[end], arr[small]);

        return small;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
