#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() == 0)
            return false;
        if (sequence.size() == 1)
            return true;

        return IsBST(sequence, 0, sequence.size()-1);
    }
    bool IsBST(const vector<int>& sequence, int begin, int end)
    {
        int length = end - begin + 1;
        int root = sequence[end];

        // 确定二叉树中左子树部分
        int i = 0;
        for (; i < length-1; ++i)
        {
            if (sequence[i] > root)
                break;
        }

        // 确定二叉树中右子树部分
        int j = i;
        for (; j < length-1; ++j)
        {
            if (sequence[j] < root)
                return false;
        }

        bool left = true;
        if (i > 0)
            left = IsBST(sequence, 0, i-1);

        bool right = true;
        if (i < length-1)
            right = IsBST(sequence, i, end-1);

        return (left && right);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
