class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (z>x + y)
			return false;
		if (z == x || z == y)    return true;
		if (x == 0 || y == 0)    return false;
		if (z%gcd(x, y) == 0)
			return true;
		return false;
	}
	int gcd(int x, int y) {
		if (y == 0)
			return x;
		return gcd(y, x%y);
	}
};