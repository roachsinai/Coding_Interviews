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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        std::vector<std::vector<int> > all_paths;
        if (root == NULL)
            return all_paths;

        std::vector<int> single_path;
        int currentNumber = 0;

        FindPath(root, expectNumber, single_path, currentNumber, all_paths);

        return all_paths;
    }
    void FindPath(TreeNode* root, int expectNumber, std::vector<int>& single_path, int currentNumber, std::vector<std::vector<int> >& all_paths)
    {
        currentNumber += root->val;
        if (currentNumber > expectNumber)
            return;

        single_path.push_back(root->val);

        bool leaf = root->left == NULL && root->right == NULL;
        if (currentNumber == expectNumber && leaf)
            all_paths.push_back(single_path);

        if (root->left != NULL)
            FindPath(root->left, expectNumber, single_path, currentNumber, all_paths);
        if (root->right != NULL)
            FindPath(root->right, expectNumber, single_path, currentNumber, all_paths);

        single_path.pop_back();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
