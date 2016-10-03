class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        for (auto str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            table[s].push_back(str);
        }
        vector<vector<string>> result;
        for (auto group : table) {
            vector<string> g = group.second;
            sort(g.begin(), g.end());
            result.push_back(g);
        }
        return result;
    }
}; // Author: XC
