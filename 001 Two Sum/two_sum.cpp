class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> counter;
        vector<int> result(2);
        for (int i = 0; i < nums.size(); i++) {
            if (counter.find(target - nums[i]) == counter.end()) {
                counter[nums[i]] = i;
            } else {
                result[0] = counter[target - nums[i]];
                result[1] = i;
                return result;
            }
        }
        return result;
    }
}; // Author: XC