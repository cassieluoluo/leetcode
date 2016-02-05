class ZigzagIterator {	// Author: Xinyu Chen
public:
	ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2) {
		auto i = v1.begin(), j = v2.begin();
			while (i != v1.end() && j != v2.end()) {
				data.push_back(*i); ++i;
				data.push_back(*j); ++j;
			}
		if (i == v1.end()) {
			for (; j != v2.end(); ++j) data.push_back(*j);
		}
		else {
			for (; i != v1.end(); ++i) data.push_back(*i);
		}
		iter = data.begin();
	}

	int next() {
		int ret = *iter;
		++iter;
		return ret;
	}

	bool hasNext() {
		return iter != data.end();
	}
private:
	std::vector<int> data;
	std::vector<int>::iterator iter;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
 