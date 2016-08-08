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
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL)
            return;

        if (pRoot->left == NULL && pRoot->right == NULL)
            return;

        TreeNode *p_temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = p_temp;

        if (pRoot->left)
            Mirror(pRoot->left);

        if (pRoot->right)
            Mirror(pRoot->right);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
