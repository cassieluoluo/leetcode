/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Maximum Depth of Binary Tree
 *	https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *	Runtime: 8 ms
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};