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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode *> st;
        TreeNode *curr = new TreeNode(0);
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            curr->right = node;            
            curr = node;
            if (curr->right != nullptr) {
                st.push(curr->right);
                curr->right = nullptr;
            }
            if (curr->left != nullptr) {
                st.push(curr->left);
                curr->left = nullptr;
            }
        }
    }
}; // Author: XC
