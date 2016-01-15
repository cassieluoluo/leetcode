class Solution {	// Author: Xinyu Chen
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> record;
		for (auto c : t) {
			record[c]++;
		}
		int i = -1, j = 0, min_len = numeric_limits<int>::max();
		int len = s.size(), count = t.size(), start = 0;
		while (i < len && j < len) {
			if (count > 0) {
				i++;
				if (record.find(s[i]) == record.end()) continue;
				record[s[i]]--;
				if (record[s[i]] >= 0) count--;
			}
			else {
				if (i - j + 1 < min_len) {
					min_len = i - j + 1;
					start = j;
				}
				if (record.find(s[j]) != record.end()) {
					record[s[j]]++;
					if (record[s[j]] > 0) count++;
				}
				j++;
			}
		}
		if (min_len == numeric_limits<int>::max()) return "";
		return s.substr(start, min_len);
	}
};
