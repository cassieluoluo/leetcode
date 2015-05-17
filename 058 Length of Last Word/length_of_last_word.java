/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Length of Last Word
 *	https://leetcode.com/problems/length-of-last-word/
 *	Runtime: 250 ms
 */

public class Solution {
    public int lengthOfLastWord(String s) {
        String[] words = s.split(" ");
        if (words.length == 0) return 0;
        return words[words.length - 1].length();
    }
}