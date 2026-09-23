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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::queue<std::pair<TreeNode*, int>> q;
        vector<vector<int>> res;
        int level = 0;
        q.push({root, 1});

        while (!q.empty()) {
            auto cur = q.front();
            TreeNode* curNode = cur.first;
            int curLevel = cur.second;
            q.pop();
            // std::cout << curNode->val << " " << curLevel << "\n";
            if (level < curLevel) {
                res.push_back({curNode->val});
                level = curLevel;
            } else {
                res[level-1].push_back(curNode->val);
            }
            if (curNode->left) {
                // std::cout << curNode->val << "\n";
                q.push({curNode->left, curLevel + 1});
            }

            if (curNode->right) {
                q.push({curNode->right, curLevel + 1});
            }
            
        }

        return res;
    }
};
