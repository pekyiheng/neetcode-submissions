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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (!root) {
            return v;
        }
        v.push_back(root->val);
        int curD = 1;
        dfs(root->right, 1, curD, v);
        dfs(root->left, 1, curD, v);
        return v;
    }

    void dfs(TreeNode* cur, int d, int& curDepth, vector<int>& v) {
        if (!cur) {return;}
        if (curDepth == d) {
            v.push_back(cur->val);
            ++curDepth;
        }
        dfs(cur->right, d+1, curDepth, v);
        dfs(cur->left, d+1, curDepth, v);

    }
};
