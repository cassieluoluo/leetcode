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
}; // Author: XC

// Dynamic Programming Solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.size();
        int pl = p.size();
        vector<vector<int>> dp(sl + 1, vector<int>(pl + 1, 0));
        dp[0][0] = 1;
        for (int j = 2; j <= pl; j++) {
            if (p[j - 1] == '*' && dp[0][j - 2]) dp[0][j] = 1;
        }
        for (int i = 1; i <= sl; i++) {
            for (int j = 1; j <= pl; j++) {
                if (p[j - 1] != '*') {
                    if (dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j - 2];
                    if ((p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j]) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        return dp[sl][pl];
    }
}; // Author: XC
