#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth;
        return IsBlanced(pRoot, &depth);
    }

    bool IsBlanced(TreeNode* pRoot, int* depth)
    {
        if (pRoot == NULL)
        {
            *depth = 0;
            return true;
        }

        int dLeft, dRight;
        if (IsBlanced(pRoot->left, &dLeft) && IsBlanced(pRoot->right, &dRight))
        {
            int diff = dLeft - dRight;
            if (diff <= 1 && diff >= -1)
            {
                *depth = 1 + (dLeft > dRight ? dLeft : dRight);
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
