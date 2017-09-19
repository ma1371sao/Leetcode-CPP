class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0)
				nums[i] = -1;
		}
		unordered_map<int, int> sumToIndex;
		sumToIndex[0] = -1;
		int sum = 0;
		int maxLen = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sumToIndex.find(sum) != sumToIndex.end()) {
				maxLen = max(maxLen, i - sumToIndex[sum]);
			}
			else {
				sumToIndex[sum] = i;
			}
		}
		return maxLen;
	}
};