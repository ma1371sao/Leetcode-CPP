class Solution {
public:
	int calculate(string s) {
		vector<char> op;
		vector<int> num;
		int opnum = 0;
		for (int i = 0; i<s.length(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				string tmp;
				while (i<s.length() && s[i] >= '0' && s[i] <= '9') {
					tmp.push_back(s[i]);
					i++;
				}
				i--;
				num.push_back(strtoint(tmp));
				if (opnum) {
					int num1 = num.back();
					num.pop_back();
					int num2 = num.back();
					num.pop_back();
					if (op.back() == '*') {
						num.push_back(num1*num2);
					}
					else if (op.back() == '/') {
						num.push_back(num2 / num1);
					}
					op.pop_back();
					opnum = 0;
				}
			}
			else if (s[i] == '+' || s[i] == '-') {
				op.push_back(s[i]);
			}
			else if (s[i] == '*' || s[i] == '/') {
				op.push_back(s[i]);
				opnum = 1;
			}
		}
		int i = 0;
		int j = 0;
		while (j<op.size()) {
			int num1 = num[i++];
			int num2 = num[i];
			if (op[j] == '+') {
				num[i] = num1 + num2;
			}
			else if (op[j] == '-') {
				num[i] = num1 - num2;
			}
			j++;
		}
		return num.back();
	}
	int strtoint(string s) {
		int res = 0;
		int flag = 1;
		for (int i = s.length() - 1; i >= 0; i--) {
			res += (s[i] - 48)*flag;
			flag *= 10;
		}
		return res;
	}
};