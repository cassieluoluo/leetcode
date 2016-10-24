// DFS
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
		vector<char> row;
		dfs(0, 0, rm_left, rm_right, row);
		vector<string> res;
		for (auto s : result) {
			res.push_back(s);
		}
		return res;
	}

	void dfs(int pos, int par, int left, int right, vector<char>& row) {
		if (pos == str.size() && left == 0 && right == 0 && par == 0) {
			stringstream ss;
			for (auto c : row) ss << c;
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
}; // Author: XC

// BFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
		vector<string> result;
        unordered_set<string> checked;
        checked.insert(s);
        queue<string> q;
        q.push(s);
		bool found = false;
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            if (validate(str)) {
                result.push_back(str);
                found = true;
            }
			if (found) continue;
            for (int i = 0; i < str.size(); i++) {
                if (str[i] != '(' && str[i] != ')') continue;
                string test = str.substr(0, i) + str.substr(i + 1);
                if (checked.find(test) == checked.end()) {
                    q.push(test);
                    checked.insert(test);
                }
            }
        }
        return result;
    }
    
    bool validate(string s) {
        int count = 0;
        for (auto ch : s) {
            if (ch == '(') count++;
            if (ch == ')' && count-- == 0) return false;
        }
        return count == 0;
    }
}; // Author: XC
