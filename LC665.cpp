class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int count = 1;
		int maxVal = INT_MIN;
		int cur = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (cur > nums[i]) {
				count--;
				if (count < 0) return false;
				if (nums[i] >= maxVal) cur = nums[i];
				else maxVal = cur;
			}
			else {
				maxVal = cur;
				cur = nums[i];
			}
		}
		return true;
	}
};