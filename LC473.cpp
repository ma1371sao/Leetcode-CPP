class Solution {
public:
	bool makesquare(vector<int>& nums) {
		int sum = 0;
		if (nums.size() < 4) return false;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		if (sum % 4 != 0) return false;
		vector<int> fourGroup(4, 0);
		return dfs(nums, fourGroup, sum / 4, 0);
	}

	bool dfs(vector<int>& nums, vector<int>& fourGroup, int side, int index) {
		if (index == nums.size()) {
			if (fourGroup[0] == side && fourGroup[1] == side && fourGroup[2] == side && fourGroup[3] == side) {
				return true;
			}
			return false;
		}
		for (int i = 0; i < 4; i++) {
			if (fourGroup[i] + nums[index] <= side) {
				fourGroup[i] += nums[index];
				if (dfs(nums, fourGroup, side, index + 1)) return true;
				fourGroup[i] -= nums[index];
			}
		}
		return false;
	}
};