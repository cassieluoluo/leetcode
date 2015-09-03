/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Same Tree
 *	https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p != nullptr && q != nullptr) {
            if (p->val != q->val) return false;
            return isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right);
        }
        return false;
    }
};