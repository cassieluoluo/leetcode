class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = dac(nums, 0, nums.size() - 1, nums.size() - k);
        return nums[index];
    }
    
    int dac(vector<int>& nums, int lo, int hi, int k) {
        if (lo == hi) return lo;
        int pivot = nums[hi];
        int left = lo, right = hi - 1;
        while (true) {
            while (nums[left] <= pivot && left < hi) left++;
            while (nums[right] > pivot && right > lo) right--;
            if (left >= right) break;
            swap(nums[left], nums[right]);
        }
        swap(nums[hi], nums[left]);
        if (left == k) return left;
        else if (left > k) return dac(nums, lo, left - 1, k);
        else return dac(nums, left + 1, hi, k);
    }
}; // Auhtor: XC