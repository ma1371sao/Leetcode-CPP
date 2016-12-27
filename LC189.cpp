class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		vector<int>tmp;
		vector<int>ans;
		int l = nums.size();
		for (int i = l - 1; i >= 0; i--)
			tmp.push_back(nums[i]);
		for (int i = 0; i<k; i++)
			tmp.push_back(tmp[i]);
		for (int i = tmp.size() - 1; i >= k; i--)
			ans.push_back(tmp[i]);
		nums = ans;
		return;
	}
};