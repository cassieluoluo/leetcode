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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        dfs(root, path, res);
        return res;
    }
    
    void dfs(TreeNode *node, string path, vector<string>& res) {
        if (node == nullptr) return;
        path += to_string(node->val) + "->";
        if (node->left != nullptr) dfs(node->left, path, res);
        if (node->right != nullptr) dfs(node->right, path, res);
        if (node->left == nullptr && node->right == nullptr)
            res.push_back(path.substr(0, path.size() - 2));
    }
}; // Author: XC
