class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(), 0);
        int len = 0;
        for (size_t i = 0; i < words.size(); i++) {
            for (auto c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
        }
        for (size_t i = 0; i < mask.size(); i++) {
            for (size_t j = i + 1; j < mask.size(); j++) {
                if ((mask[i] & mask[j]) == 0) {
                    int curr = words[i].size() * words[j].size();
                    len = max(len, curr);
                }
            }
        }
        return len;
    }
};