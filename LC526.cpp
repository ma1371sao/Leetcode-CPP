class Solution {
public:
	int countArrangement(int N) {
		vector<bool> visit(N + 1, false);
		return findBtfArrange(N, visit, 1);
	}
	int findBtfArrange(int n, vector<bool>& visit, int pos) {
		if (pos > n) return 1;
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (!visit[i] && max(pos, i) % min(pos, i) == 0) {
				visit[i] = true;
				count += findBtfArrange(n, visit, pos + 1);
				visit[i] = false;
			}
		}
		return count;
	}
};