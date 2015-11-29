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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> seq;
        vector<vector<int>> result;
        dfs(root, sum, 0, seq, result);
        return result;
    }
    
    void dfs(TreeNode* node, int sum, int curr, vector<int>& seq, vector<vector<int>>& result) {
        if (node == nullptr) return;
        curr += node->val;
        seq.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            if (sum == curr) result.push_back(seq);
            seq.pop_back();
            return;
        }
        if (node->left != nullptr) dfs(node->left, sum, curr, seq, result);
        if (node->right != nullptr) dfs(node->right, sum, curr, seq, result);
        seq.pop_back();
    }
};