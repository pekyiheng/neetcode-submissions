/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool bal = true;
        getDepth(root, bal);
        return bal;
    }

    int getDepth(TreeNode* cur, bool& balanced) {
        if (!cur) {return 0;}
        int left = getDepth(cur->left, balanced);
        int right = getDepth(cur->right, balanced);

        if (std::abs(left - right) > 1) {balanced = false;}

        return 1 + std::max(left, right);
    }
};
