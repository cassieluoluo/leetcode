struct hit_t {
	int timestamp;
	int count;
	hit_t(int t, int c) { timestamp = t; count = c; }
};

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
		if (counter.empty() || counter.back().timestamp != timestamp)
			counter.push_back(hit_t(timestamp, 1));
		else counter.back().count++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
		while (!counter.empty() && counter.front().timestamp + 300 <= timestamp) counter.pop_front();
		int count = 0;
        for (auto h : counter) {
			count += h.count;
		}
		return count;
    }
	
	deque<hit_t> counter;
}; // Author: XC
