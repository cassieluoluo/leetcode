/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
// Recursive version
public class Solution { // Author: Xinyu Chen
    private List<int> result;
    public IList<int> InorderTraversal(TreeNode root) {
        result = new List<int>();
        inorder(root);
        return result;
    }
    
    private void inorder(TreeNode node) 
    {
        if (node == null) return;
        inorder(node.left);
        result.Add(node.val);
        inorder(node.right);
    }
}
// Iterative version
public class Solution { // Author: Xinyu Chen
    public IList<int> InorderTraversal(TreeNode root) {
        var result = new List<int>();
        var st = new Stack<TreeNode>();
        while (st.Count > 0 || root != null)
        {
            if (root != null)
            {
                st.Push(root);
                root = root.left;
            }
            else
            {
                root = st.Pop();
                result.Add(root.val);
                root = root.right;
            }
        }
        return result;
    }
}
