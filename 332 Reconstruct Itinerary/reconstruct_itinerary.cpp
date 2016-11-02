class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
		count = 0;
		total = tickets.size();
        for (auto t : tickets) {
			if (hash.find(t.first) != hash.end()) {
				hash[t.first]->push_back(t.second);
			} else {
				deque<string> *pdq = new deque<string>();
				pdq->push_back(t.second);
				hash[t.first] = pdq;
			}
		}
        for (auto p : hash) {
			auto pdq = p.second;
			sort(pdq->begin(), pdq->end());
		}
		result.push_back("JFK");
		helper("JFK");
		return result;
    }
    
    void helper(string depart) {
		if (hash.find(depart) == hash.end()) return;
        auto pdq = hash[depart];
		for (auto i = 0; i < pdq->size(); i++) {
			auto arrival = pdq->front();
			pdq->pop_front();
			result.push_back(arrival);
			count++;
			helper(arrival);
			if (count == total) return;
			count--;
			result.pop_back();
			pdq->push_back(arrival);
		}
    }

private:
    unordered_map<string, deque<string> *> hash;
    vector<string> result;
	int count, total;
}; // Author: XC
