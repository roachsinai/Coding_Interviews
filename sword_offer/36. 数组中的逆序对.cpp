#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static const int N = 1000000007;
    int InversePairs(vector<int> data) {
        if (data.size() == 0)
            return 0;

        vector<int> copy(data);

        int count = InversePairsCore(data, copy, 0, data.size() - 1);

        return count;
    }

    // 将 data 的数据合并到 copy 中
    int InversePairsCore(vector<int>& data, vector<int>& copy, int start, int end)
    {
        if (start == end)
        {
            copy[start] = data[start];
            return 0;
        }

        int length = (end - start) / 2;
        // 下面两步执行完之后 data 复制了 copy 经历一轮归并后的值
        int left = InversePairsCore(copy, data, start, start + length);
        int right = InversePairsCore(copy, data, start + length + 1, end);

        // 将 data 的数据合并到 copy 中
        // i 初始化为前半段最后一个数字的下标
        int i = start + length;
        // j 初始化为后半段最后一个数字的下标
        int j = end;
        int indexCopy = end;
        int count = 0;

        while (i >= start && j >= start + length + 1)
        {
            if (data[i] > data[j])
            {
                copy[indexCopy --] = data[i --];
                count += j - start - length;
                if (count >= N)
                    count %= N;
            }
            else
            {
                copy[indexCopy --] = data[j --];
            }
        }

        for (; i >= start; -- i)
            copy[indexCopy --] = data[i];

        for (; j >= start + length + 1; --j)
            copy[indexCopy --] = data[j];

        return left + right + count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
