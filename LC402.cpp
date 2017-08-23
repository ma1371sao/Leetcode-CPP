class Solution {
public:
	string removeKdigits(string num, int k) {
		string res;
		if (num.length() == k) return "0";
		res.push_back(num[0]);
		int pos = 1;
		while (pos < num.length()) {
			if (num[pos] >= res.back() || k == 0) {
				res.push_back(num[pos]);
				pos++;
			}
			else {
				res = res.substr(0, res.length() - 1);
				k--;
			}
		}
		while (res[0] == '0' && res.length() > 0) {
			res.erase(res.begin());
		}
		res = res.substr(0, res.length() - k);
		if (res.length() == 0) return "0";
		return res;
	}
};