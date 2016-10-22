public class Solution {
    private List<string> res;
    
    public IList<string> LetterCombinations(string digits) {
        List<string> lookup = new List<string>{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        StringBuilder sb = new StringBuilder();
        res = new List<string>();
        if (digits.Length == 0) return res;
        helper(digits, 0, lookup, sb);
        return res;
    }
    
    private void helper(string digits, int pos, List<string> lookup, StringBuilder sb) {
        if (pos == digits.Length) {
            res.Add(sb.ToString());
            return;
        }
        string letters = lookup[digits[pos] - '0'];
        for (int i = 0; i < letters.Length; i++) {
            sb.Append(letters[i]);
            helper(digits, pos + 1, lookup, sb);
            sb.Remove(sb.Length - 1, 1);
        }
    }
} // Author: XC
