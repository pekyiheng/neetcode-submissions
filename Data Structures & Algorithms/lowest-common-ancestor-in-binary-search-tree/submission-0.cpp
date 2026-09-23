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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small, big;
        if (p->val > q->val) {
            small = q->val;
            big = p->val;
        } else {
            small = p->val;
            big = q->val;
        }
        auto l = dfs(root->left, root->val, small, big);
        if (l) { return l; }
        auto r = dfs(root->right, root->val, small, big);
        if (r) { return r; }
        return root;

    }

    TreeNode* dfs(TreeNode* cur, int parentVal, int p, int q) {
        if (!cur) { return nullptr; }
        if ((cur->val < parentVal && q >= parentVal)
            || (cur->val > parentVal && p <= parentVal)) {
            return nullptr;
        }

        auto left = dfs(cur->left, cur->val, p, q);
        if (left) { return left; }
        auto right = dfs(cur->right, cur->val, p, q);
        if (right) { return right; }

        return cur;

    }
};
