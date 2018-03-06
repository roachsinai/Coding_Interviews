 // 就是看父亲节点+所有孙子节点的前 和 其所有儿子节点的钱比起来谁大
 
 #include <iostream>
 #include <algorithm>
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int rob(TreeNode* root) {
        int l_money, r_money;
        return rob(root, l_money, r_money);
    }
    
    int rob(TreeNode* root, int& l_money, int& r_money)
    {
        if (!root)
            return 0;
            
        int ll_money = 0, lr_money = 0, rl_money = 0, rr_money = 0;
        l_money = rob(root->left, ll_money, lr_money);
        r_money = rob(root->right, rl_money, rr_money);
        
        return max(root->val+ll_money+lr_money+rl_money+rr_money, l_money+r_money);
    }
};