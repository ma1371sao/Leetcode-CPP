class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int fast = 0;
		int slow = 0;
		while (fast < nums.size()) {
			if (nums[fast] != 0) {
				nums[slow++] = nums[fast++];
			}
			else
				fast++;
		}
		while (slow < nums.size())
			nums[slow++] = 0;
	}
};