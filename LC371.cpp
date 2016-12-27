class Solution {
public:
	int getSum(int a, int b) {
		int ans = a ^ b;
		int plus = a & b;
		plus = plus << 1;
		if (plus != 0)
			return getSum(ans, plus);
		return ans;
	}
};