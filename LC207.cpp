class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		unordered_map<int, vector<int>> nxt;
		unordered_map<int, int> indegree;
		queue<int> zero;
		for (int i = 0; i<prerequisites.size(); i++) {
			nxt[prerequisites[i].second].push_back(prerequisites[i].first);
			indegree[prerequisites[i].first]++;
		}
		for (int i = 0; i<numCourses; i++)
			if (indegree[i] == 0)  zero.push(i);
		int count = 0;
		while (!zero.empty()) {
			int front = zero.front();
			zero.pop();
			for (int i = 0; i<nxt[front].size(); i++) {
				indegree[nxt[front][i]]--;
				if (indegree[nxt[front][i]] == 0)
					zero.push(nxt[front][i]);
			}
			count++;
		}
		if (count != numCourses)
			return false;
		return true;
	}
};