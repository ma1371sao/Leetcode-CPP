class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> lastConsecutiveOnes(nums.size(), 0);
		vector<int> maxConsecutiveOnes(nums.size(), 0);
		if (nums[0]) {
			maxConsecutiveOnes[0] = 1;
			lastConsecutiveOnes[0] = 1;
		}
		for (int i = 1; i < nums.size(); i++) {
			if (!nums[i]) maxConsecutiveOnes[i] = maxConsecutiveOnes[i - 1];
			else {
				lastConsecutiveOnes[i] = 1 + lastConsecutiveOnes[i - 1];
				maxConsecutiveOnes[i] = max(maxConsecutiveOnes[i - 1], lastConsecutiveOnes[i]);
			}
		}
		return maxConsecutiveOnes.back();
	}
};