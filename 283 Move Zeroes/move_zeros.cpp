class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        int slow = 0;
        int fast = 1;
        while (fast < nums.size()) {
            if (nums[slow] == 0) {
                while (nums[fast] == 0) {
                    fast++;
                    if (fast >= nums.size()) return;
                }
                swap(nums[slow], nums[fast]);
            }
            slow++;
            fast = slow + 1;
        }
    }
}; // Author: XC
