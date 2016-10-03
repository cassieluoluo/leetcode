class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() < t.size()) swap(s, t);
		int ls = s.size();
		int ts = t.size();
		if (ls - ts > 1) return false;
		int i = 0, j = 0;
		bool diff = false;
		while (j < ts) {
			if (s[i] == t[j]) {
				i++; j++;
			}
			else {
				if (diff) return false;
				diff = true;
				i++;
				if (s.size() == t.size()) j++;
			}
		}
		if (s.size() == t.size()) return diff;
		return true;
    }
}; // Author: XC
