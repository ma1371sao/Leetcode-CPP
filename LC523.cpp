class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		if (nums.size() < 2) return false;
		for (int i = 0; i < nums.size(); i++) {
			int sum = nums[i];
			for (int j = i + 1; j < nums.size(); j++) {
				sum += nums[j];
				if (k != 0 && sum % k == 0) return true;
				if (k == 0 && sum == 0) return true;
			}
		}
		return false;
	}
};