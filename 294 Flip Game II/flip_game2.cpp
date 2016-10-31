class Solution {
public:
    bool canWin(string s) {
		if (s.size() < 2) return false;
		if (hash.find(s) != hash.end()) return hash[s];
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == '+' && s[i + 1] == '+') {
				string t = s;
				t[i] = t[i + 1] = '-';
				if (!canWin(t)) {
					hash[s] = true;
					return true;
				}
			}
		}
		hash[s] = false;
		return false;
    }

private:
	unordered_map<string, bool> hash;
}; // Author: XC
