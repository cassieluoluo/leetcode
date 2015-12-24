struct CacheNode {
	int key;
	int value;
	CacheNode(int k, int v) {
		key = k;
		value = v;
	}
};

class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (m.find(key) == m.end()) return -1;
		auto it = m[key];
		q.splice(q.begin(), q, it);
		m[key] = q.begin();
		return it->value;
	}

	void set(int key, int value) {
		if (m.find(key) == m.end()) {
			if (q.size() == cap) {
				m.erase(q.back().key);
				q.pop_back();
			}
			auto node = CacheNode(key, value);
			q.push_front(node);
			m[key] = q.begin();
		}
		else {
		    m[key]->value = value;
			get(key);
		}
	}
private:
	int cap, count;
	list<CacheNode> q;
	unordered_map<int, list<CacheNode>::iterator> m;
};