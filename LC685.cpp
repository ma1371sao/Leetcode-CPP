class Solution {
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		vector<vector<int>> cand;
		vector<int> redEdge;
		unordered_map<int, int> inDegree;
		unordered_map<int, int> outDegree;
		for (int i = 0; i < edges.size(); i++) {
			inDegree[edges[i][1]]++;
			outDegree[edges[i][0]]++;
		}
		for (int i = edges.size() - 1; i >= 0; i--) {
			if (inDegree[edges[i][1]] == 2) {
				vector<int> v;
				v.push_back(edges[i][0]);
				v.push_back(edges[i][1]);
				cand.push_back(v);
			}
		}
		if (cand.size() == 0) {
			for (int i = edges.size() - 1; i >= 0; i--) {
				if (outDegree[edges[i][1]] != 0) {
					redEdge.push_back(edges[i][0]);
					redEdge.push_back(edges[i][1]);
					return redEdge;
				}
			}
		}
		unordered_map<int, int> v_num;
		int setNum = 0;
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i][0] == cand[0][0] && edges[i][1] == cand[0][1]) continue;
			if (v_num.find(edges[i][0]) == v_num.end() && v_num.find(edges[i][1]) == v_num.end()) {
				v_num[edges[i][0]] = setNum;
				v_num[edges[i][1]] = setNum++;
			}
			else if (v_num.find(edges[i][0]) == v_num.end()) {
				v_num[edges[i][0]] = v_num[edges[i][1]];
			}
			else if (v_num.find(edges[i][1]) == v_num.end()) {
				v_num[edges[i][1]] = v_num[edges[i][0]];
			}
			else {
				if (v_num[edges[i][0]] != v_num[edges[i][1]]) {
					int num = v_num[edges[i][1]];
					for (auto& it : v_num) {
						if (it.second == num)
							it.second = v_num[edges[i][0]];
					}
				}
				else {
					return cand[1];
				}
			}
		}
		return cand[0];
	}
};