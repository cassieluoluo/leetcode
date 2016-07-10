class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> counter;
        set<int> result;
        for (auto it = nums1.begin(); it != nums1.end(); ++it) {
            if (counter.find(*it) == counter.end()) counter[*it] = 1;
        }
        for (auto it = nums2.begin(); it != nums2.end(); ++it) {
            if (counter.find(*it) == counter.end()) continue;
            result.insert(*it);
        }
        vector<int> ret(result.begin(), result.end());
        return ret;
    }
}; // Author: XC