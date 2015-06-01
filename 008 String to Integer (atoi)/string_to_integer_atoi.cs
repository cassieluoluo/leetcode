/*	
 *	LeetCode Submissions by Xinyu Chen
 *	String to Integer (atoi)
 *	https://leetcode.com/problems/string-to-integer-atoi/
 *	Runtime: 216 ms
 */
 
public class Solution {
    public int MyAtoi(string str) {
        if (str.Length == 0) return 0;
		int index = 0;
		while (str[index] == ' '
		       || str[index] == '\t'
		       || str[index] == '\r'
		       || str[index] == '\n')
		    if (++index >= str.Length) return 0;
		bool negative = false;
		if (str[index] == '-')
		{
		    negative = true;
		    index++;
		}
		else if (str[index] == '+') index++;
		else if (str[index] < '0' || str[index] > '9') return 0;
		
		List<char> buffer = new List<char>();
		while (str[index] >= '0' && str[index] <= '9')
		{
		    buffer.Add(str[index++]);
		    if (index >= str.Length) break;
		}
		long result = 0;
		for (int i = 0; i < buffer.Count; i++)
		{
		    result *= 10;
		    result += buffer[i] - '0';
		    if (!negative && result > Int32.MaxValue) return Int32.MaxValue;
		    if (negative && -result < Int32.MinValue) return Int32.MinValue;
		}
		return negative ? -(int)result : (int)result;
    }
}