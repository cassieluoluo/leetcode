class Solution {	// Author: Xinyu Chen
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string ip;
		dfs(s, 0, 0, ip, result);
		return result;
	}

	void dfs(string s, int pos, int index, string ip, vector<string>& result) {
		if (pos == s.size()) {
			if (index == 4) {
				result.push_back(ip);
			}
			return;
		}
		if (s.size() - pos > 3 * (4 - index)) return;  // Too many digits left
		string curr;
		index++;
		if (pos > 0) ip.push_back('.');
		curr.push_back(s[pos++]);			// Add one digit
		dfs(s, pos, index, ip + curr, result);
		if (curr == "0" || pos == s.size()) return;		// If the first digit is zero, we cannot add any more digits
		curr.push_back(s[pos++]);		// Add the second digit
		dfs(s, pos, index, ip + curr, result);
		if (pos == s.size()) return;
		curr.push_back(s[pos++]);		// Add the third digit
		if (stoi(curr) > 255) return;	// After adding the third digit, if it is larger than 255, we do not proceed
		dfs(s, pos, index, ip + curr, result);
	}
};