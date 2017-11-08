class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> redEdge;
		int setNum = 0;
		unordered_map<int, int> v_num;
		for (int i = 0; i < edges.size(); i++) {
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
				if (v_num[edges[i][1]] != v_num[edges[i][0]]) {
					int num = v_num[edges[i][1]];
					for (auto& it : v_num) {
						if (it.second == num) {
							it.second = v_num[edges[i][0]];
						}
					}
				}
				else {
					redEdge.push_back(min(edges[i][0], edges[i][1]));
					redEdge.push_back(max(edges[i][0], edges[i][1]));
					break;
				}
			}
		}
		return redEdge;
	}
};