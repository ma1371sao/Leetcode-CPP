class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		return win(nums, 0, 0, true, 0, nums.size() - 1);
	}

	bool win(vector<int>& nums, int score1, int score2, bool turn, int left, int right) {
		if (left == right) {
			if (turn) {
				score1 += nums[left];
				if (score1 >= score2) return true;
				return false;
			}
			else {
				score2 += nums[left];
				if (score2 > score1) return true;
				return false;
			}
		}
		if (turn) {
			if (!win(nums, score1 + nums[left], score2, !turn, left + 1, right)) return true;
			if (!win(nums, score1 + nums[right], score2, !turn, left, right - 1)) return true;
		}
		else {
			if (!win(nums, score1, score2 + nums[left], !turn, left + 1, right)) return true;
			if (!win(nums, score1, score2 + nums[right], !turn, left, right - 1)) return true;
		}
		return false;
	}
};