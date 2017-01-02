//1.BFS

class Solution {
public:
	int numSquares(int n) {
		if (n == 0)    return 0;
		queue<pair<int, int>> q;
		q.push(make_pair(n, 0));
		unordered_map<int, int> hash;
		hash[n] = 1;
		while (!q.empty()) {
			int num = q.front().first;
			int deph = q.front().second;
			q.pop();
			for (int i = sqrt(num); i>0; i--) {
				if (i*i == num)
					return deph + 1;
				if (hash.find(num - i*i) == hash.end()) {
					q.push(make_pair(num - i*i, deph + 1));
					hash[num - i*i] = 1;
				}
			}
		}
		return 0;
	}
};

//2.DP

class Solution {
public:
	int numSquares(int n) {
		if (n == 0)    return 0;
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			int min = INT_MAX;
			int j = 1;
			while (j <= sqrt(i)) {
				if (j*j == i) {
					min = 1;
					break;
				}
				if (dp[i - j*j] + 1<min)
					min = dp[i - j*j] + 1;
				j++;
			}
			dp[i] = min;
		}
		return dp[n];
	}
};