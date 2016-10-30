class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int pos = len1 + len2 - 1;
        vector<int> buffer(len1 + len2);
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int x = num1[i] - '0';
                int y = num2[j] - '0';
                int prod = x * y;
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = prod + buffer[p2];
                buffer[p2] = sum % 10;
                buffer[p1] += sum / 10;
            }
        }
        pos = 0;
        while (pos < buffer.size()) {
			if (buffer[pos] == 0) pos++;
			else break;
		}
        if (pos == buffer.size()) return "0";
        stringstream ss;
        while (pos < buffer.size()) ss << buffer[pos++];
        return ss.str();
    }
}; // Author: XC
