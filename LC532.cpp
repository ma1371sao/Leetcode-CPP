class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (nums.size() < 2 || k < 0) return 0;
		unordered_set<int> numSearch;
		unordered_map<int, int> kDiffPair;
		for (int i = 0; i < nums.size(); i++) {
			if (numSearch.find(nums[i] + k) != numSearch.end()) {
				if (kDiffPair.find(nums[i]) == kDiffPair.end()) {
					kDiffPair[nums[i]] = nums[i] + k;
				}
			}
			if (numSearch.find(nums[i] - k) != numSearch.end()) {
				if (kDiffPair.find(nums[i] - k) == kDiffPair.end()) {
					kDiffPair[nums[i] - k] = nums[i];
				}
			}
			numSearch.insert(nums[i]);
		}
		return kDiffPair.size();
	}
};