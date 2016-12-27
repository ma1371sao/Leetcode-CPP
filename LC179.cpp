struct cmp {
	bool operator()(const string a, const string b) {
		string s1 = a + b;
		string s2 = b + a;
		return s1<s2;
	}
};
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string res;
		priority_queue<string, vector<string>, cmp> pq;
		bool zero = true;
		for (int i = 0; i<nums.size(); i++) {
			pq.push(transtostring(nums[i]));
			if (nums[i])
				zero = false;
		}
		if (zero)
			return "0";
		while (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
		return res;
	}
	string transtostring(int num) {
		string s;
		string res;
		if (num == 0)
			return "0";
		while (num) {
			s.push_back(num % 10 + 48);
			num /= 10;
		}
		for (int i = s.length() - 1; i >= 0; i--)
			res.push_back(s[i]);
		return res;
	}
};