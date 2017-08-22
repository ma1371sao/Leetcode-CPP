class Solution {
public:
	vector<int> nums;
	Solution(vector<int> nums) {
		this->nums = nums;
	}

	int pick(int target) {
		int randomRes = -1;
		int upbound = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				upbound++;
				if (upbound == 1) {
					randomRes = i;
				}
				else {
					if (rand() % upbound == 0) randomRes = i;
				}
			}
		}
		return randomRes;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* int param_1 = obj.pick(target);
*/