class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int largest = 0;
        int curr;
        while (i < j) {
            curr = min(height[i], height[j]) * (j - i);
            largest = max(largest, curr);
            if (height[i] < height[j]) i++;
            else j--;
        }
        return largest;
    }
}; // Author: XC