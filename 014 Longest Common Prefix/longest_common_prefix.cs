public class Solution {	// Author: Xinyu Chen
    public string LongestCommonPrefix(string[] strs) {
        if (strs.Length == 0) return "";
        if (strs.Length == 1) return strs[0];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < strs[0].Length; i++)
        {
            for (int j = 0; j < strs.Length; j++)
            {
                if (strs[j].Length <= i) return sb.ToString();
                if (strs[j][i] != strs[0][i]) return sb.ToString();
            }
            sb.Append(strs[0][i]);
        }
        return sb.ToString();
    }
}