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
    double min_val;
	int result;
	int closestValue(TreeNode* root, double target) {
		min_val = numeric_limits<double>::max();
		rec(root, target);
		return result;
	}

	void rec(TreeNode* node, double target) {
		if (node == nullptr) return;
		double diff;
		if (target < node->val) {
			diff = node->val - target;
			if (diff < min_val) {
				result = node->val;
				min_val = diff;
			}
			rec(node->left, target);
		}
		else {
			diff = target - node->val;
			if (diff < min_val) {
				result = node->val;
				min_val = diff;
			}
			rec(node->right, target);
		}
	}
};
