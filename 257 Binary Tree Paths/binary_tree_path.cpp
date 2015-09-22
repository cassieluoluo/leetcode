/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Binary Tree Paths
 *	https://leetcode.com/problems/binary-tree-paths/
 *	Runtime: 4 ms
 */

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
        vector<string> result;
        if (root == nullptr) return result;
        vector<int> path;
        bfs(root, path, result);
        return result;
    }

private:    
    void bfs(TreeNode* node, vector<int>& path, vector<string>& result) {
        if (node == nullptr) return;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
            result.push_back(generatePath(path));
        else {
            if (node->left != nullptr) {
                bfs(node->left, path, result);
                path.pop_back();
            }
            if (node->right != nullptr) {
                bfs(node->right, path, result);
                path.pop_back();
            }
        }
    }

    string generatePath(vector<int> path) {
        stringstream ss;
        int i;
        for (i = 0; i < path.size() - 1; i++) ss << path[i] << "->";
        ss << path[i];
        return ss.str();
    }
};