class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> st;
        st.push(0);
        int pos = 0, longest = 0;
        while (pos < input.size()) {
            string::size_type end = input.find('\n', pos);
            if (end == string::npos) end = input.size();
            string part = input.substr(pos, end - pos);
            pos = end + 1;
            int tabs = 0;
            while (tabs < part.size() && part[tabs] == '\t') tabs++;
            while (st.size() > tabs + 1) st.pop();
            string name = part.substr(tabs);
            int curr = st.top();
            if (name.find('.') == string::npos) {
                st.push(curr + name.size() + 1);
            } else {
                st.push(curr + name.size());
                longest = max(longest, curr + (int)name.size());
            }
        }
        return longest;
    }
}; // Author: XC
