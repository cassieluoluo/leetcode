class Solution { // With extra space
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        int i = (len - 1)/ 2, j = len - 1, k = 0;
        while (k < len) {
            nums[k] = k % 2 == 0 ? sorted[i--] : sorted[j--];
            k++;
        }
    }
}; // Author: XC
