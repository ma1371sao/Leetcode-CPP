class Solution {
public:
	int addDigits(int num) {
		if (num<10)
			return num;
		int ans = (num - 10) % 9 + 1;
		return ans;
	}
};