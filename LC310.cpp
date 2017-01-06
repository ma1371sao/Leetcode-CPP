class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> res;
		unordered_map<int, int> indegree;
		unordered_map<int, vector<int>> nxt;
		if (n == 1) {
			res.push_back(0);
			return res;
		}
		if (n == 2) {
			res.push_back(0);
			res.push_back(1);
			return res;
		}
		for (int i = 0; i<edges.size(); i++) {
			indegree[edges[i].first]++;
			indegree[edges[i].second]++;
			nxt[edges[i].first].push_back(edges[i].second);
			nxt[edges[i].second].push_back(edges[i].first);
		}
		queue<int> v;
		vector<int> vis(n, 0);
		int num = n;
		for (int i = 0; i<n; i++)
			if (indegree[i] == 1) {
				v.push(i);
				vis[i] = 1;
				num--;
			}
		while (!v.empty()) {
			if ((v.size() == 2 || v.size() == 1) && num == 0) {
				while (!v.empty()) {
					res.push_back(v.front());
					v.pop();
				}
				return res;
			}
			int number = v.size();
			for (int i = 0; i<number; i++) {
				int node = v.front();
				v.pop();
				for (int j = 0; j<nxt[node].size(); j++)
					if (!vis[nxt[node][j]]) {
						indegree[nxt[node][j]]--;
						if (indegree[nxt[node][j]] == 1) {
							v.push(nxt[node][j]);
							vis[nxt[node][j]] = 1;
							num--;
						}
					}
			}
		}
		return res;
	}
};