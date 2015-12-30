/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {	// Author: Xinyu Chen
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        bfs(root, path);
        return result;
    }
private:    
    void bfs(TreeNode* node, vector<int>& path) {
        if (node == nullptr) return;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(generatePath(path));
            return;
        }
        if (node->left != nullptr) {
            bfs(node->left, path);
            path.pop_back();
        }
        if (node->right != nullptr) {
            bfs(node->right, path);
            path.pop_back();
        }
    }
    string generatePath(vector<int> path) {
        stringstream ss;
        for (int i = 0; i < path.size() - 1; i++) ss << path[i] << "->";
        ss << path.back();
        return ss.str();
    }
    vector<string> result;
};