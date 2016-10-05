class Solution {
public:
    int findNthDigit(int n) {
		int i = 1;
		long nn = n;
		unsigned long long start = 9 * i * pow10(i - 1);
		while (nn > start) {
			nn -= start;
			i++;
			start = 9 * i * pow10(i - 1);
		}
		int pos = nn / i;
		int rem = nn % i;
		if (rem == 0) {
			pos--;
			rem += i;
		}
		int base = pow10(i - 1);
		int num = base + pos;
		for (int j = 0; j < i - rem; j++) {
			num /= 10;
		}
		return num % 10;
	}

	unsigned long long pow10(int n) {
		long res = 1;
		for (int i = 0; i < n; i++) {
			res *= 10;
		}
		return res;
	}
}; // Author: XC
