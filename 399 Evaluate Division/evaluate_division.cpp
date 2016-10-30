class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i].first;
            string b = equations[i].second;
            double value = values[i];
            graph[a][b] = value;
            graph[b][a] = 1.0 / value;
            graph[a][a] = 1.0;
            graph[b][b] = 1.0;
        }
        vector<double> result;
        for (auto qr : queries) {
            string a = qr.first;
            string b = qr.second;
			if (graph.find(a) == graph.end() || graph.find(b) == graph.end()) {
				result.push_back(-1.0);
				continue;
			}
			if (graph[a].find(b) != graph[a].end()) {
				result.push_back(graph[a][b]);
				continue;
			}
			if (graph[b].find(a) != graph[b].end()) {
				result.push_back(1.0 / graph[b][a]);
				continue;
			}
            unordered_set<string> visited;
            queue<string> q;
            queue<double> v;
            q.push(a);
            v.push(1.0);
			bool found = false;
            while (!q.empty()) {
                string s = q.front();
                q.pop();
                double value = v.front();
                v.pop();
                visited.insert(s);
                if (graph[s].find(b) != graph[s].end()) {
					double r = value * graph[s][b];
					graph[a][b] = r;
					graph[b][a] = 1.0 / r;
                    result.push_back(r);
					found = true;
                    break;
                }
                for (auto kv : graph[s]) {
                    auto target = kv.first;
                    auto ratio = kv.second;
                    if (visited.find(target) != visited.end()) continue;
                    q.push(target);
                    v.push(ratio * value);
                }
            }
			if (!found) result.push_back(-1.0);
        }
        return result;
    }
}; // Author: XC
