class Solution {
public:
	int findPaths(int m, int n, int N, int i, int j) {
		vector<vector<vector<int>>> numP(m, vector<vector<int>>(n, vector<int>(N, -1)));
		return dfs(m, n, N, i, j, numP, 0);
	}
	int dfs(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& numP, int cur) {
		if (i < 0 || i >= m || j < 0 || j >= n) return 1;
		else if (cur >= N) return 0;
		long long sum = 0;
		if (numP[i][j][cur] == -1) {
			sum = (sum + dfs(m, n, N, i - 1, j, numP, cur + 1)) % 1000000007;
			sum = (sum + dfs(m, n, N, i + 1, j, numP, cur + 1)) % 1000000007;
			sum = (sum + dfs(m, n, N, i, j - 1, numP, cur + 1)) % 1000000007;
			sum = (sum + dfs(m, n, N, i, j + 1, numP, cur + 1)) % 1000000007;
			numP[i][j][cur] = sum;
		}
		return numP[i][j][cur];
	}
};