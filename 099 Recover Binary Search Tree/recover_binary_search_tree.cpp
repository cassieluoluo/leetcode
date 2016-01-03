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
    void recoverTree(TreeNode* root) {
        curr = new TreeNode(numeric_limits<int>::min());
        inorder(root);
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
    }
    
    void inorder(TreeNode* node) {
		if (node == nullptr) return;
		inorder(node->left);
		if (left == nullptr && curr->val >= node->val) {
			left = curr;
		}
		if (left != nullptr && curr->val >= node->val) {
			right = node;
		}
		curr = node;
		inorder(node->right);
	}

private:
    TreeNode *left, *right, *curr;
};
