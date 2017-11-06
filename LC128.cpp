class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> LCS;
		int maxLen = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (LCS.find(nums[i]) == LCS.end()) {
				int left = (LCS.find(nums[i] - 1) != LCS.end()) ? LCS[nums[i] - 1] : 0;
				int right = (LCS.find(nums[i] + 1) != LCS.end()) ? LCS[nums[i] + 1] : 0;
				int sum = left + right + 1;
				if (maxLen < sum) maxLen = sum;
				LCS[nums[i]] = sum;
				LCS[nums[i] - left] = sum;
				LCS[nums[i] + right] = sum;
			}
		}
		return maxLen;
	}
};