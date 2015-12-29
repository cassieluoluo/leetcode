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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (depth(root) == -1) return false;
        return true;
    }
    
    int depth(TreeNode* node) {
        if (node == nullptr) return 0;
        int depthLeft = depth(node->left);
        if (depthLeft == -1) return -1;
        int depthRight = depth(node->right);
        if (depthRight == -1) return -1;
        int diff = depthLeft - depthRight;
        if (diff > 1 || diff < -1) return -1;
        return max(depthLeft, depthRight) + 1;
    }
};