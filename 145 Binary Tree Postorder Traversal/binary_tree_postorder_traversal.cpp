/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Binary Tree Postorder Traversal
 *	https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
    
    void postorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->val);
    }
};

class SolutionIterative {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        while (!st.empty() || root != nullptr) {
            if (root != nullptr) {
                result.push_back(root->val);
                st.push(root);
                root = root->right;
            }
            else {
                root = st.top();
                st.pop();
                root = root->left;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};