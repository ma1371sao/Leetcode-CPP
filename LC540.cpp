class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int singleNum = 0;
		for (int i = 0; i < nums.size(); i++)
			singleNum = singleNum ^ nums[i];
		return singleNum;
	}
};