class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			int index = abs(nums[i]) - 1;
			if (nums[index] > 0) nums[index] *= -1;
		}
		vector<int> disappearedNum;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0)
				disappearedNum.push_back(i + 1);
		}
		return disappearedNum;
	}
};