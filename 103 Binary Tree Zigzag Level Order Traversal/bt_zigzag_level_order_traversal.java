public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Stack<TreeNode> curtLevel = new Stack<>();
        Stack<TreeNode> nextLevel = new Stack<>();
        Stack<TreeNode> temp;
        boolean left = true;
        curtLevel.push(root);
        while (!curtLevel.isEmpty()) {
            ArrayList<Integer> list = new ArrayList<>();
            while(!curtLevel.isEmpty()) {
                TreeNode curt = curtLevel.pop();
                list.add(curt.val);
                if (left) {
                    if (curt.left != null) nextLevel.push(curt.left);
                    if (curt.right != null) nextLevel.push(curt.right);
                } else {
                    if (curt.right != null) nextLevel.push(curt.right);
                    if (curt.left != null) nextLevel.push(curt.left);
                }
            }
            res.add(list);
            temp = curtLevel;
            curtLevel = nextLevel;
            nextLevel = temp;
            left = !left;
        }
        return res;
    }
} // Author: Cassie
