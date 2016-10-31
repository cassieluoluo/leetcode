class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
		result.push_back(word);
		helper(word, 0, result);
		return result;
    }
	
	void helper(string word, int pos, vector<string>& result) {
		for (int i = pos; i < word.size(); i++) {
			for (int j = 1; i + j <= word.size(); j++) {
				string t = word.substr(0, i);
				string r = to_string(j);
				t += r + word.substr(i + j);
				result.push_back(t);
				helper(t, i + r.size() + 1, result);
			}
		}
	}
}; // Author: XC
