class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0) return "0";
		string res;
		int sign = 0;
		if (num < 0) {
			sign = 1;
			num = -num;
		}
		while (num) {
			res.push_back(num % 7 + '0');
			num /= 7;
		}
		if (sign) res.push_back('-');
		reverse(res.begin(), res.end());
		return res;
	}
};