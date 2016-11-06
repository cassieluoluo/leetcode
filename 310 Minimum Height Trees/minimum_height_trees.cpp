class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (edges.empty()) return vector<int>{0};
        unordered_map<int, unordered_set<int>> graph;
        for (auto e : edges) {
            int node1 = e.first;
            int node2 = e.second;
            graph[node1].insert(node2);
            graph[node2].insert(node1);
        }
        queue<int> q;
        for (auto node : graph) 
            if (node.second.size() == 1) q.push(node.first);
        while (n > 2) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                int node = q.front(); q.pop();
                for (auto neighbor : graph[node]) {
                    graph[neighbor].erase(node);
                    if (graph[neighbor].size() == 1) q.push(neighbor);
                }
                graph.erase(node);
                n--;
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
}; // Author: XC
