class Solution {	// Author: Xinyu Chen
public:
    vector<string> addOperators(string num, int target) {
		if (num.empty()) return result;
		this->num = num;
		this->target = target;
		for (int i = 1; i <= num.size(); ++i) {
			string str = num.substr(0, i);
			long first = stol(str);
			if (to_string(first) != str) continue;
			dfs(i, first, first, '+', str);
		}
		return result;
	}
	
private:
	void dfs(int pos, long last, long val, char op, string res) {
		if (pos == num.size() && val == target) {
			result.push_back(res);
			return;
		}
		for (int i = 1; i <= num.size() - pos; ++i) {
			string str = num.substr(pos, i);
			long curr = stol(str);
			if (to_string(curr) != str) continue;
			dfs(pos + i, curr, val + curr, '+', res + "+" + str);
			dfs(pos + i, curr, val - curr, '-', res + "-" + str);
			long sign = op == '+' ? 1 : -1;
			long temp = val - last * sign;
			dfs(pos + i, curr * last, temp + sign * curr * last, op, res + "*" + str);
		}
	}

	vector<string> result;
	string num;
	int target;
};