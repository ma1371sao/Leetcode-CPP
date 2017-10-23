class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
		hp[m][n - 1] = 1;
		hp[m - 1][n] = 1;
		for (int r = m - 1; r >= 0; r--) {
			for (int c = n - 1; c >= 0; c--) {
				int need = min(hp[r + 1][c], hp[r][c + 1]) - dungeon[r][c];
				hp[r][c] = need > 0 ? need : 1;
			}
		}
		return hp[0][0];
	}
};