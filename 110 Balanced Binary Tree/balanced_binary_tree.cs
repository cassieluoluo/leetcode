/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {	// Author: Xinyu Chen
    public bool IsBalanced(TreeNode root) {
        if (root == null) return true;
        return dfs(root) != -1;
    }
    
    public int dfs(TreeNode node) {
        if (node == null) return 0;
        int left = dfs(node.left);
        if (left == -1) return -1;
        int right = dfs(node.right);
        if (right == -1) return -1;
        int diff = left - right;
        if (diff < -1 || diff > 1) return -1;
        return Math.Max(left, right) + 1;
    }
}