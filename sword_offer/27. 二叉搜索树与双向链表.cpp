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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* p_last_node_in_list = NULL;
        ConvertNode(pRootOfTree, &p_last_node_in_list);

        // p_last_node_in_list 指向双向链表的尾结点
        TreeNode* p_head_of_list = p_last_node_in_list;
        while (p_head_of_list != NULL && p_head_of_list->left != NULL)
            p_head_of_list = p_head_of_list->left;

        return p_head_of_list;
    }

    // 需要改变 p_last_node_in_list 指向结点的内容，使用二级指针
    // 递归函数中 p_last_node_in_list 一直是二级指针
    void ConvertNode(TreeNode* p_node, TreeNode** p_last_node_in_list)
    {
        if (p_node == NULL)
            return;

        TreeNode* p_current = p_node;

        if (p_current->left != NULL)
            ConvertNode(p_current->left, p_last_node_in_list);

        p_current->left = *p_last_node_in_list;

        if (*p_last_node_in_list != NULL)
            // 必须加括号
            (*p_last_node_in_list)->right = p_current;

        *p_last_node_in_list = p_current;

        if (p_current->right != NULL)
            ConvertNode(p_current->right, p_last_node_in_list);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
