public class Solution {
    public string AddBinary(string a, string b) {
        int i = a.Length - 1;
        int j = b.Length - 1;
        int carry = 0;
        StringBuilder sb = new StringBuilder();
        while (i >= 0 || j >= 0) {
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;
            int sum = x + y + carry;
            carry = (sum >> 1) & 1;
            sb.Append(sum & 1);
            --i; --j;
        }
        if (carry != 0) sb.Append(carry);
        string res = sb.ToString();
        char[] chs = res.ToCharArray();
        Array.Reverse(chs);
        return new string(chs);
    }
} // Author: XC
