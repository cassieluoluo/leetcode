/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
   //private int max = 0;
    public int longestConsecutive(TreeNode root) {
      if(root == null) return 0;
        return longestConsecutive(root, root.val, 0);
    }
    public int longestConsecutive(TreeNode root, int prev, int len) {
        if (root == null) return len;
        int leftLen = 0;
        int rightLen = 0;
        if (root.val == prev + 1) {
            leftLen = longestConsecutive(root.left, root.val, len + 1);
            rightLen = longestConsecutive(root.right, root.val, len + 1);
        } else {
            leftLen = Math.max(len, longestConsecutive(root.left, root.val, 1));
            rightLen = Math.max(len,longestConsecutive(root.right, root.val, 1));
        }
        return Math.max(leftLen, rightLen);
    }
} // Author: Cassie
