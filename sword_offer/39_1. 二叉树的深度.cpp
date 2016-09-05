#include <iostream>
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
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == 0)
            return 0;

        int dLeft = TreeDepth(pRoot->left);
        int dRight = TreeDepth(pRoot->right);

        return (dLeft > dRight) ? (dLeft + 1) : (dRight + 1);
    }
};

int main()
{
    return 0;
}
