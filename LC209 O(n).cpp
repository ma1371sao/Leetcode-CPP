class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int i = 0;
		int j = 0;
		int minLen = INT_MAX;
		int sum = 0;
		while (j < nums.size()) {
			sum += nums[j++];
			while (sum >= s) {
				minLen = min(minLen, j - i);
				sum -= nums[i++];
			}
		}
		return (minLen < INT_MAX) ? minLen : 0;
	}
};