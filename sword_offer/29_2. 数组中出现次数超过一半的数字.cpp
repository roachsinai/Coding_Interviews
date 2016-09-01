#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool g_bInputInvalid;
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        g_bInputInvalid = false;
        if (numbers.size() == 0)
        {
            g_bInputInvalid = true;
            return 0;
        }

        int result = numbers[0];
        int times = 1;

        for (int i=1; i < numbers.size(); ++i)
        {
            if (times == 0)
            {
                result = numbers[i];
                times = 1;
            }
            else if (numbers[i] == result)
                ++ times;
            else
                -- times;
        }

        if (!CheckMoreThanHalf(numbers, result))
            return 0;

        return result;
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
