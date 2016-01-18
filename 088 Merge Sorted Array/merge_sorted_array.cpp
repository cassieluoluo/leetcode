class Solution {	// Author: Xinyu Chen
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;
		int pos = m + n - 1;
		m -= 1; n -= 1;
		while (m >= 0 && n >= 0) {
			nums1[pos--] = nums1[m] > nums2[n] ?
				nums1[m--] : nums2[n--];
		}
		if (m < 0) {
			while (n >= 0) {
				nums1[pos--] = nums2[n--];
			}
		}
	}
};
