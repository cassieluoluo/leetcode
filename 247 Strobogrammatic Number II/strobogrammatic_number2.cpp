class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if (n == 0) return result;
		vector<string> even{""};
		vector<string> odd{"0", "1", "8"};
		if (n % 2 == 0) return helper(n, even);
		return helper(n, odd);
    }
	
private:
	vector<string> helper(int n, vector<string> curr) {
		if (n == 0 || n == 1) return curr;
		vector<string> next;
		int i = n == 2 || n == 3 ? 1 : 0;
		for (; i < patterns.size(); i++) {
			string p = patterns[i];
			for (auto s : curr) {
				next.push_back(p[0] + s + p[1]);
			}
		}
		return helper(n - 2, next);
	}

	const vector<string> patterns{ "00", "11", "69", "88", "96" };
}; // Author: XC
