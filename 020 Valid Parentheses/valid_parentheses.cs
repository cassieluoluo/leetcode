/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Valid Parentheses
 *	https://leetcode.com/problems/valid-parentheses/
 *	Runtime: 163 ms
 */

public class Solution {
    public bool IsValid(string s) {
    	Dictionary<char, char> pairs = new Dictionary<char, char>();
        pairs.Add(')', '(');
		pairs.Add('}', '{');
		pairs.Add(']', '[');
		Stack<char> st = new Stack<char>();
		foreach (var c in s)
		{
			if (c == '(' || c == '{' || c == '[') st.Push(c);
			else if (st.Count == 0) return false;
			else if (pairs[c] != st.Pop()) return false;
		}
		if (st.Count == 0) return true;
		return false;
    }
}