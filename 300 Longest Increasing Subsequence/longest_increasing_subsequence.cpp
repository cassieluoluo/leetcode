class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
    	vector<int> seq{ nums[0] };
    	for (auto n : nums) {
    		if (n > seq.back())
    			seq.push_back(n);
    		else
    			insertNum(seq, n);
    	}
    	return seq.size();
    }
    
    void insertNum(vector<int>& seq, int n) {
        int lo = 0, hi = seq.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (seq[mid] < n) lo = mid + 1;
            else hi = mid;
        }
        seq[lo] = n;
    }
};