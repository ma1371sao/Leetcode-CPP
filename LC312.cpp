class Solution {
public:
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
		vector<vector<int>> maxCoinsNum(nums.size() + 1, vector<int>(nums.size() + 1, 0));
		return divide(nums, maxCoinsNum, 0, nums.size() - 1);
	}
	int divide(vector<int>& nums, vector<vector<int>>& maxCoinsNum, int low, int high) {
		if (low + 1 == high) return 0;
		if (maxCoinsNum[low][high] > 0) return maxCoinsNum[low][high];
		int maxNum = 0;
		for (int i = low + 1; i < high; i++) {
			maxNum = max(maxNum, nums[low] * nums[i] * nums[high] + divide(nums, maxCoinsNum, low, i) + divide(nums, maxCoinsNum, i, high));
		}
		maxCoinsNum[low][high] = maxNum;
		return maxNum;
	}
};