class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> res;
		vector<int> indegree(numCourses, 0);
		unordered_map<int, vector<int>> arrivedPts;
		for (auto edge : prerequisites) {
			indegree[edge.first]++;
			arrivedPts[edge.second].push_back(edge.first);
		}
		while (res.size() < numCourses) {
			int preSize = res.size();
			for (int i = 0; i < numCourses; i++) {
				if (indegree[i] == 0) {
					res.push_back(i);
					for (int point : arrivedPts[i])
						indegree[point]--;
					indegree[i] = -1;
				}
			}
			if (res.size() == preSize) {
				vector<int> v;
				return v;
			}
		}
		return res;
	}
};