class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int prev = 1, curr = 1;
        for (int i = 1; i < s.size(); i++) {
            int res = 0;
            if (s[i] != '0') res = curr;
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') res += prev;
            prev = curr;
            curr = res;
        }
        return curr;
    }
}; // Author: XC
