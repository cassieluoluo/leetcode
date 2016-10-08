class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> edges(numCourses);
		vector<int> indeg(numCourses, 0);
		vector<int> result;
		queue<int> nodes;
		for (auto e : prerequisites)
			edges[e.second].insert(e.first);    // Construct the graph
		for (auto e : edges)
			for (auto v : e) indeg[v]++; // Compute the indegree
		for (int i = 0; i < numCourses; ++i)
			if (indeg[i] == 0) nodes.push(i);
		while (!nodes.empty()) {
			int i = nodes.front();
			nodes.pop();
			result.push_back(i);
			for (auto v : edges[i]) {
				indeg[v]--;	// Disconnect from its neighbors
				if (indeg[v] == 0) nodes.push(v);
			}
			edges[i].clear();
			indeg[i] = -1;
		}
		if (result.size() != numCourses) return vector<int>();
		return result;
	}
}; // Author: XC
