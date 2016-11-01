

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto pair_compare = [](const pair<int, int>& a, const pair<int, int>& b) {
		    return a.first + a.second < b.first + b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(pair_compare)> pq(pair_compare);
        int len1 = min((int)nums1.size(), k);
        int len2 = min((int)nums2.size(), k);
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int a = nums1[i];
                int b = nums2[j];
                if (pq.size() < k) {
                    pq.push(pair<int, int>{a, b});
                } else {
                    auto p = pq.top();
                    if (a + b < p.first + p.second) {
                        pq.pop();
                        pq.push(pair<int, int>{a, b});
                    }
                }
            }
        }
        vector<pair<int, int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
}; // Author: XC
