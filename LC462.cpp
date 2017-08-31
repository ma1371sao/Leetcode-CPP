class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int medium = nums[nums.size() / 2];
		int moves = 0;
		for (int i = 0; i < nums.size(); i++) {
			moves += abs(nums[i] - medium);
		}
		return moves;
	}
};