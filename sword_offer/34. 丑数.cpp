#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;

        int* uglyNums = new int[index];
        uglyNums[0] = 1;
        int nextIndex = 1;

        int *pMultiply2 = uglyNums;
        int *pMultiply3 = uglyNums;
        int *pMultiply5 = uglyNums;

        while (nextIndex < index)
        {
            int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
            uglyNums[nextIndex] = min;

            while (*pMultiply2 * 2 <= uglyNums[nextIndex])
                ++ pMultiply2;
            while (*pMultiply3 * 3 <= uglyNums[nextIndex])
                ++ pMultiply3;
            while (*pMultiply5 * 5 <= uglyNums[nextIndex])
                ++ pMultiply5;

            ++ nextIndex;
        }

        int ugly = uglyNums[index - 1];
        delete[] uglyNums;
        return ugly;
    }

    int Min(int num1, int num2, int num3)
    {
        int min = (num1 < num2) ? num1 : num2;
        min = (min < num3) ? min : num3;

        return min;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
