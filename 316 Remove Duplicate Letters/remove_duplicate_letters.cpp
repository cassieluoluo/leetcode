class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        bool checker[26] = { false };
        int counter[26] = { 0 };
        for (auto c : s) {
            counter[c - 'a']++;
        }
        for (auto c : s) {
            counter[c - 'a']--;
            if (result.empty()) {
                result.push_back(c);
                checker[c - 'a'] = true;
            }
            if (checker[c - 'a']) continue;
            char last = result.back();
            while (c < last && !result.empty() && counter[last - 'a'] > 0) {
                checker[result.back() - 'a'] = false;
                result.pop_back();
                last = result.back();
            }
            result.push_back(c);
            checker[c - 'a'] = true;
        }
        return result;
    }
};