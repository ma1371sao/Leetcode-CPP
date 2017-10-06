class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> sorted = nums;
		sort(sorted.begin(), sorted.end());
		int start = 0;
		for (; start < nums.size() && sorted[start] == nums[start]; start++);
		int end = nums.size() - 1;
		for (; end >= 0 && nums[end] == sorted[end]; end--);
		if (end <= start) return 0;
		return end - start + 1;
	}
};