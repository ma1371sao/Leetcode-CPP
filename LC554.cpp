class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		if (wall.size() == 0) return 0;
		unordered_map<int, int> edgeNum;
		int maxNum = 0;
		for (int i = 0; i < wall.size(); i++) {
			int rightEdge = 0;
			for (int j = 0; j < wall[i].size() - 1; j++) {
				rightEdge += wall[i][j];
				edgeNum[rightEdge]++;
				if (maxNum < edgeNum[rightEdge]) maxNum = edgeNum[rightEdge];
			}
		}
		return wall.size() - maxNum;
	}
};