/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        bool rev = false;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> row(n);
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                row[i] = node->val;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            if (rev) reverse(row.begin(), row.end());
            rev = !rev;
            res.push_back(row);
        }
        return res;
    }
}; // Auhtor: XC
