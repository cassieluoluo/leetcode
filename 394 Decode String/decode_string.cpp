class Solution {
public:
    string decodeString(string s) {
		int p = 0;
        return helper(s, p);
    }
    
private:
    string helper(const string& s, int& pos) {
        string res = "";
        while (pos < s.size() && s[pos] != ']') {
            if (isDigit(s[pos])) {
                int count = 0;
                while (isDigit(s[pos]))
                    count = count * 10 + s[pos++] - '0';
                ++pos;
                string str = helper(s, pos);
				for (int i = 0; i < count; i++) res += str;
                ++pos;
            } else {
                res += s[pos++];
            }
        }
        return res;
    }
    
    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }
}; // Author: XC
