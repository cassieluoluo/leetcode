class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, sum = 0;
        stringstream ss;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0) {
            int da = i >= 0 ? a[i--] - '0' : 0;
            int db = j >= 0 ? b[j--] - '0' : 0;
            sum = da + db + carry;
            ss << (sum & 1);
            carry = sum >> 1;
        }
        if (carry != 0) ss << carry;
        string res = ss.str();
        reverse(res.begin(), res.end());
        return res;
    }
}; // Author: XC
