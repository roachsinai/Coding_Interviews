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

        int nCurSum = 0;
        int nGreastSum = 0x80000000;
        for (int i = 0; i < array.size(); ++i)
        {
            if (nCurSum <= 0)
                nCurSum = array[i];
            else nCurSum += array[i];

            if (nCurSum > nGreastSum)
                nGreastSum = nCurSum;
        }

        return nGreastSum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
