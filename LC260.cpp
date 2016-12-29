class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res(2, 0);
		int axorb = 0;
		for (int i = 0; i<nums.size(); i++)
			axorb ^= nums[i];
		axorb &= -axorb;
		for (int i = 0; i<nums.size(); i++)
			if (nums[i] & axorb)
				res[0] ^= nums[i];
			else
				res[1] ^= nums[i];
		return res;
	}
};