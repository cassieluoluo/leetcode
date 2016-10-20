class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
    	map<char, char> pairs;
    	pairs[')'] = '(';
    	pairs['}'] = '{';
    	pairs[']'] = '[';
    	for (int i = 0; i < s.size(); i++) {
    		if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
    		else if (st.size() == 0) return false;
    		else if (st.top() != pairs[s[i]]) return false;
    		else st.pop();
    	}
    	if (st.size() > 0) return false;
    	return true;
    }
}; // Author: XC
