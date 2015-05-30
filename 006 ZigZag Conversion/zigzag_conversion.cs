/*	
 *	LeetCode Submissions by Xinyu Chen
 *	ZigZag Conversion
 *	https://leetcode.com/problems/zigzag-conversion/
 *	Runtime: 168 ms
 */

public class Solution {
    public string Convert(string s, int numRows) {
        if (s.Length <= numRows || numRows == 1) return s;
		List<char> ret = new List<char>();
		int n = numRows * 2 - 2, index = 0;
		for (int row = 0; row < numRows; row++)
		{
		    if (row == 0 || row == numRows - 1)
		    {
		        for (int i = 0; i + row < s.Length; i += n)
		        {
				ret.Add(s[row + i]);
		        }
		    }
		    else
		    {
		        int i = -n;
		        while (true)
		        {
				i += n;
				if (i - row >= s.Length) break;
				if (i - row >= 0) ret.Add(s[i - row]);
				if (i + row >= s.Length) break;
				ret.Add(s[i + row]);
		        }
		    }
		}
		return new string(ret.ToArray());
    }
}