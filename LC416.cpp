class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		if (sum % 2) return false;
		int target = sum / 2;
		vector<int> value(target + 1, INT_MIN);
		value[0] = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = target; j >= nums[i]; j--) {
				value[j] = max(value[j], value[j - nums[i]]);
			}
		}
		if (value[target] == 0) return true;
		return false;
	}
};