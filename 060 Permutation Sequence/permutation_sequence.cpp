class Solution {	// Author: Xinyu Chen
public:
    string getPermutation(int n, int k) {
        const vector<int> fac{ 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
		vector<int> num(n);
		for (size_t i = 1; i <= n; ++i) num[i - 1] = i + '0';
		string result;
		int q, r; k--;
		while (--n >= 0) {
			q = k / fac[n];
			r = k % fac[n];
			result.push_back(num[q]);
			num.erase(num.begin() + q);
			k = r;
		}
		return result;
    }
};