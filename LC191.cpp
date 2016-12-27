class Solution {
public:
	int hammingWeight(uint32_t n) {
		int c;
		int ans = 0;
		while (n)
		{
			c = n % 2;
			if (c == 1)    ans++;
			n /= 2;
		}
		return ans;
	}
};