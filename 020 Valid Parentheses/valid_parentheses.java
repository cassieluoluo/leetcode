/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Valid Parentheses
 *	https://leetcode.com/problems/valid-parentheses/
 *	Runtime: 450 ms
 */

public class Solution {
    public boolean isValid(String s) {
        HashMap<Character, Character> pairs = new HashMap<Character, Character>();
        pairs.put(')', '(');
        pairs.put('}', '{');
        pairs.put(']', '[');
        Stack<Character> st = new Stack<Character>();
        try {
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') st.push(s.charAt(i));
                else if (st.pop() != pairs.get(s.charAt(i))) return false;
            }
        } catch (java.util.EmptyStackException e) {
            return false;
        }
        return st.empty();
    }
}