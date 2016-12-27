class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int tmax = nums[0];
		int tmin = nums[0];
		int max = nums[0];
		for (int i = 1; i<nums.size(); i++) {
			int tm = tmax;
			if (tmax*nums[i] >= nums[i])
				tmax *= nums[i];
			else
				tmax = nums[i];
			if (tmax<tmin*nums[i])
				tmax = tmin*nums[i];
			if (tmin*nums[i] <= nums[i])
				tmin *= nums[i];
			else
				tmin = nums[i];
			if (tm*nums[i]<tmin)
				tmin = tm*nums[i];
			if (max<tmax)
				max = tmax;
		}
		return max;
	}
};