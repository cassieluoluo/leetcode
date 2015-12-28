class MaxDeque{	// Author: Xinyu Chen
public:
	void push(int value) {
		while (!counter.empty() && counter.back() < value) counter.pop_back();
		counter.push_back(value);
		values.push_back(value);
	}

	void pop() {
		if (values.front() == counter.front()) counter.pop_front();
		values.pop_front();
	}

	int get_max() {
		return counter.front();
	}
private:
	std::deque<int> values;
	std::deque<int> counter;
};

class Solution {	// Author: Xinyu Chen
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) return vector<int>();
        MaxDeque mq;
		vector<int> result(nums.size() - k + 1);
		mq.push(INT_MIN);
		for (int i = 0; i < k - 1; ++i) mq.push(nums[i]);
		for (int i = k - 1; i < nums.size(); ++i) {
			mq.pop();
			mq.push(nums[i]);
			result[i - k + 1] = mq.get_max();
		}
		return result;
    }
};