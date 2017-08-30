class Solution {
public:
	int minMoves(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		int sum = 0;
		int min = INT_MAX;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < min) min = nums[i];
			sum += nums[i];
		}
		return sum - min * nums.size();
	}
};