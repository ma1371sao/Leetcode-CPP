class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> num;
		int res;
		int a1, a2;
		for (int i = 0; i<tokens.size(); i++) {
			if (tokens[i] == "+") {
				if (num.size()<2)
					return 0;
				a1 = num.top();
				num.pop();
				a2 = num.top();
				num.pop();
				num.push(a1 + a2);
			}
			else if (tokens[i] == "-") {
				if (num.size()<2)
					return 0;
				a1 = num.top();
				num.pop();
				a2 = num.top();
				num.pop();
				num.push(a2 - a1);
			}
			else if (tokens[i] == "*") {
				if (num.size()<2)
					return 0;
				a1 = num.top();
				num.pop();
				a2 = num.top();
				num.pop();
				num.push(a1*a2);
			}
			else if (tokens[i] == "/") {
				if (num.size()<2)
					return 0;
				a1 = num.top();
				num.pop();
				a2 = num.top();
				num.pop();
				num.push(a2 / a1);
			}
			else {
				int k = 1;
				int n = 0;
				for (int j = tokens[i].length() - 1; j >= 0; j--) {
					if (tokens[i][j] == '-')   n *= -1;
					else {
						n += (tokens[i][j] - 48)*k;
						k *= 10;
					}
				}
				num.push(n);
			}
		}
		if (num.size() != 1)   return 0;
		return num.top();
	}
};