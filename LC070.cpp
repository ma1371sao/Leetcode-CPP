class Solution {
public:
	int climbStairs(int n) {
		map<int, int> m;
		m[1] = 1;
		m[2] = 2;
		int ans = DP(n, m);
		return ans;
	}
	int DP(int n, map<int, int>& m)
	{
		int num;
		if (n == 1)
			return m[1];
		else if (n == 2)
			return m[2];
		else
		{
			if (!m.count(n))
			{
				num = DP(n - 1, m) + DP(n - 2, m);
				m[n] = num;
			}
			else
				return m[n];
		}
		return m[n];
	}
};
