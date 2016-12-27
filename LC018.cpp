class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		int n = nums.size();
		if (n<4)
			return ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i<n - 3; i++)
		{
			for (int j = i + 1; j<n - 2; j++)
			{
				int p, q;
				for (p = j + 1, q = n - 1; p<q;)
				{
					if (nums[i] + nums[j] + nums[p] + nums[q] == target)
					{
						vector<int> v;
						v.push_back(nums[i]);
						v.push_back(nums[j]);
						v.push_back(nums[p]);
						v.push_back(nums[q]);
						ans.push_back(v);
						for (; p<q && nums[p] == nums[p + 1]; p++);
						p++;
						for (; p<q && nums[q] == nums[q - 1]; q--);
						q--;
					}
					else if (nums[i] + nums[j] + nums[p] + nums[q]<target)
					{
						for (; p<q && nums[p] == nums[p + 1]; p++);
						p++;
					}
					else if (nums[i] + nums[j] + nums[p] + nums[q]>target)
					{
						for (; p<q && nums[q] == nums[q - 1]; q--);
						q--;
					}
				}
				for (; j<n - 2 && nums[j] == nums[j + 1]; j++);
			}
			for (; i<n - 3 && nums[i] == nums[i + 1]; i++);
		}
		return ans;
	}
};