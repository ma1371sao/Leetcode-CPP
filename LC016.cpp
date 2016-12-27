class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans;
		sort(nums.begin(), nums.end());
		int l = nums.size();
		int dis = INT_MAX;
		if (l == 0)
			return 0;
		for (int i = 0; i<l; i++)
		{
			int sum;
			int tmp = nums[i];
			int p, q;
			for (p = i + 1, q = l - 1; p<q;)
			{
				sum = tmp + nums[p] + nums[q];
				if (target - sum == 0)
					return sum;
				if (abs(target - sum)<dis)
				{
					dis = abs(target - sum);
					ans = sum;
				}
				if (target - sum>0)
				{
					for (; p<q && nums[p] == nums[p + 1]; p++);
					p++;
				}
				else if (target - sum<0)
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