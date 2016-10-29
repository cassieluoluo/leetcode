class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.size() - 1;
		int digits[] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
		while (i <= j) {
			int p = num[i++] - '0';
			int q = num[j--] - '0';
			if (digits[p] == -1 || digits[q] == -1) return false;
			if (digits[p] != q) return false;
		}
		return true;
    }
}; // Author: XC
