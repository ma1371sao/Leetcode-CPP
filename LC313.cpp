class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		if (n == 1)    return 1;
		vector<int> dp(n, 0);
		dp[0] = 1;
		vector<int> v(primes.size(), 0);
		unordered_map<int, int>hash;
		hash[1] = 1;
		for (int i = 1; i<n; i++) {
			int min = INT_MAX;
			int p;
			for (int j = 0; j<primes.size(); j++)
				if (primes[j] * dp[v[j]]<min) {
					min = primes[j] * dp[v[j]];
					p = j;
				}
			if (hash.find(min) == hash.end()) {
				dp[i] = min;
				hash[min] = 1;
			}
			else
				i--;
			v[p]++;
		}
		return dp.back();
	}
};