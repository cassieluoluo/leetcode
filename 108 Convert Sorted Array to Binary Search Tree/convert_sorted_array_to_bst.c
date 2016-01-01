/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Author: Xinyu Chen
struct TreeNode * bfs(int *nums, int lo, int hi) {
    if (lo > hi) return NULL;
    int mid = lo + (hi - lo) / 2;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = bfs(nums, lo, mid - 1);
    node->right = bfs(nums, mid + 1, hi);
    return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return bfs(nums, 0, numsSize - 1);
}