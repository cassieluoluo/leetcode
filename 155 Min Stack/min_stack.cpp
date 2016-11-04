class MinStack {
public:
    std::stack<int> st1, st2;
    void push(int x) {
        st1.push(x);
        if (x <= getMin()) st2.push(x);
    }

    void pop() {
        if (st1.top() == getMin()) st2.pop();
        st1.pop();
    }

    int top() {
        return st1.top();
    }

    int getMin() {
        if (st2.empty()) return INT_MAX;
        return st2.top();
    }
}; // Author: XC
