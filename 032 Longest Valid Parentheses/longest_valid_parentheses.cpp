class Solution {
public:
    int longestValidParentheses(string s) {
    	stack<int> st;
    	for (size_t i = 0; i < s.size(); i++) {
    		if (s[i] == '(') {
    			st.push(i);
    		}
    		else {
    			if (st.empty())
    				st.push(i);
    			else if (s[st.top()] == '(')
    				st.pop();
    			else
    				st.push(i);
    		}
    	}
    	int max_len = INT_MIN;
    	int last = s.size(), first;
    	while (!st.empty()) {
    		first = st.top();
    		st.pop();
    		max_len = max(last - first - 1, max_len);
    		last = first;
    	}
    	max_len = max(last, max_len);
    	return max_len;
    }
};