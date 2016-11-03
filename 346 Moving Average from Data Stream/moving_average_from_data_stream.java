public class MovingAverage {

    /** Initialize your data structure here. */
    private Queue<Integer> queue;
    
    private int size;
    
    private double sum;
    public MovingAverage(int size) {
        this.size = size;
        queue = new LinkedList<>();
        sum = 0;
    }
    
    public double next(int val) {
        sum += val;
        queue.add(val);
        if (queue.size() <= size) return sum / queue.size();// <= 
        else {
            sum -= queue.poll();
            return sum / size;
        }
    }
} // Author: Cassie

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
