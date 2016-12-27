class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.size() == 0 || nums.size() == 1 || k == 0)    return false;
		set<int> s;
		unordered_map<int, int> hash;
		long long tt = t;
		for (int i = 0; i<nums.size(); i++) {
			if (i>k && hash[nums[i - k - 1]] == i - k - 1)
				s.erase(nums[i - k - 1]);
			set<int>::iterator it = s.lower_bound(nums[i] - tt);
			if (it != s.end() && (*it) <= nums[i] + tt)
				return true;
			s.insert(nums[i]);
			hash[nums[i]] = i;
		}
		return false;
	}
};