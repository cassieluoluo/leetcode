class Solution {	// Author: Xinyu Chen
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> edges(numCourses);
		for (auto p : prerequisites) {
			edges[p.second].insert(p.first);
		}
		vector<int> indegrees(numCourses, 0);
		for (auto e : edges) {
			for (auto d : e) {
				indegrees[d]++;
			}
		}
		for (int cnt = 0; cnt < numCourses; ++cnt) {
			int i;
			for (i = 0; i < numCourses; ++i) {
				if (indegrees[i] == 0) {
					break;
				}
			}
			if (i == numCourses) return false;
			for (auto p : edges[i]) {
				indegrees[p]--;
			}
			indegrees[i] = -1;
		}
		return true;
	}
};