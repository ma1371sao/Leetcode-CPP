class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		if (!nums.size())    return res;
		int min = nums[0];
		int max;
		for (int i = 0; i<nums.size() - 1; i++) {
			if (nums[i] + 1<nums[i + 1]) {
				max = nums[i];
				string s;
				if (min<max)
					s = s + inttostr(min) + "->" + inttostr(max);
				else
					s = inttostr(min);
				res.push_back(s);
				min = nums[i + 1];
			}
		}
		max = nums.back();
		string s;
		if (min<max)
			s = s + inttostr(min) + "->" + inttostr(max);
		else
			s = inttostr(min);
		res.push_back(s);
		return res;
	}
	string inttostr(int x) {
		string s, res;
		long long xx = x;
		if (xx == 0)    return "0";
		if (xx<0) {
			xx = -xx;
			res.push_back('-');
		}
		while (xx) {
			s.push_back(xx % 10 + 48);
			xx /= 10;
		}
		for (int i = s.length() - 1; i >= 0; i--)
			res.push_back(s[i]);
		return res;
	}
};