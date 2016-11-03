class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
    	if (pq_lt.empty()) {
    		pq_lt.push(num);
    		return;
    	}
    	int lt = pq_lt.top();
    	if (num < lt) pq_lt.push(num);
    	else pq_rt.push(num);
    	if (pq_lt.size() > pq_rt.size() + 1) {
    		pq_rt.push(pq_lt.top());
    		pq_lt.pop();
    	} else if (pq_lt.size() < pq_rt.size()) {
    		pq_lt.push(pq_rt.top());
    		pq_rt.pop();
    	}
    }

    // Returns the median of current data stream
    double findMedian() {
    	if (pq_lt.empty() && pq_rt.empty()) return 0.0;
        if (pq_lt.size() == pq_rt.size()) return (pq_lt.top() + pq_rt.top()) / 2.0;
        return pq_lt.top();
    }

private:
    priority_queue<int, vector<int>, less<int>> pq_lt;
    priority_queue<int, vector<int>, greater<int>> pq_rt;
}; // Author: XC

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
