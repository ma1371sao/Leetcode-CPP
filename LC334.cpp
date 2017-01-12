class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int n = nums.size();
		if (n<3) return false;
		int min = INT_MAX;
		int minnd = INT_MAX;
		for (int i = 0; i<n; i++) {
			if (nums[i]<min)
				min = nums[i];
			else if (nums[i]>min && nums[i]<minnd)
				minnd = nums[i];
			else if (nums[i]>minnd)
				return true;
		}
		return false;
	}
};