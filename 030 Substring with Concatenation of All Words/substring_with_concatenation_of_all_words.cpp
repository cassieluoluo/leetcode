class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> result;
    	if (s.empty() || words.empty()) return result;
    	int word_len = words[0].size();
    	if (word_len > s.size()) return result;
    	int left = 0, right = 0;
    	unordered_map<string, int> dict, used;
    	for (auto w : words) {
    		if (dict.find(w) == dict.end()) {
    			dict[w] = 1;
    		}
    		else dict[w]++;
    	}
    	used = dict;
    	while (left + words.size() * word_len <= s.size() && right <= s.size()) {
    		string word = s.substr(right, word_len);
    		if (used.empty()) {
    			result.push_back(left);
    			used = dict;
    			left++;
    			right = left;
    		}
    		else if (used.find(word) == used.end()) {
    			left++;
    			right = left;
    			used = dict;
    		}
    		else {
    			right += word_len;
    			used[word]--;
    			if (used[word] == 0) used.erase(word);
    		}
    	}
    	return result;
    }
};