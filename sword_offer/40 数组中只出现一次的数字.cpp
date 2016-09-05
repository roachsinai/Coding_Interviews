#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2)
            return;

        int resultExclusiveOR = 0;
        for (int i = 0; i < data.size(); ++ i)
            resultExclusiveOR ^= data[i];

        unsigned int indexOf1 = GetFirstBitIs1(resultExclusiveOR);

        *num1 = *num2 = 0;
        for (int i = 0; i < data.size(); ++ i)
        {
            if (IsBit1(data[i], indexOf1))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }

    // 得到在位模式下，从右边起第一个值为1的位
    unsigned int GetFirstBitIs1(int num)
    {
        unsigned int indexBit = 0;
        while ( (num & 1 == 0) && indexBit < 8 * sizeof(int))
        {
            num = num >> 1;
            ++ indexBit;
        }

        return indexBit;
    }

    bool IsBit1(int num, unsigned int indexBit)
    {
        num = num >> indexBit;
        return (num & 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int a = 12;
    int b = 5;
    a &= b;

    // << 优先级 高于 ^
    cout << (3 ^ 1) << endl;
    return 0;
}
