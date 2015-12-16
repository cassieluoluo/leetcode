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

class SolutionIterative {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> st;
        while (!st.empty() || root != nullptr) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};