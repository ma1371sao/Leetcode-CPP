class Solution {
public:
	int hammingDistance(int x, int y) {
		int xy = x ^ y;
		int dis = 0;
		while (xy > 0) {
			if (xy % 2) dis++;
			xy = xy >> 1;
		}
		return dis;
	}
};