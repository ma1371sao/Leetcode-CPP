class Solution {
public:
	int rob(vector<int>& nums) {
		int l = nums.size();
		vector<int> s;
		if (l == 0)
			return 0;
		s.push_back(nums[0]);
		if (l == 1)
			return s[0];
		if (nums[0] >= nums[1])
			s.push_back(nums[0]);
		else
			s.push_back(nums[1]);
		if (l == 2)
			return s[1];
		for (int i = 2; i<l; i++)
		{
			if (nums[i] + s[i - 2] >= s[i - 1])
				s.push_back(nums[i] + s[i - 2]);
			else
				s.push_back(s[i - 1]);
		}
		return s[l - 1];
	}
};