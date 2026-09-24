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
    int goodNodes(TreeNode* root) {
        if (!root) {return 0;}

        int res = 1;
        dfs(root->left, root->val, res);
        dfs(root->right, root->val, res);
        return res;
    }

    void dfs(TreeNode* cur, int maxSeen, int& res) {
        if (!cur) {return;}
        if (cur->val >= maxSeen) {
            ++res;
            maxSeen = cur->val;
        }
        dfs(cur->left, maxSeen, res);
        dfs(cur->right, maxSeen, res);
    }
};
