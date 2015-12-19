class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto n : nums) strs.push_back(to_string(n));
        sort(strs.begin(), strs.end(), [](string s1, string s2)->bool { return s1 + s2 > s2 + s1; });
        if (strs[0][0] == '0') return "0";
        stringstream ss;
        for (auto s : strs) ss << s;
        return ss.str();
    }
};