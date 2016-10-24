class Solution {
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
}; // Author: XC

// Another similar solution
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for (auto c : t) hash[c]++;
        int count = 0, min_len = numeric_limits<int>::max();
        int len_s = s.size(), len_t = t.size(), start = 0, end = 0;
        string res;
        for (end = 0; end < len_s; end++) {
			if (hash.find(s[end]) != hash.end()) {
				hash[s[end]]--;
				if (hash[s[end]] >= 0) count++;
			}
			while (count == len_t) {
				if (end - start + 1 < min_len) {
					min_len = end - start + 1;
					res = s.substr(start, min_len);
				}
				if (hash.find(s[start]) != hash.end()) {
					hash[s[start]]++;
					if (hash[s[start]] > 0) count--;
				}
				start++;
			}
		}
        return res;
    }
}; // Author: XC
