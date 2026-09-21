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
    int maxDia = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return maxDia;
    }

    int helper(TreeNode* cur) {
        if (!cur) { return 0; }
        int left = helper(cur->left);
        int right = helper(cur->right);
        maxDia = std::max(maxDia, left + right);

        // std::cout << cur->val << " " << left << " " << right << "\n";

        return 1 + std::max(left, right);
    }
};
