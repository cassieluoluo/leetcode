class Solution {	// Author: Xinyu Chen
public:
    vector<vector<string>> partition(string s) {
		if (s.empty()) return result;
		vector<string> row;
		dfs(s, 0, row);
		return result;
	}
private:
	void dfs(string s, int start, vector<string>& row) {
		if (start == s.size() && row.size() != 0) {
			result.push_back(row);
			return;
		}
		for (int i = start; i < s.size(); ++i) {
			if (validate(s, start, i)) {
				row.push_back(s.substr(start, i - start + 1));
				dfs(s, i + 1, row);
				row.pop_back();
			}
		}
	}

	bool validate(string s, int start, int end) {
		if (start < 0 || end >= s.size()) return false;
		while (start < end) {
			if (s[start] != s[end]) return false;
			start++; end--;
		}
		return true;
	}

	vector<vector<string>> result;
};