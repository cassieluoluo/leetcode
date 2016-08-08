public class MinStack {
    private Stack<Integer> dat, aux;
    private int min;
    /** initialize your data structure here. */
    public MinStack() {
        dat = new Stack<>();
        aux = new Stack<>();
        min = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        dat.push(x);
        min = Math.min(x, min);
        aux.push(min);
    }
    
    public void pop() {
        if (dat.isEmpty()) return;
        dat.pop();
        aux.pop();
        if (aux.isEmpty()) min = Integer.MAX_VALUE;
        else min = aux.peek();
    }
    
    public int top() {
        if (dat.isEmpty()) return 0;
        return dat.peek();
    }
    
    public int getMin() {
        if (aux.isEmpty()) return 0;
        return aux.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 * Author: XC
 */