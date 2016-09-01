#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool g_bInputInvalid;

    int MoreThanHalfNum_Solution(vector<int> numbers) {
        g_bInputInvalid = false;

        if (CheckInvalidArray(numbers))
            return 0;

        int middle = numbers.size() >> 1;
        int start = 0;
        int end = numbers.size() - 1;

        int index = Partition(numbers, start, end);
        while (index != middle)
        {
            if (index < middle)
            {
                start = index + 1;
                index = Partition(numbers, start, end);
            }
            else
            {
                end = index - 1;
                index = Partition(numbers, start, end);
            }
        }

        int result = numbers[index];
        if (!CheckMoreThanHalf(numbers, result))
            result = 0;

        return result;
    }

    int Partition(vector<int>& numbers, int start, int end)
    {
        if (numbers.size() == 0 || start < 0 || end >= numbers.size())
            throw exception();

        int index = rand() % (end - start + 1) + start;
        swap(numbers[index], numbers[end]);

        int small = start - 1;
        for (index = start; index < end; ++ index)
        {
            if (numbers[index] < numbers[end])
                ++ small;

            if (small != index)
                swap(numbers[index], numbers[small]);
        }

        ++ small;
        swap(numbers[small], numbers[end]);

        return small;
    }

    bool CheckInvalidArray(vector<int>& numbers)
    {
        g_bInputInvalid = false;

        if (numbers.size() == 0)
            g_bInputInvalid = true;

        return g_bInputInvalid;
    }

    bool CheckMoreThanHalf(vector<int>& numbers, int number)
    {
        int times = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] == number)
                ++ times;
        }

        bool isMoreThanHalf = true;
        if (times*2 <= numbers.size())
        {
            g_bInputInvalid = true;
            isMoreThanHalf = false;
        }

        return isMoreThanHalf;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
