bool cmp(int x, int y) {
	return x > y;
}
class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<string> rank;
		vector<int> sortNum = nums;
		sort(sortNum.begin(), sortNum.end(), cmp);
		unordered_map<int, int> index;
		for (int i = 0; i < sortNum.size(); i++)
			index[sortNum[i]] = i;
		for (int i = 0; i < nums.size(); i++) {
			if (index[nums[i]] < 3) {
				if (index[nums[i]] == 0) rank.push_back("Gold Medal");
				else if (index[nums[i]] == 1) rank.push_back("Silver Medal");
				else rank.push_back("Bronze Medal");
			}
			else {
				rank.push_back(to_string(index[nums[i]] + 1));
			}
		}
		return rank;
	}
};