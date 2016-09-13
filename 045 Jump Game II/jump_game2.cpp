class Solution {
public:
    int jump(vector<int>& nums) {   // Time out
        int curr = nums.size() - 1;
        int total = 0;
        while (curr > 0) {
            int leftmost = curr;
            total++;
            for (int j = curr - 1; j >= 0; j--) {
                if (nums[j] + j < curr) continue;
                if (j < leftmost) {
                    leftmost = j;
                }
            }
            curr = leftmost;
        }
        return total;
    }
};  // Author: XC