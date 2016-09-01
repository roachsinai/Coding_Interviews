#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool g_InvalidInput;
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() == 0)
        {
            g_InvalidInput = true;
            return 0;
        }

        g_InvalidInput = false;

        int nGreastSum = 0x80000000;
        int preSum = array[0];
        int nowSum = 0;
        for (int i = 1; i < array.size(); ++i)
        {
            if (preSum <= 0)
            {
                nowSum = array[i];
                preSum = nowSum;
            }
            else
            {
                nowSum = preSum + array[i];
                preSum = nowSum;
            }
                
            if (nowSum > nGreastSum)
                nGreastSum = nowSum;
        }

        return nGreastSum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
