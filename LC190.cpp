class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		int c;
		vector<int>v;
		uint32_t ans = 0;
		while (n)
		{
			c = n % 2;
			v.push_back(c);
			n = n / 2;
		}
		int l = v.size();
		if (l<32)
			for (int i = l; i<32; i++)
				v.push_back(0);
		for (int i = 0; i<32; i++)
		{
			ans += v[i] * pow(2, 31 - i);
		}
		return ans;
	}
};