/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Longest Substring Without Repeating Characters
 *	https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *	Runtime: 76 ms
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> t;
        int l = s.size();
        if (l < 2) return l;
        int maxlen = 1;
        int left = 0, right = 1;
        st.insert(s[left]);
        while (right < l) {
            if (st.find(s[right]) == st.end()) {
                st.insert(s[right++]);
                maxlen = max(maxlen, right - left);
            }
            else st.erase(s[left++]);
        }
        return maxlen;
    }
};