class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> duplicates;
		nums.push_back(1);
		for (int i = 0; i < nums.size() - 1; i++) {
			int num = nums[i] > 0 ? nums[i] : -1 * nums[i];
			if (nums[num] < 0) duplicates.push_back(num);
			else nums[num] = -nums[num];
		}
		return duplicates;
	}
};