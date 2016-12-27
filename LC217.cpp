class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int l = nums.size();
		if (l == 0 || l == 1)
			return false;
		map<int, int> m;
		for (int i = 0; i<l; i++)
		{
			if (m.find(nums[i]) == m.end())
				m[nums[i]] = 1;
			else
				return true;
		}
		return false;
	}
};