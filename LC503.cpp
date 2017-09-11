class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> res;
		if (nums.size() == 0) return res;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			nums.push_back(nums[i]);
		}
		vector<int> nxtGreater(nums.size(), -1);
		for (int i = nums.size() - 2; i >= 0; i--) {
			int right = i + 1;
			while (!(right == -1 || nums[right] > nums[i])) {
				right = nxtGreater[right];
			}
			nxtGreater[i] = right;
		}
		for (int i = 0; i < n; i++) {
			if (nxtGreater[i] == -1) res.push_back(-1);
			else res.push_back(nums[nxtGreater[i]]);
		}
		return res;
	}
};