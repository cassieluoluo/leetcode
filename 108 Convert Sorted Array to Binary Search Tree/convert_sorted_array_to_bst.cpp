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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return bfs(nums, 0, nums.size() - 1);
    }
    
    TreeNode* bfs(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int pos = (left + right) / 2;
        TreeNode *node = new TreeNode(nums[pos]);
        node->left = bfs(nums, left, pos - 1);
        node->right = bfs(nums, pos + 1, right);
        return node;
    }
}; // Author: XC
