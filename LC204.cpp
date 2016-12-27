class Solution {
public:
	vector<int> prime;
	int countPrimes(int n) {
		if (n == 1)
			return 0;
		int ans = 0;
		for (int i = 2; i<n; i++)
			if (isPrime(i))
			{
				ans++;
				prime.push_back(i);
			}
		return ans;
	}
	bool isPrime(int k)
	{
		if (k == 2)
			return true;
		int l = prime.size();
		for (int i = 0; i<l && prime[i] * prime[i] <= k; i++)
			if (k%prime[i] == 0)
				return false;
		return true;
	}
};