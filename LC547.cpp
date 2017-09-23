
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		if (n == 0) return 0;
		unordered_map<int, int> friendCircle;
		int circleNum = 0;
		unordered_set<int> circleNumSet;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (M[i][j]) {
					if (friendCircle.find(i) == friendCircle.end() && friendCircle.find(j) == friendCircle.end()) {
						friendCircle[i] = friendCircle[j] = circleNum++;
					}
					else if (friendCircle.find(i) == friendCircle.end()) {
						friendCircle[i] = friendCircle[j];
					}
					else if (friendCircle.find(j) == friendCircle.end()) {
						friendCircle[j] = friendCircle[i];
					}
					else {
						int number = friendCircle[j];
						for (auto it = friendCircle.begin(); it != friendCircle.end(); it++) {
							if (it->second == number) {
								it->second = friendCircle[i];
							}
						}
					}
				}
				else {
					if (friendCircle.find(i) == friendCircle.end()) friendCircle[i] = circleNum++;
					if (friendCircle.find(j) == friendCircle.end()) friendCircle[j] = circleNum++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (circleNumSet.find(friendCircle[i]) == circleNumSet.end())
				circleNumSet.insert(friendCircle[i]);
		}
		return circleNumSet.size();
	}
};