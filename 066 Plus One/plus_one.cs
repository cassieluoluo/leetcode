/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Plus One
 *	https://leetcode.com/problems/plus-one/
 *	Runtime: 524 ms
 */
 
public class Solution {
    public int[] PlusOne(int[] digits) {
        int carry = 0;
		List<int> res = new List<int>();
		if (digits[digits.Length - 1] == 9)
		{
		    res.Add(0);
		    carry = 1;
		}
		else
		{
		    res.Add(digits[digits.Length - 1] + 1);
		}
		for (int i = digits.Length - 2; i >= 0; i--)
		{
		    if (digits[i] == 9 && carry == 1)
		    {
		        res.Add(0);
		    }
		    else
		    {
		        res.Add(digits[i] + carry);
		        carry = 0;
		    }
		}
		if (carry == 1)
		{
		    res.Add(1);
		}
		res.Reverse();
		return res.ToArray();
    }
}