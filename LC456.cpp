class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		if (nums.size() < 3) return false;
		int first = 0, second, third;
		while (first < nums.size() - 2) {
			for (; first < nums.size() - 2 && nums[first] >= nums[first + 1]; first++);
			for (second = first + 1; second < nums.size() - 1 && nums[second] <= nums[second + 1]; second++);
			third = second + 1;
			for (; third < nums.size() && !(nums[third] > nums[first] && nums[third] < nums[second]); third++);
			if (third < nums.size()) return true;
			first = second + 1;
		}
		return false;
	}
};