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
    public void Flatten(TreeNode root) {
        if (root == null) return;
        var st = new Stack<TreeNode>();
        TreeNode curr = new TreeNode(0);
        st.Push(root);
        while (st.Count > 0)
        {
            TreeNode node = st.Pop();
            curr.right = node;
            curr = node;
            if (curr.right != null)
            {
                st.Push(curr.right);
                curr.right = null;
            }
            if (curr.left != null)
            {
                st.Push(curr.left);
                curr.left = null;
            }
        }        
    }
}