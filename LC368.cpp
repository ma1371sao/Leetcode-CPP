class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<int> res;
		if (nums.size() == 0)
			return res;
		sort(nums.begin(), nums.end());
		vector<int> dpmax(nums.size(), -1);
		vector<int> dpn(nums.size(), 1);
		int max = 1;
		int p = 0;
		for (int i = 1; i<nums.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (nums[i] % nums[j] == 0 && dpn[j] + 1>dpn[i]) {
					dpn[i] = dpn[j] + 1;
					dpmax[i] = j;
				}
			}
			if (dpn[i]>max) {
				max = dpn[i];
				p = i;
			}
		}
		while (p != -1) {
			res.push_back(nums[p]);
			p = dpmax[p];
		}
		return res;
	}
};