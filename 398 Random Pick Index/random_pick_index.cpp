class Solution {
public:
	Solution(vector<int> nums) {
		data = nums;
		srand(time(NULL));
	}
	
	int pick(int target) {
		int index = 0, count = 0;
		for (int i = 0; i < data.size(); i++) {
			if (data[i] == target) {
				++count;
				int r = rand() % count;
				if (r == 0) index = i;
			}
		}
		return index;
	}

private:
	vector<int> data;
}; // Author:XC

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
