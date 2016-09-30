class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        stringstream ss;
        char c;
        int count;
        for (int i = 1; i < n; i++) {
            ss.str(string());
            c = s[0];
            count = 1;
            for (int j = 1; j < s.size(); j++) {
                if (s[j] == c) count++;
                else {
                    ss << count << c;
                    c = s[j];
                    count = 1;
                }
            }
            ss << count << c;
            s = ss.str();
        }
        return s;
    }
}; // Author: XC