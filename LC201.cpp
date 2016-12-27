class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int offset = 0;
		while (m != n) {
			offset++;
			m = m >> 1;
			n = n >> 1;
		}
		return m << offset;
	}
};