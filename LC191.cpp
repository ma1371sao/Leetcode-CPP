class Solution {
public:
	int hammingWeight(uint32_t n) {
		int numOne = 0;
		while (n) {
			if (n % 2) numOne++;
			n = n >> 1;
		}
		return numOne;
	}
};