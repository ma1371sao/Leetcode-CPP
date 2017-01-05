class Solution {
public:
	bool isAdditiveNumber(string num) {
		int n = num.length();
		if (n<3)
			return false;
		for (int i = 1; i <= n - 2; i++) {
			string num1 = num.substr(0, i);
			if (num1[0] == '0' && i != 1)
				continue;
			for (int j = i + 1; j <= n - 1; j++) {
				string num2 = num.substr(i, j - i);
				if (num2[0] == '0' && j - i>1)
					continue;
				if (verify(num1, num2, num, j))
					return true;
			}
		}
		return false;
	}
	bool verify(string num1, string num2, string num, int pos) {
		while (pos<num.length()) {
			string s = sum(num1, num2);
			if (pos + s.length() <= num.length() && num.substr(pos, s.length()) == s) {
				num1 = num2;
				num2 = s;
				pos += s.length();
			}
			else
				return false;
		}
		return true;
	}
	string sum(string num1, string num2) {
		int flag = 0;
		int i = num1.length() - 1;
		int j = num2.length() - 1;
		string s, res;
		int tmp;
		while (i >= 0 || j >= 0) {
			if (i >= 0 && j >= 0)
				tmp = num1[i--] - 48 + num2[j--] - 48 + flag;
			else if (i >= 0)
				tmp = num1[i--] - 48 + flag;
			else if (j >= 0)
				tmp = num2[j--] - 48 + flag;
			flag = tmp / 10;
			s.push_back(tmp % 10 + 48);
		}
		if (flag)
			s.push_back('1');
		for (i = s.length() - 1; i >= 0; i--)
			res.push_back(s[i]);
		return res;
	}
};