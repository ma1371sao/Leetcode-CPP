class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int l = nums.size();
		map<int, int> m;
		for (int i = 0; i<l; i++)
		{
			if (m.find(nums[i]) == m.end())
				m[nums[i]] = i;
			else
			{
				if (i - m[nums[i]] <= k)
					return true;
				else
					m[nums[i]] = i;
			}
		}
		return false;
	}
};