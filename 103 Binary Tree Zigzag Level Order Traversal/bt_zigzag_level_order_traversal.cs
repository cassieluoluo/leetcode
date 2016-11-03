/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        IList<IList<int>> res = new List<IList<int>>();
        if (root == null) return res;
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        bool rev = false;
        while (q.Count > 0) {
            int n = q.Count;
            List<int> row = new List<int>();
            for (int i = 0; i < n; i++) {
                TreeNode node = q.Dequeue();
                row.Add(node.val);
                if (node.left != null) q.Enqueue(node.left);
                if (node.right != null) q.Enqueue(node.right);
            }
            if (rev) row.Reverse();
            res.Add(row);
            rev = !rev;
        }
        return res;
    }
} // Author: XC
