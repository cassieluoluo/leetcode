class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        int total = 0;
        bool odd = false;
        for (auto c : s) hash[c]++;
        for (auto h : hash) {
            if (h.second % 2 == 1) {
                odd = true;
                total += h.second - 1;
            } else {
                total += h.second;
            }
            
        }
        if (odd) total++;
        return total;
    }
}; // Author: XC
