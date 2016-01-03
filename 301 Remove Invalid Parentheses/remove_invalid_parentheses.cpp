class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
		str = s;
		int rm_left = 0, rm_right = 0;
		for (auto c : s) {
			if (c == '(') rm_left++;
			else if (c == ')') {
				if (rm_left > 0) rm_left--;
				else rm_right++;
			}
		}
		if (rm_left == 0 && rm_right == 0) return vector<string>{s};
		deque<char> row;
		dfs(0, 0, rm_left, rm_right, row);
		vector<string> res;
		for (auto s : result) {
			res.push_back(s);
		}
		return res;
	}

	void dfs(int pos, int par, int left, int right, deque<char>& row) {
		if (pos == str.size() && left == 0 && right == 0 && par == 0) {
			stringstream ss;
			for (auto c : row) {
				ss << c;
			}
			result.insert(ss.str());
			return;
		}
		if (pos == str.size() || left < 0 || right < 0 || par < 0) return;
		if (str[pos] == '(') {
			dfs(pos + 1, par, left - 1, right, row);
			row.push_back('(');
			dfs(pos + 1, par + 1, left, right, row);
			row.pop_back();
		}
		else if (str[pos] == ')') {
			dfs(pos + 1, par, left, right - 1, row);
			row.push_back(')');
			dfs(pos + 1, par - 1, left, right, row);
			row.pop_back();
		}
		else {
			row.push_back(str[pos]);
			dfs(pos + 1, par, left, right, row);
			row.pop_back();
		}
	}
private:
	string str;
	unordered_set<string> result;
};