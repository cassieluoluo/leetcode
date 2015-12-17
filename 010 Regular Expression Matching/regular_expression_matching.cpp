class Solution {
public:
	bool isMatch(string s, string p) {
		sl = s.size();
		pl = p.size();
		str = s;
		pat = p;
		return rec(0, 0);
	}

	bool rec(int s, int p) {
		if (p >= pl) return s >= sl;
		if (p < pl - 1 && pat[p + 1] == '*') {
			while (pat[p] == str[s] || (pat[p] == '.' && s < sl)) {
				if (rec(s, p + 2)) return true;
				s++;
			}
			return rec(s, p + 2);
		}
		else {
			if (str[s] == pat[p] || (pat[p] == '.' && s < sl)) {
				return rec(s + 1, p + 1);
			}
			else {
				return false;
			}
		}
	}
private:
	string str, pat;
	int sl, pl;
};
