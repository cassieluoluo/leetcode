// Author: Xinyu Chen
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	unordered_map<int, int> counter;
    	vector<string> result;
    	unsigned int code = 0;
    	for (int i = 0; i < s.size(); ++i) {
    		code <<= 3;
    		code &= 0x3fffffff;
    		code += s[i] & 7;
    		if (counter.find(code) == counter.end())
    			counter[code] = 1;
    		else
    			counter[code]++;
    		if (counter[code] == 2)
    			result.push_back(s.substr(i - 9, 10));
    	}
    	return result;
    }
};