class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string res;
		long long num = numerator;
		long long den = denominator;
		if (num == 0) {
			res.push_back('0');
			return res;
		}
		if (den == 0)
			return res;
		if (num<0 && den<0) {
			num = -num;
			den = -den;
		}
		if (num<0 && den>0) {
			res.push_back('-');
			num = -num;
		}
		if (num>0 && den<0) {
			res.push_back('-');
			den = -den;
		}
		long long divi, remainder;
		int flag = 1;
		unordered_map<long long, int> repeat;
		while (1) {
			if (repeat.find(num) != repeat.end()) {
				res = res.substr(0, repeat[num]) + "(" + res.substr(repeat[num]) + ")";
				break;
			}
			if (!flag)
				repeat[num] = res.length();
			divi = num / den;
			remainder = num%den;
			if (divi<10)
				res.push_back(divi + 48);
			else {
				string s;
				while (divi) {
					s.push_back(divi % 10 + 48);
					divi /= 10;
				}
				for (int i = s.length() - 1; i >= 0; i--)
					res.push_back(s[i]);
			}
			if (!remainder)  break;
			if (flag) {
				res.push_back('.');
				flag = 0;
			}
			num = remainder * 10;
		}
		return res;
	}
};
