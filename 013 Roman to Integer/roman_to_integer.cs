public class Solution {	// Author: Xinyu Chen
    public int RomanToInt(string s) {
        var mapping = new Dictionary<char, int>()
		{
		    {'I', 1},
		    {'V', 5},
		    {'X', 10},
		    {'L', 50},
		    {'C', 100},
		    {'D', 500},
		    {'M', 1000}
		};
		int result = 0;
		for (int i = 0; i < s.Length - 1; i++)
		{
		    if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
		        result -= mapping[s[i]];
		    else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
		        result -= mapping[s[i]];
		    else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
		        result -= mapping[s[i]];
		    else
		        result += mapping[s[i]];
		}
		result += mapping[s[s.Length - 1]];
		return result;
    }
}