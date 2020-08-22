//dp[i][j]: count when start from (i, j) and move k-1 steps
//dp_k[i][j]: count when start from (i, j) and move k steps
//TC: O(K * N * N) SC: O(N *N)
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if (K == 0) return 1;
        vector<vector<double>> dp(N, vector<double>(N, 1));
        vector<vector<int>> nxt{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        for (int k = 1; k <= K; k++) {
            vector<vector<double>> dp_k(N, vector<double>(N, 0));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (auto v : nxt) {
                        int x = i + v[0];
                        int y = j + v[1];
                        if (x < 0 || x >= N || y < 0 || y >= N) continue;
                        dp_k[i][j] += dp[x][y];
                    }
                }
            }
            dp = dp_k;
        }
        return dp[r][c] / pow(8, K);
    }
};

//dp[k][i][j]: count when start from (i, j) and move k steps
//TC: O(K * N * N) SC: O(K * N *N)
class Solution2 {
public:
    double knightProbability(int N, int K, int r, int c) {
        if (K == 0) return 1;
        vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, 0)));
        vector<vector<int>> nxt{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        for (int k = 0; k <= K; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (k == 0) dp[k][i][j] = 1;
                    else {
                        for (auto v : nxt) {
                            int x = i + v[0];
                            int y = j + v[1];
                            if (x < 0 || x >= N || y < 0 || y >= N) continue;
                            dp[k][i][j] += dp[k - 1][x][y];
                        }
                    }
                }
            }
        }
        return dp[K][r][c] / pow(8, K);
    }
};
