class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> m;
		int n = nums.size();
		int k = n / 2;
		for (int i = 0; i<n; i++)
		{
			if (m.find(nums[i]) == m.end())
				m[nums[i]] = 1;
			else
				m[nums[i]]++;
			if (m[nums[i]]>k)
				return nums[i];
		}
		return 0;
	}
};