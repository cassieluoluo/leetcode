public class Solution {
    public int lengthLongestPath(String input) {
        int maxLen = 0;
        String[] dirs = input.split("\n");
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < dirs.length; i++) {
            String curDir = dirs[i];
            int curtLen = curDir.length();
            int level = curDir.lastIndexOf('\t') + 1;
            while (level < stack.size()) stack.pop();
            if (!stack.isEmpty()) curtLen += stack.peek();
            stack.push(curtLen - level);
            if (curDir.contains(".")) maxLen = Integer.max(maxLen,curtLen);
        }
        return maxLen;
    }
} // Author: Cassie
