class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, temp;
        for (auto n : nums) {
            twos |= ones & n;
            ones ^= n;
            temp = ~(ones & twos);
            ones &= temp;
            twos &= temp;
        }
        return ones;
    }
}; // Author: XC
