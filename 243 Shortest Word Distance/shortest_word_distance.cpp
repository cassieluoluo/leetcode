class Solution {	// Author: Xinyu Chen
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i1 = -1, i2 = -1, result = numeric_limits<int>::max();
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) i1 = i;
            else if (words[i] == word2) i2 = i;
            if (i1 != -1 && i2 != -1) {
                result = min(result, i1 < i2 ? i2 - i1 : i1 - i2);
            }
        }
        return result;
    }
};
