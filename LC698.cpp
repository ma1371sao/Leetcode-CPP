class Solution {
public:
	bool canPartition;
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		if (sum % k != 0) return false;
		sort(nums.begin(), nums.end());
		reverse(nums.begin(), nums.end());
		if (nums.back() > sum / k) return false;
		vector<int> kParts(k, 0);
		canPartition = false;
		dfs(kParts, sum / k, nums, 0);
		return canPartition;
	}

	void dfs(vector<int>& kParts, int limit, vector<int>& nums, int pos) {
		if (pos >= nums.size()) {
			canPartition = true;
			return;
		}
		for (int i = 0; i < kParts.size(); i++) {
			if (kParts[i] + nums[pos] <= limit) {
				kParts[i] += nums[pos];
				dfs(kParts, limit, nums, pos + 1);
				if (canPartition) return;
				kParts[i] -= nums[pos];
			}
		}
	}
};