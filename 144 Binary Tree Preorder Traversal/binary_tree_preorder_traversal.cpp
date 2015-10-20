/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Binary Tree Preorder Traversal
 *	https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
    
    void dfs(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        result.push_back(node->val);
        dfs(node->left, result);
        dfs(node->right, result);
    }
};

class SolutionIterative {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> st;
        while (!st.empty() || root != nullptr) {
            if (root != nullptr) {
                result.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return result;
    }
};