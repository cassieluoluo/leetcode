public class Solution {	// Author: Xinyu Chen
    public bool IsPalindrome(string s) {
        int i = 0, j = s.Length - 1;
        while (i <= j)
        {
            while (!char.IsLetterOrDigit(s[i]) && i < j) i++;
            while (!char.IsLetterOrDigit(s[j]) && i < j) j--;
            if (char.ToLower(s[i]) != char.ToLower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
}
