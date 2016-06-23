class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int prev = 0, curr = 1;
        for (size_t i = 1; i <= s.size(); i++) {
            if (s[i - 1] == '0') curr = 0;
            if (i < 2 || 
                !((s[i - 2] == '2' && s[i - 1] <= '6') || 
                   s[i - 2] == '1'
                  )
                ) prev = 0;
            int temp = curr;
            curr += prev;
            prev = temp;
        }
        return curr;
    }
};
