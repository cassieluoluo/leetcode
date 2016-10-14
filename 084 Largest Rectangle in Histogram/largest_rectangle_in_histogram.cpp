class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
    	stack<int> st;
    	int result = 0;
    	height.push_back(0);
    	int i = 0;
    	while (i < height.size()) {
    		if (st.empty() || height[st.top()] <= height[i]) {
    			st.push(i++);
    		}
    		else {
    			int j = st.top();
    			st.pop();
    			int width = st.empty() ? i : i - st.top() - 1;
    			result = max(result, width * height[j]);
    		}
    	}
    	return result;
    }
}; // Author: XC
