class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> res;
		int n = prerequisites.size();
		if (numCourses == 0)   return res;
		vector<int> innum(numCourses, 0);
		vector<int> vis(numCourses, 0);
		unordered_map<int, vector<int>> next;
		for (int i = 0; i<n; i++) {
			innum[prerequisites[i].first]++;
			next[prerequisites[i].second].push_back(prerequisites[i].first);
		}
		for (int i = 0; i<numCourses; i++) {
			int flag = 0;
			for (int j = 0; j<numCourses; j++)
				if (innum[j] == 0 && !vis[j]) {
					flag = 1;
					vis[j] = 1;
					res.push_back(j);
					for (int k = 0; k<next[j].size(); k++)
						innum[next[j][k]]--;
					break;
				}
			if (!flag) {
				vector<int> v;
				return v;
			}
		}
		return res;
	}
};