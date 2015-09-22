/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Evaluate Reverse Polish Notation
 *	https://leetcode.com/problems/evaluate-reverse-polish-notation/
 *	Runtime: 16 ms
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                char op = s[0];
                int res;
                switch (op) {
                    case '+':
                        res = a + b;
                        break;
                    case '-':
                        res = a - b;
                        break;
                    case '*':
                        res = a * b;
                        break;
                    case '/':
                        res = a / b;
                        break;
                }
                st.push(res);
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};