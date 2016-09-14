/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Binary Tree Inorder Traversal
 *	https://leetcode.com/problems/binary-tree-inorder-traversal/
 *	Runtime: 0 ms
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
class SolutionRecursive {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> res;
        while (root != nullptr || !st.empty()) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode *node = st.top();
                st.pop();
                res.push_back(node->val);
                root = node->right;
            }
        }
        return res;
    }
};  // Author: XC
