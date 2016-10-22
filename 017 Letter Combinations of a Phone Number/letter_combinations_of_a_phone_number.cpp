class Solution {
public:
    const vector<string> letters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        string line;
        dfs(digits, 0, line);
        return result;
    }
    
    void dfs(string& digits, int level, string line) {
        if (level == digits.size()) {
            result.push_back(line);
        }
        else {
            for (auto c : letters[digits[level] - '0']) {
                dfs(digits, level + 1, line + c);
            }
        }
    }
private:
    vector<string> result;
}; // Author: XC
