/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Plus One
 *	https://leetcode.com/problems/plus-one/
 *	Runtime: 321 ms
 */
 
public class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 0;
        ArrayList<Integer> res = new ArrayList<Integer>();
        if (digits[digits.length - 1] == 9) {
            res.add(0);
            carry = 1;
        } else {
            res.add(digits[digits.length - 1] + 1);
        }
        for (int i = digits.length - 2; i >= 0; i--) {
            if (digits[i] == 9 && carry == 1) {
                res.add(0);
            } else {
                res.add(digits[i] + carry);
                carry = 0;
            }
        }
        if (carry == 1) {
            res.add(1);
        }
        Collections.reverse(res);
        int[] ret = new int[res.size()];
        for (int i = 0; i < res.size(); i++) ret[i] = res.get(i).intValue();
        return ret;
    }
}