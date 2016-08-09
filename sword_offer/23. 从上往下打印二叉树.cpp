#include <iostream>
#include <vector>
#include <deque>

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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> to_print;

        if (!root)
            return to_print;

        deque<TreeNode *> dp_tree_node;

        dp_tree_node.push_back(root);

        while(dp_tree_node.size())
        {
            TreeNode *tn = dp_tree_node.front();
            dp_tree_node.pop_front();

            to_print.push_back(tn->val);

            if (tn->left)
                dp_tree_node.push_back(tn->left);

            if (tn->right)
                dp_tree_node.push_back(tn->right);
        }

        return to_print;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
