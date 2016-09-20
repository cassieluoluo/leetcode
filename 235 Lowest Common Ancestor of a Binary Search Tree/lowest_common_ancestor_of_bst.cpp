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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            TreeNode* t = p;
            p = q; q = t;
        }
        if (q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};  // XC

// Iterative version
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            TreeNode *temp = p;
            p = q;
            q = temp;
        }
        while (root != nullptr) {
            if (p->val <= root->val && q->val >= root->val) return root;
            if (root->val < p->val) root = root->right;
            else root = root->left;
        }
        return nullptr;
    }
};