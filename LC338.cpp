class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res;
		if (num<0)   return res;
		res.push_back(0);
		int base = 1;
		for (int i = 1; i <= num; i++) {
			while (base <= i)
				base *= 2;
			base /= 2;
			res.push_back(1 + res[i - base]);
		}
		return res;
	}
};