class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        sums.push_back(0);
        for (auto n : nums) {
            sum += n;
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
private:
    vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
