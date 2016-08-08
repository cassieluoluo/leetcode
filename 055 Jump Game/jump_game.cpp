class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right = 0;
        int last = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i + nums[i] > right) {
                right = i + nums[i];
            }
            if (right >= last) return true;
            else if (i == right) return false;
        }
        return true;
    }
}; // Author: XC