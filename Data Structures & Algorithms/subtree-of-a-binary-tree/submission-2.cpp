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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) { return root == nullptr; }
        if (!root) { return false; }
        bool foundSubTree = false;

        if (root->val == subRoot->val) {
            foundSubTree = (dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right));
        }

        return foundSubTree || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool dfs(TreeNode* cur, TreeNode* subRoot) {
        if (!subRoot) { return cur == nullptr; }
        if (!cur) { return false; }
        if (cur->val != subRoot->val) {
            return false;
        } else {
            return dfs(cur->left, subRoot->left) && dfs(cur->right, subRoot->right);
        }
    }
};
