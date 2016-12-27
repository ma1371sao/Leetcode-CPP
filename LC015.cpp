class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int l = nums.size();
		if (l == 0)
			return ans;
		for (int i = 0; i<l; i++)
		{
			int k = nums[i];
			int p, q;
			for (p = i + 1, q = l - 1; p<q;)
			{
				int tmp = nums[p] + nums[q];
				if (tmp == -k)
				{
					vector<int> tuple;
					tuple.push_back(k);
					tuple.push_back(nums[p]);
					tuple.push_back(nums[q]);
					ans.push_back(tuple);
					for (; p<q && nums[p] == nums[p + 1]; p++);
					p++;
					for (; p<q && nums[q] == nums[q - 1]; q--);
					q--;
				}
				else if (tmp<-k)
				{
					for (; p<q && nums[p] == nums[p + 1]; p++);
					p++;
				}
				else if (tmp>-k)
				{
					for (; p<q && nums[q] == nums[q - 1]; q--);
					q--;
				}
			}
			for (; i<l && nums[i] == nums[i + 1]; i++);
		}
		return ans;
	}
};