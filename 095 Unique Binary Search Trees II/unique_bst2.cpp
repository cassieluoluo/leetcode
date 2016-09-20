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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode *>();
        return helper(1, n);
    }
    
    vector<TreeNode *> helper(int lo, int hi) {
        vector<TreeNode *> res;
        if (lo > hi) {
            res.push_back(nullptr);
            return res;
        }
        
        for (int i = lo; i <= hi; i++) {
            vector<TreeNode *> lt = helper(lo, i - 1);
            vector<TreeNode *> rt = helper(i + 1, hi);
            for (auto n1 : lt) {
                for (auto n2 : rt) {
                    TreeNode *node = new TreeNode(i);
                    node->left = n1;
                    node->right = n2;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
}; // Author: XC